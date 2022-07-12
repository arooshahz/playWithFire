#include "Player.h"
#include "Block.h"

Player::Player(int sceneWidth, int sceneHeight,QList<QPixmap*> frames, QGraphicsPathItem *parent):frames(frames),QGraphicsPixmapItem(parent) {
//    setFlags(GraphicsItemFlag::ItemIsFocusable);
//    setFocus();
    setPixmap(*frames.at(0));

    heightAnimator=new QPropertyAnimation(this,"height",this);
    widthAnimator=new QPropertyAnimation(this,"width",this);



}

void Player::walkingDown(){
    heightAnimator->stop();
    heightAnimator->setStartValue(y());
    heightAnimator->setEndValue(y()+10);
    heightAnimator->setDuration(30);
    heightAnimator->start();
}
void Player::walkedUp() {
    heightAnimator->stop();
    heightAnimator->setStartValue(y());
    heightAnimator->setEndValue(y()-10);
    heightAnimator->setDuration(30);
    heightAnimator->start();

}
void Player::walkedLeft() {
    widthAnimator->stop();
    widthAnimator->setStartValue(x());
    widthAnimator->setEndValue(x()-10);
    widthAnimator->setDuration(30);
    widthAnimator->start();

}
void Player::walkedRight() {
    widthAnimator->stop();
    widthAnimator->setStartValue(x());
    widthAnimator->setEndValue(x()+10);
    widthAnimator->setDuration(30);
    widthAnimator->start();

}
//void Player::keyPressEvent(QKeyEvent *event) {
//    QGraphicsItem::keyPressEvent(event);
//    if(event->key()==Qt::Key::Key_Down){
//        walkingDown();
//    }
//    if(event->key()==Qt::Key::Key_Up){
//        walkedUp();
//    }
//
//    if(event->key()==Qt::Key::Key_Left){
//        walkedLeft();
//    }
//
//    if(event->key()==Qt::Key::Key_Right){
//        walkedRight();
//    }
//}

