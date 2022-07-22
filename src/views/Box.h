#ifndef TESTPRO_BOX_H
#define TESTPRO_BOX_H

#include "Block.h"
#include "Item.h"

class Box : public Block {
private:

//    Item* item;

public:

    Box(int X, int Y);

    void remove();

    bool hasItem();

};


#endif //TESTPRO_BOX_H
