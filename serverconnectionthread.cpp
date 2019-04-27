#include "serverconnectionthread.h"

ServerConnectionThread::ServerConnectionThread(int threadID, qintptr socketID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = socketID;
    this->threadID = threadID;
}

void ServerConnectionThread::run()
{

    //create Socket
    socket = new QTcpSocket();

    // set socket to socket Descriptor passed into socketID
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }


    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    qDebug() << "Client ID: "<< socketDescriptor << " connected.";

    exec();
}

void ServerConnectionThread::readyRead()
{
    //If message doesnt have Active code it is sent to USERLOGIN only

    //Read All Data in Socket buffer
    QString data = socket->readAll();

    //Break message into QList
    QList<QString> messages = data.split("||");

    for(int i=0; i < messages.size(); i++){
        processMessage(messages[i]);
    }
}

void ServerConnectionThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";


    socket->deleteLater();
    exit(0);
}

void ServerConnectionThread::processMessage(QString message){
    qDebug() << "Server received (" << message << ") from MainServer";
    //Seperate message into tokens
    QList<QString> tokens = message.split("|");

    switch(tokens[0].toInt())
    {
    case Msg::STARTGAME:
        startGame();
        break;
    case Msg::WAKEUPGAME:
        wakeUpGame();
        break;
    case Msg::TERMINATEGAME:
        terminateGame();
        break;
    //Default Drops message
    }

}

void ServerConnectionThread::startGame(/*QString gameData*/)
{
    emit createGame();
}

void ServerConnectionThread::wakeUpGame(/*QString gameData*/)
{

}

void ServerConnectionThread::terminateGame(/*QString gameData*/)
{
    //Send endGamePacket
    emit gameFinished();
}
