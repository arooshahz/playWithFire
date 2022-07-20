#ifndef PROJECT_CONTROLLER_H
#define PROJECT_CONTROLLER_H

#include <QGraphicsItem>
#include <QKeyEvent>

#include "../windows/Game.h"


class Controller : public QGraphicsItem {
private:
    Game *game{};
    int newXPlayer[2];
    int newYPlayer[2];
    int playerWidth;
    int playerHeight;


public:
    Controller(Game *game);

    void movementPlayer(int, int);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;





protected:
    void keyPressEvent(QKeyEvent *event) override;


    std::pair<int, int> findPlayerPos(int x, int y);
};


#endif //PROJECT_CONTROLLER_H
