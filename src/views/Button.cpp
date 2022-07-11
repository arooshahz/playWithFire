#include <QTextDocument>
#include <QFont>
#include <QPainter>

#include "Button.h"

Button::Button(int width, int height):width(width),height(height), QGraphicsTextItem() {

    setDefaultTextColor(QColor("black"));
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    setFont(font);

    setTextWidth(width);


    document()->setDocumentMargin(10);
}

void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPixmap pixmap(":/images/button");
    pixmap=pixmap.scaled(width,height);
    painter->setBrush(pixmap);
    painter->drawRect(boundingRect());



    QGraphicsTextItem::paint(painter, option, widget);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit onPress();
}
