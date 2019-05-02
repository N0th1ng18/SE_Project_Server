#include "object.h"

/*
 *  Description:
 *      Default object class for storing a getting positions
 *
 *  Author:
 *      Nick
 *
 */
Object::Object()
{
    this->pos = new QVector3D(0.0f, 0.0f, 0.0f);
    this->space = 0;
}







int Object::getSpace()
{
    return this->space;
}
QVector3D* Object::getPos()
{
    return this->pos;
}
