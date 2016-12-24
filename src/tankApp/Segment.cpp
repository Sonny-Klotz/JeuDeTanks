#include "Segment.h"

Segment::Segment(const Point& pp1, const Point& pp2) : p1(pp1), p2(pp2){}
Point Segment::getp1() const{ return p1; }
Point Segment::getp2() const{ return p2; }
Segment::Segment(const Segment& s): p1(s.getp1()), p2(s.getp2()){}
Segment::~Segment(){}
