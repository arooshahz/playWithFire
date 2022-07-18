#ifndef PROJECT_BOMB_H
#define PROJECT_BOMB_H
#include<QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Box.h"
#include "../windows/Game.h"

class Bomb :public QObject,public QGraphicsPixmapItem{
Q_OBJECT



public:
    Bomb(int X, int Y,int indexOfPlayer,Game* game, QGraphicsPathItem *parent= nullptr);
    void removeBoxes();
    void damagePlayer();


public slots:
    void explode();
    void animateBomb();
private:
    int frame={};
    int X{};
    int Y{};
    int indexOfPlayer;
    int explodeTime;
    Game* game;
    QList<QPixmap*>frames{};
    QTimer *animateBombTimer;
    QTimer *removeBombTimer;
};


#endif //PROJECT_BOMB_H
