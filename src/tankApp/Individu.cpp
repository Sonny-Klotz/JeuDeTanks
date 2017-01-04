#include "Individu.h"

Individu::Individu(Point posinit): QGraphicsItemGroup()
{
    setPos(posinit.getx(), posinit.gety());
    tank = new Tank(this);
    tank->setZValue(qreal(1));
    addToGroup(tank);

    infos = new Infos(tank, this);
    addToGroup(infos);
    infos->setZValue(qreal(5));
}

void Individu::keyPressEvent(QKeyEvent *event)
{
    if(tank->canMove(event)) {
        if(event->key()== Qt::Key_Left) setPos(x() - 5, y());
        if(event->key()== Qt::Key_Right) setPos(x() + 5, y());
        if(event->key()== Qt::Key_Up) setPos(x(), y() - 5);
        if(event->key()== Qt::Key_Down) setPos(x(), y() + 5);
    }
}
