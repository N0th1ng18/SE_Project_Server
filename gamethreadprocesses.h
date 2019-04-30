#ifndef GAMETHREADPROCESSES_H
#define GAMETHREADPROCESSES_H

#include <QObject>
#include <QThread>
#include <QUdpSocket>
#include <QDebug>
#include <QNetworkDatagram>
#include "serverstate.h"

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



private:
    void sendMessage(QList<QString> tokens, QHostAddress address, quint16 port);
    void sendMessageAll(QList<QString> tokens);
    void processMessage(QNetworkDatagram datagram);
    QUdpSocket *socket;
    qintptr socketDescriptor;
    quint16 port;
    int gameID;

    ServerState* serverState;

    enum clientMsg {
        client_connect = 1,
        client_disconnect,
        client_lobby,
        client_game,
        client_minigame
    };

    enum serverMsg {
        server_connect = 1,
        server_disconnect,
        server_lobby,
        server_game,
        server_minigame

    };

};

#endif // GAMEMASTER_H
