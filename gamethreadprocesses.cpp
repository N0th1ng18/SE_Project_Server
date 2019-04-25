#include "gamethreadprocesses.h"

GameThreadProcesses::GameThreadProcesses()
{

}

GameThreadProcesses::~GameThreadProcesses()
{

}


void GameThreadProcesses::setup(quint16 port)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::AnyIPv4, port);

    connect(socket, SIGNAL(socket.readyRead()), this, SLOT(readMessageBuffer()));


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

bool GameThreadProcesses::processMessage(QString message)
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
