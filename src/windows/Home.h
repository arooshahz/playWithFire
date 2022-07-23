#ifndef TESTPRO_HOME_H
#define TESTPRO_HOME_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "../views/textField.h"
#include <QObject>

class Home : public QGraphicsView {
Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    textField *textfield1;
    textField *textfield2;
    textField *textfield3;

public:
    Home();

    ~Home();
};


#endif //TESTPRO_HOME_H
