#ifndef MAP_H
#define MAP_H

#include <QDebug>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QVector>
#include "list.h"

class Map
{
public:
    Map(QString fileLocation);
    ~Map();

private:
    //Returns list of points from Start position to end
    //Roll n -> n number of points to move to from starting point
    movePlayer(startingPos, roll, playerID);

    QList<QVector<int>> coordinateList;
    QList<QVector<int>> indicesList;
    List list;


};

#endif // MAP_H
