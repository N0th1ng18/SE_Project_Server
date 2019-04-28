#include "player.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::addObject(Object* o)
{
    objects.push_back(o);
}
void Player::removeObject(int objectID)
{

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
