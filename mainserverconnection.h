#ifndef mainServerConnection_H
#define mainServerConnection_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>

#include "gamethreadprocesses.h"
#include "threadmanager.h"

class MainServerConnection
{

public:
    MainServerConnection(quint16 startingPort, int MAX_GAME_THREADS);
    ~MainServerConnection();
    void connectMainServer(QObject *parent = nullptr);
    void listen();
    void disconnectMainServer();
    void processMessage(QString message);

    void startGame();
    void wakeUpGame();
    void terminateGame();


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
    ThreadManager* tm;


};

#endif // mainServerConnection_H
