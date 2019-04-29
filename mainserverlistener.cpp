#include "mainserverlistener.h"


MainServerListener::MainServerListener(QObject *parent) :
    QTcpServer(parent)
{

}

/*
 *  Description:
 *      Creates a threaded server to receive messages from the main server
 *      upon recieving a main server connection
 *  Contributors:
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
 *      creates the actual connection thread from the incoming main server connection,
 *
 *  Contributors:
 *      Isaac
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


/*
 *  Description:
 *      Daisy Chains gameId from created game server over to GameThreadProcesses
 *      to create the game server as a child of the thread manager
 *
 *  Contributors:
 *      Isaac
 */
void MainServerListener::passAddGameThread(int gameId)
{
    emit addGameThread(gameId);
}

/*
 *  Description:
 *
 *  Contributors:
 *      Isaac
 */
void MainServerListener::passRemoveGameThread(int gameId)
{
    emit removeGameThread(gameId);
}

/*
 *  Description:
 *      emits the port recieved from the
 *  Contributors:
 *      Isaac
 */
void MainServerListener::passGamePort(quint16 port)
{
    emit recievedGamePort(port);
}
