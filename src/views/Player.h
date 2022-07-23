#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include<QPropertyAnimation>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>


class Player : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
    Q_PROPERTY(qreal height READ y WRITE setY);
    Q_PROPERTY(qreal width READ x WRITE setX)

private:
    QString name;
    int X{};
    int Y{};
    int frame{};
    int lifeCount{};
    int score{};
    QList<QPixmap *> frames{};
    QPropertyAnimation *heightAnimator{};
    QPropertyAnimation *widthAnimator{};
    QTimer *walkingTimer{};
    int speed{};
    int bombRadius{};
    int bombCount{};
    bool bombLimitation{false};
    QGraphicsScene *scene;

    static int toInteger(QString s);

public:
    Player(int X, int Y, QList<QPixmap *> frames, QGraphicsScene *scene, QGraphicsPathItem *parent = nullptr);

    ~Player();

    void walking();

    void movement(int newX, int newY);

    int getX();

    int getY();

    int *getScore();

    int *getLifeCount();

    int getBombRadius();

    void setBombRadius(int bombRadius);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    int getBombCount();

    void setBomCount(int bombCount);

    bool getBombLimitation();

    void setBombLimitation(bool bombLimitation);

    void setSpeed(int speed);

    int getSpeed();




};


#endif //PROJECT_PLAYER_H
