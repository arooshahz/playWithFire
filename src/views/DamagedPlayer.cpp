#include "DamagedPlayer.h"
#include "Block.h"

DamagedPlayer::DamagedPlayer(int X, int Y, int index, QGraphicsPathItem *parent) : X(X), Y(Y),
                                                                                   QGraphicsPixmapItem(parent) {


    QString name = ":/images/deadPlayer";
    if (index == 0)
        name += "0";
    else
        name += "1";
    auto pixmap = new QPixmap(name);
    *pixmap = pixmap->scaled(Block::getBlockWidth() - 25, Block::getBlockHeight() - 15);

    setPixmap(*pixmap);

    heightAnimator = new QPropertyAnimation(this, "height", this);
    movement();

    removeDamagedPlayerTimer = new QTimer();
    removeDamagedPlayerTimer->setInterval(1000);
    connect(removeDamagedPlayerTimer, &QTimer::timeout, this, &DamagedPlayer::removeDamagedPlayer);
    removeDamagedPlayerTimer->start();

}
DamagedPlayer::~DamagedPlayer(){
    delete heightAnimator;
    delete removeDamagedPlayerTimer;

}
void DamagedPlayer::movement() {
    heightAnimator->stop();
    heightAnimator->setStartValue(Y);
    heightAnimator->setEndValue(Y - 100);
    heightAnimator->setDuration(1000);
    heightAnimator->setEasingCurve(QEasingCurve::OutQuad);
    heightAnimator->start();

}

void DamagedPlayer::removeDamagedPlayer() {
    delete this;
}