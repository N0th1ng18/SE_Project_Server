#ifndef NODE_H
#define NODE_H
#include <QVector>

class Node
{
private:
    int x1, x2, y1, y2;
    Node * ptr1;
    Node * ptr2;

public:
    Node();
    Node(QVector<int> qv);
    void setPointer(Node * n, Node * m);
    Node getNode(Node * n);
    QVector<int> getCoordinates(Node n);
    Node * getPointer1();
    Node * getPointer2();
 };

#endif // NODE_H
