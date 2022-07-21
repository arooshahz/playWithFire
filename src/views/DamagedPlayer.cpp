#include "DamagedPlayer.h"
#include "Block.h"

DamagedPlayer::DamagedPlayer(int X,int Y,QGraphicsPathItem *parent) :X(X),Y(Y), QGraphicsPixmapItem(parent) {


    auto pixmap = new QPixmap(":/images/deadPlayer");
    *pixmap = pixmap->scaled(Block::getBlockWidth ()- 25, Block::getBlockHeight() - 15);

    setPixmap(*pixmap);

    heightAnimator=new QPropertyAnimation(this,"height",this);
    movement();

    removeDamagedPlayerTimer = new QTimer();
    removeDamagedPlayerTimer->setInterval(1000);
    connect(removeDamagedPlayerTimer, &QTimer::timeout, this, &DamagedPlayer::removeDamagedPlayer);
    removeDamagedPlayerTimer->start();

}
void DamagedPlayer::movement() {
    heightAnimator->stop();
    heightAnimator->setStartValue(Y);
    heightAnimator->setEndValue(Y-100);
    heightAnimator->setDuration(1000);
    heightAnimator->setEasingCurve(QEasingCurve::OutQuad);
    heightAnimator->start();

}
void DamagedPlayer::removeDamagedPlayer() {

    delete this;
}