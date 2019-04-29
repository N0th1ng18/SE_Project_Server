#include "point.h"

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}
void Point::setX(int num){
    x = num;
}
void Point::setY(int num){
    y = num;
}
int Point::getX(){
    return x;
}
int Point::getY(){
    return y;
}
