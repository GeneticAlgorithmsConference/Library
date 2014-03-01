#include "map.h"

#include "Box2D/Box2D.h"

Map::Map()
{
    roadBrush.setColor(Qt::darkGray);
    roadBrush.setStyle(Qt::SolidPattern);
    font.setFamily("Times");
    font.setPixelSize(20);
    world = NULL;
    endTimerStarted = false;
    waitingTime = 3000;
    lastPositionNotSet = true;

    boxWidth = 0.1;
    minDeltaX = 5.0;
    maxDeltaX = 10.0;
    minDeltaY = -5.0;
    maxDeltaY = 5.0;
    lengthTotal = 1000.0;
    lengthStartEnd = 5.0 * maxDeltaX;
    showInfo = false;

    leftPopulation = new Population(3, true, true);
    rightPopulation = new Population(3, true, false);
}

Map::~Map()
{
    delete leftPopulation;
    delete rightPopulation;
}

void Map::generateBasic()
{
    for(int i = 0; i < 100; ++i)
    {
        Point point;
        point.x = i * 100;
        point.y = qrand() % 100;
        points.push_back(point);
    }
}

void Map::generate()
{
    lengthStartEnd = (leftPopulation -> getSize() > rightPopulation -> getSize())
            ? (leftPopulation -> getSize()) : (rightPopulation -> getSize());
    lengthStartEnd *= 5.0;
    lengthStartEnd += 5.0;
    points.clear();
    double cur_len = 0;
    double max_cur_len = (lengthTotal - maxDeltaX);
    double dltDeltaX = maxDeltaX - minDeltaX;
    double dltDeltaY = maxDeltaY - minDeltaY;

    Point curPoint;
    curPoint.x = 0;
    curPoint.y = 0;
    double rndCoeffX;
    double rndCoeffY = (double)(qrand() % 10000) / 10000;
    double dltX;
    double dltY = minDeltaY + rndCoeffY * dltDeltaY;


    points.push_back(curPoint);

    curPoint.x += lengthStartEnd;
    points.push_back(curPoint);

    while(cur_len < max_cur_len)
    {
        rndCoeffX = (double)(qrand() % 10000) / 10000;
        double dltX = minDeltaX + rndCoeffX * dltDeltaX;
        curPoint.x += dltX;

        rndCoeffY = (double)(qrand() % 10000) / 10000;
        dltY = minDeltaY + rndCoeffY * dltDeltaY;
        curPoint.y += dltY;

        points.push_back(curPoint);
        cur_len += dltX;
    }



    rndCoeffX = (double)(qrand() % 10000) / 10000.0;
    dltX = minDeltaX + rndCoeffX * dltDeltaX;
    rndCoeffY = (double)(qrand() % 10000) / 10000.0;
    dltY = minDeltaY + rndCoeffY * dltDeltaY;
    curPoint.y += dltY;
    curPoint.x = points[points.size() - 1].x + dltX;
    points.push_back(curPoint);
    curPoint.x += lengthStartEnd;
    points.push_back(curPoint);

    updateMapPhysics();

    leftPopulation -> initPopulation(world, points[points.size() - 2].x, points[points.size() - 2].y);
    if(leftPopulation -> getPopulationType())
    {
        rightPopulation -> initPopulation(world, points[points.size() - 2].x, points[points.size() - 2].y);
    }

    lastRemoveUpdate = QTime::currentTime();
}

void Map::show(QPainter &painter, int minX, int maxX)
{
    static QPointF polygonPoints[4];
    painter.setFont(font);
    roadBrush.setColor(Qt::darkGray);
    painter.setBrush(roadBrush);
    for(int i = 0; i < points.size() - 1; ++i)
    {
        polygonPoints[0].setX((points[i].x) * 100);
        polygonPoints[0].setY((points[i].y + boxWidth) * 100);
        polygonPoints[1].setX((points[i].x) * 100);
        polygonPoints[1].setY((points[i].y - boxWidth) * 100);
        polygonPoints[2].setX(points[i + 1].x * 100);
        polygonPoints[2].setY((points[i + 1].y - boxWidth) * 100);
        polygonPoints[3].setX(points[i + 1].x * 100);
        polygonPoints[3].setY((points[i + 1].y + boxWidth) * 100);
        if((polygonPoints[2].x() >= minX) && (polygonPoints[0].x() <= maxX))
        {
            painter.drawPolygon(polygonPoints, 4);
        }
    }

    leftPopulation -> show(painter);
    if(leftPopulation -> getPopulationType())
    {
        rightPopulation -> show(painter);
    }

    if(showInfo)
    {
        if(leftPopulation -> getPopulationType())
        {
            QFont tmpFont;
            tmpFont.setPixelSize(40);
            painter.setFont(tmpFont);
            for(int i = 0; i < leftPopulation -> getSize(); ++i)
            {
                Vehicle *tmpVehicle = leftPopulation -> getVehicle(i);
                if(tmpVehicle -> alive())
                {
                    painter.translate(tmpVehicle -> GetPosition().x * 100, tmpVehicle -> GetPosition().y * 100);
                    painter.rotate(180.0);
                    painter.scale(-1.0, 1.0);
                    painter.drawText(10, -150, QString::number(i + 1));
                    painter.scale(-1.0, 1.0);
                    painter.rotate(-180.0);
                    painter.translate(-tmpVehicle -> GetPosition().x * 100, -tmpVehicle -> GetPosition().y * 100);
                }
            }

            for(int i = 0; i < rightPopulation -> getSize(); ++i)
            {
                Vehicle *tmpVehicle = rightPopulation -> getVehicle(i);
                if(tmpVehicle -> alive())
                {
                    painter.translate(tmpVehicle -> GetPosition().x * 100, tmpVehicle -> GetPosition().y * 100);
                    painter.rotate(180.0);
                    painter.scale(-1.0, 1.0);
                    painter.drawText(10, -150, QString::number(i + 1));
                    painter.scale(-1.0, 1.0);
                    painter.rotate(-180.0);
                    painter.translate(-tmpVehicle -> GetPosition().x * 100, -tmpVehicle -> GetPosition().y * 100);
                }
            }
        }

        painter.setFont(font);
        painter.setTransform(QTransform(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0));
        painter.drawText(10, 100,
                         QString("Score: ") + QString::number(leftPopulation -> getCurrentVehicle() -> getScore(), 'f', 1));
        painter.drawText(10, 150,
                         QString("Generation: ") + QString::number(leftPopulation -> getCurrentGeneration() + 1));
        painter.drawText(10, 200,
                         QString("Test: ") + QString::number(leftPopulation -> getCurrentTest() + 1));
        painter.drawText(10, 250,
                         QString("Best score: ") + QString::number(leftPopulation -> getBestResult(), 'f', 1));
    }
}

void Map::updateMapPhysics()
{
    if(world != NULL)
    {
        delete world;
    }
    world = new b2World(b2Vec2(0.0f, -10.0f));
    b2Vec2 *tmp = new b2Vec2[points.size()];
    for(int i = 0; i < points.size(); ++i)
    {
        tmp[i].Set(points[i].x, points[i].y + boxWidth);
    }

    b2ChainShape groundBox;
    groundBox.CreateChain(tmp, points.size());
    b2BodyDef groundBodyDef;
    b2FixtureDef groundBodyFixtureDef;
    groundBodyFixtureDef.shape = &groundBox;
    groundBodyFixtureDef.friction = 1.0;
    groundBodyFixtureDef.restitution = 1.0;
    groundBodyFixtureDef.density = 1.0;
    road = world -> CreateBody(&groundBodyDef);
    road -> CreateFixture(&groundBox, 0.0f);

    delete[] tmp;
}

void Map::updateAllPhysics()
{
    updateMapPhysics();
    leftPopulation -> updatePhysics(world);
    if(leftPopulation -> getPopulationType())
    {
        rightPopulation -> updatePhysics(world);
    }
}

void Map::tick()
{
    static float32 timeStep = 0.016666667f;
    static int32 velocityIterations = 8;
    static int32 positionIterations = 3;
    world -> Step(timeStep * 1.5, velocityIterations, positionIterations);
    if(leftPopulation -> getPopulationType())
    {
        leftPopulation -> tick(world, points[points.size() - 1].x);
        rightPopulation -> tick(world, points[points.size() - 1].x);
        if(!leftPopulation -> isAnyoneAlive() && !rightPopulation -> isAnyoneAlive())
        {
            if(endTimerStarted && (endTimer.msecsTo(QTime::currentTime()) >= waitingTime))
            {
                endTimerStarted = false;
                lastRemoveUpdate = QTime::currentTime();
                leftPopulation -> genNextGeneration();
                rightPopulation -> genNextGeneration();
                save(QDir::currentPath() + "\\Saves\\AutoSave\\");
                updateAllPhysics();
            } else if(!endTimerStarted) {
                endTimerStarted = true;
                endTimer = QTime::currentTime();
            }
        }
    } else {
        leftPopulation -> getCurrentVehicle() -> tick(world, points[points.size() - 1].x);
        if(!leftPopulation -> getCurrentVehicle() -> alive())
        {
            if(endTimerStarted && (endTimer.msecsTo(QTime::currentTime()) >= waitingTime))
            {
                leftPopulation -> testFinish();
                endTimerStarted = false;
                lastRemoveUpdate = QTime::currentTime();
                if(leftPopulation -> currentEnd())
                {
                    leftPopulation -> genNextGeneration();
                }
                updateAllPhysics();
            } else if(!endTimerStarted) {
                endTimerStarted = true;
                endTimer = QTime::currentTime();
            }
        } else if(lastRemoveUpdate.secsTo(QTime::currentTime()) >= 3)
        {
            vehicleRemoveTest();
            lastRemoveUpdate = QTime::currentTime();
        }
    }
}

void Map::vehicleRemoveTest()
{
    if(!leftPopulation -> getPopulationType())
    {
        if(leftPopulation -> getCurrentVehicle() -> alive())
        {
            if(lastPositionNotSet)
            {
                lastPosition = leftPopulation -> getCurrentVehicle() -> GetPosition();
                lastPositionNotSet = false;
            } else if((lastPosition - (leftPopulation -> getCurrentVehicle() -> GetPosition())).Length() <= 1.0)
            {
                leftPopulation -> testFinish();
                lastRemoveUpdate = QTime::currentTime();
                if(leftPopulation -> currentEnd())
                {
                    leftPopulation -> genNextGeneration();
                }
                updateAllPhysics();
            } else if((leftPopulation -> getCurrentVehicle() -> GetPosition().x >= lengthTotal + 2.0 * lengthStartEnd)
                      || (leftPopulation -> getCurrentVehicle() -> GetPosition().x <= 0.0))
            {
                leftPopulation -> testFinish();
                lastRemoveUpdate = QTime::currentTime();
                if(leftPopulation -> currentEnd())
                {
                    leftPopulation -> genNextGeneration();
                }
                updateAllPhysics();
            }
            lastPosition = leftPopulation -> getCurrentVehicle() -> GetPosition();
        }
    }
}

Population* Map::getFirstPopulation()
{
    return leftPopulation;
}

Population* Map::getSecondPopulation()
{
    return rightPopulation;
}

void Map::updateLoseTimer()
{
    lastRemoveUpdate = QTime::currentTime();
}


void Map::save(QString dir)
{
    QDir qDir(dir);
    qDir.mkpath(dir);

    if(dir[dir.size() - 1] != '\\')
        dir += '\\';

    leftPopulation -> savePopulation(dir + "LeftPopulation\\");
    rightPopulation -> savePopulation(dir + "RightPopulation\\");

    QFile *fileX = new QFile(dir + "mapX.save");
    QFile *fileY = new QFile(dir + "mapY.save");
    QFile *fileS = new QFile(dir + "mapS.save");
    if (! fileX -> open(QIODevice::WriteOnly | QIODevice::Text) ||
            ! fileY -> open(QIODevice::WriteOnly | QIODevice::Text) ||
            ! fileS -> open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        // Error while trying to write file
    }
    else
    {
        // Everything is OK
        QTextStream outX(fileX);
        QTextStream outY(fileY);
        QTextStream outS(fileS);

        outS << minDeltaX << "\n";
        outS << maxDeltaX << "\n";
        outS << minDeltaY << "\n";
        outS << maxDeltaY << "\n";
        outS << lengthStartEnd << "\n";
        outS << lengthTotal << "\n";


        outX << points.size() << "\n";
        outY << points.size() << "\n";
        for(int i = 0; i < points.size(); ++i)
        {
            QString tmp;

            tmp = "";
            tmp.setNum(points[i].x, 'f', 4);
            outX << tmp << "\n";

            tmp = "";
            tmp.setNum(points[i].y, 'f', 4);
            outY << tmp << "\n";
        }
    }

    fileX -> close();
    fileY -> close();
    fileS -> close();
}

void Map::load(QString dir)
{
    QDir qDir(dir);
    qDir.mkpath(dir);

    if(dir[dir.size() - 1] != '\\')
        dir += '\\';

    leftPopulation -> loadPopulation(dir + "LeftPopulation\\");
    rightPopulation -> loadPopulation(dir + "RightPopulation\\");

    QFile *fileX = new QFile(dir + "mapX.save");
    QFile *fileY = new QFile(dir + "mapY.save");
    QFile *fileS = new QFile(dir + "mapS.save");
    if (! fileX -> open(QIODevice::ReadOnly | QIODevice::Text) ||
            ! fileY -> open(QIODevice::ReadOnly | QIODevice::Text) ||
            ! fileS -> open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        // Error while trying to read file
    }
    else
    {
        // Everything is OK
        QTextStream inX(fileX);
        QTextStream inY(fileY);
        QTextStream inS(fileS);

        inS >> minDeltaX;
        inS >> maxDeltaX;
        inS >> minDeltaY;
        inS >> maxDeltaY;
        inS >> lengthStartEnd;
        inS >> lengthTotal;

        int tmp_size;
        inX >> tmp_size;
        inY >> tmp_size;
        points.resize(tmp_size);
        for(int i = 0; i < points.size(); ++i)
        {
            inX >> points[i].x;
            inY >> points[i].y;
        }
    }

    fileX -> close();
    fileY -> close();
    fileS -> close();

    updateLoseTimer();
}


void Map::setShowInfo(bool value)
{
    showInfo = value;
}

void Map::setMapLength(double value)
{
    lengthTotal = value;
}

void Map::setMinDeltaX(double value)
{
    minDeltaX = value;
}

void Map::setMaxDeltaX(double value)
{
    maxDeltaX = value;
}

void Map::setMinDeltaY(double value)
{
    minDeltaY = value;
}

void Map::setMaxDeltaY(double value)
{
    maxDeltaY = value;
}

void Map::setWaitingTime(int value)
{
    waitingTime = value;
}

b2World* Map::getWorld()
{
    return world;
}
