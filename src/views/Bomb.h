#ifndef PROJECT_BOMB_H
#define PROJECT_BOMB_H
#include<QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
class Bomb :public QObject,public QGraphicsPixmapItem{
Q_OBJECT



public:
    Bomb(int X, int Y, QGraphicsPathItem *parent= nullptr);

public slots:
    void removeBomb();
    void animateBomb();
private:
    int frame={};
    int X{};
    int Y{};
    int explodeTime;
    QList<QPixmap*>frames{};
    QTimer *animateBombTimer;
    QTimer *removeBombTimer;
};


#endif //PROJECT_BOMB_H
