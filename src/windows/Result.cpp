#include <QFile>
#include "Result.h"
#include "../views/Label.h"

Result::Result(Game *game) : game(game) {

    QFile file("names.txt");
    QString names[2] = {"", ""};
    int cnt = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            names[cnt++] = in.readLine();
        }
    }

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, width(), height());
    setBackgroundBrush(QColor("#2c2721"));
    setScene(scene);

    chooseWinner();


    auto label1 = new Label();
    label1->setPlainText(names[0] + " score:");
    scene->addItem(label1);
    label1->setPos(width() / 2 - 100, height() / 2 - label1->boundingRect().height() + 100);


    QString scores1 = QString::number(*game->getPlayers().at(0)->getScore());
    auto labelScores1 = new Label();
    labelScores1->setPlainText(scores1);
    scene->addItem(labelScores1);
    labelScores1->setPos(width() / 2 - 100 + label1->boundingRect().width(),
                         height() / 2 - label1->boundingRect().height() + 100);


    auto label2 = new Label();
    label2->setPlainText(names[1] + " score:");
    scene->addItem(label2);
    label2->setPos(width() / 2 - 100, height() / 2 - label2->boundingRect().height() + 200);


    QString scores2 = QString::number(*game->getPlayers().at(1)->getScore());
    auto labelScores2 = new Label();
    labelScores2->setPlainText(scores2);
    scene->addItem(labelScores2);
    labelScores2->setPos(width() / 2 - 100 + label2->boundingRect().width(),
                         height() / 2 - label2->boundingRect().height() + 200);
}

void Result::chooseWinner() {

    QFile file("names.txt");
    QString names[2] = {"", ""};
    int cnt = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            names[cnt++] = in.readLine();
        }
    }

    if (*game->getPlayers().at(1)->getScore() > *game->getPlayers().at(0)->getScore()) {
        indexOfWinnerPlayer = 1;
    } else if (*game->getPlayers().at(1)->getScore() < *game->getPlayers().at(0)->getScore()) {
        indexOfWinnerPlayer = 0;
    } else { indexOfWinnerPlayer = -1; }

    auto winnerLabel = new Label();
    winnerLabel->setPlainText("Winner:");
    this->scene()->addItem(winnerLabel);
    winnerLabel->setPos(width() / 2 - 100, height() / 2 - 300);

    if (indexOfWinnerPlayer == 0) {
        auto label = new Label();
        label->setPlainText(names[0]);
        this->scene()->addItem(label);
        label->setPos(width() / 2 - 100 + winnerLabel->boundingRect().width(), height() / 2 - 300);
    } else if (indexOfWinnerPlayer == 1) {
        auto label = new Label();
        label->setPlainText(names[1]);
        this->scene()->addItem(label);
        label->setPos(width() / 2 - 100 + winnerLabel->boundingRect().width(), height() / 2 - 300);
    }

}