#include <QFile>
#include "Game.h"
#include "../views/Controller.h"
#include "Result.h"
#include "../views/Label.h"
#include "../views/playerInformation.h"


Game::Game() {


    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    setFrameShape(NoFrame);

    playBackgroundScene = new QGraphicsScene(this);
    playBackgroundScene->setSceneRect(-width() / 4.8, 0, width(), height());
    setBackgroundBrush(QPixmap(":/images/wallpaper3"));
    setScene(playBackgroundScene);


    Block::setBlockWidth((width() - (width() / 5)) / 15);
    Block::setBlockHeight(height() / 15);
    blockWidth = Block::getBlockWidth();
    blockHeight = Block::getBlockHeight();

    MakeMap();

    QList<QPixmap *> frames1, frames2;
    QString name = ":/images/p";

    auto pixmap1 = new QPixmap(":/images/p11");
    *pixmap1 = pixmap1->scaled(blockWidth - (blockWidth / 3), blockHeight - (blockHeight / 5));
    frames1.append(pixmap1);
    pixmap1 = new QPixmap(":/images/p12");
    *pixmap1 = pixmap1->scaled(blockWidth - (blockWidth / 3), blockHeight - (blockHeight / 5));
    frames1.append(pixmap1);
    pixmap1 = new QPixmap(":/images/p13");
    *pixmap1 = pixmap1->scaled(blockWidth - (blockWidth / 3), blockHeight - (blockHeight / 5));
    frames1.append(pixmap1);

    auto player1 = new Player(blockWidth, blockHeight, frames1, this->scene());
    this->players.append(player1);
    playBackgroundScene->addItem(player1);
    player1->setPos(blockWidth, blockHeight);

    auto pixmap2 = new QPixmap(":/images/p21");
    *pixmap2 = pixmap2->scaled(blockWidth - (blockWidth / 3), blockHeight - (blockHeight / 5));
    frames2.append(pixmap2);
    pixmap2 = new QPixmap(":/images/p22");
    *pixmap2 = pixmap2->scaled(blockWidth - (blockWidth / 3), blockHeight - (blockHeight / 5));
    frames2.append(pixmap2);
    pixmap2 = new QPixmap(":/images/p23");
    *pixmap2 = pixmap2->scaled(blockWidth - (blockWidth / 3), blockHeight - (blockHeight / 5));
    frames2.append(pixmap2);
    auto player2 = new Player((blockWidth * 13), blockHeight * 13, frames2, this->scene());
    this->players.append(player2);
    playBackgroundScene->addItem(player2);
    player2->setPos((blockWidth * 13), blockHeight * 13);

    showInfoTimer = new QTimer();
    showInfoTimer->setInterval(100);
    connect(showInfoTimer, &QTimer::timeout, this, &Game::showPlayersInformation);
    showInfoTimer->start();


    auto controller = new Controller(this);
    playBackgroundScene->addItem(controller);


}
QList<Player *> Game::getPlayers() {
    return players;
}
Game::~Game(){
    qDeleteAll(players);
    delete showInfoTimer;
    delete labelPlayerName1;
    delete labelPlayerScores1;
    delete labelPlayerBombCount1;
    delete labelPlayerName2;
    delete labelPlayerScores2;
    delete labelPlayerBombCount2;
  for(int i=0;i<15;i++){
      for (int j=0;j<15;j++)
      {
          delete boxes[i][j];
      }  }




}
Box *Game::getBox(int i, int j) {
    if (i <= 0 or 14 <= i or j <= 0 or 14 <= j)
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
    isBlocked[i][j] = false;
}

void Game::stopGame() {
    close();
    (new Result(this))->show();

}

void Game::showPlayersInformation() {

    QFile file("names.txt");
    QString names[2] = {"", ""};
    int num = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            names[num++] = in.readLine();
        }
    }

    if (initialized) {
        delete labelPlayerName1;
        delete labelPlayerScores1;
        delete labelPlayerBombCount1;
        delete labelPlayerName2;
        delete labelPlayerScores2;
        delete labelPlayerBombCount2;
        playerInfo[0]->remove();
        playerInfo[1]->remove();
    }

    double w = width(), h = height();
    auto player0infopixmap = new playerInformation(1, *getPlayers().at(0)->getLifeCount(), w);
    auto player1infopixmap = new playerInformation(2, *getPlayers().at(1)->getLifeCount(), w);
    playerInfo[0] = player0infopixmap;
    playerInfo[1] = player1infopixmap;
    playBackgroundScene->addItem(player0infopixmap);
    playBackgroundScene->addItem(player1infopixmap);
    player0infopixmap->setPos(-w/4.8+player0infopixmap->boundingRect().width()/12, height()/36);
    player1infopixmap->setPos(-w/4.8+player1infopixmap->boundingRect().width()/12, h/36 + h / 2);

    labelPlayerName1 = new Label();
    labelPlayerName1->setPlainText(names[0]);
    playBackgroundScene->addItem(labelPlayerName1);
    labelPlayerName1->setPos(-w / 5.7, w / (4.3 * 2)+h/20);

    labelPlayerName2 = new Label();
    labelPlayerName2->setPlainText(names[1]);
    playBackgroundScene->addItem(labelPlayerName2);
    labelPlayerName2->setPos(-w / 4.3, w / (4.3 * 2) + h / 2+h/20);

    QString scores1 = QString::number(*players.at(0)->getScore());
    labelPlayerScores1 = new Label();
    labelPlayerScores1->setPlainText(scores1);
    playBackgroundScene->addItem(labelPlayerScores1);
    labelPlayerScores1->setPos(-w / (2.25 * 4.8)+player1infopixmap->boundingRect().width()/4, h / 18);

    QString scores2 = QString::number(*players.at(1)->getScore());
    labelPlayerScores2 = new Label();
    labelPlayerScores2->setPlainText(scores2);
    playBackgroundScene->addItem(labelPlayerScores2);
    labelPlayerScores2->setPos(-w / (2.25 * 4.8)+player1infopixmap->boundingRect().width()/4, height() / 18 + h / 2);

    QString bombCount1 = QString::number(players.at(0)->getBombCount());
    labelPlayerBombCount1 = new Label();
    labelPlayerBombCount1->setPlainText(bombCount1);
    playBackgroundScene->addItem(labelPlayerBombCount1);
    labelPlayerBombCount1->setPos(-w / (2.25 * 4.8)+player1infopixmap->boundingRect().width()/4, h / 7.7);

    QString bombCount2 = QString::number(players.at(1)->getBombCount());
    labelPlayerBombCount2 = new Label();
    labelPlayerBombCount2->setPlainText(bombCount2);
    playBackgroundScene->addItem(labelPlayerBombCount2);
    labelPlayerBombCount2->setPos(-w / (2.25 * 4.8)+player1infopixmap->boundingRect().width()/4, h / 7.7 + h / 2);

    initialized = true;
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
//
//void Game::removeBoxItem(Item *item) {
//    scene()->removeItem(item);
//}

bool Game::getItem(int i, int j) {
    if (i < 0 or 14 < i or j < 0 or 14 < j)
        return false;
    return hasItem[i][j];
}

void Game::MakeMap() {
    QList<QPair<int, int>> temp = {{1,  1},
                                   {13, 13},
                                   {1,  2},
                                   {2,  1},
                                   {12, 13},
                                   {13, 12}};
    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            isBlocked[i][j] = false;
            setPicture(i, j, "bg");
        }
    }
    isBlocked[0][0] = true;
    isBlocked[0][14] = true;
    isBlocked[14][0] = true;
    isBlocked[14][14] = true;
    boxes[0][0] = nullptr;
    boxes[0][14] = nullptr;
    boxes[14][0] = nullptr;
    boxes[14][14] = nullptr;
    for (int x = 1; x < 14; x++) {
        setPicture(0, x, "lb");
        setPicture(x, 0, "tb");
        setPicture(14, x, "rb");
        setPicture(x, 14, "db");
        isBlocked[0][x] = true;
        isBlocked[x][0] = true;
        isBlocked[14][x] = true;
        isBlocked[x][14] = true;
        boxes[0][x] = nullptr;
        boxes[x][0] = nullptr;
        boxes[14][x] = nullptr;
        boxes[x][14] = nullptr;
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
                    int test = rand() % 10;
                    if (test < 3)
                        hasItem[i][j] = true;
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
}