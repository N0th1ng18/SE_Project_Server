#ifndef SERVERSTATE_H
#define SERVERSTATE_H

#include "player.h"

using namespace std;

class ServerState
{
public:
    ServerState();
    ~ServerState();

private:

    int state;
    enum State{
        lobby,
        game,
        miniGame
    };

    enum PowerUps{
        swap,
        plusOneRoll,
        doubleRoll,
        halfWinnerRoll,
    };

    int hasTurn;
    int mapID;
    vector<Player*> players;


    /*Add & Remove Players*/
    void addPlayer(Player* p);
    void removePlayer(int playerID);

    /*Getters and setters*/
    int getState();
    void setState(int state);
    int getHasTurn();
    void setHasTurn(int playerID);
    int getMapID();
    void setMapID(int mapID);

};

#endif // SERVERSTATE_H
