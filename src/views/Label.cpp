#include <QFont>
#include <QTextDocument>
#include "Label.h"

Label::Label() {


    setDefaultTextColor(QColor("white"));
    QFont font;
    font.setPixelSize(45);
    font.setBold(true);
    setFont(font);


    document()->setDocumentMargin(10);

}