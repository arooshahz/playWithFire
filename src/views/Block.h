#ifndef TESTPRO_BLOCK_H
#define TESTPRO_BLOCK_H
#include <QGraphicsPixmapItem>

class Block :public QGraphicsPixmapItem{
private:
    int width;
    int height;
public:

    Block(int width,int height);
};


#endif //TESTPRO_BLOCK_H
