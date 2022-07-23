#ifndef PROJECT_BOMB_H
#define PROJECT_BOMB_H

#include<QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Box.h"
#include "../windows/Game.h"

typedef std::pair<int, int> pii;

class Bomb : public QObject, public QGraphicsPixmapItem {
Q_OBJECT


public:
    Bomb(int X, int Y, int indexOfPlayer, Game *game, QGraphicsPathItem *parent = nullptr);

    ~Bomb();

    void removeBoxes();

    void damagePlayer();


public slots:

    void explode();

    void animateBomb();

private:
    int frame = {};
    int X{};
    int Y{};
    int indexOfPlayer;
    int explodeTime;
    Game *game;
    QList<QPixmap *> frames{};
    QTimer *animateBombTimer;
    QTimer *removeBombTimer;

    void decreaseLifeCount(int index);
};


#endif //PROJECT_BOMB_H
