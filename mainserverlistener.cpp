#include "mainserverlistener.h"


MainServerListener::MainServerListener(QObject *parent) :
    QTcpServer(parent)
{

}

bool MainServerListener::startServer(quint16 port)
{

    if(!this->listen(QHostAddress::Any,port))
    {
        qDebug() << "Server Failed to start";
        return false;
    }
    else
    {
        qDebug() << "Listening to port: " << port << "...";
        return true;
    }
}

void MainServerListener::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";

    ServerConnectionThread *serverThread = new ServerConnectionThread(socketDescriptor, this);
    connect(serverThread, SIGNAL(finished()), serverThread, SLOT(deleteLater()));
    connect(serverThread, SIGNAL(createGameThread(gameId)), this, SLOT(addGameThread(gameId)));
    connect(serverThread, SIGNAL(terminateGameThread(gameId)), this, SLOT(removeGameThread(gameId)));


    /*
     *
     *
     *                  COME BACK TO THIS
     *                          ISAAC
     *
     *
     *
     */


    serverThread->start();
}

void MainServerListener::passAddGameThread(int gameId)
{
    emit addGameThread(gameId);
}

void MainServerListener::passRemoveGameThread(int gameId)
{
    emit removeGameThread(gameId);
}
