#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <QObject>
#include <QThread>
#include <QUdpSocket>
#include <QDebug>

class GameThreadProcesses: public QThread
{
    Q_OBJECT
    struct gameState {
        int gameID,         //The game's info either already from the database or to be saved to the database
            currentTurn,
            maxPlayers;
    };

public:
    GameThreadProcesses();
    ~GameThreadProcesses();

public slots:
    void setup(quint16 port);
    void readMessageBuffer();
    bool processMessage(QString message);
    bool beginGame(QString message);
    bool resumeGame(QString message);
    bool endGame(QString message);

signals:
    void refreshPort();
    void saveGameState();
    void retrieveGameState();


private:
    QUdpSocket *socket;
    qintptr socketDescriptor;
    enum Msg {
        WAKEUP,
        STARTGAME,
        TERMINATEGAME
    };

};

#endif // GAMEMASTER_H
