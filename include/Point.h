#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
    unsigned int x, y;
public:
    Point() {};
    Point(unsigned int x, unsigned int y) : x(x), y(y) {}
    unsigned int getX() const;
    unsigned int getY() const;
    void setX(unsigned int x);
    void setY(unsigned int y);
    bool operator==(const Point &pos);
    friend std::ostream& operator<< (std::ostream &out, Point &pos);
};
#endif
