#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H
#include <QGraphicsPixmapItem>
#include<QPropertyAnimation>
#include <QObject>
#include <QKeyEvent>
class Player :public  QObject,public QGraphicsPixmapItem{
    Q_OBJECT
    Q_PROPERTY(qreal height READ y WRITE setY);
    Q_PROPERTY(qreal width READ x WRITE setX)

private:
    QString name;
    int X{};
    int Y{};
    int frame{};
    QList<QPixmap*>frames{};
    QPropertyAnimation *heightAnimator;
    QPropertyAnimation *widthAnimator;

public:
    Player(int sceneWidth,int sceneHeight, QList <QPixmap*>frames,QGraphicsPathItem* parent= nullptr);
    void walkingDown();
    void walkedUp();
    void walkedLeft();
    void walkedRight();

//protected:
//    void keyPressEvent(QKeyEvent *event) override;








};


#endif //PROJECT_PLAYER_H
