#ifndef mainServerConnection_H
#define mainServerConnection_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>

#include "gamethreadprocesses.h"

class MainServerConnection
{

public:
    MainServerConnection();
    ~MainServerConnection();
    void connectMainServer(QObject *parent = nullptr);
    void listen();
    void disconnectMainServer();
    void processMessage(QString message);

    void spawnGameThread();
    void terminateThread();


private:
    QTcpSocket* socket = nullptr;
    int maxGameThreads = 5;
    int currentGameThreads = 0;
    bool isRunning = true;
    enum Msg
    {
        STARTGAME,
        WAKEUPGAME,
        TERMINATEGAME
    };


};

#endif // mainServerConnection_H
