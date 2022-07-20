#pragma clang diagnostic push
#pragma ide diagnostic ignored "Simplify"
#include "Bomb.h"

Bomb::Bomb(int X, int Y, int indexOfPlayer, Game *game, QGraphicsPathItem *parent) : X(X), Y(Y),
                                                                                     indexOfPlayer(indexOfPlayer),
                                                                                     game(game),
                                                                                     QGraphicsPixmapItem(parent) {

    explodeTime = 3;

    auto pixmap = new QPixmap(":/images/bomb1");
    *pixmap = pixmap->scaled(79, 65);
    frames.append(pixmap);
    setPixmap(*pixmap);

    pixmap = new QPixmap(":/images/bomb2");
    *pixmap = pixmap->scaled(79, 65);
    frames.append(pixmap);
    pixmap = new QPixmap(":/images/bomb3");
    *pixmap = pixmap->scaled(79, 65);
    frames.append(pixmap);

    animateBombTimer = new QTimer();
    animateBombTimer->setInterval(100);
    connect(animateBombTimer, &QTimer::timeout, this, &Bomb::animateBomb);
    animateBombTimer->start();

    removeBombTimer = new QTimer();
    removeBombTimer->setInterval(explodeTime * 1000);
    connect(removeBombTimer, &QTimer::timeout, this, &Bomb::explode);
    removeBombTimer->start();

}

void Bomb::animateBomb() {
    setPixmap(*frames.at(frame));
    frame = (frame + 1) % 3;
}

void Bomb::explode() {
    damagePlayer();
    removeBoxes();
    delete this;
}

void Bomb::removeBoxes() {
    pii temp = findPos();
    int x = temp.first, y = temp.second;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, +1, 0, -1};
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 3; j++) {
            int a = x + j * dx[i], b = y + j * dy[i];
            Block *temp = (*game).getBlock(a, b);
            if (temp != NULL) {
                *game->getPlayers().at(indexOfPlayer)->getScore() += 5;
                game->setBlock(a, b, nullptr);
                delete temp;
                break;
            }
            else if (~(a != 0 && a != 14 && b != 0 && b != 14 && (a % 2 != 0 || b % 2 != 0))){
                break;
            }
        }
    }
    qInfo() << "remove Boxes finished";
}

void Bomb::damagePlayer() {
    auto player = game->getPlayers().at(indexOfPlayer);

    if ((player->y() > this->y() - 15 &&
         player->y() + player->boundingRect().height() < this->y() + this->boundingRect().height() + 15
         && this->x() - 2 * player->boundingRect().width() <= player->x() + player->boundingRect().width() &&
         player->x() + player->boundingRect().width() <=
         this->x() + this->boundingRect().width() + 3 * player->boundingRect().width())
        || (player->x() > this->x() - 15 &&
            player->x() + player->boundingRect().width() < this->x() + this->boundingRect().width() + 15
            && this->y() - 3 * player->boundingRect().height() <= player->y() &&
            player->y() + player->boundingRect().height() <=
            this->y() + this->boundingRect().height() + 3 * player->boundingRect().height())) {

        --(*game->getPlayers().at(indexOfPlayer)->getLifeCount());
        if(*game->getPlayers().at(indexOfPlayer)->getLifeCount()==0){
            *game->getPlayers().at((indexOfPlayer+1)%2)->getScore() +=50;
            game->stopGame();
        }

    }
}

pii Bomb::findPos(){
    int x = this->x();
    int y = this->y();
    pii pos;
    pos.first = x / Block::getBlockWidth();
    pos.second = y / Block::getBlockHeight();
    qInfo() << pos;
    return pos;
}

#pragma clang diagnostic pop