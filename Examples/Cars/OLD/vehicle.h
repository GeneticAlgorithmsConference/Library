#ifndef VEHICLE_H
#define VEHICLE_H

#include <QVector>
#include <QVector2D>
#include <QPointF>
#include <QPainter>
#include <QBrush>

#include "Box2D/Box2D.h"
#include "AngleVector.h"

class Vehicle
{
public:
    Vehicle(int _x, int _y, int _pointsNum, int _maxWheelsNum);
    ~Vehicle();

    void generate(uint seed);
    void tick(b2World *world, double maxX);
    void updatePhysics(b2World *world, bool motorEnabled);
    void breakVehicle(b2World *world);
    void show(QPainter &painter);
    void copy(Vehicle *vehicle);

    QVector<double> getDNA();
    void setDNA(QVector<double> &dna);
    void save(QString fileName);
    void load(QString fileName);

    void setX(double value);
    void setY(double value);
    void setPointsNum(int value);
    void setMaxWheelsNum(int value);
    void setVectorLength(double value);
    void setWheelRadius(double value);
    void setMotorEnabled(bool value);
    void setLeftSide(bool value);

    bool alive();
    b2Vec2 GetPosition();
    double getScore();
    bool isMotorEnabled();
    double getX();
    double getY();

    // Genetic
    static void crossover(Vehicle *veh1, Vehicle *veh2);
    void mutate(int maxMutationsCount);

    static int waitingTime;
    static double minLength;
private:
    // Векторы из центральной точки
    QVector <AngleVector> vectors;
    int wheelsNum;

    // Тело машины
    b2Body *body;
    QVector <b2Body*> bodyParts;
    QVector <b2Fixture*> bodyPartFixtures;

    QTime lastUpdateTime;

    // Тела колёс
    QVector <b2Body*> wheelsBodies;

    // Пружины
    QVector <b2WheelJoint*> wheelsJoints;

    QVector <b2PolygonShape> shape;
    QVector <b2Fixture*> fixture;

    QBrush vehicleBrush;
    double score;
    int pointsNum;
    int maxWheelsNum;
    int x, y;

    // Springs properties
    int springSegmentsNum;
    double springWidth;
    double springLength;

    int wheelRemoveChance;
    int wheelAddChance;

    bool leftSide;

    bool motorEnabled;

    double vectorLength;
    double wheelRadius;

    b2Vec2 lastUpdatePoint;
};

#endif // VEHICLE_H
