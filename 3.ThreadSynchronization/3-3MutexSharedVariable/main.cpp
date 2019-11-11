#include <QApplication>
#include <QMessageBox>
#include "printdevice.h"
#include "printworker.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool stopFlag = false;

    PrintDevice printDevice;

    PrintWorker black("Black",&stopFlag,&printDevice),white("White",&stopFlag,&printDevice);

    black.start();
    white.start();

    QMessageBox::information(nullptr,"QMutex",
                                 "Thread working. Close Me to stop");

    stopFlag = true;

    black.wait();
    white.wait();


    return 0;
}
