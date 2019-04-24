#include "gamethreadprocesses.h"

gameThreadProcesses::gameThreadProcesses()
{

}

gameThreadProcesses::~gameThreadProcesses()
{

}


void gameThreadProcesses::setup()
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::AnyIPv4, 2468);

    connect(socket, SIGNAL(socket.readyRead()), this, SLOT(readMessageBuffer()));


}

void gameThreadProcesses::readMessageBuffer()
{
    while(socket->hasPendingDatagrams())
    {
        QNetworkDatagram data = socket->receiveDatagram();
    }
}

void gameThreadProcesses::processMessage()
{

}
