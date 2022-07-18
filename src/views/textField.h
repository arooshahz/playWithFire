#ifndef TESTPRO_TEXTFIELD_H
#define TESTPRO_TEXTFIELD_H

#include <QGraphicsTextItem>

class textField : public QGraphicsTextItem {

private:
    int width{};
    int height{};
public :
    textField(int width, int height);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif //TESTPRO_TEXTFIELD_H
