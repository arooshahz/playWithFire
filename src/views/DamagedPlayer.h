#ifndef PROJECT_DAMAGEDPLAYER_H
#define PROJECT_DAMAGEDPLAYER_H

#include <QGraphicsPixmapItem>
#include<QPropertyAnimation>
#include <QObject>
#include <QTimer>

class DamagedPlayer : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
    Q_PROPERTY(qreal height READ y WRITE setY);


private:
    QPropertyAnimation *heightAnimator;
    QTimer *removeDamagedPlayerTimer;
    int X;
    int Y;
    int index;

public:
    DamagedPlayer(int X, int Y, int index, QGraphicsPathItem *parent = nullptr);

    ~DamagedPlayer();

    void movement();

    void removeDamagedPlayer();
};


#endif //PROJECT_DAMAGEDPLAYER_H
