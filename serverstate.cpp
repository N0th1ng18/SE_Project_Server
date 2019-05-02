#include "serverstate.h"


/*
 *  Description:
 *      Structure for adding and removing players from the game
 *      store their game info for use in game
 *
 *  Author:
 *      Nick
 *
 */
ServerState::ServerState()
{
    this->state = State::lobby;
    this->numPlayers = 0;
    this->hasTurn = 0;
    this->mapID = this->map1;
}

ServerState::~ServerState()
{
    //Clean Up
}


/*Add & Remove Players*/
Player* ServerState::addPlayer(QString username, QString address, quint16 port)
{
    Player* newPlayer = new Player();
    newPlayer->setUsername(username);
    newPlayer->setID(this->numPlayers);
    newPlayer->setImgID(1);
    setNumPlayers(this->numPlayers + 1);
    newPlayer->setAddress(address);
    newPlayer->setPort(port);
    players.push_back(newPlayer);

    return  newPlayer;
}
void ServerState::removePlayer(int playerID)
{
    //would need to change playerID's
    //to keep consistent with ith position and playerID
}

Player* ServerState::getPlayer(size_t id)
{
    return this->players.at(id);
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

int ServerState::getNumPlayers()
{
    return this->numPlayers;
}
void ServerState::setNumPlayers(int numPlayers)
{
    this->numPlayers = numPlayers;
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

QList<QString> ServerState::toStringList()
{
    QList<QString> strList;
    strList.append(QString::number(getState()));
    strList.append(QString::number(getHasTurn()));
    strList.append(QString::number(getMapID()));
    strList.append(QString::number(getNumPlayers()));
    for(size_t i=0; i < static_cast<size_t>(getNumPlayers()); i++)
    {
        strList.append(QString::number(getPlayer(i)->getID()));
        strList.append(QString::number(getPlayer(i)->getImgID()));
        strList.append(QString::number(getPlayer(i)->getHasMoved()));
        strList.append(QString::number(static_cast<double>(getPlayer(i)->getObj()->getPos()->x())));
        strList.append(QString::number(static_cast<double>(getPlayer(i)->getObj()->getPos()->y())));
        strList.append(QString::number(static_cast<double>(getPlayer(i)->getObj()->getPos()->z())));
    }
    return strList;
}
