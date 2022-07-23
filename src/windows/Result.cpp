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
    setFrameShape(NoFrame);
    chooseWinner();

    auto scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, width(), height());
    if (indexOfWinnerPlayer == 0) {
        auto pixmap = new QPixmap(":/images/GameOver1");
        *pixmap = pixmap->scaled(width(), height(), Qt::IgnoreAspectRatio);
        setBackgroundBrush(QPixmap(*pixmap));
        setScene(scene);
    }
    if (indexOfWinnerPlayer == 1) {
        auto pixmap = new QPixmap(":/images/GameOver2");
        *pixmap = pixmap->scaled(width(), height(), Qt::IgnoreAspectRatio);
        setBackgroundBrush(QPixmap(*pixmap));
        setScene(scene);
    }

    QString scores1 = QString::number(*game->getPlayers().at(0)->getScore());
    auto labelScores1 = new Label();
    labelScores1->setPlainText(scores1);
    scene->addItem(labelScores1);
    labelScores1->setPos(width() / 2 - width() / 3,
                         (height() / 2) + labelScores1->boundingRect().height());

    QString scores2 = QString::number(*game->getPlayers().at(1)->getScore());
    auto labelScores2 = new Label();
    labelScores2->setPlainText(scores2);
    scene->addItem(labelScores2);
    labelScores2->setPos(width() - (width() / 2 - width() / 3 + labelScores2->boundingRect().width()),
                         (height() / 2) + labelScores1->boundingRect().height());
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
}