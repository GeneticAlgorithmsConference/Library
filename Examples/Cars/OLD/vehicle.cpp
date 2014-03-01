#include <cmath>
#include <qmath.h>
#include <QPair>
#include <QtWidgets>

#include "vehicle.h"

int Vehicle::waitingTime = 5000;
double Vehicle::minLength = 1.0;

Vehicle::Vehicle(int _x, int _y, int _pointsNum, int _maxWheelsNum)
{
    x = _x;
    y = _y;
    pointsNum = _pointsNum;
    maxWheelsNum = _maxWheelsNum;
    vehicleBrush.setColor(Qt::red);
    vehicleBrush.setStyle(Qt::SolidPattern);
    score = 0.0;

    springSegmentsNum = 4;
    springWidth = 0.2;
    springLength = 1.0;
    wheelRemoveChance = 5;
    wheelAddChance = 5;

    vectorLength = 1.0;
    wheelRadius = 0.5;

    leftSide = true;
    motorEnabled = true;
}

Vehicle::~Vehicle()
{
}

void Vehicle::generate(uint seed)
{
    vectors.clear();
    vectors.resize(pointsNum);
    qsrand(seed);
    double deltaAngle = M_PI * 2.0 / static_cast<double>(pointsNum);
    unsigned char r = 128 + (qrand() % 128);
    unsigned char g = 128 + (qrand() % 128);
    unsigned char b = 128 + (qrand() % 128);
    // Создание массива неиспользованных (для колёс) вершин.
    QVector <int> notUsed(pointsNum);
    for(int i = 0; i < pointsNum; ++i)
    {
        notUsed[i] = i;
    }

    wheelsNum = (maxWheelsNum > 0) ? (qrand() % (maxWheelsNum + 1)) : 0;

    // Генерация векторов из точки
    for(int i = 0; i < pointsNum; ++i)
    {
        vectors[i].angle = static_cast<double>(i) * deltaAngle + (qrand() % 1000) / 1000.0 * deltaAngle;
        vectors[i].length = 0.2 + (qrand() % 1000) / 1000.0 * vectorLength;
        vectors[i].r = r;
        vectors[i].g = g;
        vectors[i].b = b;
        vectors[i].wheel = false;
        vectors[i].radius = 0.3 + (qrand() % 1000) / 1000.0f * wheelRadius;
        if(leftSide)
        {
            vectors[i].motorSpeed = -(qrand() % 30 + 10);
        } else {

            vectors[i].motorSpeed = (qrand() % 30 + 10);
        }
    }

    for(int i = 0; i < wheelsNum; ++i)
    {
        // Выбор для колеса одной из неиспользуемых вершин.
        int choosed = qrand() % notUsed.size();
        int id = notUsed[choosed];
        vectors[id].wheel = true;
        notUsed.remove(choosed);
    }

    double x1, x2, y1, y2;
    double r1, r2;
    for(int i = 0; i < pointsNum; ++i)
    {
        if(vectors[i].wheel)
        {
            x1 = qCos(vectors[i].angle) * (vectors[i].length + springLength);
            y1 = qSin(vectors[i].angle) * (vectors[i].length + springLength);
            r1 = vectors[i].radius;
            for(int j = i + 1; j < pointsNum; ++j)
            {
                x2 = qCos(vectors[j].angle) * (vectors[j].length + springLength);
                y2 = qSin(vectors[j].angle) * (vectors[j].length + springLength);
                r2 = vectors[j].radius;
                if((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2))
                {
                    if(qrand() % 2)
                    {
                        vectors[i].wheel = false;
                    } else {
                        vectors[j].wheel = false;
                    }
                    break;
                }
            }
        }
    }
    score = 0.0;
}

void Vehicle::tick(b2World *world, double maxX)
{
    b2Manifold *manifold;
    b2ManifoldPoint manifoldPoint;
    b2Vec2 normal;
    if(body != NULL)
    {
        for(b2ContactEdge *ce = body -> GetContactList(); ce; ce = ce -> next)
        {

            manifold = ce -> contact -> GetManifold();
            normal = manifold -> localNormal;
            for(int i = 0; i < manifold -> pointCount; ++i)
            {
                manifoldPoint = manifold -> points[i];
                if(manifoldPoint.normalImpulse > 1.0)
                {
                    breakVehicle(world);
                    while(ce -> next)
                    {
                        ce = ce -> next;
                    }
                    break;
                }
            }
        }
    }

    if(body != NULL)
    {
        if(lastUpdateTime.msecsTo(QTime::currentTime()) >= waitingTime)
        {
            if(lastUpdatePoint.x < 0.0)
            {
                breakVehicle(world);
            } else if(lastUpdatePoint.x > maxX)
            {
                breakVehicle(world);
            } else if((lastUpdatePoint - (body -> GetPosition())).Length() < minLength)
            {
                breakVehicle(world);
            } else {
                lastUpdatePoint = body -> GetPosition();
            }
            lastUpdateTime = QTime::currentTime();
        }
    }
}

void Vehicle::updatePhysics(b2World *world, bool motorEnabled)
{
    // Добавление машины в физический мир
    shape.clear();
    fixture.clear();
    wheelsBodies.clear();
    wheelsJoints.clear();
    bodyParts.clear();
    bodyPartFixtures.clear();

    b2BodyDef bd;
    static b2Vec2 verticies[3];
    bd.type = b2_dynamicBody;
    bd.position.Set(x, y);
    bd.angle = 0.0;
    body = world -> CreateBody(&bd);

    shape.resize(pointsNum);
    fixture.resize(pointsNum);
    for(int i = 0; i < pointsNum - 1; ++i)
    {
        verticies[0].Set(vectors[i].x(), vectors[i].y());
        verticies[1].Set(vectors[i + 1].x(), vectors[i + 1].y());
        verticies[2].Set(0.0f, 0.0f);
        shape[i].Set(verticies, 3);
        fixture[i] = body -> CreateFixture(shape.begin() + i, 1.0f);
    }
    verticies[0].Set(vectors[pointsNum - 1].x(), vectors[pointsNum - 1].y());
    verticies[1].Set(vectors[0].x(), vectors[0].y());
    verticies[2].Set(0.0f, 0.0f);
    shape[pointsNum - 1].Set(verticies, 3);
    fixture[pointsNum - 1] = body -> CreateFixture(shape.begin() + pointsNum - 1, 1.0f);

    wheelsBodies.resize(wheelsNum);
    wheelsJoints.resize(wheelsNum);
    b2WheelJointDef jd;
    b2CircleShape wheelShape;
    b2FixtureDef fixtureDef;
    b2Vec2 axis;
    bd.type = b2_dynamicBody;

    int currentWheel = 0;
    for(int i = 0; i < pointsNum; ++i)
    {
        if(vectors[i].wheel)
        {
            // Установка физических параметров
            bd.position.Set(qCos(vectors[i].angle) * (vectors[i].length + springLength) + x,
                    qSin(vectors[i].angle) * (vectors[i].length + springLength) + y);
            wheelsBodies[currentWheel] = world -> CreateBody(&bd);
            wheelShape.m_radius = vectors[i].radius;
            fixtureDef.shape = &wheelShape;
            fixtureDef.density = 1.0f;
            fixtureDef.friction = 1.0f;
            fixtureDef.restitution = 0.3f;
            wheelsBodies[currentWheel] -> CreateFixture(&fixtureDef);

            axis.Set(qCos(vectors[i].angle) * vectors[i].length,
                    qSin(vectors[i].angle) * vectors[i].length);
            axis.Normalize();
            jd.Initialize(body, wheelsBodies[currentWheel], wheelsBodies[currentWheel] -> GetPosition(), axis);
            jd.motorSpeed = vectors[i].motorSpeed;
            jd.maxMotorTorque = 20.0f;
            jd.enableMotor = motorEnabled;
            jd.frequencyHz = 5.0f;
            jd.dampingRatio = 1.0f;
            wheelsJoints[currentWheel] = dynamic_cast<b2WheelJoint*>(world -> CreateJoint(&jd));
            ++currentWheel;
        }
    }

    lastUpdateTime = QTime::currentTime();
    lastUpdatePoint = body -> GetPosition();
}

void Vehicle::breakVehicle(b2World *world)
{
    b2Body *currentBody;
    b2Fixture *currentBodyFixture;
    score = (body -> GetPosition().x - x > 0.0) ? (body -> GetPosition().x - x) : 0.0;
    bodyParts.clear();
    bodyPartFixtures.clear();
    b2BodyDef bd;
    bd.type = b2_dynamicBody;
    bd.position = body -> GetPosition();
    bd.angle = body -> GetAngle();
    bd.linearVelocity = body -> GetLinearVelocity();
    bd.angularVelocity = body -> GetAngularVelocity();

    for(int j = 0; j < pointsNum; ++j)
    {
        currentBody = world -> CreateBody(&bd);
        currentBodyFixture = currentBody -> CreateFixture(shape.begin() + j, 1.0f);
        bodyParts.push_back(currentBody);
        bodyPartFixtures.push_back(currentBodyFixture);
    }
    world -> DestroyBody(body);
    body = NULL;
}

void Vehicle::show(QPainter &painter)
{
    // Точки для рисования полигона
    static QPointF polygonPoints[3];
    if(body != NULL)
    {
        b2Vec2 position = body -> GetPosition();
        float32 angle = body -> GetAngle();
        for(int i = 0; i < pointsNum; ++i)
        {
            vehicleBrush.setColor(QColor(vectors[i].r, vectors[i].g, vectors[i].b));
            painter.setBrush(vehicleBrush);
            polygonPoints[0].setX((vectors[i].length * qCos(angle + vectors[i].angle) + position.x) * 100);
            polygonPoints[0].setY((vectors[i].length * qSin(angle + vectors[i].angle) + position.y) * 100);
            polygonPoints[1].setX((vectors[(i == pointsNum - 1) ? 0 : (i + 1)].length * qCos(angle + vectors[(i == pointsNum - 1) ? 0 : (i + 1)].angle) + position.x) * 100);
            polygonPoints[1].setY((vectors[(i == pointsNum - 1) ? 0 : (i + 1)].length * qSin(angle + vectors[(i == pointsNum - 1) ? 0 : (i + 1)].angle) + position.y) * 100);
            polygonPoints[2].setX((position.x) * 100);
            polygonPoints[2].setY((position.y) * 100);
            painter.drawPolygon(polygonPoints, 3);
        }

        // Рисование колёс
        vehicleBrush.setColor(Qt::gray);
        painter.setBrush(vehicleBrush);
        int currentWheel = 0;
        for(int i = 0; i < pointsNum; ++i)
        {
            if(vectors[i].wheel)
            {
                b2Vec2 position = wheelsBodies[currentWheel] -> GetPosition();
                float32 angle = wheelsBodies[currentWheel] -> GetAngle();
                float32 radius = vectors[i].radius;
                painter.drawEllipse((position.x - radius) * 100, (position.y - radius) * 100, 200 * radius, 200 * radius);
                painter.drawLine(position.x * 100, position.y * 100, (position.x + radius * cos(angle)) * 100, (position.y + radius * sin(angle)) * 100);
                ++currentWheel;
            }
        }

        // Рисование пружин
        b2Vec2 position1, position2;
        float deltaLength;
        float currentLength;
        float springAngle;
        currentWheel = 0;
        for(int i = 0; i < pointsNum; ++i)
        {
            if(vectors[i].wheel)
            {
                position2 = wheelsBodies[currentWheel] -> GetPosition();
                position1.Set(vectors[i].length * qCos(angle + vectors[i].angle) + position.x,
                        vectors[i].length * qSin(angle + vectors[i].angle) + position.y);
                deltaLength = (position2 - position1).Length() / (springSegmentsNum + 2);
                springAngle = qAtan((position2 - position1).y / (position2 - position1).x);
                if((position2 - position1).x < 0.0f)
                {
                    springAngle -= M_PI;
                }

                // Рисование части пружины возле машины
                currentLength = deltaLength * 0.5 + vectors[i].length;
                position2.Set(currentLength * qCos(angle + vectors[i].angle) + position.x,
                        currentLength * qSin(angle + vectors[i].angle) + position.y);
                painter.drawLine(position1.x * 100, position1.y * 100, position2.x * 100, position2.y * 100);

                currentLength += deltaLength * 0.5;
                position1 = position2;
                position2.x = qCos(springAngle) * deltaLength * 0.5 + qSin(springAngle) * springWidth * 0.5;
                position2.y = qSin(springAngle) * deltaLength * 0.5 - qCos(springAngle) * springWidth * 0.5;
                position2 += position1;
                painter.drawLine(position1.x * 100, position1.y * 100, position2.x * 100, position2.y * 100);

                position1 = position2;
                position2.x = -qSin(springAngle) * springWidth;
                position2.y = qCos(springAngle) * springWidth;
                position2 += position1;
                painter.drawLine(position1.x * 100, position1.y * 100, position2.x * 100, position2.y * 100);

                for(int j = 0; j < springSegmentsNum; ++j)
                {
                    position1 = position2;
                    currentLength += deltaLength;
                    position2.x = qCos(springAngle) * deltaLength + qSin(springAngle) * springWidth;
                    position2.y = qSin(springAngle) * deltaLength - qCos(springAngle) * springWidth;
                    position2 += position1;
                    painter.drawLine(position1.x * 100, position1.y * 100, position2.x * 100, position2.y * 100);

                    position1 = position2;
                    position2.x = -qSin(springAngle) * springWidth;
                    position2.y = qCos(springAngle) * springWidth;
                    position2 += position1;
                    painter.drawLine(position1.x * 100, position1.y * 100, position2.x * 100, position2.y * 100);
                }

                // Рисование части пружины возле колеса
                position1 = position2;
                currentLength += deltaLength;
                position2.x = qCos(springAngle) * deltaLength * 0.5 + qSin(springAngle) * springWidth * 0.5;
                position2.y = qSin(springAngle) * deltaLength * 0.5 - qCos(springAngle) * springWidth * 0.5;
                position2 += position1;
                painter.drawLine(position1.x * 100, position1.y * 100, position2.x * 100, position2.y * 100);

                position1 = position2;
                position2.x = qCos(springAngle) * deltaLength * 0.5;
                position2.y = qSin(springAngle) * deltaLength * 0.5;
                position2 += position1;
                painter.drawLine(position1.x * 100, position1.y * 100, position2.x * 100, position2.y * 100);
                ++currentWheel;
            }
        }
    } else {
        for(int i = 0; i < bodyParts.size(); ++i)
        {
            vehicleBrush.setColor(QColor(vectors[i].r, vectors[i].g, vectors[i].b));
            painter.setBrush(vehicleBrush);

            b2Vec2 position = bodyParts[i] -> GetPosition();
            float32 angle = bodyParts[i] -> GetAngle();
            polygonPoints[0].setX((vectors[i].length * qCos(angle + vectors[i].angle) + position.x) * 100);
            polygonPoints[0].setY((vectors[i].length * qSin(angle + vectors[i].angle) + position.y) * 100);
            polygonPoints[1].setX((vectors[(i == pointsNum - 1) ? 0 : (i + 1)].length * qCos(angle + vectors[(i == pointsNum - 1) ? 0 : (i + 1)].angle) + position.x) * 100);
            polygonPoints[1].setY((vectors[(i == pointsNum - 1) ? 0 : (i + 1)].length * qSin(angle + vectors[(i == pointsNum - 1) ? 0 : (i + 1)].angle) + position.y) * 100);
            polygonPoints[2].setX((position.x) * 100);
            polygonPoints[2].setY((position.y) * 100);
            painter.drawPolygon(polygonPoints, 3);
        }

        // Рисование колёс
        vehicleBrush.setColor(Qt::gray);
        painter.setBrush(vehicleBrush);
        int currentWheel = 0;
        for(int j = 0; j < pointsNum; ++j)
        {
            if(vectors[j].wheel)
            {
                b2Vec2 position = wheelsBodies[currentWheel] -> GetPosition();
                float32 angle = wheelsBodies[currentWheel] -> GetAngle();
                float32 radius = vectors[j].radius;
                painter.drawEllipse((position.x - radius) * 100, (position.y - radius) * 100, 200 * radius, 200 * radius);
                painter.drawLine(position.x * 100, position.y * 100, (position.x + radius * cos(angle)) * 100, (position.y + radius * sin(angle)) * 100);
                ++currentWheel;
            }
        }
    }
}

void Vehicle::copy(Vehicle *vehicle)
{
    vectors = vehicle -> vectors;
    wheelsNum = vehicle -> wheelsNum;
    score = vehicle -> score;
}

double Vehicle::getX()
{
    return x;
}

double Vehicle::getY()
{
    return y;
}

void Vehicle::crossover(Vehicle *veh1, Vehicle *veh2)
{
    // Преобразование машины в ДНК
    QVector<double> dna1 = (veh1 -> getDNA());
    QVector<double> dna2 = (veh2 -> getDNA());

    int point_num = veh1 -> pointsNum;

    // Сам кроссинговер
    int minLength = (dna1.size() < dna2.size()) ? dna1.size() : dna2.size();
    int rnd_point = qrand() % minLength;
    for(int i = 0; i < rnd_point; ++i)
    {
        double tmp = dna1[i];
        dna1[i] = dna2[i];
        dna2[i] = tmp;
    }

    // Пересчитывается количество колёс, чтобы не привысить максимальное.
    QVector <int> veh1Wheels;
    QVector <int> veh2Wheels;
    // Восстановление машин из ДНК
    for(int i = 0; i < point_num; ++i)
    {
        veh1 -> vectors[i].angle = dna1[i * 8];
        veh1 -> vectors[i].length = dna1[i * 8 + 1];
        veh1 -> vectors[i].r = dna1[i * 8 + 2];
        veh1 -> vectors[i].g = dna1[i * 8 + 3];
        veh1 -> vectors[i].b = dna1[i * 8 + 4];
        veh1 -> vectors[i].wheel = dna1[i * 8 + 5];
        veh1 -> vectors[i].radius = dna1[i * 8 + 6];
        veh1 -> vectors[i].motorSpeed = dna1[i * 8 + 7];

        veh2 -> vectors[i].angle = dna2[i * 8];
        veh2 -> vectors[i].length = dna2[i * 8 + 1];
        veh2 -> vectors[i].r = dna2[i * 8 + 2];
        veh2 -> vectors[i].g = dna2[i * 8 + 3];
        veh2 -> vectors[i].b = dna2[i * 8 + 4];
        veh2 -> vectors[i].wheel = dna2[i * 8 + 5];
        veh2 -> vectors[i].radius = dna2[i * 8 + 6];
        veh2 -> vectors[i].motorSpeed = dna2[i * 8 + 7];

        // Подсчёт количетсва колёс у каждого автомобиля
        if(veh1 -> vectors[i].wheel)
        {
            veh1Wheels.push_back(i);
        }
        if(veh2 -> vectors[i].wheel)
        {
            veh2Wheels.push_back(i);
        }
    }

    veh1 -> setDNA(dna1);
    veh2 -> setDNA(dna2);
}

void Vehicle::mutate(int maxMutationsCount)
{
    int dnaSize = vectors.size();
    int currentMutationPoint;
    double deltaAngle;
    int mutationsCount = qrand() % (maxMutationsCount + 1);
    for(int i = 0; i < mutationsCount; ++i)
    {
        currentMutationPoint = qrand() % dnaSize;
        deltaAngle = M_PI * 2.0 / static_cast<double>(vectors.size());
        vectors[currentMutationPoint].angle = currentMutationPoint * deltaAngle + (qrand() % 1000) / 1000.0 * deltaAngle;
        vectors[currentMutationPoint].length = 0.2 + (qrand() % 1000) / 1000.0 * vectorLength;
        vectors[currentMutationPoint].r = 128 + (qrand() % 128);
        vectors[currentMutationPoint].g = 128 + (qrand() % 128);
        vectors[currentMutationPoint].b = 128 + (qrand() % 128);
        vectors[currentMutationPoint].radius = 0.3 + (qrand() % 500) / 1000.0f;
        if(vectors[currentMutationPoint].motorSpeed > 0.0)
        {
            vectors[currentMutationPoint].motorSpeed = rand() % 20 + 20;
        } else {
            vectors[currentMutationPoint].motorSpeed = -(rand() % 20 + 20);
        }
        if(vectors[currentMutationPoint].wheel && !(rand() % wheelRemoveChance))
        {
            vectors[currentMutationPoint].wheel = false;
            --wheelsNum;
        } else if((wheelsNum < maxWheelsNum) && (!vectors[currentMutationPoint].wheel) && (rand() % wheelAddChance))
        {
            vectors[currentMutationPoint].wheel = true;
            ++wheelsNum;
        }
    }
}

void Vehicle::setMotorEnabled(bool value)
{
    int currentWheelNum = 0;
    motorEnabled = value;
    for(int i = 0; i < pointsNum; ++i)
    {
        if(vectors[i].wheel)
        {
            wheelsJoints[currentWheelNum] -> EnableMotor(value);
            ++currentWheelNum;
        }
    }
}

QVector<double> Vehicle::getDNA()
{
    QVector<double> dna;
    for(int i = 0; i < pointsNum; ++i)
    {
        dna.push_back(vectors[i].angle);
        dna.push_back(vectors[i].length);
        dna.push_back(vectors[i].r);
        dna.push_back(vectors[i].g);
        dna.push_back(vectors[i].b);
        dna.push_back(vectors[i].wheel);
        dna.push_back(vectors[i].radius);
        dna.push_back(vectors[i].motorSpeed);
    }
    return dna;
}

void Vehicle::setDNA(QVector<double> &dna)
{
    // Пересчитывается количество колёс, чтобы не привысить максимальное.
    QVector <int> vehWheels;

    vectors.resize(pointsNum);
    // Восстановление машин из ДНК
    for(int i = 0; i < pointsNum; ++i)
    {
        vectors[i].angle = dna[i * 8];
        vectors[i].length = dna[i * 8 + 1];
        vectors[i].r = dna[i * 8 + 2];
        vectors[i].g = dna[i * 8 + 3];
        vectors[i].b = dna[i * 8 + 4];
        vectors[i].wheel = dna[i * 8 + 5];
        vectors[i].radius = dna[i * 8 + 6];
        vectors[i].motorSpeed = dna[i * 8 + 7];

        // Подсчёт количетсва колёс у каждого автомобиля
        if(vectors[i].wheel)
        {
            vehWheels.push_back(i);
        }
    }

    // Удаление лишних колёс
    while((vehWheels.size() > maxWheelsNum) && (vehWheels.size() > 0))
    {
        int currentRemoved = rand() % vehWheels.size();
        vectors[vehWheels[currentRemoved]].wheel = false;
        vehWheels.remove(currentRemoved, 1);
    }

    wheelsNum = vehWheels.size();
}

void Vehicle::save(QString fileName)
{
    QVector<double> dna = getDNA();
    QFile *file = new QFile(fileName);

    if (! file -> open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // Error while trying to write file
    }
    else
    {
        // Everything is OK
        QTextStream out(file);
        out << x << "\n";
        out << y << "\n";
        out << pointsNum << "\n";
        out << dna.size() << "\n";

        out << maxWheelsNum << "\n";
        out << wheelsNum << "\n";
        out << springSegmentsNum << "\n";
        out << springWidth << "\n";
        out << springLength << "\n";

        out << wheelRemoveChance << "\n";
        out << wheelAddChance << "\n";

        out << vectorLength << "\n";
        out << wheelRadius << "\n";

        for(int i = 0; i < dna.size(); ++i)
        {
            QString tmp = "";
            tmp.setNum(dna[i], 'f', 10);
            out << tmp << "\n";
        }
    }
    file -> close();
}

void Vehicle::load(QString fileName)
{
    QVector<double> dna;
    QFile *file = new QFile(fileName);
    if (! file -> open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // Error while trying to read file
    }
    else
    {
        // Everything is OK
        QTextStream in(file);
        in >> x;
        in >> y;

        in >> pointsNum;

        int dna_size;
        in >> dna_size;
        dna.resize(dna_size);
        in >> maxWheelsNum;
        in >> wheelsNum;
        in >> springSegmentsNum;
        in >> springWidth;
        in >> springLength;

        in >> wheelRemoveChance;
        in >> wheelAddChance;

        in >> vectorLength;
        in >> wheelRadius;

        for(int i = 0; i < dna.size(); ++i)
        {
            in >> dna[i];
        }
    }

    setDNA(dna);

    file -> close();
    lastUpdateTime = QTime::currentTime();
}

void Vehicle::setX(double value)
{
    x = value;
}

void Vehicle::setY(double value)
{
    y = value;
}

void Vehicle::setPointsNum(int value)
{
    pointsNum = value;
}

void Vehicle::setMaxWheelsNum(int value)
{
    maxWheelsNum = value;
}

void Vehicle::setVectorLength(double value)
{
    vectorLength = value;
}

void Vehicle::setWheelRadius(double value)
{
    wheelRadius = value;
}

void Vehicle::setLeftSide(bool value)
{
    leftSide = value;
}

bool Vehicle::alive()
{
    return (body != NULL);
}

b2Vec2 Vehicle::GetPosition()
{
    return body -> GetPosition();
}

double Vehicle::getScore()
{
    if(body != NULL)
    {
        if(leftSide)
        {
            return (((body -> GetPosition().x - x) > 0.0) ? (body -> GetPosition().x - x) : 0.0);
        } else {
            return (((x - body -> GetPosition().x) > 0.0) ? (x - body -> GetPosition().x) : 0.0);
        }
    } else {
        return score;
    }
}

bool Vehicle::isMotorEnabled()
{
    return motorEnabled;
}
