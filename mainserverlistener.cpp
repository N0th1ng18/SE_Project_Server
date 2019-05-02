#include "mainserverlistener.h"

/*
 *  Description:
 *     constructor for MainServerListener
 *
 *  Author:
 *      Isaac
 *
 */
MainServerListener::MainServerListener(QObject *parent) :
    QTcpServer(parent)
{

}

/*
 *  Description:
 *      begins server to listen for imcomming connections
 *
 *  Author:
 *      Isaac
 *
 */
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

/*
 *  Description:
 *      Catches Incomming connections
 *      spawns a SercerConnectionThread to maintain and handle that Connection
 *
 *  Author:
 *      Isaac
 *
 */
void MainServerListener::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";

    ServerConnectionThread *serverThread = new ServerConnectionThread(socketDescriptor, this);
    ServerConnectionThread::connect(serverThread, SIGNAL(finished()), serverThread, SLOT(deleteLater()));
    ServerConnectionThread::connect(serverThread, SIGNAL(started()), serverThread, SLOT(setup()));
    ServerConnectionThread::connect(serverThread, SIGNAL(createGameThread(int)), this, SLOT(passAddGameThread(int)));
    ServerConnectionThread::connect(serverThread, SIGNAL(terminateGameThread(int)), this, SLOT(passRemoveGameThread(int)));
    ServerConnectionThread::connect(this, SIGNAL(recievedGamePort(quint16)), serverThread, SLOT(passGamePort(quint16)));



    serverThread->start();
}

/*
 *  Description:
 *      Next three are emits for slots and signals to maintain Heirarchy
 *
 *  Author:
 *      Isaac
 *
 */
void MainServerListener::passAddGameThread(int gameId)
{
    emit addGameThread(gameId);
}

void MainServerListener::passRemoveGameThread(int gameId)
{
    emit removeGameThread(gameId);
}

void MainServerListener::passGamePort(quint16 port)
{
    emit recievedGamePort(port);
}
