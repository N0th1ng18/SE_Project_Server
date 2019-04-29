#ifndef POINT_H
#define POINT_H


class Point
{
private:
    int x, y;
public:
    Point(int x, int y);
    void setX(int num);
    void setY(int num);
    int getX();
    int getY();
};

#endif // POINT_H
