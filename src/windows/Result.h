#ifndef PROJECT_RESULT_H
#define PROJECT_RESULT_H

#include <QGraphicsView>
#include "Game.h"

class Result : public QGraphicsView {
private:
    Game *game;
    int indexOfWinnerPlayer;
public:
    Result(Game *game);

    void chooseWinner();
};


#endif //PROJECT_RESULT_H
