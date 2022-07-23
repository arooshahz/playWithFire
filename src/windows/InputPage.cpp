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


    QFile file("names.txt");
    QString names[2] = {"", ""};
    int num = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            names[num++] = in.readLine();
        }
    }

    double w = width(), h = height();
    textfieldName1 = new textField(w / 4.2, h / 12.5, 0);
    textfieldName1->setPlainText(names[0]);
    playBackgroundScene->addItem(textfieldName1);
    textfieldName1->setPos(w / 8, h / 5.5);

    textfieldName2 = new textField(w / 4.8, h / 12.5, 1);
    textfieldName2->setPlainText(names[1]);
    playBackgroundScene->addItem(textfieldName2);
    textfieldName2->setPos(w - textfieldName2->boundingRect().width() - w / 8, h / 5.5);

    WriteNamesToFile();

    QFile file2("info.txt");
    QString info[2] = {"3", "3"};
    int cnt = 0;
    if (file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file2);
        while (!in.atEnd()) {
            info[cnt++] = in.readLine();
        }
    }

    textfieldBombRadius = new textField(w / 28.1, w / 28, 2);
    textfieldBombRadius->setPlainText(info[0]);
    playBackgroundScene->addItem(textfieldBombRadius);
    textfieldBombRadius->setPos(w - textfieldName2->boundingRect().width() - w / 4.2, h / 6.6);

    textfieldLifeCount = new textField(w / 28.1, w / 28, 2);
    textfieldLifeCount->setPlainText(info[1]);
    playBackgroundScene->addItem(textfieldLifeCount);
    textfieldLifeCount->setPos(w - textfieldName2->boundingRect().width() - w / 4.2,
                               (h / 5.3) + textfieldBombRadius->boundingRect().height());

    auto button = new Button(((width() / 2) - (width() / 20)) / 3.5, ((width() / 2) - (width() / 20)) / 3.5);
    playBackgroundScene->addItem(button);
    button->setPos((width() / 2) - (width() / 20), height() / 2 + button->boundingRect().height() - height() / 6);

    connect(button, &Button::onPress, this, &InputPage::onGameStart);
}

void InputPage::onGameStart() {
    QList<QString> available = {"1", "2", "3", "4", "5", "6"};
    if (available.contains(textfieldLifeCount->toPlainText())) {
        WriteNamesToFile();
        WriteInfoToFile();
        close();
        auto game = new Game();
        game->show();
    } else {
        this->close();
        auto inputPage = new InputPage();
        inputPage->show();
    }
}

void InputPage::WriteNamesToFile() {
    auto name1 = textfieldName1->toPlainText();
    auto name2 = textfieldName2->toPlainText();
    QFile file("names.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << name1 + '\n' + name2;
        file.close();
    }
}

void InputPage::WriteInfoToFile() {
    auto bombradius = textfieldBombRadius->toPlainText();
    auto lifeCounter = textfieldLifeCount->toPlainText();
    QFile file("info.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << bombradius + '\n' + lifeCounter;
        file.close();
    }
}