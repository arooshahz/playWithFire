#include "Controller.h"
#include "Bomb.h"

Controller::Controller(Game* game) : game(game){
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    setFocus();


    newXPlayer1= game->getPlayers().at(0)->getX();
    newYPlayer1=  game->getPlayers().at(0)->getY();
    newXPlayer2= game->getPlayers().at(1)->getX();
    newYPlayer2=  game->getPlayers().at(1)->getY();
    playerWidth=game->getPlayers().at(0)->boundingRect().width();
    playerHeight=game->getPlayers().at(0)->boundingRect().height();



}
void Controller::keyPressEvent(QKeyEvent *event) {
    QGraphicsItem::keyPressEvent(event);
        QGraphicsItem::keyPressEvent(event);
    if(event->key()==Qt::Key::Key_Down){
newYPlayer1=game->getPlayers().at(0)->y()+15;
}

    if(event->key()==Qt::Key::Key_Up){
newYPlayer1=game->getPlayers().at(0)->y()-15;
    }

    if(event->key()==Qt::Key::Key_Left){
        newXPlayer1=game->getPlayers().at(0)->x()-15;
    }

    if(event->key()==Qt::Key::Key_Right){
        newXPlayer1=game->getPlayers().at(0)->x()+15;
    }
    if(event->key()==Qt::Key::Key_Return){
        auto bomb=new Bomb(game->getPlayers().at(0)->x(),game->getPlayers().at(0)->y(),0,game);
        game->scene()->addItem(bomb);
        bomb->setPos(game->getPlayers().at(0)->x(),game->getPlayers().at(0)->y());
    }




    if(event->key()==Qt::Key::Key_S){
        newYPlayer2=game->getPlayers().at(1)->y()+15;
    }

    if(event->key()==Qt::Key::Key_W){
        newYPlayer2=game->getPlayers().at(1)->y()-15;
    }

    if(event->key()==Qt::Key::Key_A){
        newXPlayer2=game->getPlayers().at(1)->x()-15;
    }

    if(event->key()==Qt::Key::Key_D){
        newXPlayer2=game->getPlayers().at(1)->x()+15;
    }
    if(event->key()==Qt::Key::Key_Space){
        auto bomb=new Bomb(game->getPlayers().at(1)->x(),game->getPlayers().at(1)->y(),1,game);
        game->scene()->addItem(bomb);
        bomb->setPos(game->getPlayers().at(1)->x(),game->getPlayers().at(1)->y());
    }


        for (const auto block: *game->getBlocks()) {
            if (block->x() < newXPlayer1 && block->x() + block->boundingRect().width() > newXPlayer1
                && block->y() < newYPlayer1 && block->y() + block->boundingRect().height() > newYPlayer1)
                return;
            if (block->x() < newXPlayer1 + playerWidth &&
                block->x() + block->boundingRect().width() > newXPlayer1 + playerWidth
                && block->y() < newYPlayer1 && block->y() + block->boundingRect().height() > newYPlayer1)
                return;
            if (block->x() < newXPlayer1 + playerWidth &&
                block->x() + block->boundingRect().width() > newXPlayer1 + playerWidth
                && block->y() < newYPlayer1 + playerHeight &&
                block->y() + block->boundingRect().height() > newYPlayer1 + playerHeight)
                return;
            if (block->x() < newXPlayer1 && block->x() + block->boundingRect().width() > newXPlayer1
                && block->y() < newYPlayer1 + playerHeight &&
                block->y() + block->boundingRect().height() > newYPlayer1 + playerHeight)
                return;
        }
        game->getPlayers().at(0)->movement(newXPlayer1, newYPlayer1);




        for (const auto block: *game->getBlocks()) {
            if (block->x() < newXPlayer2 && block->x() + block->boundingRect().width() > newXPlayer2
                && block->y() < newYPlayer2 && block->y() + block->boundingRect().height() > newYPlayer2)
                return;
            if (block->x() < newXPlayer2 + playerWidth &&
                block->x() + block->boundingRect().width() > newXPlayer2 + playerWidth
                && block->y() < newYPlayer2 && block->y() + block->boundingRect().height() > newYPlayer2)
                return;
            if (block->x() < newXPlayer2 + playerWidth &&
                block->x() + block->boundingRect().width() > newXPlayer2 + playerWidth
                && block->y() < newYPlayer2 + playerHeight &&
                block->y() + block->boundingRect().height() > newYPlayer2 + playerHeight)
                return;
            if (block->x() < newXPlayer2 && block->x() + block->boundingRect().width() > newXPlayer2
                && block->y() < newYPlayer2 + playerHeight &&
                block->y() + block->boundingRect().height() > newYPlayer2 + playerHeight)
                return;
        }
        game->getPlayers().at(1)->movement(newXPlayer2, newYPlayer2);



}
void Controller::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

}

QRectF Controller::boundingRect() const {
    return QRectF();
}
