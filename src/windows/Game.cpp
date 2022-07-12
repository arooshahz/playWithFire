#include "Game.h"
#include "../views/Box.h"
#include "../views/Player.h"
#include "../views/Controller.h"


Game::Game() {




    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene =new QGraphicsScene();
    scene->setSceneRect(0,0,width(),height());
    setBackgroundBrush(QColor("#2c2721"));
    setScene(scene);



    blockWidth=(width()-200)/15;
    blockHeight=height()/15;

            for(int i=0;i<15;i++){
                for(int j=0;j<15;j++){
                    if((i==1&&j==1) ||(i==13&&j==13)||(i==1&&j==2)||(i==2&&j==1)||(i==12&&j==13)||(i==13&&j==12))
                        continue;
                   if(i!=0 && i!=14 && j!=0 && j!=14 && (i%2!=0 || j%2!=0)) {
                       int num = (rand() %(2));
                     if(num==1 ){

                             auto box = new class Box(blockWidth, blockHeight);
                             addBlock(box);
                             scene->addItem(box);
                             box->setPos(i * blockWidth+200, j * blockHeight);

                     }

                   }
                    else{
                       auto wall = new Wall(blockWidth, blockHeight);
                       addBlock(wall);
                       scene->addItem(wall);
                       wall->setPos(i * blockWidth+200, j * blockHeight);
                    }

                }
            }



            QList <QPixmap*>frames1;
            auto pixmap1=new QPixmap(":/images/p11");
            *pixmap1=pixmap1->scaled(blockWidth -10, blockHeight );
             frames1.append(pixmap1);
    pixmap1=new QPixmap(":/images/p12");
            *pixmap1=pixmap1->scaled(blockWidth -10, blockHeight );
             frames1.append(pixmap1);pixmap1=new QPixmap(":/images/p13");
             *pixmap1=pixmap1->scaled(blockWidth -10, blockHeight );
              frames1.append(pixmap1);


        auto player1=new Player(width(),height(),frames1);
        this->players.append(player1);
        scene->addItem(player1);
        player1->setPos(blockWidth+200,blockHeight);






    QList <QPixmap*>frames2;
    auto pixmap2=new QPixmap(":/images/p21");
    *pixmap2=pixmap2->scaled(blockWidth -10, blockHeight );
    frames2.append(pixmap2);

    auto player2=new Player(width(),height(),frames2);
    this->players.append(player2);
    scene->addItem(player2);
    player2->setPos((blockWidth*13)+200,blockHeight*13);


    auto controller=new Controller(this);
scene->addItem(controller);
scene->setFocus();


}
void Game::addBlock(Block *block) {


    this->blocks.append(block);
}
QList<Player*> Game::getPlayers() {

    return players;
}