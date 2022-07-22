#ifndef PROJECT_ITEM_H
#define PROJECT_ITEM_H

#include "Player.h"
#include <QGraphicsPixmapItem>

class Item : public QGraphicsPixmapItem {

private:
    Player *player;
    int type;

public:
    Item();

    void increaseSpeed();

    void addBomb();

    void addLifeCount();

    void increaseBombRadius();

    void controller(Player *player);




};


#endif //PROJECT_ITEM_H