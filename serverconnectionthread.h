#ifndef CONNECTIONTHREADCLIENT_H
#define CONNECTIONTHREADCLIENT_H


#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class ServerConnectionThread : public QThread
{
    Q_OBJECT
public:
    explicit ServerConnectionThread(qintptr socketID, QObject *parent = nullptr);

    void run();


signals:
    void error(QTcpSocket::SocketError socketerror);
    void createGameThread(int gameId);
    void terminateGameThread(int gameId);


public slots:
    void readyRead();
    void disconnected();

private:
    void processMessage(QString message);
    QTcpSocket *socket;
    qintptr socketDescriptor;

    enum Msg
    {
        STARTGAME,
        TERMINATEGAME
        //WAKEUPGAME    ONLY USED IF WE ARE ALLOWING PAUSED GAMES
    };

    void startGame(QList<QString> tokens);
//    void wakeUpGame(QList<QString> tokens);  ONLY USED IF WE ARE ALLOWING PAUSED GAMES
    void terminateGame(QList<QString> tokens);


};

#endif // CONNECTIONTHREADCLIENT_H
