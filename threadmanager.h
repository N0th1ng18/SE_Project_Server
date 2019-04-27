#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QCoreApplication>
#include <QThread>
#include <QObject>
#include "gamethread.h"
#include "gamethreadprocesses.h"
#include "mainserverlistener.h"

class ThreadManager
{
public:
    ThreadManager(quint16 startingPort, int MAX_GAME_THREADS);
    ~ThreadManager();

private:
    quint16 startingPort;
    int MAX_GAME_THREADS;
    QList<bool> freePorts;
    QList<GameThread*> gameThreads;

signals:


public slots:
    bool addGameThread(int gameID);
    void storeGameThread(GameThread* gameThread);
    void removeGameThread(int gameID);
    void createServerThread();

};

#endif // THREADMANAGER_H
