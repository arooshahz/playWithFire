#ifndef TESTPRO_GAME_H
#define TESTPRO_GAME_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "../views/Wall.h"
#include "../views/Player.h"
#include "../views/Box.h"

class Game : public QGraphicsView {
private:

//    bool isValid (int, int);
    class Box *boxes[15][15];
    bool isBlocked[15][15];
    QList<Block *> blocks{};
    QList<Player *> players{};
    int blockWidth;
    int blockHeight;
    QGraphicsScene *playBackgroundScene;


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
};


#endif //TESTPRO_GAME_H
