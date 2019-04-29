#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include "object.h"
#include "powerup.h"

using namespace std;

class Player
{
public:
    Player();
    ~Player();

private:
    int ID;
    QString address;
    int port;
    vector<Object*> objects;
    vector<PowerUp*> powerUps;

    /*Add Remove Objects*/
    void addObject(Object* o);
    void removeObject(int objectID);

    /*Add Remove PowerUps*/
    void addPowerUp(PowerUp* p);
    void removePowerUp(int powerUpID);

    /*Getters & Setters*/
    int getID();
    void setID(int id);
    QString getAddress();
    void setAddress(QString address);
    int getPort();
    void setPort(int port);



};

#endif // PLAYER_H
