#include "gamethread.h"

GameThread::GameThread(int gameID, QThread* thread, quint16 port)
{
    this->gameID = gameID;
    this->thread = thread;
    this->port = port;
}

GameThread::~GameThread()
{

}

int GameThread::getGameID()
{
    return gameID;
}

void GameThread::setGameID(int g)
{
    this->gameID = g;
}

QThread* GameThread::getThread()
{
    return thread;
}

void GameThread::setThread(QThread* t)
{
    this->thread = t;
}

quint16 GameThread::getPort()
{
    return port;
}

void GameThread::setPort(quint16 p)
{
    this->port = p;
}
