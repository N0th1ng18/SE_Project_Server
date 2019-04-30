#ifndef OBJECT_H
#define OBJECT_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

class Object
{
public:
    Object();
    ~Object();

    int getSpace();
    QVector3D* getPos();

private:
    int space; //Node*
    QVector3D* pos = nullptr;


    //Map Stuff
};

#endif // OBJECT_H
