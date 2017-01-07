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
    int i;
    QList<QGraphicsItem *> liste = scene()->items();
    for(i = 0; i < liste.size() ; i++) {
        if(typeid(*liste[i]) == typeid(Individu)) {
            break;
        }
        if(typeid(*liste[i]) == typeid(Ordinateur)) {
            if(liste[i] != this) {
                break;
            }
        }
    }

    int pos2x = liste[i]->scenePos().x();
    int pos2y = liste[i]->scenePos().y();
    int pos1x = scenePos().x();
    int pos1y = scenePos().y();

    double distance = sqrt( pow((pos2x - pos1x), 2) + pow((pos2y - pos1y), 2) );
    if(distance < 100) tank->setCanonAngle( distance * 45 / 100);
    else tank->setCanonAngle(45);

    double angle;
    double d1, d2;
    d1 = distance;
    if(     pos2x > pos1x && pos2y > pos1y) {
        d2 = pos2x - pos1x;
        angle = acos( d2 / d1 );
    }
    else if(pos2x < pos1x && pos2y > pos1y) {
        d2 = pos2y - pos1y;
        angle = acos( d2 / d1 ) + PI / 2;
    }
    else if(pos2x < pos1x && pos2y < pos1y) {
        d2 = pos2x - pos1x;
        angle = acos( d2 / d1 ) + PI;
    }
    else /* pos2x > pos1x && pos2y < pos1y */{
        d2 = pos2y - pos1y;
        angle = acos( d2 / d1 ) + 3 * PI / 2;
    }
    angle = (angle * 360) / (2 * PI);
    tank->setCanonPivot((int) angle);



    Obus *obus = new Obus(x() + 10, y() + 10, tank->impactpos(), 1);
    obus->setZValue(qreal(6));
    scene()->addItem(obus);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), obus, SLOT(move()));
    timer->start(50);


    tank->tankCapDeplacement = LARGEUR / 10;
}

Tank *Ordinateur::getTank()
{
    return tank;
}
