#include <iostream>
#include "Point.h"

unsigned int Point::getX() const {
    return x;
}

unsigned int Point::getY() const {
    return y;
}

void Point::setX(unsigned int x) {
    this->x = x;
}

void Point::setY(unsigned int y) {
    this->y = y;
}

bool Point::operator==(const Point &pos) {
    return x == pos.getX() && y == pos.getY();
}

std::ostream& operator<< (std::ostream &out, Point &pos) {
    out << "[" << pos.getX() << ", " << pos.getY() << "]";
    return out;
}
