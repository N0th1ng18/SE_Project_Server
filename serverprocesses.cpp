#include "serverprocesses.h"


serverProcesses::serverProcesses(int serverType, QObject *parent) :
    QTcpServer(parent)
{
    this->serverType = serverType;
}

void serverProcesses::startServer(quint16 port)
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

void serverProcesses::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";


}

void processMessage
