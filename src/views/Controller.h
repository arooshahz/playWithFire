#ifndef PROJECT_CONTROLLER_H
#define PROJECT_CONTROLLER_H

#include <QGraphicsItem>
#include <QKeyEvent>

#include "../windows/Game.h"



class Controller : public QGraphicsItem{
private:
    Game* game{};
    int newXPlayer1;
    int newYPlayer1;
    int newXPlayer2;
    int newYPlayer2;
    int playerWidth;
    int playerHeight;



public:
    Controller(Game* game);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;

protected:
    void keyPressEvent(QKeyEvent *event) override;


};


#endif //PROJECT_CONTROLLER_H
