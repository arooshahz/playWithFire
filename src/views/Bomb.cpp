#include "Bomb.h"
Bomb::Bomb(int X, int Y, QGraphicsPathItem *parent):X(X),Y(Y),QGraphicsPixmapItem(parent) {

    auto pixmap=new QPixmap(":/images/bomb1");
    *pixmap=pixmap->scaled(79, 65);
    frames.append(pixmap);
    setPixmap(*pixmap);

    pixmap=new QPixmap(":/images/bomb2");
    *pixmap=pixmap->scaled(79, 65);
    frames.append(pixmap);
    pixmap=new QPixmap(":/images/bomb3");
    *pixmap=pixmap->scaled(79, 65);
    frames.append(pixmap);


    animateBombTimer=new QTimer();
    animateBombTimer->setInterval(100);
    connect(animateBombTimer,&QTimer::timeout,this,&Bomb::animateBomb);
    animateBombTimer->start();


    removeBombTimer=new QTimer();
    removeBombTimer->setInterval(3000);
    connect(removeBombTimer,&QTimer::timeout,this,&Bomb::removeBomb);
    removeBombTimer->start();
}
void Bomb::animateBomb(){
    setPixmap(*frames.at(frame));
    frame=(frame+1)%3;

}
void Bomb::removeBomb(){
    delete this;
}