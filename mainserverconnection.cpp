#include "mainServerConnection.h"

MainServerConnection::MainServerConnection()
{

}

MainServerConnection::~MainServerConnection()
{
    delete socket;
}


void MainServerConnection::connectMainServer(QObject *parent)
{
    qDebug() << "connectMainServer()";
    socket = new QTcpSocket(parent);
    socket->connectToHost("192.168.1.2", 5556);

    while (!socket->waitForConnected(3000))
    {
        qDebug("Failed to Connect to Host Server Trying again...");
        socket->connectToHost("192.168.1.2", 5556);
    }
}

void MainServerConnection::disconnectMainServer()
{
    socket->disconnectFromHost();
    if (socket->state() == QAbstractSocket::UnconnectedState || socket->waitForDisconnected(1000))
    {
        qDebug("Disconnected!");
    }
}

void MainServerConnection::listen()
{
    while(isRunning)
    {
        if(socket->waitForReadyRead())
        {
            //Read All Data in Socket buffer
            QString data = socket->readAll();

            //Break message into QList
            QList<QString> messages = data.split("||");

            for(int i=0; i < messages.size(); i++){
                processMessage(messages[i]);
            }
        }
    }
}

void MainServerConnection::processMessage(QString message){
    qDebug() << "Server received (" << message << ") from MainServer";
    //Seperate message into tokens
    QList<QString> tokens = message.split("|");

    switch(tokens[0].toInt())
    {
    case Msg::STARTGAME:

        break;
    case Msg::WAKEUPGAME:

        break;
    case Msg::TERMINATEGAME:

        break;
    //Default Drops message
    }

}


void spawnGameThread()
{
    //GameThreadProcesses* gThread = new GameThreadProcesses();
    //gThread->currentThreadId();
    //Add ThreadID and pointer to

}
void terminateThread()
{

}
/*
void mainServerConnection::createNewGameThread()
{
    if (currentGameThreads >= maxGameThreads)
    {

    }
    else
    {
            gameThreadProcesses *thread = new gameThreadProcesses(socketDescriptor, this);
            connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
            thread->start();
    }

}

void mainServerConnection::deleteGameThread()
{

}
*/
