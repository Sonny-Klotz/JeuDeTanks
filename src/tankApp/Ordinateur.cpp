#include "Ordinateur.h"

Ordinateur::Ordinateur(Point posinit): QGraphicsItemGroup()
{
    tank = new Tank(posinit.getx(), posinit.gety());
    tank->setZValue(1);
    addToGroup(tank);
}

void Ordinateur::jouerTour()
{

}
