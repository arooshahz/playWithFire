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
    setBackgroundBrush(QPixmap(":/images/wallpaper2"));
    setScene(playBackgroundScene);

    QFile file("names.txt");
    QString names[2] = {"", ""};
    int cnt = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            names[cnt++] = in.readLine();
        }
    }

    auto label1 = new Label();
    label1->setPlainText("player1 :");
    playBackgroundScene->addItem(label1);
    label1->setPos(width() / 2 - 300, height() / 2 - label1->boundingRect().height() + 50);


    textfield1 = new textField(250, 50);
    textfield1->setPlainText(names[0]);
    playBackgroundScene->addItem(textfield1);
    textfield1->setPos(width() / 2 - 300, height() / 2 + 50);



    auto label2 = new Label();
    label2->setPlainText("player2 :");
    playBackgroundScene->addItem(label2);
    label2->setPos(width() / 2 + 100, height() / 2 - label2->boundingRect().height() + 50);

    textfield2 = new textField(250, 50);
    textfield2->setPlainText(names[1]);
    playBackgroundScene->addItem(textfield2);
    textfield2->setPos(width() / 2 + 100, height() / 2 + 50);

    //lifeCount
    textfield3 = new textField(250, 50);
    textfield3->setPlainText("");
    playBackgroundScene->addItem(textfield3);
    textfield3->setPos(width() / 2 -100, height() / 2 + 150);

    auto button = new Button(200, 50);
    button->setPlainText("      Start Game");
    playBackgroundScene->addItem(button);
    button->setPos((width() / 2) - 75, height() / 2 + button->boundingRect().height() + 225);

    connect(button, &Button::onPress, this, &InputPage::onGameStart);
}

void InputPage::onGameStart() {
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