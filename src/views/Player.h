#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H
#include <QGraphicsPixmapItem>
#include<QPropertyAnimation>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>
class Player :public  QObject,public QGraphicsPixmapItem{
    Q_OBJECT
    Q_PROPERTY(qreal height READ y WRITE setY);
    Q_PROPERTY(qreal width READ x WRITE setX)

private:
    QString name;
    int X{};
    int Y{};
    int frame{};
    int lifeCount{};
    QList<QPixmap*>frames{};
    QPropertyAnimation *heightAnimator;
    QPropertyAnimation *widthAnimator;
    QTimer* walkingTimer;

public:
    Player(int X,int Y, QList <QPixmap*>frames,QGraphicsPathItem* parent= nullptr);


    void walking();
    void movement(int newX,int newY);
    int getX();
    int getY();



};


#endif //PROJECT_PLAYER_H
