#include "Individu.h"

Individu::Individu(Point posinit): QGraphicsItemGroup()
{

    tank = new Tank(posinit.getx(), posinit.gety());
    tank->setZValue(qreal(1));
    addToGroup(tank);

    tank->infos = new Infos(tank);
    addToGroup(tank->infos);
    tank->infos->setZValue(qreal(5));
}

void Individu::keyPressEvent(QKeyEvent *event)
{
    tank->keyPressEvent(event);
}
