#ifndef TESTPRO_GAME_H
#define TESTPRO_GAME_H

#include <QGraphicsView>
#include "../views/Wall.h"
#include "../views/Player.h"
#include "../views/Box.h"

class Game : public QGraphicsView {
private:

    bool isValid (int, int);
    Block* Blocks[15][15];
    QList<Block *> blocks{};
    QList<Player *> players{};
    int blockWidth;
    int blockHeight;


public :
    Game();
    QList<Player *> getPlayers();
    QList<Block *> *getBlocks();
    Block* getBlock (int, int);
    friend class Block;
    void stopGame();

    void setBlock(int i, int j, Block *block);
};


#endif //TESTPRO_GAME_H
