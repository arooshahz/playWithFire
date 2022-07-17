#include <QFont>
#include <QTextDocument>
#include "Lable.h"
Lable::Lable() {



    setDefaultTextColor(QColor("white"));
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    setFont(font);


    document()->setDocumentMargin(10);

}