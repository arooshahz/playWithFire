#ifndef TESTPRO_GAME_H
#define TESTPRO_GAME_H
#include <QGraphicsView>
#include "../views/Block.h"
#include "../views/Wall.h"

class Game :public QGraphicsView{
private:

    QList<Block*>blocks;
    int blockWidth;
    int blockHeight;


public :
    Game();
     void addBlock(Block * block);
};


#endif //TESTPRO_GAME_H
