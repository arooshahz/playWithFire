#ifndef TESTPRO_HOME_H
#define TESTPRO_HOME_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "../views/textField.h"
#include <QObject>

class Home : public QGraphicsView {
Q_OBJECT
private:
    textField *textfield1;
    textField *textfield2;
    textField *textfield3;
public:
    Home();

public slots:

    void onGameStart();
};


#endif //TESTPRO_HOME_H
