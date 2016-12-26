#include "Ordinateur.h"

Ordinateur::Ordinateur(Point posinit): QGraphicsItemGroup()
{
    tank = new Tank(posinit.getx(), posinit.gety());
    tank->setZValue(1);
    addToGroup(tank);

    tank->infos = new Infos(tank);
    addToGroup(tank->infos);
    tank->infos->setZValue(qreal(5));
}

void Ordinateur::jouerTour()
{

}
