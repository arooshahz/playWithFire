#include "Box.h"
#include "Item.h"

Box::Box(int X, int Y) : Block(X, Y) {
    blockType = box;
    QPixmap pixmap(":/images/box");
    pixmap = pixmap.scaled(blockWidth, blockHeight);
    setPixmap(pixmap);
}

void Box::remove() {

    delete this;
}