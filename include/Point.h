#ifndef POINT_H
#define POINT_H
class Point {
private:
    unsigned int x, y;
public:
    Point() {};
    Point(unsigned int x, unsigned int y) : x(x), y(y) {}
    unsigned int getX();
    unsigned int getY();
    void setX(unsigned int x);
    void setY(unsigned int y);
};
#endif
