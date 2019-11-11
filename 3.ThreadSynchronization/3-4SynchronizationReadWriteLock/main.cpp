#include <QApplication>
#include <QMessageBox>
#include "printdevice.h"
#include "printworker.h"
#include "incrementworker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool stopFlag = false;

    PrintDevice printDevice;

    PrintWorker white("White",&stopFlag,&printDevice),black("Black",&stopFlag,&printDevice);

    IncrementWorker incrementWorker(&stopFlag,&printDevice);


    white.start();
    black.start();
    incrementWorker.start();

    QMessageBox::information(nullptr,"QMutex",
                                 "Thread working. Close Me to stop");

    stopFlag = true;

    white.wait();
    black.wait();
    incrementWorker.wait();

    return 0;
}
