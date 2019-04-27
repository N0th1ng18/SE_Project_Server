#ifndef CONNECTIONTHREADCLIENT_H
#define CONNECTIONTHREADCLIENT_H


#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include "threadmanager.h"

class ServerConnectionThread : public QThread
{
    Q_OBJECT
public:
    explicit ServerConnectionThread(int threadID, qintptr socketID, QObject *parent = nullptr);

    void run();


signals:
    void error(QTcpSocket::SocketError socketerror);
    void createGame();
    void gameFinished();


public slots:
    void readyRead();
    void disconnected();

private:
    void processMessage(QString message);
    QTcpSocket *socket;
    qintptr socketDescriptor;
    ThreadManager tm;
    int threadID;

    enum Msg
    {
        STARTGAME,
        WAKEUPGAME,
        TERMINATEGAME
    };

    void startGame();
    void wakeUpGame();
    void terminateGame();


};

#endif // CONNECTIONTHREADCLIENT_H
