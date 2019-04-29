#ifndef NODE_H
#define NODE_H
#include <QVector>

class Node
{
private:
    int x1, x2, y1, y2;
    Node * ptr1;

public:
    Node(int x1, int x2, int y1, int y2);
    ~Node();
    void setX1(int x);
    void setX2(int x);
    void setY1(int y);
    void setY2(int y);
    int getX1();
    int getX2();
    int getY1();
    int getY2();
    void setPtr1(Node* node);
    Node* getPtr1();
 };

#endif // NODE_H
