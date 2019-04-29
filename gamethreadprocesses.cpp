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


void GameThreadProcesses::setup()
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::AnyIPv4, port);

    connect(socket, SIGNAL(socket.readyRead()), this, SLOT(readMessageBuffer()));

    qDebug()<< "GameID: " << gameID << "is listening on port: " << port;

    //Game Init


}

void GameThreadProcesses::readMessageBuffer()
{
    while(socket->hasPendingDatagrams())
    {  

        QString data = socket->readAll();
        QList<QString> messages = data.split("||", QString::SkipEmptyParts);

        for(int i=0; i < messages.size(); i++){
            processMessage(messages[i]);
        }

    }
}

void GameThreadProcesses::processMessage(QString message)
{
    QList<QString> tokens = message.split("|", QString::SkipEmptyParts);
    qDebug() << tokens;



    switch(tokens[0].toInt())
    {
        /*
         *
         *      Messages from Clients go here
         *
         */


    }
}
