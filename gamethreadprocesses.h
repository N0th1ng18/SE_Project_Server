#ifndef GAMETHREADPROCESSES_H
#define GAMETHREADPROCESSES_H

#include <QObject>
#include <QThread>
#include <QUdpSocket>
#include <QDebug>

class GameThreadProcesses: public QThread
{
    Q_OBJECT

public:
    explicit GameThreadProcesses(int gameID, quint16 port, QObject *parent = nullptr);
    ~GameThreadProcesses();



public slots:
    void setup();
    void readMessageBuffer();

signals:
    void refreshPort();
    void saveGameState();
    void retrieveGameState();
    void resetFreePort(quint16 port);


private:
    void processMessage(QString message);
    QUdpSocket *socket;
    qintptr socketDescriptor;
    quint16 port;
    int gameID;

};

#endif // GAMEMASTER_H
