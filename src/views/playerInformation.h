#ifndef PROJECT_PLAYERINFORMATION_H
#define PROJECT_PLAYERINFORMATION_H


#include <QGraphicsPixmapItem>

class playerInformation : public QGraphicsPixmapItem {
public:
    void remove();

    playerInformation(int index, int life, int width);
};


#endif //PROJECT_PLAYERINFORMATION_H
