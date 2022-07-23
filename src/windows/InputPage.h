#ifndef PROJECT_INPUTPAGE_H
#define PROJECT_INPUTPAGE_H


#include <QGraphicsView>
#include "../views/textField.h"

class InputPage : public QGraphicsView {
private:
    QGraphicsScene *playBackgroundScene;
    textField *textfieldName1;
    textField *textfieldName2;
    textField *textfieldLifeCount;
    textField *textfieldBombRadius;


public:
    InputPage();

    ~InputPage();

    void onGameStart();

    void WriteNamesToFile();

    void WriteInfoToFile();
};


#endif //PROJECT_INPUTPAGE_H
