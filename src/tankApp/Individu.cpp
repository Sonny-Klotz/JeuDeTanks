#include "Individu.h"

Individu::Individu(Point posinit)
{

    tank = new Tank(posinit.getx(), posinit.gety());
    tank->setZValue(1);
    addToGroup(tank);


}

void Individu::jouerTour()
{

}

void Individu::keyPressEvent(QKeyEvent *event)
{
    tank->keyPressEvent(event);
}
