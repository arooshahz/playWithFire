#include "Block.h"

Block::Block(int X,int Y): X(X), Y(Y) {




}
int Block::blockWidth{};
int Block::blockHeight{};
void Block::setBlockWidth(int width) {
    blockWidth=width;
}
void Block::setBlockHeight(int height) {
    blockHeight=height;
}

int Block::getBlockWidth() {
    return blockWidth;
}
int Block::getBlockHeight() {
    return blockHeight;
}
int Block::getX(){
    return X;
}

int Block::getY() {
    return Y;
}
