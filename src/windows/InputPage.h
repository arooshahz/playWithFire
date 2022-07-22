#ifndef PROJECT_INPUTPAGE_H
#define PROJECT_INPUTPAGE_H


#include <QGraphicsView>
#include "../views/textField.h"

class InputPage: public QGraphicsView {
private:
    QGraphicsScene *playBackgroundScene;
    textField *textfield1;
    textField *textfield2;
    textField *textfield3;

public:
    InputPage();

    void onGameStart();
};


#endif //PROJECT_INPUTPAGE_H
