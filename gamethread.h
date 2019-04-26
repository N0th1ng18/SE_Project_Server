#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include <QThread>
#include <QCoreApplication>

class GameThread
{
public:
    GameThread(int gameID, QThread* thread, quint16 port);
    ~GameThread();

    int getGameID();
    void setGameID(int g);
    QThread* getThread();
    void setThread(QThread* t);
    quint16 getPort();
    void setPort(quint16 p);

private:
    int gameID;
    QThread* thread;
    quint16 port;

};

#endif // GAMETHREAD_H
