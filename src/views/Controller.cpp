#include "Controller.h"
#include "Bomb.h"

typedef std::pair<int, int> pii;

Controller::Controller(Game *game) : game(game) {
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    setFocus();
    for (int i = 0; i < 2; i++) {
        newXPlayer[i] = game->getPlayers().at(i)->x();
        newYPlayer[i] = game->getPlayers().at(i)->y();
    }
    playerWidth = game->getPlayers().at(0)->boundingRect().width();
    playerHeight = game->getPlayers().at(0)->boundingRect().height();

    this->installEventFilter(this);
}

void Controller::keyPressEvent(QKeyEvent *event) {
    playerWidth = game->getPlayers().at(0)->boundingRect().width();
    playerHeight = game->getPlayers().at(0)->boundingRect().height();
    QGraphicsItem::keyPressEvent(event);
    for (int i = 0; i < 2; i++) {
        newXPlayer[i] = game->getPlayers().at(i)->x();
        newYPlayer[i] = game->getPlayers().at(i)->y();
    }
    if (event->type() == QEvent::KeyPress) {
        pressedKeys += event->key();
        if (pressedKeys.contains(Qt::Key_Down)) {
            newYPlayer[0] = game->getPlayers().at(0)->y() + 15;
//            pii pos = game->findPos(newXPlayer[0], newYPlayer[0] + playerHeight);
            movementPlayer(0);
        }

        if (pressedKeys.contains(Qt::Key_Up)) {
            newYPlayer[0] = game->getPlayers().at(0)->y() - 15;
//            pii pos = game->findPos(newXPlayer[0], newYPlayer[0]);
            movementPlayer(0);
        }

        if (pressedKeys.contains(Qt::Key_Left)) {
            newXPlayer[0] = game->getPlayers().at(0)->x() - 15;
            pii pos = game->findPos(newXPlayer[0], newYPlayer[0]);
            movementPlayer(0);
        }

        if (pressedKeys.contains(Qt::Key_Right)) {
            newXPlayer[0] = game->getPlayers().at(0)->x() + 15;
            pii pos = game->findPos(newXPlayer[0] + playerWidth, newYPlayer[0]);
            movementPlayer(0);
        }
        if (pressedKeys.contains(Qt::Key_Return)) {
            int bombCount=game->getPlayers().at(0)->getBombCount();
            if(bombCount > 0 && game->getPlayers().at(0)->getBombLimitation()== 0) {
                auto bomb = new Bomb(game->getPlayers().at(0)->x(), game->getPlayers().at(0)->y(), 0, game);
                game->scene()->addItem(bomb);
                bomb->setPos(game->getPlayers().at(0)->x(), game->getPlayers().at(0)->y());
                game->getPlayers().at(0)->setBombLimitation(1);
                game->getPlayers().at(0)->setBomCount(--bombCount);
            }

        }


        if (pressedKeys.contains(Qt::Key_S)) {
            newYPlayer[1] = game->getPlayers().at(1)->y() + 15;
            pii pos = game->findPos(newXPlayer[1], newYPlayer[1] + playerHeight);
            movementPlayer(1);
        }

        if (pressedKeys.contains(Qt::Key_W)) {
            newYPlayer[1] = game->getPlayers().at(1)->y() - 15;
            pii pos = game->findPos(newXPlayer[1], newYPlayer[1]);
            movementPlayer(1);
        }

        if (pressedKeys.contains(Qt::Key_A)) {
            newXPlayer[1] = game->getPlayers().at(1)->x() - 15;
            pii pos = game->findPos(newXPlayer[1], newYPlayer[1]);
            movementPlayer(1);
        }

        if (pressedKeys.contains(Qt::Key_D)) {
            newXPlayer[1] = game->getPlayers().at(1)->x() + 15;
            pii pos = game->findPos(newXPlayer[0] + playerWidth, newYPlayer[0]);
            movementPlayer(1);
        }
        if (pressedKeys.contains(Qt::Key_Space)) {
            int bombCount=game->getPlayers().at(1)->getBombCount();
            if(bombCount > 0 && game->getPlayers().at(1)->getBombLimitation()==0) {
                auto bomb = new Bomb(game->getPlayers().at(1)->x(), game->getPlayers().at(1)->y(), 1, game);
                game->scene()->addItem(bomb);
                bomb->setPos(game->getPlayers().at(1)->x(), game->getPlayers().at(1)->y());
                game->getPlayers().at(1)->setBombLimitation(1);
                game->getPlayers().at(1)->setBomCount(--bombCount);
            }
        }
    }

}

void Controller::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

}

QRectF Controller::boundingRect() const {
    return QRectF();
}


void Controller::movementPlayer(int index) {
    int x[2] = {newXPlayer[index], newXPlayer[index] + playerWidth}, y[2] = {newYPlayer[index], newYPlayer[index] + playerHeight};
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            pii pos = game->findPos(x[i], y[j]);
            if (game->getBlocked(pos.first, pos.second)){
                qInfo() << pos.first << pos.second << "blocked";
                return;
            }
        }
    }
    game->getPlayers().at(index)->movement(newXPlayer[index], newYPlayer[index]);
}

void Controller::keyReleaseEvent(QKeyEvent *event) {
    QGraphicsItem::keyReleaseEvent(event);
    if (event->type() == QEvent::KeyRelease) {
        pressedKeys -= event->key();
    }
}

