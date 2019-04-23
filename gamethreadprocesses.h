#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <QObject>
#include <QUdpSocket>
#include <QThread>

class gameThreadProcesses: public QObject
{
    struct gameState {
        int gameID,         //The game's info either already from the database or to be saved to the database
            currentTurn,
            maxPlayers;
    };

public:
    gameThreadProcesses();
    ~gameThreadProcesses();

public slots:
    void setup();
    void readMessageBuffer();
    void processMessage();
    void beginGame();
    void endGame();

signals:
    void refreshPort();
    void saveGameState();
    void retrieveGameState();


private:
    QUdpSocket *socket;

};

#endif // GAMEMASTER_H
