#include "point.h"

Point::Point(const int x, const int y)
{
    this->x = x;
    this->y = y;
}

Point::Point(const Point& p)
{
    this->x = p.x;
    this->y = p.y;
}


Point::~Point(){}
int Point::getx() const{ return x; }
int Point::gety() const{ return y; }
void Point::setx(int x){ this->x = x; }
void Point::sety(int y){ this->y = y; }

Point& Point::operator=(const Point& p)
{
    this->x = p.x;
    this->y = p.y;
    return *this;
}
