#include "serverconnectionthread.h"

ServerConnectionThread::ServerConnectionThread(qintptr socketID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = socketID;
}

void ServerConnectionThread::setup()
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
    QList<QString> messages = data.split("||", QString::SkipEmptyParts);

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
    QList<QString> tokens = message.split("|", QString::SkipEmptyParts);
    qDebug() << message;

    switch(tokens[0].toInt())
    {
    case Msg::STARTGAME:
        startGame(tokens);
        break;

    case Msg::TERMINATEGAME:
        terminateGame(tokens);
        break;

//    case Msg::WAKEUPGAME:
//        wakeUpGame(tokens);
//        break;
//                              Default Drops message
    }

}

void ServerConnectionThread::startGame(QList<QString> tokens)
{
    //get gameId from MainServer message

    emit createGameThread(tokens.at(1).toInt());         /*gameId from tokens*/
}

//
//      ONLY USED IF WE ARE ALLOWING DORMANT GAMES
//
//
//void ServerConnectionThread::wakeUpGame(QList<QString> tokens)
//{
//    emit createGameThread();
//}
//
//

void ServerConnectionThread::terminateGame(QList<QString> tokens)
{
    //get gameId from MainServer message
    emit terminateGameThread(0/*gameId from tokens*/);
}

void ServerConnectionThread:: passGamePort(quint16 port)
{
    QByteArray response = "3|";
    response.append("1|");
    response.append(QString::number(port));
    socket->write(response);
    socket->flush();
}
