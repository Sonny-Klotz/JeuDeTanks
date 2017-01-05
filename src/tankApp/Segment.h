#ifndef SEGMENT_H
#define SEGMENT_H

#include "Point.h"
#include "def.h"

#include <cmath>

class Segment
{
    private:
        Point p1;
        Point p2;

    public:
        Segment(const Point& pp1, const Point& pp2);
        Segment(const Segment& s);
        Segment(const Point& pp1, int pivot, int angle);
        ~Segment();
        Point getp1() const;
        Point getp2() const;
};

#endif // SEGMENT_H
