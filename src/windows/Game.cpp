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
    setBackgroundBrush(QPixmap(":/images/wallpaper3"));
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
//    isBlocked[0][0] = true;
//    isBlocked[0][14] = true;
//    isBlocked[14][0] = true;
//    isBlocked[14][14] = true;
    for (int x = 1; x < 14; x++) {
        setPicture(0, x, "lb");
        setPicture(x, 0, "tb");
        setPicture(14, x, "rb");
        setPicture(x, 14, "db");
//        isBlocked[0][x] = true;
//        isBlocked[x][0] = true;
//        isBlocked[14][x] = true;
//        isBlocked[x][14] = true;
    }
    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            isBlocked[i][j] = false;
            setPicture(i, j, "bg");
        }
    }
    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            if (temp.contains({i, j})) {
                boxes[i][j] = nullptr;
                continue;
            }
            if (i != 0 && i != 14 && j != 0 && j != 14 && (i % 2 != 0 || j % 2 != 0)) {
                int num = (rand() % (2));
                if (num == 1) {
                    auto box = new class Box(i, j);
                    isBlocked[i][j] = true;
                    boxes[i][j] = box;
                    playBackgroundScene->addItem(box);
                    box->setPos(i * blockWidth, j * blockHeight);
                }

            } else {
                auto wall = new Wall(i, j);
                isBlocked[i][j] = true;
                boxes[i][j] = nullptr;
                playBackgroundScene->addItem(wall);
                wall->setPos(i * blockWidth, j * blockHeight);
            }
        }
    }

    QList<QPixmap *> frames1;
    auto pixmap1 = new QPixmap(":/images/p11");
    *pixmap1 = pixmap1->scaled(blockWidth -( blockWidth/3), blockHeight -( blockHeight/5));
    frames1.append(pixmap1);
    pixmap1 = new QPixmap(":/images/p12");
    *pixmap1 = pixmap1->scaled(blockWidth - ( blockWidth/3), blockHeight - ( blockHeight/5));
    frames1.append(pixmap1);
    pixmap1 = new QPixmap(":/images/p13");
    *pixmap1 = pixmap1->scaled(blockWidth - ( blockWidth/3), blockHeight - ( blockHeight/5));
    frames1.append(pixmap1);

    auto player1 = new Player(blockWidth, blockHeight, frames1, this->scene());
    this->players.append(player1);
    playBackgroundScene->addItem(player1);
    player1->setPos(blockWidth, blockHeight);

    QList<QPixmap *> frames2;
    auto pixmap2 = new QPixmap(":/images/p21");
    *pixmap2 = pixmap2->scaled(blockWidth - ( blockWidth/3), blockHeight - ( blockHeight/5));
    frames2.append(pixmap2);
    pixmap2 = new QPixmap(":/images/p22");
    *pixmap2 = pixmap2->scaled(blockWidth - ( blockWidth/3), blockHeight - ( blockHeight/5));
    frames2.append(pixmap2);
    pixmap2 = new QPixmap(":/images/p23");
    *pixmap2 = pixmap2->scaled(blockWidth - ( blockWidth/3), blockHeight - ( blockHeight/5));
    frames2.append(pixmap2);
    auto player2 = new Player((blockWidth * 13), blockHeight * 13, frames2, this->scene());
    this->players.append(player2);
    playBackgroundScene->addItem(player2);
    player2->setPos((blockWidth * 13), blockHeight * 13);


    auto pixmapInformation = new QPixmap(":/images/Player 1 Information 6 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation1.append(pixmapInformation);
    pixmapInformation = new QPixmap(":/images/Player 1 Information 5 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation1.append(pixmapInformation);
    pixmapInformation = new QPixmap(":/images/Player 1 Information 4 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation1.append(pixmapInformation);
    pixmapInformation = new QPixmap(":/images/Player 1 Information 3 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation1.append(pixmapInformation);
    pixmapInformation = new QPixmap(":/images/Player 1 Information 2 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation1.append(pixmapInformation);
    pixmapInformation = new QPixmap(":/images/Player 1 Information 1 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation1.append(pixmapInformation);
    pixmapInformation = new QPixmap(":/images/Player 1 Information 0 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation1.append(pixmapInformation);

    pixmapInformation = new QPixmap(":/images/Player 2 Information 6 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation2.append(pixmapInformation);
    pixmapInformation = new QPixmap(":/images/Player 2 Information 5 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation2.append(pixmapInformation);
    pixmapInformation = new QPixmap(":/images/Player 2 Information 4 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation2.append(pixmapInformation);
    pixmapInformation = new QPixmap(":/images/Player 2 Information 3 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation2.append(pixmapInformation);
    pixmapInformation = new QPixmap(":/images/Player 2 Information 2 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation2.append(pixmapInformation);
    pixmapInformation = new QPixmap(":/images/Player 2 Information 1 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation2.append(pixmapInformation);
    pixmapInformation = new QPixmap(":/images/Player 2 Information 0 life");
    *pixmapInformation = pixmapInformation->scaled(blockWidth - 25, blockHeight - 15);
    playerInformation2.append(pixmapInformation);


    QFile file("names.txt");
    names = {"", ""};
    int cnt = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            names[cnt++] = in.readLine();
        }
    }


    showPlayersInformation();

    auto controller = new Controller(this);
    playBackgroundScene->addItem(controller);


}

QList<Player *> Game::getPlayers() {
    return players;
}

Box *Game::getBox(int i, int j) {
    if (i < 0 or 14 < i or j < 0 or 14 < j)
        return nullptr;
    return boxes[i][j];
}

void Game::deleteBox(int i, int j) {
    if (i < 0 or 14 < i or j < 0 or 14 < j)
        return;
    boxes[i][j]->remove();
    boxes[i][j] = nullptr;
    unblock(i, j);
}

bool Game::getBlocked(int i, int j) {
    if (i < 0 or 14 < i or j < 0 or 14 < j)
        return true;
    return isBlocked[i][j];
}

void Game::unblock(int i, int j) {
    qInfo() << i << j << "unblocked";
    isBlocked[i][j] = false;
}

void Game::stopGame() {


    close();
    (new Result(this))->show();

}

void Game::showPlayersInformation() {
    if (count > 0) {
//        delete labelPlayerName1;
//        delete labelPlayerScores1;
//        delete labelPlayerLifeCount1;
//        delete labelPlayerName2;
//        delete labelPlayerScores2;
//        delete labelPlayerLifeCount2;
    }


    auto pixmap1 = new QPixmap;
    pixmap1 = playerInformation1.at(*getPlayers().at(0)->getLifeCount());
//    *pixmap1 = pixmap1->scaled(340, 450);
    playBackgroundScene->addRect(QRect(-150, 0, 150, 150),
                                 QPen(Qt::NoPen), QPixmap(*pixmap1));

    auto pixmap2 = new QPixmap;
    pixmap2 = playerInformation1.at(*getPlayers().at(1)->getLifeCount());
    *pixmap2 = pixmap2->scaled(200, 150);
    playBackgroundScene->addRect(QRect(-150, 300, 150, 150),
                                 QPen(Qt::NoPen), QPixmap(*pixmap2));




//    labelPlayerName1 = new Label();
//    labelPlayerName1->setPlainText(names[0]);
//    playBackgroundScene->addItem(labelPlayerName1);
//    labelPlayerName1->setPos(-150, 150);
//
//    QString scores1 = QString::number(*players.at(0)->getScore());
//    labelPlayerScores1 = new Label();
//    labelPlayerScores1->setPlainText("score: " + scores1);
//    playBackgroundScene->addItem(labelPlayerScores1);
//    labelPlayerScores1->setPos(-150, 180);
//
//
//    QString lifeCount1 = QString::number(*players.at(0)->getLifeCount());
//    labelPlayerLifeCount1 = new Label();
//    labelPlayerLifeCount1->setPlainText("life count: " + lifeCount1);
//    playBackgroundScene->addItem(labelPlayerLifeCount1);
//    labelPlayerLifeCount1->setPos(-150, 210);
//
//
//    QPixmap pixmapPlayer2(":/images/player2");
//    pixmapPlayer2 = pixmapPlayer2.scaled(200, 150);
//    playBackgroundScene->addRect(QRect(-150, 300, 150, 150),
//                                 QPen(Qt::NoPen), QPixmap(pixmapPlayer2));
//
//
//    labelPlayerName2 = new Label();
//    labelPlayerName2->setPlainText(names[1]);
//    playBackgroundScene->addItem(labelPlayerName2);
//    labelPlayerName2->setPos(-150, 450);
//
//
//    QString scores2 = QString::number(*players.at(1)->getScore());
//    labelPlayerScores2 = new Label();
//    labelPlayerScores2->setPlainText("score: " + scores2);
//    playBackgroundScene->addItem(labelPlayerScores2);
//    labelPlayerScores2->setPos(-150, 480);
//
//
//    QString lifeCount2 = QString::number(*players.at(1)->getLifeCount());
//    labelPlayerLifeCount2 = new Label();
//    labelPlayerLifeCount2->setPlainText(lifeCount2);
//    playBackgroundScene->addItem(labelPlayerLifeCount2);
//    labelPlayerLifeCount2->setPos(-100, 510);
//
//    QPixmap lifeCountPixmap(":/images/heart3");
//    lifeCountPixmap = lifeCountPixmap.scaled(50, 50);
//    playBackgroundScene->addRect(QRect(-150, 500, 50, 50),
//                                 QPen(Qt::NoPen), QPixmap(lifeCountPixmap));

    count++;
}

pii Game::findPos(int x, int y) {
    return {x / Block::getBlockWidth(), y / Block::getBlockHeight()};
}


void Game::setPicture(int i, int j, QString name) {
    QPixmap backgroundPixmap(":/images/" + name);
    backgroundPixmap = backgroundPixmap.scaled(blockWidth, blockHeight);
    playBackgroundScene->addRect(QRect(i * blockWidth, j * blockHeight, blockWidth, blockHeight),
                                 QPen(Qt::NoPen), QPixmap(backgroundPixmap));

}

void Game::addItem(int x, int y) {
    auto temp = new Item();
    this->scene()->addItem(temp);
    temp->setPos(x * Block::getBlockWidth(), y * Block::getBlockHeight());

}

void Game::removeBoxItem(Item *item) {

    scene()->removeItem(item);

}