#include <QCoreApplication>
#include <QTcpSocket>

#include "threadmanager.h"




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    quint16 STARTINGPORT = 5557;
    int MAX_GAME_THREADS = 5;

    ThreadManager* tm = new ThreadManager(STARTINGPORT, MAX_GAME_THREADS);

    tm->createServerThread();



    //TEST
    //GameThreadProcesses* testGame = new GameThreadProcesses(1, 5557);
    //testGame->start();
    //END TEST

    return a.exec();
}








