#include "Bomb.h"
Bomb::Bomb(int X, int Y, QGraphicsPathItem *parent):X(X),Y(Y),QGraphicsPixmapItem(parent) {

    auto pixmap=new QPixmap(":/images/bomb1");
    auto scaledPixmap=pixmap->scaled(79,65);
    setPixmap(scaledPixmap);
}