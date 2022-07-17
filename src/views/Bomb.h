#ifndef PROJECT_BOMB_H
#define PROJECT_BOMB_H
#include <QGraphicsPixmapItem>

class Bomb :public QGraphicsPixmapItem{

public:

    Bomb(int X, int Y, QGraphicsPathItem *parent= nullptr);
private:
    int X{};
    int Y{};
    int explodeTime;
};


#endif //PROJECT_BOMB_H
