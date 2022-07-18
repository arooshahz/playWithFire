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
public:
    Home();

public slots:

    void onGAmeStart();
};


#endif //TESTPRO_HOME_H
