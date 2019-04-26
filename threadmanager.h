#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QCoreApplication>
#include <QThread>
#include "gamethread.h"
#include "gamethreadprocesses.h"

class ThreadManager
{
public:
    ThreadManager(quint16 startingPort, int MAX_GAME_THREADS);
    ~ThreadManager();

    bool addGameThread(int gameID);
    bool removeGameThread(int gameID);
private:
    quint16 startingPort;
    int MAX_GAME_THREADS;
    QList<bool> freePorts;

    QList<GameThread*> gameThreads;

};

#endif // THREADMANAGER_H
