#include <QString>
#include <QPixmap>
#include "playerInformation.h"

void playerInformation::remove() {
    delete this;
}

playerInformation::playerInformation(int index, int life, int width) {
    QString inttostr[] = {"0", "1", "2", "3", "4", "5", "6"};
    QString name = ":/images/p";
    name = name + inttostr[index] + inttostr[life] + "l";
    QPixmap pixmap(name);
    pixmap = pixmap.scaled(290, 404);
    setPixmap(pixmap);
}
