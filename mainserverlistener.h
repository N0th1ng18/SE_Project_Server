#ifndef MAINSERVERLISTENER_H
#define MAINSERVERLISTENER_H


#include <QTcpServer>
#include "serverconnectionthread.h"

class MainServerListener : public QTcpServer
{
    Q_OBJECT
public:
    explicit MainServerListener(ThreadManager* tm, QObject *parent = nullptr);
    void startServer(quint16 port);
signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);

private:
    int threadID = 0;

    quint16 STARTING_PORT;
    int MAX_GAME_THREADS;
    ThreadManager* tm;

};

#endif // SERVER_H
