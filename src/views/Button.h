#ifndef TEST3_BUTTON_H
#define TEST3_BUTTON_H
#include <QGraphicsPixmapItem>

#include <QObject>

class Button :public QObject,  public QGraphicsPixmapItem {
Q_OBJECT
private:
    int width{};
    int height{};
public:
    Button(int width, int height, QGraphicsPathItem *parent= nullptr);
//
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:

    void onPress();
};


#endif //TEST3_BUTTON_H