#ifndef TESTPRO_BLOCK_H
#define TESTPRO_BLOCK_H

#include <QGraphicsPixmapItem>
enum blockTypes{box,wall};

class Block : public QGraphicsPixmapItem {
protected:
    int X{};
    int Y{};
    static int blockWidth;
    static int blockHeight;
    blockTypes blockType;



public:

    Block(int X, int Y);

    int getX();

    int getY();

    static void setBlockWidth(int width);

    static void setBlockHeight(int height);

    static int getBlockWidth();

    static int getBlockHeight();

    virtual void remove() = 0;
};


#endif //TESTPRO_BLOCK_H
