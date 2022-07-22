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
    auto pixmap=new QPixmap(":/images/wallpaper");
    *pixmap=pixmap->scaled(width(),height(),Qt::IgnoreAspectRatio);
    setBackgroundBrush(QPixmap(*pixmap));
    setScene(scene);


    QFile file("names.txt");
    QString names[2] = {"", ""};
    int cnt = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            names[cnt++] = in.readLine();
        }
    }

//    auto label1 = new Label();
//    label1->setPlainText("player1 :");
//    scene->addItem(label1);
//    label1->setPos(width() / 2 - 300, height() / 2 - label1->boundingRect().height() + 50);
//
//
//    textfield1 = new textField(250, 50);
//    textfield1->setPlainText(names[0]);
//    scene->addItem(textfield1);
//    textfield1->setPos(width() / 2 - 300, height() / 2 + 50);
//


//    auto label2 = new Label();
//    label2->setPlainText("player2 :");
//    scene->addItem(label2);
//    label2->setPos(width() / 2 + 100, height() / 2 - label2->boundingRect().height() + 50);
//
//    textfield2 = new textField(250, 50);
//    textfield2->setPlainText(names[1]);
//    scene->addItem(textfield2);
//    textfield2->setPos(width() / 2 + 100, height() / 2 + 50);
//
//    //lifeCount
//    textfield3 = new textField(250, 50);
//    textfield3->setPlainText("");
//    scene->addItem(textfield3);
//    textfield3->setPos(width() / 2 -100, height() / 2 + 150);

    auto button = new Button(300, 700);
    button->setPlainText("");
    scene->addItem(button);
    button->setPos((width() / 2) - 75, height() / 2  );

    connect(button, &Button::onPress, this, &Home::onGameStart);
}

void Home::onGameStart() {

//    auto name1 = textfield1->toPlainText();
//    auto name2 = textfield2->toPlainText();
//    QFile file("names.txt");
//    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//        QTextStream out(&file);
//        out << name1 + '\n' + name2;
//        file.close();
//    }

    close();
    auto game=new Game();
    game->show();
}