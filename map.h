#ifndef MAP_H
#define MAP_H
#include <node.h>
#include <QRandomGenerator>
#include <QDebug>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QVector>
#include "point.h"

using namespace std;

class Map
{
private:
    int calcRandPos(int x1, int x2);
    Node* head;

    //Map Loader
    QList<QVector<int>> coordinateList;

public:
    Map(QString loc);
    ~Map();

    bool loadMap(QString fileLocation);
    Node* getHead();
    int movePlayer(Node* startingNode, int roll, std::vector<Point*>& outList);
};

#endif // MAP_H
