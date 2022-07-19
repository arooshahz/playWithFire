#include <QFile>
#include "Home.h"
#include "../views/label.h"
#include "../views/Button.h"
#include "Game.h"

Home::Home() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    setFrameShape(NoFrame);

    auto scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, width(), height());
    setBackgroundBrush(QColor("#2c2721"));
    setScene(scene);


    QPixmap pixmap(":/images/playWithFire");
    pixmap = pixmap.scaled(495, 380);


    scene->addRect(QRect(500, 10, 510, 370),
                   QPen(Qt::NoPen), QPixmap(pixmap));


    QFile file("names.txt");
    QString names[2] = {"", ""};
    int cnt = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            names[cnt++] = in.readLine();
        }
    }
    textfield1 = new textField(250, 50);
    textfield1->setPlainText(names[0]);
    scene->addItem(textfield1);
    textfield1->setPos(width() / 2 - 100, height() / 2 + 100);


    auto label1 = new Label();
    label1->setPlainText("player1 :");
    scene->addItem(label1);
    label1->setPos(width() / 2 - 100, height() / 2 - label1->boundingRect().height() + 100);

    textfield2 = new textField(250, 50);
    textfield2->setPlainText(names[1]);
    scene->addItem(textfield2);
    textfield2->setPos(width() / 2 - 100, height() / 2 + 200);


    auto label2 = new Label();
    label2->setPlainText("player2 :");
    scene->addItem(label2);
    label2->setPos(width() / 2 - 100, height() / 2 - label2->boundingRect().height() + 200);


    auto button = new Button(200, 50);
    button->setPlainText("      Start Game");
    scene->addItem(button);
    button->setPos((width() / 2) - 75, height() / 2 + button->boundingRect().height() + 225);

    connect(button, &Button::onPress, this, &Home::onGameStart);
}

void Home::onGameStart() {

    auto name1 = textfield1->toPlainText();
    auto name2 = textfield2->toPlainText();
    QFile file("names.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << name1 + '\n' + name2;
        file.close();
    }

    close();
    auto game=new Game();
    game->show();
}