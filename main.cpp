#include <QCoreApplication>
#include <QTcpSocket>

#include "threadmanager.h"




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ThreadManager* tm = new ThreadManager(5557,5);

    tm->createServerThread()

    //TEST
    //GameThreadProcesses* testGame = new GameThreadProcesses(1, 5557);
    //testGame->start();
    //END TEST

    return a.exec();
}








