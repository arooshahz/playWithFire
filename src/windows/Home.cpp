#include <QFile>
#include "Home.h"
#include "../views/label.h"
#include "Game.h"
#include "InputPage.h"

Home::Home() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    setFrameShape(NoFrame);

    auto scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, width(), height());
    auto pixmap = new QPixmap(":/images/wallpaper");
    *pixmap = pixmap->scaled(width(), height(), Qt::IgnoreAspectRatio);
    setBackgroundBrush(QPixmap(*pixmap));
    setScene(scene);


//    QFile file("names.txt");
//    QString names[2] = {"", ""};
//    int cnt = 0;
//    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        QTextStream in(&file);
//        while (!in.atEnd()) {
//            names[cnt++] = in.readLine();
//        }
//    }
}
Home::~Home(){
    delete  textfield1;
    delete textfield2;
    delete textfield3;
}
void Home::keyPressEvent(QKeyEvent *event) {
    QGraphicsView::keyPressEvent(event);
    if(event->key()==Qt::Key::Key_Space){
        this->close();
        auto inputPage=new InputPage();
        inputPage->show();
    }
}











