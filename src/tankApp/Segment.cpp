#include "Segment.h"
#include <QDebug>
Segment::Segment(const Point& pp1, const Point& pp2) : p1(pp1), p2(pp2){}
Point Segment::getp1() const{ return p1; }
Point Segment::getp2() const{ return p2; }
Segment::Segment(const Segment& s): p1(s.getp1()), p2(s.getp2()){}

Segment::Segment(const Point &pp1, int pivot, int angle) : p1(pp1), p2(0, 0)
{
    //pivot pour la directioon, angle pour la distance
    int distance;
    if(angle < 45) distance = angle * (100 / 45);
    else distance = (90 - angle) * (100 / 45);
    double rad = pivot * (2 * PI) / 360;

    int x, y;
    if(pivot > 90 && pivot < 270)
        x = pp1.getx() - sqrt( (cos(2*rad) + 1) * pow(distance, 2) / 2 );
    else
        x = sqrt( (cos(2*rad) + 1) * pow(distance, 2) / 2 ) + pp1.getx();

    if(pivot > 180)
        y = pp1.gety() - sqrt( pow(distance, 2) - pow(x - pp1.getx(), 2) );
    else
        y = sqrt( pow(distance, 2) - pow(x - pp1.getx(), 2) ) + pp1.gety();

    p2.setx(x);
    p2.sety(y);
}
Segment::~Segment(){}
