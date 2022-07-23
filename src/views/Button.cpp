#include <QTextDocument>
#include <QFont>
#include <QPainter>

#include "Button.h"

Button::Button(int width, int height, QGraphicsPathItem *parent) : width(width), height(height),
                                                                   QGraphicsPixmapItem(parent) {

    QPixmap pixmap(":/images/start");
    pixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio);
    setPixmap(pixmap);

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit onPress();
}
