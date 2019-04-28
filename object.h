#ifndef OBJECT_H
#define OBJECT_H

#include <QOpenGLFunctions>

class Object
{
public:
    Object(int space);
    ~Object();

private:
    int space; //Node*
    QVector3D *pos = nullptr;


    //Map Stuff
};

#endif // OBJECT_H
