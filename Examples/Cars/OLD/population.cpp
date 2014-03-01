#include <QPair>
#include <QtWidgets>

#include "population.h"
#include "vehicle.h"

Population::Population(int _populationSize, bool _populationType, bool _populationSide)
{
    populationSize = _populationSize;
    populationType = _populationType;
    populationSide = _populationSide;
    vehiclePointsNum = 8;
    vehicleMaxWheelsNum = 4;
    currentTest = 0;
    bestResult = 0.0;
    maxMutationsCount = 1;
    resData.resize(populationSize);

    vehicleVectorLength = 0.5;
    vehicleWheelsSize = 0.5;

    defaultMotorEnabled = true;
}

void Population::initPopulation(b2World *world, double rightX, double rightY)
{
    updateVehiclesCount();
    double deltaX = rightX + 5.0;
    double deltaY = rightY + 5.0;
    if(populationSide)
    {
        deltaX = 5.0;
        deltaY = 5.0;
    }
    if(populationType)
    {
        for(int i = 0; i < populationSize; ++i)
        {
            if(populationSide)
            {
                vehData[i] -> setX(5.0 * (populationSize - i - 1) + deltaX);
                vehData[i] -> setY(deltaY);
                vehData[i] -> updatePhysics(world, defaultMotorEnabled);
            } else {
                vehData[i] -> setX(5.0 * i + deltaX);
                vehData[i] -> setY(deltaY);
                vehData[i] -> updatePhysics(world, defaultMotorEnabled);
            }
        }
    } else {
        for(int i = 0; i < populationSize; ++i)
        {
            vehData[i] -> setX(deltaX);
            vehData[i] -> setY(deltaY);
        }
        vehData[0] -> updatePhysics(world, defaultMotorEnabled);
    }
    curGeneration = 0;
    currentTest = 0;
    bestResult = 0.0;
}

void Population::testFinish()
{
    double result = vehData[currentTest] -> getScore();
    resData[currentTest++] = result;
    if(result > bestResult)
    {
        bestResult = result;
    }
}

void Population::genNextGeneration()
{
    // Селекция
    QVector < QPair<double, Vehicle*> > selData;
    QPair <double, Vehicle*> tmpPair;
    for(int i = 0; i < populationSize; ++i)
    {
        tmpPair.first = resData[i];
        tmpPair.second = vehData[i];
        selData.push_back(tmpPair);
    }
    for(int i = 0; i < populationSize; ++i)
    {
        for(int j = 0; j < populationSize - i - 1; ++j)
        {
            if(selData[j + 1] > selData[j])
            {
                tmpPair.first = selData[j].first;
                tmpPair.second = selData[j].second;
                selData[j].first = selData[j + 1].first;
                selData[j].second = selData[j + 1].second;
                selData[j + 1].first = tmpPair.first;
                selData[j + 1].second = tmpPair.second;
            }
        }
    }

    for(int i = 0; i < populationSize / 2; ++i)
    {
        vehData[i] -> copy(selData[i].second);
        vehData[populationSize / 2 + i] -> copy(vehData[i]);
    }

    if(populationSize / 2 > 1)
    {
        for(int i = populationSize / 2; i < populationSize; ++i)
        {
            int id2 = qrand() % (populationSize / 2) + populationSize / 2;
            while(id2 == i)
            {
                id2 = qrand() % (populationSize / 2) + populationSize / 2;
            }
            Vehicle::crossover(vehData[i], vehData[id2]);
        }
    } else if(populationSize == 3)
    {
        Vehicle::crossover(vehData[1], vehData[2]);
    } else if(populationSize == 2)
    {
        Vehicle::crossover(vehData[0], vehData[1]);
    }

    // Мутации
    for(int i = 0; i < populationSize; ++i)
    {
        vehData[i] -> mutate(maxMutationsCount);
    }

//    // Сортировка по очкам. Спереди лучшие машины.
//    Vehicle tmpVehicle(0, 0, 0, 0);
//    for(int i = 0; i < populationSize; ++i)
//    {
//        for(int j = 0; j < populationSize - i - 1; ++j)
//        {
//            if(vehData[j + 1] -> getScore() > vehData[j] -> getScore())
//            {
//                tmpVehicle.copy(vehData[j]);
//                vehData[j] -> copy(vehData[j + 1]);
//                vehData[j + 1] -> copy(&tmpVehicle);
//            }
//        }
//    }

    if(populationType)
    {
        if(populationSide)
        {
            double maxXValue = 0.0;
            for(int i = 0; i < populationSize; ++i)
            {
                if(vehData[i] -> getX() > maxXValue)
                {
                    maxXValue = vehData[i] -> getX();
                }
            }

            for(int i = 0; i < populationSize; ++i)
            {
                vehData[i] -> setX(maxXValue - i * 5.0);
            }
        } else {
            double minXValue = 999999.0;
            for(int i = 0; i < populationSize; ++i)
            {
                if(vehData[i] -> getX() < minXValue)
                {
                    minXValue = vehData[i] -> getX();
                }
            }

            for(int i = 0; i < populationSize; ++i)
            {
                vehData[i] -> setX(minXValue + i * 5.0);
            }
        }
    }

    ++curGeneration;
    currentTest = 0;
}

void Population::updatePhysics(b2World *world)
{
    if(populationType)
    {
        for(int i = 0; i < populationSize; ++i)
        {
            vehData[i] -> updatePhysics(world, defaultMotorEnabled);
        }
    } else {
        vehData[currentTest] -> updatePhysics(world, defaultMotorEnabled);
    }
}

void Population::updateVehiclesCount()
{
    // Удаление старых машин
    for(int i = 0; i < vehData.size(); ++i)
    {
        delete vehData[i];
    }
    resData.resize(populationSize);
    vehData.clear();
    Vehicle *tmpVehicle;
    for(int i = 0; i < populationSize; ++i)
    {
        tmpVehicle = new Vehicle(5.0 * (populationType ? (i + 1) : 1.0), 5.0, vehiclePointsNum, vehicleMaxWheelsNum);
        tmpVehicle -> setVectorLength(vehicleVectorLength);
        tmpVehicle -> setWheelRadius(vehicleWheelsSize);
        tmpVehicle -> setLeftSide(populationSide);
        tmpVehicle -> generate(qrand());
        vehData.push_back(tmpVehicle);
        resData[i] = 0.0;
    }
}

void Population::show(QPainter &painter)
{
    if(populationType)
    {
        for(int i = 0; i < populationSize; ++i)
        {
            vehData[i] -> show(painter);
        }
    } else {
        vehData[currentTest] -> show(painter);
    }
}

void Population::tick(b2World *world, double maxX)
{
    if(populationType)
    {
        for(int i = 0; i < populationSize; ++i)
        {
            vehData[i] -> tick(world, maxX);
        }
    } else {
        vehData[currentTest] -> tick(world, maxX);
    }
}

void Population::savePopulation(QString dir)
{
    QDir tmpDir(dir);
    tmpDir.mkpath(dir);
    QFile *fileScore = new QFile(dir + "score.save");
    QFile *fileSettings = new QFile(dir + "sets.save");

    if (! fileSettings -> open(QIODevice::WriteOnly | QIODevice::Text) ||
            ! fileScore -> open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // Error while trying to write file
    }
    else
    {
        // Everything is OK
        QTextStream outSettings(fileSettings);
        QTextStream outScore(fileScore);

        outSettings << populationSize << "\n";
        outSettings << currentTest << "\n";
        outSettings << curGeneration << "\n";
        outSettings << maxMutationsCount << "\n";
        outSettings << bestResult << "\n";

        outSettings << vehiclePointsNum << "\n";
        outSettings << vehicleMaxWheelsNum << "\n";
        outSettings << vehicleVectorLength << "\n";
        outSettings << vehicleWheelsSize << "\n";

        outSettings << populationType << "\n";
        outSettings << populationSide << "\n";

        for(int i = 0; i < populationSize; ++i)
            vehData[i] -> save(dir + "veh" + QString::number(i) + ".save");

        for(int i = 0; i < populationSize; ++i)
        {
            QString tmp = "";
            tmp.setNum(resData[i], 'f', 5);
            outScore << tmp << "\n";
        }
    }

    fileSettings -> close();
    fileScore -> close();
}

void Population::loadPopulation(QString dir)
{
    QFile *fileScore = new QFile(dir + "score.save");
    QFile *fileSettings = new QFile(dir + "sets.save");

    if (! fileSettings -> open(QIODevice::ReadOnly | QIODevice::Text) ||
            ! fileScore -> open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // Error while trying to read file
    }
    else
    {
        // Everything is OK
        QTextStream inSettings(fileSettings);
        QTextStream inScore(fileScore);

        inSettings >> populationSize;
        inSettings >> currentTest;
        inSettings >> curGeneration;
        inSettings >> maxMutationsCount;
        inSettings >> bestResult;

        inSettings >> vehiclePointsNum;
        inSettings >> vehicleMaxWheelsNum;
        inSettings >> vehicleVectorLength;
        inSettings >> vehicleWheelsSize;

        int tmpB;

        inSettings >> tmpB;
        populationType = tmpB == 1;

        inSettings >> tmpB;
        populationSide = tmpB == 1;

        for(int i = 0; i < vehData.size(); ++i)
            delete vehData[i];

        vehData.resize(populationSize);
        for(int i = 0; i < populationSize; ++i)
        {
            vehData[i] = new Vehicle(0,0,0,0);
            vehData[i] -> load(dir + "veh" + QString::number(i) + ".save");
        }

        resData.resize(populationSize);
        for(int i = 0; i < populationSize; ++i)
        {
            inScore >> resData[i];
        }
    }

    fileSettings -> close();
    fileScore -> close();

}

Vehicle* Population::getCurrentVehicle()
{
    return vehData[currentTest];
}

Vehicle* Population::getVehicle(int i)
{
    return vehData[i];
}

b2Vec2 Population::getFocusPosition()
{
    return vehData[currentTest] -> GetPosition();
}

bool Population::currentEnd()
{
    return (currentTest == populationSize);
}

int Population::getCurrentGeneration()
{
    return curGeneration;
}

int Population::getCurrentTest()
{
    return currentTest;
}

double Population::getBestResult()
{
    return bestResult;
}

bool Population::getPopulationType()
{
    return populationType;
}

bool Population::isAnyoneAlive()
{
    for(int i = 0; i < populationSize; ++i)
    {
        if(vehData[i] -> alive())
        {
            return true;
        }
    }
    return false;
}

int Population::getSize()
{
    return populationSize;
}

void Population::setDefaultMotorEnabled(bool value)
{
    defaultMotorEnabled = value;
}

void Population::setPopulationSize(int value)
{
    populationSize = value;
}

void Population::setMaxMutationsCount(int value)
{
    maxMutationsCount = value;
}

void Population::setVehiclePointsNum(int value)
{
    vehiclePointsNum = value;
}

void Population::setVehicleMaxWheelsNum(int value)
{
    vehicleMaxWheelsNum = value;
}

void Population::setVehicleVectorLength(double value)
{
    vehicleVectorLength = value;
}

void Population::setVehicleWheelsSize(double value)
{
    vehicleWheelsSize = value;
}

void Population::setPopulationType(bool value)
{
    populationType = value;
}
