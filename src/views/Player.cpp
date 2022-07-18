#include "Player.h"
#include "Block.h"

Player::Player(int X, int Y,QList<QPixmap*> frames, QGraphicsPathItem *parent):X(X),Y(Y),frames(frames),QGraphicsPixmapItem(parent) {

    lifeCount=3;
    setPixmap(*frames.at(0));

    heightAnimator=new QPropertyAnimation(this,"height",this);
    widthAnimator=new QPropertyAnimation(this,"width",this);


    walkingTimer=new QTimer();
    walkingTimer->setInterval(100);
    connect(walkingTimer,&QTimer::timeout,this,&Player::walking);
    walkingTimer->start();

}




void Player::walking(){
    setPixmap(*frames.at(frame));
    frame=(frame+1)%3;
}
void Player::movement(int newX, int newY) {

    heightAnimator->stop();
    heightAnimator->setStartValue(y());
    heightAnimator->setEndValue(newY);
    heightAnimator->setDuration(5);
    heightAnimator->start();

    widthAnimator->stop();
    widthAnimator->setStartValue(x());
    widthAnimator->setEndValue(newX);
    widthAnimator->setDuration(5);
    widthAnimator->start();


}
int Player::getX() {
    return X;
}
int Player::getY() {
    return Y;
}

