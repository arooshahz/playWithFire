#ifndef TESTPRO_GAME_H
#define TESTPRO_GAME_H
#include <QGraphicsView>
#include "../views/Block.h"
#include "../views/Wall.h"
#include "../views/Player.h"

class Game :public QGraphicsView{
private:

    QList<Block*>blocks{};
    QList<Player*>players{};
    int blockWidth{};
    int blockHeight{};



public :
    Game();
     void addBlock(Block * block);
     QList<Player*> getPlayers();
    QList<Block*> getBlocks();
};


#endif //TESTPRO_GAME_H
