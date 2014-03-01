#ifndef MAP_H
#define MAP_H

#include <QtWidgets>
#include "Box2D/Box2D.h"

#include "point.h"
#include "vehicle.h"
#include "population.h"

class Map
{
public:
    Map();
    ~Map();
    void generateBasic();
    void generate();
    void show(QPainter &painter, int minX, int maxX);
    void updateMapPhysics();
    void updateAllPhysics();
    void tick();
    void vehicleRemoveTest();
    Population* getFirstPopulation();
    Population* getSecondPopulation();
    b2World* getWorld();

    void updateLoseTimer();

    void save(QString dir);
    void load(QString dir);

    void setShowInfo(bool value);
    void setMapLength(double value);
    void setMinDeltaX(double value);
    void setMaxDeltaX(double value);
    void setMinDeltaY(double value);
    void setMaxDeltaY(double value);
    void setWaitingTime(int value);
private:
    Population *leftPopulation;
    Population *rightPopulation;
    QVector <Point> points;
    QBrush roadBrush;
    QFont font;
    double boxWidth;

    bool endTimerStarted;
    QTime endTimer;
    int waitingTime;

    b2Body *road;
    b2World *world;
    b2CircleShape *dynamicBox;
    b2FixtureDef *fixtureDef;
    b2BodyDef *bodyDef;
    bool doSleep;
    int testY;

    bool lastPositionNotSet;
    b2Vec2 lastPosition;

    QTime lastRemoveUpdate;

    double minDeltaX;
    double maxDeltaX;
    double minDeltaY;
    double maxDeltaY;
    double lengthStartEnd;
    double lengthTotal;
    bool showInfo;
};

#endif // MAP_H
