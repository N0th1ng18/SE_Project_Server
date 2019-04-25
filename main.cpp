#include <QCoreApplication>
#include <QTcpSocket>
#include "mainserverconnection.h"
#include "gamethreadprocesses.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    MainServerConnection* sc = new MainServerConnection();
    sc->connectMainServer();
    sc->listen();
    sc->disconnectMainServer();


    return a.exec();
}








