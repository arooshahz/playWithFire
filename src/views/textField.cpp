#include <QFont>
#include <QPainter>
#include "textField.h"
#include <QStyleOptionGraphicsItem>
#include <QTextDocument>

textField::textField(int width, int height, int index) : width(width), height(height), index(index),
                                                         QGraphicsTextItem() {
    setDefaultTextColor(QColor("white"));
    QFont font;
    font.setPixelSize(index == 2 ? 40 : 50);
    font.setBold(true);
    setFont(font);
    setTextInteractionFlags(Qt::TextEditorInteraction);
    setTextWidth(width);
    document()->setDocumentMargin(10);

    auto pixmap = new QPixmap(":/images/nameempty");
    *pixmap = pixmap->scaled(width, height);
    pixmapTextField.append(pixmap);

    pixmap = new QPixmap(":/images/nameempty");
    *pixmap = pixmap->scaled(width, height);
    pixmapTextField.append(pixmap);

    pixmap = new QPixmap(":/images/nameempty");
    *pixmap = pixmap->scaled(width, height);
    pixmapTextField.append(pixmap);


}
textField::~textField(){
    qDeleteAll(pixmapTextField);

}
void textField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(*pixmapTextField.at(index));
    painter->drawRect(boundingRect());

    QStyleOptionGraphicsItem newOption(*option);
    newOption.state = QStyle::State_None;
    QGraphicsTextItem::paint(painter, &newOption, widget);
}

QRectF textField::boundingRect() const {
    auto rect = QGraphicsTextItem::boundingRect();
    rect.setWidth(width);
    rect.setHeight(height);
    return rect;
}
