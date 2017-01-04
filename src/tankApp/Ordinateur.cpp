#include "Ordinateur.h"

Ordinateur::Ordinateur(Point posinit): QGraphicsItemGroup()
{
    setPos(posinit.getx(), posinit.gety());
    tank = new Tank(this);
    tank->setZValue(1);
    addToGroup(tank);
}

void Ordinateur::jouerTour()
{

}
