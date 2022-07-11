#include "Box.h"

Box::Box(int width, int height) : Block(width,height){

    QPixmap pixmap(":/images/box");
    pixmap=pixmap.scaled(width,height);
    setPixmap(pixmap);


}