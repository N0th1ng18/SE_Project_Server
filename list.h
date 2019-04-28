#ifndef LIST_H
#define LIST_H
#include <QList>
#include <node.h>
#include <QOpenGLFunctions>
#include <QRandomGenerator>

using namespace std;

class List
{
private:
    QList<Node> boardList;
public:
    List();
    List(QList<QVector<int>> coordinateList);
    Node * returnAddress(int i);

    void addNode(Node a);
    void setPointer(Node * n, Node * m, int i);
    Node getNode(int pos);
    Node getNextNode(int pos, int counter, vector<QVector2D>* listOfMoves);
};

#endif // LIST_H
