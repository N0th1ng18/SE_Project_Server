#include "node.h"
//
Node::Node(int x1, int x2, int y1, int y2)
{
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
    ptr1 = nullptr;

}
Node::~Node()
{

}

void Node::setX1(int x){
    x1 = x;
}

void Node::setX2(int x){
    x2 = x;
}
void Node::setY1(int y){
    y1 = y;
}

void Node::setY2(int y){
    y2 = y;
}

int Node::getX1(){
    return x1;
}

int Node::getX2(){
    return x2;
}

int Node::getY1(){
    return y1;
}

int Node::getY2(){
    return y2;
}

void Node::setPtr1(Node* node){
    ptr1 = node;
}
Node* Node::getPtr1(){
    return ptr1;
}
