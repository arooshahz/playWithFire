#include "Controller.h"
#include "Bomb.h"

typedef std::pair<int,int> pii;

Controller::Controller(Game *game) : game(game) {
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    setFocus();


    newXPlayer[0] = game->getPlayers().at(0)->getX();
    newYPlayer[0] = game->getPlayers().at(0)->getY();
    newXPlayer[1] = game->getPlayers().at(1)->getX();
    newYPlayer[1] = game->getPlayers().at(1)->getY();
    playerWidth = game->getPlayers().at(0)->boundingRect().width();
    playerHeight = game->getPlayers().at(0)->boundingRect().height();


}

void Controller::keyPressEvent(QKeyEvent *event) {
    QGraphicsItem::keyPressEvent(event);
    QGraphicsItem::keyPressEvent(event);
    int F = -1, dir = 1;
    if (event->key() == Qt::Key::Key_Down) {
        newYPlayer[0] = game->getPlayers().at(0)->y() + 15;
        F = 0;
    }

    if (event->key() == Qt::Key::Key_Up) {
        newYPlayer[0] = game->getPlayers().at(0)->y() - 15;
        F = 0;
        dir = -1;
    }

    if (event->key() == Qt::Key::Key_Left) {
        newXPlayer[0] = game->getPlayers().at(0)->x() - 15;
        F = 0;
        dir = -1;
    }

    if (event->key() == Qt::Key::Key_Right) {
        newXPlayer[0] = game->getPlayers().at(0)->x() + 15;
        F = 0;
    }
    if (event->key() == Qt::Key::Key_Return) {
        auto bomb = new Bomb(game->getPlayers().at(0)->x(), game->getPlayers().at(0)->y(), 0, game);
        game->scene()->addItem(bomb);
        bomb->setPos(game->getPlayers().at(0)->x(), game->getPlayers().at(0)->y());
    }


    if (event->key() == Qt::Key::Key_S) {
        newYPlayer[1] = game->getPlayers().at(1)->y() + 15;
        F = 1;
    }

    if (event->key() == Qt::Key::Key_W) {
        newYPlayer[1] = game->getPlayers().at(1)->y() - 15;
        dir = -1;
        F = 1;
    }

    if (event->key() == Qt::Key::Key_A) {
        newXPlayer[1] = game->getPlayers().at(1)->x() - 15;
        dir = -1;
        F = 1;
    }

    if (event->key() == Qt::Key::Key_D) {
        newXPlayer[1] = game->getPlayers().at(1)->x() + 15;
        F = 1;
    }
    if (event->key() == Qt::Key::Key_Space) {
        auto bomb = new Bomb(game->getPlayers().at(1)->x(), game->getPlayers().at(1)->y(), 1, game);
        game->scene()->addItem(bomb);
        bomb->setPos(game->getPlayers().at(1)->x(), game->getPlayers().at(1)->y());
    }
    if (F == 0 or F == 1)
        movementPlayer(F, dir);

}

void Controller::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

}

QRectF Controller::boundingRect() const {
    return QRectF();
}

void Controller::movementPlayer(int index, int dir) {
    pii pos;
    if (dir == -1){
        pos = findPlayerPos(newXPlayer[index], newYPlayer[index]);
    }
    else {
        pos = findPlayerPos(newXPlayer[index] + playerWidth, newYPlayer[index] + playerHeight);
    }
    int a = pos.first, b = pos.second;
    if (game->getBlocked(a, b)){
        qInfo() << a << b << "blocked";
        return;
    }
    game->getPlayers().at(index)->movement(newXPlayer[index], newYPlayer[index]);
}

pii Controller::findPlayerPos(int x, int y){
    pii pos;
    pos.first = x / Block::getBlockWidth();
    pos.second = y / Block::getBlockHeight();
    return pos;
}