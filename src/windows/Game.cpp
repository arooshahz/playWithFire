#include <QFile>
#include "Game.h"
#include "../views/Controller.h"
#include "Result.h"
#include "../views/Label.h"


Game::Game() {


    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    setFrameShape(NoFrame);

    playBackgroundScene = new QGraphicsScene(this);
    playBackgroundScene->setSceneRect(-200, 0, width(), height());
    setBackgroundBrush(QColor("#2c2721"));
    setScene(playBackgroundScene);



    Block::setBlockWidth((width() - 190) / 15);
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
            if (temp.contains({i, j})) {
                Blocks[i][j] = nullptr;
                continue;
            }
            if (i != 0 && i != 14 && j != 0 && j != 14 && (i % 2 != 0 || j % 2 != 0)) {
                int num = (rand() % (2));
                if (num == 1) {
                    auto box = new class Box(i, j);
                    Blocks[i][j] = box;
                    blocks.append(box);
                    playBackgroundScene->addItem(box);
                    box->setPos(i * blockWidth, j * blockHeight);
                }

            } else {
                auto wall = new Wall(i, j);
                Blocks[i][j] = NULL;
                blocks.append(wall);
                playBackgroundScene->addItem(wall);
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
    playBackgroundScene->addItem(player1);
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
    playBackgroundScene->addItem(player2);
    player2->setPos((blockWidth * 13), blockHeight * 13);


    QPixmap pixmapPlayer1(":/images/player1");
    pixmapPlayer1 = pixmapPlayer1.scaled(200, 150);
    playBackgroundScene->addRect(QRect(-150, 0, 150, 150),
                                 QPen(Qt::NoPen), QPixmap(pixmapPlayer1));

    QFile file("names.txt");
    QString names[2] = {"", ""};
    int cnt = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            names[cnt++] = in.readLine();
        }
    }

    auto labelPlayerName1 = new Label();
    labelPlayerName1->setPlainText(names[0]);
    playBackgroundScene->addItem(labelPlayerName1);
    labelPlayerName1->setPos(-150, 150);

    QString scores1 = QString::number(*players.at(0)->getScore());
    auto labelPlayerScores1 = new Label();
    labelPlayerScores1->setPlainText("score: " + scores1);
    playBackgroundScene->addItem(labelPlayerScores1);
    labelPlayerScores1->setPos(-150, 180);


    QString lifeCount1 = QString::number(*players.at(0)->getLifeCount());
    auto labelPlayerLifeCount1 = new Label();
    labelPlayerLifeCount1->setPlainText("life count: " + lifeCount1);
    playBackgroundScene->addItem(labelPlayerLifeCount1);
    labelPlayerLifeCount1->setPos(-150, 210);


    QPixmap pixmapPlayer2(":/images/player2");
    pixmapPlayer2 = pixmapPlayer2.scaled(200, 150);
    playBackgroundScene->addRect(QRect(-150, 300, 150, 150),
                                 QPen(Qt::NoPen), QPixmap(pixmapPlayer2));


    auto labelPlayerName2 = new Label();
    labelPlayerName2->setPlainText(names[1]);
    playBackgroundScene->addItem(labelPlayerName2);
    labelPlayerName2->setPos(-150, 450);


    QString scores2 = QString::number(*players.at(1)->getScore());
    auto labelPlayerScores2 = new Label();
    labelPlayerScores2->setPlainText("score: " + scores2);
    playBackgroundScene->addItem(labelPlayerScores2);
    labelPlayerScores2->setPos(-150, 480);


    QString lifeCount2 = QString::number(*players.at(1)->getLifeCount());
    auto labelPlayerLifeCount2 = new Label();
    labelPlayerLifeCount2->setPlainText("life count: " + lifeCount2);
    playBackgroundScene->addItem(labelPlayerLifeCount2);
    labelPlayerLifeCount2->setPos(-150, 510);


    auto controller = new Controller(this);
    playBackgroundScene->addItem(controller);
//    scene->setFocus();

}

QList<Player *> Game::getPlayers() {
    return players;
}

Block *Game::getBlock(int i, int j) {
    return Blocks[i][j];
}

void Game::setBlock(int i, int j, Block *block) {
    Blocks[i][j] = block;
}

QList<Block *> *Game::getBlocks() {
    return &blocks;
}

void Game::stopGame() {


    close();
    (new Result(this))->show();

}
