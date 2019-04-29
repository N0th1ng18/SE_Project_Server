#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QCoreApplication>
#include <QObject>
#include <QThread>
#include "gamethread.h"
#include "gamethreadprocesses.h"
#include "mainserverlistener.h"

class ThreadManager : public QObject
{
    Q_OBJECT

public:
    ThreadManager(quint16 startingPort, int MAX_GAME_THREADS);

private:
    quint16 startingPort;
    int MAX_GAME_THREADS;
    QList<bool> freePorts;
    QList<GameThread*> gameThreads;

signals:
    void receivedGamePort(quint16 port);

public slots:
    bool addGameThread(int gameId);
    //void storeGameThread(GameThread* gameThread);
    void removeGameThread(int gameID);
    void createServerThread();
    void freePort(quint16 port);

};

#endif // THREADMANAGER_H
