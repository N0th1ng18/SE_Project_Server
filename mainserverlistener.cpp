#include "mainserverlistener.h"


MainServerListener::MainServerListener(QObject *parent) :
    QTcpServer(parent)
{

}

bool MainServerListener::startServer(quint16 port)
{

    if(!this->listen(QHostAddress::Any,port))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void MainServerListener::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";

    ServerConnectionThread *thread = new ServerConnectionThread(threadID++, socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

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
