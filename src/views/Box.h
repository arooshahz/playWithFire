#ifndef TESTPRO_BOX_H
#define TESTPRO_BOX_H
#include "Block.h"

class Box : public Block{
public:
    Box(int X,int Y);
    void remove();
};


#endif //TESTPRO_BOX_H
