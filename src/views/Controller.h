#ifndef PROJECT_CONTROLLER_H
#define PROJECT_CONTROLLER_H

#include <QGraphicsItem>
#include <QKeyEvent>

#include "../windows/Game.h"



class Controller : public QGraphicsItem{
private:
    Game* game{};
public:
    Controller(Game* game);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;

protected:
    void keyPressEvent(QKeyEvent *event) override;


};


#endif //PROJECT_CONTROLLER_H
