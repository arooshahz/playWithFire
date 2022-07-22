#ifndef TESTPRO_GAME_H
#define TESTPRO_GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "../views/Wall.h"
#include "../views/Player.h"
#include "../views/Box.h"
#include "../views/Label.h"

typedef std::pair<int,int> pii;

class Game :  public QGraphicsView {

Q_OBJECT


private:

//    bool isValid (int, int);
    class Box *boxes[15][15];
    bool isBlocked[15][15];
//    QList<Block *> blocks{};
    QList<Player *> players{};
    int blockWidth;
    int blockHeight;
    QGraphicsScene *playBackgroundScene;
    QList<QString> names;
    Label* labelPlayerName1;
    Label* labelPlayerScores1;
    Label* labelPlayerBombCount1;
    Label* labelPlayerName2;
    Label* labelPlayerScores2;
    Label* labelPlayerBombCount2;
    int count=0;
    QList<QPixmap*>playerInformation1{};
    QList<QPixmap*>playerInformation2{};
//    int frame1Information{};
//    int frame2Information{};
    QPixmap* pixmap1;
    QPixmap* pixmap2;


public :
    Game();

    QList<Player *> getPlayers();

    QList<Block *> *getBlocks();

    class Box *getBox(int, int);

    friend class Block;

    void stopGame();

    void deleteBox(int i, int j);

    void unblock (int i, int j);

    bool getBlocked(int i, int j);

    void showPlayersInformation();

    static pii findPos(int, int);

    void setPicture(int i, int j, QString name);

    void addItem(int x,int y);

    void removeBoxItem(Item *item);

};


#endif //TESTPRO_GAME_H
