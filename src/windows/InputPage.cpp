#include <QFile>
#include "InputPage.h"
#include "../views/Controller.h"
#include "../views/Button.h"

InputPage::InputPage() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    setFrameShape(NoFrame);

    playBackgroundScene = new QGraphicsScene(this);
    playBackgroundScene->setSceneRect(0, 0, width(), height());
    auto pixmap = new QPixmap(":/images/wallpaper2");
    *pixmap = pixmap->scaled(width(), height(), Qt::IgnoreAspectRatio);
    setBackgroundBrush(*pixmap);
    setScene(playBackgroundScene);

//
//    QFile file("names.txt");
    QString names[2] = {"", ""};
//    int num = 0;
//    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        QTextStream in(&file);
//        while (!in.atEnd()) {
//            names[num++] = in.readLine();
//        }
//    }

//    auto label1 = new Label();
//    label1->setPlainText("player1 :");
//    playBackgroundScene->addItem(label1);
//    label1->setPos(width() / 2 - 300, height() / 2 - label1->boundingRect().height() + 50);


    textfieldName1 = new textField(450, 130,0);
    textfieldName1->setPlainText("                      "+names[0]);
    playBackgroundScene->addItem(textfieldName1);
    textfieldName1->setPos(60, height() / 2 - 300);



//    auto label2 = new Label();
//    label2->setPlainText("player2 :");
//    playBackgroundScene->addItem(label2);
//    label2->setPos(width() / 2 + 100, height() / 2 - label2->boundingRect().height() + 50);

    textfieldName2 = new textField(450, 130,1);
    textfieldName2->setPlainText("             "+names[1]);
    playBackgroundScene->addItem(textfieldName2);
    textfieldName2->setPos(width() -textfieldName2->boundingRect().width()-60,height() / 2 - 300);



    textfieldBombRadius = new textField(70, 70,2);
    textfieldBombRadius->setPlainText("  ");
    playBackgroundScene->addItem(textfieldBombRadius);
    textfieldBombRadius->setPos(width() -textfieldName2->boundingRect().width()-200, height() / 2 - 320);



    textfieldLifeCount = new textField(70, 70,2);
    textfieldLifeCount->setPlainText("  ");
    playBackgroundScene->addItem(textfieldLifeCount);
    textfieldLifeCount->setPos(width() -textfieldName2->boundingRect().width()-200, height() / 2 +20+textfieldBombRadius->boundingRect().height()- 320);










    auto button = new Button(200, 200);
//    button->setPlainText("      Start Game");
    playBackgroundScene->addItem(button);
    button->setPos((width() / 2) - 75, height() / 2 + button->boundingRect().height() -200);

    connect(button, &Button::onPress, this, &InputPage::onGameStart);
}

void InputPage::onGameStart() {
    auto name1 = textfieldName1->toPlainText();
    auto name2 = textfieldName2->toPlainText();
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