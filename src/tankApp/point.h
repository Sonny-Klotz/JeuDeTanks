#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y);
    Point(const Point& p);
    ~Point();
    int getx() const;
    int gety() const;
    void setx(int x);
    void sety(int y);
    Point& operator=(const Point& p);
};

#endif // POINT_H
