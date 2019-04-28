#ifndef GAMETHREADPROCESSES_H
#define GAMETHREADPROCESSES_H

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
    explicit GameThreadProcesses(int gameID, quint16 port, QObject *parent = nullptr);
    ~GameThreadProcesses();

    void setup();

public slots:
    void readMessageBuffer();
    void processMessage(QString message);
   // bool beginGame(QString message);
   // bool resumeGame(QString message);
   // bool endGame(QString message);

signals:
    void refreshPort();
    void saveGameState();
    void retrieveGameState();


private:
    QUdpSocket *socket;
    qintptr socketDescriptor;
    quint16 port;
    int gameID;
    enum Msg {
        WAKEUP,
        STARTGAME,
        TERMINATEGAME
    };

};

#endif // GAMEMASTER_H
