#include "gamethreadprocesses.h"

GameThreadProcesses::GameThreadProcesses(int gameID, quint16 port, QObject *parent) :
    QThread(parent)
{
    this->gameID = gameID;
    this->port = port;
}

GameThreadProcesses::~GameThreadProcesses()
{
    emit gameFinished(port);
}


void GameThreadProcesses::setup()
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::AnyIPv4, port);

    socket->connect(socket, SIGNAL(readyRead()), this, SLOT(readMessageBuffer()));

    qDebug()<< "GameID: " << gameID << "is listening on port: " << port;

    //Game Init
    this->serverState = new ServerState();

}

void GameThreadProcesses::readMessageBuffer()
{
    while(socket->hasPendingDatagrams())
    {  

        QNetworkDatagram datagram = socket->receiveDatagram();
        processMessage(datagram);
    }
}

void GameThreadProcesses::processMessage(QNetworkDatagram datagram)
{
    //Convert Datagram into QByteArray
    QByteArray data = datagram.data();
    //Convert QByteArray to QString
    QString str_Data = data;
    //Split message
    QList<QString> messages = str_Data.split("||", QString::SkipEmptyParts);

    //go through group of messages and process them
    for(int i=0; i < messages.size(); i++){

        QList<QString> tokens = messages[i].split("|", QString::SkipEmptyParts);
        qDebug() << tokens;


        //Reactive Server
        switch(tokens[0].toInt())
        {
        case client_connect:
        {
            //Clients can only connect while game is in lobby state
            if(serverState->getState() == serverState->lobby || serverState->getNumPlayers() <= serverState->MAX_NUMBER_PLAYERS)
            {

                //Update ServerState
                Player* newPlayer = serverState->addPlayer(tokens[1], datagram.senderAddress().toString(), static_cast<quint16>(datagram.senderPort()));

                //In Lobby - set player to correct position
                switch(newPlayer->getID())
                {
                case 0:
                {
                    newPlayer->getObj()->getPos()->setX(-0.5f);
                    newPlayer->getObj()->getPos()->setY(0.5f);
                    break;
                }
                case 1:
                {
                    newPlayer->getObj()->getPos()->setX(0.5f);
                    newPlayer->getObj()->getPos()->setY(0.5f);
                    break;
                }
                case 2:
                {
                    newPlayer->getObj()->getPos()->setX(-0.5f);
                    newPlayer->getObj()->getPos()->setY(-0.5f);
                    break;
                }
                case 3:
                {
                    newPlayer->getObj()->getPos()->setX(0.5f);
                    newPlayer->getObj()->getPos()->setY(-0.5f);
                    break;
                }
                }



                //Send Connected to client
                QList<QString> toClient;
                toClient.append(QString::number(client_connect));
                sendMessage(toClient, datagram.senderAddress(), static_cast<quint16>(datagram.senderPort()));

                //Send Server State to all clients
                sendMessageAll(serverState->toStringList());

            }else{
                QList<QString> toClient;
                toClient.append(QString::number(client_disconnect));
                sendMessage(toClient, datagram.senderAddress(), static_cast<quint16>(datagram.senderPort()));

            }
            break;
        }
        case client_disconnect:
        {
            //Send disconnect message to everyone
            break;
        }
        case client_lobby:
        {
            //change imgID
            //Read up for host.
            break;
        }
        case client_game:
        {

            break;
        }
        case client_minigame:
        {

            break;
        }


        }
    }


}

void GameThreadProcesses::sendMessageAll(QList<QString> tokens)
{
    QByteArray array;

    for(QString each: tokens)
    {
        array.append("|");
        array.append(each);
    }
    array.append("||");

    for(size_t i=0; i < static_cast<size_t>(serverState->getNumPlayers()); i++){
        QNetworkDatagram datagram(array,
                                  QHostAddress(serverState->getPlayer(i)->getAddress()),
                                  static_cast<quint16>(serverState->getPlayer(i)->getPort()));
        socket->writeDatagram(datagram);
        socket->flush();
    }
}

void GameThreadProcesses::sendMessage(QList<QString> tokens, QHostAddress address, quint16 port){
    QByteArray array;

    for(QString each: tokens)
    {
        array.append("|");
        array.append(each);
    }
    array.append("||");

    QNetworkDatagram datagram(array, address, port);
    socket->writeDatagram(datagram);
    socket->flush();
}
