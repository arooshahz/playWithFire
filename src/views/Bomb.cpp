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
//    int i = 0;
//
//    for (const auto block: *game->getBlocks()) {
//
//        if ((block->y() > this->y() - 15 &&
//             block->y() + block->boundingRect().height() < this->y() + this->boundingRect().height() + 15
//             && this->x() - 2 * block->boundingRect().width() <= block->x() + block->boundingRect().width() &&
//             block->x() + block->boundingRect().width() <=
//             this->x() + this->boundingRect().width() + 3 * block->boundingRect().width())
//            || (block->x() > this->x() - 15 &&
//                block->x() + block->boundingRect().width() < this->x() + this->boundingRect().width() + 15
//                && this->y() - 3 * block->boundingRect().height() <= block->y() &&
//                block->y() + block->boundingRect().height() <=
//                this->y() + this->boundingRect().height() + 3 * block->boundingRect().height())) {
//            auto *box = dynamic_cast<Box *>(block);
//
//            if (box != nullptr) {
//                game->getBlocks()->removeAt(i);
//                delete block;
//                *game->getPlayers().at(indexOfPlayer)->getScore() = +5;
//            }
//        }
//
//
//        ++i;
//    }
    int width = Block::getBlockWidth() + 10, height = Block::getBlockHeight() + 10;
    int dx[4] = {width, -width, 0, 0}, dy[4] = {0, 0, height, -height};
    for (int i = 0; i < 4; i++) {
        int j = 0;
        bool F = false;
        for (int j = 1; j <= 3; j++){
            if (F)
                break;
            int k = 0;
            for (const auto block : *game -> getBlocks()){
                if (F)
                    break;
                auto disty = this -> y() + j * dy[i] - block->y(), distx = this->x() + j * dx[i] - block->x();
                if (0 <= disty and disty <= height and 0 <= distx and distx <= width){
                    auto *box = dynamic_cast<Box *>(block);
                    if (box != nullptr) {
                        game->getBlocks()->removeAt(k);
                        delete block;
                        *game->getPlayers().at(indexOfPlayer)->getScore() += 5;
                    }
                    F = true;
                }
                k++;
            }
        }
    }
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