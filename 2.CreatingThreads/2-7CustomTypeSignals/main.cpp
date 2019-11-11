#include "widget.h"
#include <QApplication>
#include "numberedstring.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<NumberedString>("NumberedString");
    Widget w;
    w.show();

    return a.exec();
}
