#include "Game.h"
#include "../views/Box.h"


Game::Game() {




    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene =new QGraphicsScene();
    scene->setSceneRect(0,0,width(),height());
    setBackgroundBrush(QColor("#2c2721"));
    setScene(scene);



    blockWidth=(width())/15;
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
                             box->setPos(i * blockWidth, j * blockHeight);

                     }

                   }
                    else{
                       auto wall = new Wall(blockWidth, blockHeight);
                       addBlock(wall);
                       scene->addItem(wall);
                       wall->setPos(i * blockWidth, j * blockHeight);
                    }

                }
            }

}
void Game::addBlock(Block *block) {


    this->blocks.append(block);
}