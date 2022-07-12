#include "Controller.h"
Controller::Controller(Game* game) : game(game){
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    setFocus();

}
void Controller::keyPressEvent(QKeyEvent *event) {
    QGraphicsItem::keyPressEvent(event);
        QGraphicsItem::keyPressEvent(event);
    if(event->key()==Qt::Key::Key_Down){
        game->getPlayers().at(0)->walkingDown();
    }
    if(event->key()==Qt::Key::Key_Up){
        game->getPlayers().at(0)->walkedUp();
    }

    if(event->key()==Qt::Key::Key_Left){
        game->getPlayers().at(0)->walkedLeft();
    }

    if(event->key()==Qt::Key::Key_Right){
        game->getPlayers().at(0)->walkedRight();
    }

    if(event->key()==Qt::Key::Key_S){
        game->getPlayers().at(1)->walkingDown();
    }
    if(event->key()==Qt::Key::Key_W){
        game->getPlayers().at(1)->walkedUp();
    }

    if(event->key()==Qt::Key::Key_A){
        game->getPlayers().at(1)->walkedLeft();
    }

    if(event->key()==Qt::Key::Key_D){
        game->getPlayers().at(1)->walkedRight();
    }

}
void Controller::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

}

QRectF Controller::boundingRect() const {
    return QRectF();
}
