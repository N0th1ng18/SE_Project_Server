#include <QCoreApplication>
#include <QTcpSocket>
#include "mainserverconnection.h"
#include "gamethreadprocesses.h"
#include "mainserverlistener.h"
#include "threadmanager.h"




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ThreadManager* tm = new ThreadManager(5557,5);

    MainServerListener* sc = new MainServerListener(tm);

    //TEST
    GameThreadProcesses* testGame = new GameThreadProcesses(1, 5557);
    testGame->start();
    //END TEST

    return a.exec();
}








