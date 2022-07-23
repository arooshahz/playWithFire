#include <QFile>
#include "Player.h"
#include "Block.h"
#include "Item.h"
#include "../windows/Game.h"


Player::Player(int X, int Y, QList<QPixmap *> frames, QGraphicsScene *scene, QGraphicsPathItem *parent) : X(X), Y(Y),
                                                                                                          frames(frames),
                                                                                                          scene(scene),
                                                                                                          QGraphicsPixmapItem(
                                                                                                                  parent) {

    QFile file2("info.txt");
    QString info[2] = {"3", "3"};
    int cnt = 0;
    if (file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file2);
        while (!in.atEnd()) {
            info[cnt++] = in.readLine();
        }
    }

    bombCount = 10;
    speed = 60;
    bombRadius = Player::toInteger(info[0]);
    lifeCount = Player::toInteger(info[1]);
    score = 0;
    setPixmap(*frames.at(0));

    heightAnimator = new QPropertyAnimation(this, "height", this);
    widthAnimator = new QPropertyAnimation(this, "width", this);


    walkingTimer = new QTimer();
    walkingTimer->setInterval(100);
    connect(walkingTimer, &QTimer::timeout, this, &Player::walking);
    walkingTimer->start();

}
Player::~Player(){
    delete heightAnimator;
    delete widthAnimator;
    delete walkingTimer;
    qDeleteAll(frames);
    delete scene;

}

void Player::walking() {
    setPixmap(*frames.at(frame));
    frame = (frame + 1) % 3;
}

void Player::movement(int newX, int newY) {

    heightAnimator->stop();
    heightAnimator->setStartValue(y());
    heightAnimator->setEndValue(newY);
    heightAnimator->setDuration(speed);
    heightAnimator->start();

    widthAnimator->stop();
    widthAnimator->setStartValue(x());
    widthAnimator->setEndValue(newX);
    widthAnimator->setDuration(speed);
    widthAnimator->start();


}

int Player::getX() {
    return X;
}

int Player::getY() {
    return Y;
}

int *Player::getScore() {
    return &score;
}

int *Player::getLifeCount() {
    return &lifeCount;
}

int Player::getBombRadius() {
    return bombRadius;
}

void Player::setBombRadius(int bombRadius) {
    this->bombRadius = bombRadius;
}

int Player::getBombCount() {
    return bombCount;

}

void Player::setBomCount(int bombCount) {
    this->bombCount = bombCount;
}

bool Player::getBombLimitation() {
    return bombLimitation;
}

void Player::setBombLimitation(bool bombLimitation) {
    this->bombLimitation = bombLimitation;
}

void Player::setSpeed(int speed) {
    this->speed = speed;
}

int Player::getSpeed() {
    return speed;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QGraphicsPixmapItem::paint(painter, option, widget);

    for (QGraphicsItem *temp: collidingItems()) {
        Item *item = dynamic_cast<Item *>(temp);
        if (item != nullptr) {

            item->controller(this);
            scene->removeItem(temp);



        }
    }
}

int Player::toInteger(QString s) {
    int ret = 0;
    QString Char[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    for (int i = 0; i < s.size(); i++) {
        ret = ret * 10;
        for (int j = 0; j < 10; j++) {
            if (Char[j] == s[i]) {
                ret += j;
                break;
            }
        }
    }
    return ret;
}
