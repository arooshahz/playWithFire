#include "Bomb.h"
Bomb::Bomb(int X, int Y,Game* game, QGraphicsPathItem *parent):X(X),Y(Y),game(game),QGraphicsPixmapItem(parent) {

    explodeTime=3;

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
    removeBombTimer->setInterval(explodeTime*1000);
    connect(removeBombTimer,&QTimer::timeout,this,&Bomb::explode);
    removeBombTimer->start();




}
void Bomb::animateBomb(){
    setPixmap(*frames.at(frame));
    frame=(frame+1)%3;

}
void Bomb::explode(){


    removeBoxes();
    delete this;
}
void Bomb::removeBoxes() {
int i=0;

    for (const auto block: *game->getBlocks()) {

    if ((block->y() > this->y()-15 && block->y()+block->boundingRect().height() < this->y()+this->boundingRect().height()+15
    &&  this->x()- 2*block->boundingRect().width()<= block->x()+block->boundingRect().width() && block->x()+block->boundingRect().width() <= this->x()+this->boundingRect().width()+ 3*block->boundingRect().width())
    || ( block->x() > this->x()-15 && block->x()+block->boundingRect().width() < this->x()+this->boundingRect().width()+15
            &&  this->y()- 3*block->boundingRect().height()<= block->y() && block->y()+block->boundingRect().height() <= this->y()+this->boundingRect().height()+ 3*block->boundingRect().height()))
    {
            auto *box=dynamic_cast<Box*>(block);
if(box!=nullptr){
    game->getBlocks()->removeAt(i);
delete block;
}
    }

++i;
}}