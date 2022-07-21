#pragma clang diagnostic push
#pragma ide diagnostic ignored "Simplify"

#include "Bomb.h"
#include "DamagedPlayer.h"

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
    pii pos = game->findPos(this->x(), this->y());
    int x = pos.first, y = pos.second;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, +1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int bombRadius = game->getPlayers().at(indexOfPlayer)->getBombRadius();
        for (int j = 1; j <= bombRadius; j++) {
            int a = x + j * dx[i], b = y + j * dy[i];
            if (!game->getBlocked(a, b)){
                continue;
            }
            Box *temp = (*game).getBox(a, b);
            if (temp != NULL) {
                *game->getPlayers().at(indexOfPlayer)->getScore() += 5;
                game->deleteBox(a, b);
                game->showPlayersInformation();
            }
            break;
        }
    }
}

void Bomb::damagePlayer() {

    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, +1, 0, -1};
    pii bPos = game->findPos(this->x(), this->y());      // bomb position
    int bx = bPos.first, by = bPos.second;
    for (int index = 0; index < 2; index++){
        auto player = game->getPlayers().at(index);
        int bombRadius = player->getBombRadius();
        pii pPos = game->findPos(player->x(), player->y());  // player position
        int px = pPos.first, py = pPos.second;
        if (bx == px and by == py)
            decreaseLifeCount(index);
        auto damagedPlayer1 = new DamagedPlayer(game->getPlayers().at(indexOfPlayer)->x(), game->getPlayers().at(indexOfPlayer)->y());
        game->scene()->addItem(damagedPlayer1);
        damagedPlayer1->setPos(game->getPlayers().at(indexOfPlayer)->x(), game->getPlayers().at(indexOfPlayer)->y());

        for (int i = 0; i < 4; i++){
            for (int j = 1; j <= bombRadius; j++){
                int x = px + j * dx[i], y = py + j * dy[i];
                if (game->getBlocked(x, y))
                    break;
                if (x == bx and y == by){
                    decreaseLifeCount(index);
                    auto damagedPlayer2 = new DamagedPlayer(game->getPlayers().at(indexOfPlayer)->x(), game->getPlayers().at(indexOfPlayer)->y());
                    game->scene()->addItem(damagedPlayer2);
                    damagedPlayer2->setPos(game->getPlayers().at(indexOfPlayer)->x(), game->getPlayers().at(indexOfPlayer)->y());
                    break;
                }}

        }
    }
}

void Bomb::decreaseLifeCount (int index){
    auto player = game->getPlayers().at(index);
    (*player->getLifeCount())--;
    if (*player->getLifeCount() == 0){
        *game->getPlayers().at(1 - index)->getScore() += 50;
        game->stopGame();
    }
}

#pragma clang diagnostic pop