#ifndef PROJECT_CONTROLLER_H
#define PROJECT_CONTROLLER_H

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QObject>
#include "../windows/Game.h"


class Controller : public QObject,public QGraphicsItem {
Q_OBJECT
private:
    Game *game{};
    int newXPlayer[2];
    int newYPlayer[2];
    int playerWidth;
protected:
    void keyReleaseEvent(QKeyEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    int playerHeight;
    QSet<int> pressedKeys{};

//    protected:
//    bool eventFilter(QObject * obj, QEvent * event);



public:
    Controller(Game *game);

    void movementPlayer(int);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;
};


#endif //PROJECT_CONTROLLER_H
