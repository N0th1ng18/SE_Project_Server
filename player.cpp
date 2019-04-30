#include "player.h"

Player::Player()
{
    object = new Object();
}

Player::~Player()
{

}

Object* Player::getObj()
{
    return this->object;
}

/*Add Remove PowerUps*/
void Player::addPowerUp(PowerUp* p)
{
    powerUps.push_back(p);
}
void Player::removePowerUp(int powerUpID)
{

}

/*Getters & Setters*/
int Player::getID()
{
    return this->ID;
}
void Player::setID(int id)
{
    this->ID = id;
}

int Player::getImgID()
{
    return this->imgID;
}

void Player::setImgID(int imgID)
{
    this->imgID = imgID;
}

QString Player::getAddress()
{
    return this->address;
}
void Player::setAddress(QString address)
{
    this->address = address;
}
int Player::getPort()
{
    return this->port;
}
void Player::setPort(int port)
{
    this->port = port;
}

int Player::getHasMoved()
{
    return this->hasMoved;
}
void Player::setHasMoved(int hasMoved)
{
    this->hasMoved = hasMoved;
}

QString Player::getUsername()
{
    return this->username;
}
void Player::setUsername(QString username)
{
    this->username = username;
}
