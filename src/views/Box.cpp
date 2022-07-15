#include "Box.h"

Box::Box(int X, int Y) : Block(X,Y){

    QPixmap pixmap(":/images/box");
    pixmap=pixmap.scaled(blockWidth,blockHeight);
    setPixmap(pixmap);


}