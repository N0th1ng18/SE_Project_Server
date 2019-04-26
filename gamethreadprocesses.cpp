#include "gamethreadprocesses.h"

GameThreadProcesses::GameThreadProcesses(int gameID, quint16 port, QObject *parent) :
    QThread(parent)
{
    this->gameID = gameID;
    this->port = port;
}

GameThreadProcesses::~GameThreadProcesses()
{

}


void GameThreadProcesses::run()
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::AnyIPv4, port);

    connect(socket, SIGNAL(socket.readyRead()), this, SLOT(readMessageBuffer()));

    qDebug()<< "GameID: " << gameID << "is listening on port: " << port;
}

void GameThreadProcesses::readMessageBuffer()
{
    while(socket->hasPendingDatagrams())
    {  

        QString data = socket->readAll();
        QList<QString> messages = data.split("||");

        for(int i=0; i < messages.size(); i++){
            processMessage(messages[i]);
        }

    }
}

void GameThreadProcesses::processMessage(QString message)
{
    QList<QString> tokens = message.split("|");



    switch(tokens[0].toInt())
    {
        case Msg::WAKEUP:
        {
           resumeGame(message);
           break;
        }
        case Msg::STARTGAME:
        {
           beginGame(message);
           break;
        }
        case Msg::TERMINATEGAME:
        {
            endGame(message);
            break;
        }
        //improper messages dropped
    }
}


bool GameThreadProcesses::beginGame(QString message)
{
    //Check if MAX_GAME_THREADS

}
bool GameThreadProcesses::resumeGame(QString message)
{
    //Check if MAX_GAME_THREADS

}
bool GameThreadProcesses::endGame(QString message)
{

}
