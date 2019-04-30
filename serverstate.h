#ifndef SERVERSTATE_H
#define SERVERSTATE_H

#include "player.h"
#include <QOpenGLShaderProgram>

using namespace std;

class ServerState
{
public:
    ServerState();
    ~ServerState();

    /*Add & Remove Players*/
    Player* addPlayer(QString username, QString address, quint16 port);
    void removePlayer(int playerID);

    /*Getters and setters*/
    int getState();
    void setState(int state);
    int getNumPlayers();
    void setNumPlayers(int numPlayers);
    Player* getPlayer(size_t id);
    int getHasTurn();
    void setHasTurn(int playerID);
    int getMapID();
    void setMapID(int mapID);

    QList<QString> toStringList();

    enum State{
        lobby = 3,
        game,
        miniGame
    };

    enum textures{
        map1,
        fox,
        bear,
        deer,
        butterfly,
        owl,
        frog,
        rabbit,
        squirrel,
        font_arial,
    };

    const int MAX_NUMBER_PLAYERS  = 4;

private:

    int state;
    int numPlayers;

    enum PowerUps{
        swap,
        plusOneRoll,
        doubleRoll,
        halfWinnerRoll,
    };

    int hasTurn;
    int mapID;
    vector<Player*> players;


};

#endif // SERVERSTATE_H
