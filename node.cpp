#include "node.h"

Node::Node(){
    x1 = 0;
    x2 = 0;
    y1 = 0;
    y2 = 0;
}

Node::Node(QVector<int> qv){
    x1 =qv.at(0);
    x2 = qv.at(1);
    y1 = qv.at(2);
    y2 = qv.at(3);
}

void Node::setPointer(Node * n, Node * m){
    ptr1 = n;
    ptr2 = m;
}

Node * Node::getPointer1(){
    return ptr1;
}

Node * Node::getPointer2(){
    return ptr2;
}

Node Node::getNode(Node * n){
    return *n;
}

QVector<int> Node::getCoordinates(Node n){
    int tL = n.x1;
    int tR = n.x2;
    int bL = n.y1;
    int bR = n.y2;

    QVector<int> qv = {tL, tR, bL, bR};
    return qv;
}
