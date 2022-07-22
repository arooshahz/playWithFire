#ifndef PROJECT_ITEM_H
#define PROJECT_ITEM_H
#include "Player.h"
#include <QGraphicsPixmapItem>
class Item  : public QGraphicsPixmapItem {

private:
    Player*player;
    int type;

public:
    Item();

    ~Item();

    void increaseSpeed();

    void addBomb();

    void addLifeCount();

    void increaseBombRadius();

    void controller(Player*player);

    void removeItem();


};


#endif //PROJECT_ITEM_H
