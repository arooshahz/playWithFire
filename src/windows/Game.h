#ifndef TESTPRO_GAME_H
#define TESTPRO_GAME_H

#include <QGraphicsView>
#include "../views/Wall.h"
#include "../views/Player.h"
#include "../views/Box.h"

class Game : public QGraphicsView {
private:

    QList<Block *> blocks{};
    QList<Player *> players{};
    int blockWidth;
    int blockHeight;


public :
    Game();
    QList<Player *> getPlayers();
    QList<Block *> *getBlocks();
    friend class Block;
    void stopGame();
};


#endif //TESTPRO_GAME_H
