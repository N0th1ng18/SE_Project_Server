#ifndef POWERUP_H
#define POWERUP_H


class PowerUp
{
public:
    PowerUp();

private:
    int typeID;
    int num;

    /*Getters and Setters*/
    int getType();
    void setType(int type);
    int getNum();
    void setNum(int n);
};

#endif // POWERUP_H
