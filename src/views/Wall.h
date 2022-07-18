#ifndef TESTPRO_WALL_H
#define TESTPRO_WALL_H

#include "Block.h"

class Wall : public Block {
public:
    Wall(int X, int y);

    void remove();
};


#endif //TESTPRO_WALL_H
