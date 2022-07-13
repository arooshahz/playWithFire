#include "Player.h"
#include "Block.h"

Player::Player(int sceneWidth, int sceneHeight,QList<QPixmap*> frames, QGraphicsPathItem *parent):frames(frames),QGraphicsPixmapItem(parent) {

    setPixmap(*frames.at(0));

    heightAnimator=new QPropertyAnimation(this,"height",this);
    widthAnimator=new QPropertyAnimation(this,"width",this);


    walkingTimer=new QTimer();
    walkingTimer->setInterval(100);
    connect(walkingTimer,&QTimer::timeout,this,&Player::walking);
    walkingTimer->start();

}

void Player::walkingDown(){

    heightAnimator->stop();
    heightAnimator->setStartValue(y());
    heightAnimator->setEndValue(y() + 15);
    heightAnimator->setDuration(30);
    heightAnimator->start();


}
void Player::walkingUp() {

        heightAnimator->stop();
        heightAnimator->setStartValue(y());
        heightAnimator->setEndValue(y() -15);
        heightAnimator->setDuration(30);
        heightAnimator->start();

}
void Player::walkingLeft() {

        widthAnimator->stop();
        widthAnimator->setStartValue(x());
        widthAnimator->setEndValue(x() - 15);
        widthAnimator->setDuration(30);
        widthAnimator->start();

}
void Player::walkingRight() {

        widthAnimator->stop();
        widthAnimator->setStartValue(x());
        widthAnimator->setEndValue(x() + 15);
        widthAnimator->setDuration(30);
        widthAnimator->start();


}
void Player::walking(){
    setPixmap(*frames.at(frame));
    frame=(frame+1)%3;
}



