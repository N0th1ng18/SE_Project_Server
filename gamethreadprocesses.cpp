/*
 *  Description:
 *      This class runs the game thread
 *  Contributors:
 *      Isaac, Nick
 */
#include "gamethreadprocesses.h"

GameThreadProcesses::GameThreadProcesses(int gameID, quint16 port, QObject *parent) :
    QThread(parent)
{
    this->gameID = gameID;
    this->port = port;
}

GameThreadProcesses::~GameThreadProcesses()
{
    emit resetFreePort(port);
}

/*
 *  Description:
 *      Sets up the game, creating the socket for client-gameserver communication
 *  Contributors:
 *      Isaac, Nick
 */
void GameThreadProcesses::setup()
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::AnyIPv4, port);

    connect(socket, SIGNAL(socket.readyRead()), this, SLOT(readMessageBuffer()));

    qDebug()<< "GameID: " << gameID << "is listening on port: " << port;

    //Game Init


}


/*
 *  Description:
 *      Reads the message buffer whent he readyRead signal is emmited by the QTcpSocket
 *  Contributors:
 *      Isaac, Nick, Tyler
 */
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


/*
 *  Description:
 *      Is passed the message from readMessageBuffer,
 *      splits the message into tokens,
 *      and calls the proper method for the message depending on the message header
 *  Contributors:
 *      Isaac, Nick
 */
void GameThreadProcesses::processMessage(QString message)
{
    QList<QString> tokens = message.split("|", QString::SkipEmptyParts);



    switch(tokens[0].toInt())
    {
        /*
         *
         *      Messages from Clients go here
         *
         */


    }
}
