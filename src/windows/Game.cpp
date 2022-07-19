#include "Game.h"
#include "../views/Controller.h"
#include "Result.h"


Game::Game() {

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, width(), height());
    setBackgroundBrush(QColor("#2c2721"));
    setScene(scene);

    Block::setBlockWidth((width()) / 15);
    Block::setBlockHeight(height() / 15);
    blockWidth = Block::getBlockWidth();
    blockHeight = Block::getBlockHeight();

    QList<QPair<int, int>> temp = {{1,  1},
                                   {13, 13},
                                   {1,  2},
                                   {2,  1},
                                   {12, 13},
                                   {13, 12}};
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (temp.contains({i, j}))
                continue;
            if (i != 0 && i != 14 && j != 0 && j != 14 && (i % 2 != 0 || j % 2 != 0)) {
                int num = (rand() % (2));
                if (num == 1) {
                    auto box = new class Box(blockWidth, blockHeight);
                    this->blocks.append(box);
                    scene->addItem(box);
                    box->setPos(i * blockWidth, j * blockHeight);
                }

            } else {
                auto wall = new Wall(blockWidth, blockHeight);
                this->blocks.append(wall);
                scene->addItem(wall);
                wall->setPos(i * blockWidth, j * blockHeight);
            }

        }
    }

    QList<QPixmap *> frames1;
    auto pixmap1 = new QPixmap(":/images/p11");
    *pixmap1 = pixmap1->scaled(blockWidth - 25, blockHeight - 15);
    frames1.append(pixmap1);
    pixmap1 = new QPixmap(":/images/p12");
    *pixmap1 = pixmap1->scaled(blockWidth - 25, blockHeight - 15);
    frames1.append(pixmap1);
    pixmap1 = new QPixmap(":/images/p13");
    *pixmap1 = pixmap1->scaled(blockWidth - 25, blockHeight - 15);
    frames1.append(pixmap1);

    auto player1 = new Player(blockWidth, blockHeight, frames1);
    this->players.append(player1);
    scene->addItem(player1);
    player1->setPos(blockWidth, blockHeight);

    QList<QPixmap *> frames2;
    auto pixmap2 = new QPixmap(":/images/p21");
    *pixmap2 = pixmap2->scaled(blockWidth - 25, blockHeight - 15);
    frames2.append(pixmap2);
    pixmap2 = new QPixmap(":/images/p22");
    *pixmap2 = pixmap2->scaled(blockWidth - 25, blockHeight - 15);
    frames2.append(pixmap2);
    pixmap2 = new QPixmap(":/images/p23");
    *pixmap2 = pixmap2->scaled(blockWidth - 25, blockHeight - 15);
    frames2.append(pixmap2);
    auto player2 = new Player((blockWidth * 13), blockHeight * 13, frames2);
    this->players.append(player2);
    scene->addItem(player2);
    player2->setPos((blockWidth * 13), blockHeight * 13);

    auto controller = new Controller(this);
    scene->addItem(controller);
    scene->setFocus();

}

QList<Player *> Game::getPlayers() {
    return players;
}

QList<Block *> *Game::getBlocks() {
    return &blocks;
}
void Game::stopGame(){



    close();
    (new Result(this))->show();

}