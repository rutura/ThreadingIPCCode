#include "widget.h"
#include <QApplication>
#include "customdata.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<CustomData>();
    Widget w;
    w.show();

    return a.exec();
}
