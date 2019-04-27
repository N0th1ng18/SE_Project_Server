#ifndef MAINSERVERLISTENER_H
#define MAINSERVERLISTENER_H


#include <QTcpServer>
#include "serverconnectionthread.h"

class MainServerListener : public QTcpServer
{
    Q_OBJECT

public:
    explicit MainServerListener(QObject *parent = nullptr);
    bool startServer(quint16 port);

signals:

    void addGameThread(int gameId);
    void removeGameThread(int gameId);

public slots:

    void passAddGameThread(int gameId);
    void passRemoveGameThread(int gameId);

protected:
    void incomingConnection(qintptr socketDescriptor);

private:
    int threadID = 0;

    quint16 STARTING_PORT;
    int MAX_GAME_THREADS;

};

#endif // SERVER_H
