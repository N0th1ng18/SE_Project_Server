#include "serverstate.h"

ServerState::ServerState()
{
    this->state = State::lobby;
    this->hasTurn = 0;
    this->mapID = 0;
}

ServerState::~ServerState()
{
    //Clean Up
}


/*Add & Remove Players*/
void ServerState::addPlayer(Player* p)
{
    players.push_back(p);
}
void ServerState::removePlayer(int playerID)
{
    //would need to change playerID's
    //to keep consistent with ith position and playerID
}


/*Getters and setters*/
int ServerState::getState()
{
    return this->state;
}

void ServerState::setState(int state)
{
    this->state = state;
}

int ServerState::getHasTurn()
{
    return this->hasTurn;
}

void ServerState::setHasTurn(int playerID)
{
    this->hasTurn = playerID;
}

int ServerState::getMapID()
{
    return this->mapID;
}

void ServerState::setMapID(int mapID)
{
    this->mapID = mapID;
}
