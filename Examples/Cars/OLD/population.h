#ifndef POPULATION_H
#define POPULATION_H

#include "vehicle.h"
#include "Box2D/Box2D.h"

class Population
{
public:
    Population(int _populationSize, bool _populationType, bool _populationSide);

    void initPopulation(b2World *world, double rightX, double rightY);

    void testFinish();
    void genNextGeneration();
    void updatePhysics(b2World *world);
    void updateVehiclesCount();
    void show(QPainter &painter);
    void tick(b2World *world, double maxX);

    void savePopulation(QString dir);
    void loadPopulation(QString dir);

    Vehicle *getCurrentVehicle();
    Vehicle *getVehicle(int i);
    b2Vec2 getFocusPosition();
    bool currentEnd();
    int getCurrentGeneration();
    int getCurrentTest();
    double getBestResult();
    bool getPopulationType();
    bool isAnyoneAlive();
    int getSize();

    void setDefaultMotorEnabled(bool value);
    void setPopulationSize(int value);
    void setMaxMutationsCount(int value);
    void setVehiclePointsNum(int value);
    void setVehicleMaxWheelsNum(int value);
    void setVehicleVectorLength(double value);
    void setVehicleWheelsSize(double value);
    void setPopulationType(bool value);

private:

    int curGeneration;
    int currentTest;

    int populationSize;
    int maxMutationsCount;

    bool defaultMotorEnabled;

    double bestResult;
    QVector <double> resData;
    QVector <Vehicle*> vehData;


    int vehiclePointsNum;
    int vehicleMaxWheelsNum;

    double vehicleVectorLength;
    double vehicleWheelsSize;

    bool populationType;
    bool populationSide;
};

#endif // POPULATION_H
