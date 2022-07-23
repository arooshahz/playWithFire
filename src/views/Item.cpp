#include "Item.h"
#include "Block.h"

Item::Item() {

    type = (rand() % (4));
    if (type == 0) {
        QPixmap *pixmap = new QPixmap(":/images/bomb1");
        *pixmap = pixmap->scaled(Block::getBlockWidth(), Block::getBlockHeight());
        setPixmap(*pixmap);

    } else if (type == 1) {
        QPixmap *pixmap = new QPixmap(":/images/lifeCount");
        *pixmap = pixmap->scaled(Block::getBlockWidth(), Block::getBlockHeight());
        setPixmap(*pixmap);

    } else if (type == 2) {
        QPixmap *pixmap = new QPixmap(":/images/speed");
        *pixmap = pixmap->scaled(Block::getBlockWidth(), Block::getBlockHeight());
        setPixmap(*pixmap);

    } else if (type == 3) {
        QPixmap *pixmap = new QPixmap(":/images/bomb4");
        *pixmap = pixmap->scaled(Block::getBlockWidth(), Block::getBlockHeight());
        setPixmap(*pixmap);

    }
}
Item::~Item() {

    delete player;
}

void Item::controller(Player *player) {
    this->player = player;

    if (type == 0) {
        addBomb();
    } else if (type == 1) {
        addLifeCount();
    } else if (type == 2) {
        increaseSpeed();
    } else if (type == 3) {
        increaseBombRadius();
    }


}

void Item::increaseSpeed() {
    player->setSpeed(player->getSpeed() - 20);

}

void Item::addBomb() {

    player->setBomCount(player->getBombCount() + 1);
}

void Item::addLifeCount() {

    ++(*player->getLifeCount());
}

void Item::increaseBombRadius() {

    player->setBombRadius(player->getBombRadius() + 1);
}
