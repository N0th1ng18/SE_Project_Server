#include "mainserverlistener.h"


MainServerListener::MainServerListener(ThreadManager* tm, QObject *parent) :
    QTcpServer(parent)
{
    //this->STARTING_PORT = STARTING_PORT;
    //this->MAX_GAME_THREADS = MAX_GAME_THREADS;
    this->tm = tm;

}

void MainServerListener::startServer(quint16 port)
{

    if(!this->listen(QHostAddress::Any,port))
    {
        qDebug() << "Failed to Listen on port: " << port;
    }
    else
    {
        qDebug() << "Listening to port: " << port << "...";
    }
}

void MainServerListener::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";

    ServerConnectionThread *thread = new ServerConnectionThread(threadID++, socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    //connect(thread, SIGNAL(thread.createGame()), tm, SLOT(tm.addGameThread()), Qt::AutoConnection);


    /*
     *
     *
     *                  COME BACK TO THIS
     *                          ISAAC
     *
     *
     *
     */


    thread->start();

}
