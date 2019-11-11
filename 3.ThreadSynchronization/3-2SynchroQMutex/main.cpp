#include <QApplication>
#include <QDebug>
#include <QMutex>
#include <QMessageBox>
#include "printworker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool stopFlag = false;

    QMutex mutex;

    PrintWorker black("Black",&stopFlag,&mutex), white("White",&stopFlag,&mutex);


    black.start();
    white.start();

    QMessageBox::information(nullptr,"QMutex",
                                 "Thread working. Close Me to stop");

    stopFlag = true;

    black.wait();
    white.wait();

    return 0 ;
}
