#include "Wall.h"

Wall::Wall(int X, int Y) : Block(X, Y) {
    QPixmap pixmap(":/images/wall");
    pixmap = pixmap.scaled(blockWidth, blockHeight);
    setPixmap(pixmap);
}

void Wall::remove() {

}