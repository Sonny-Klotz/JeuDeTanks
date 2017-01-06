#include "Individu.h"

void Individu::modifPivot(int newPivot)
{
    if(actif) {

    tank->setCanonPivot(newPivot);
    infos->rewrite(tank);

    }
}

void Individu::modifAngle(int newAngle)
{
    if(actif) {

    tank->setCanonAngle(newAngle);
    infos->rewrite(tank);

    }
}

void Individu::tirerObus1()
{
    if(actif) {

    Obus *obus = new Obus(x() + 10, y() + 10, tank->impactpos(), 1);
    obus->setZValue(qreal(6));
    scene()->addItem(obus);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), obus, SLOT(move()));
    timer->start(50);

    actif = false;
    tank->tankCapDeplacement = LARGEUR / 10;
    infos->rewrite(tank);
    }
}

void Individu::tirerObus2()
{
    if(actif) {

    if(tank->tankNbrObusT2 > 0) {
        Obus *obus = new Obus(x() + 10, y() + 10, tank->impactpos(), 2);
        obus->setZValue(qreal(6));
        scene()->addItem(obus);

        QTimer *timer = new QTimer();
        connect(timer, SIGNAL(timeout()), obus, SLOT(move()));
        timer->start(50);

        tank->tankNbrObusT2--;
        infos->rewrite(tank);
    }
    tank->tankCapDeplacement = LARGEUR / 10;
    actif = false;
    infos->rewrite(tank);
    }
}

void Individu::tirerObus3()
{
    if(actif) {

    if(tank->tankNbrObusT3 > 0) {
        Obus *obus = new Obus(x() + 10, y() + 10, tank->impactpos(), 3);
        obus->setZValue(qreal(6));
        scene()->addItem(obus);

        QTimer *timer = new QTimer();
        connect(timer, SIGNAL(timeout()), obus, SLOT(move()));
        timer->start(50);

        tank->tankNbrObusT3--;
        infos->rewrite(tank);
    }
    tank->tankCapDeplacement = LARGEUR / 10;
    actif = false;
    infos->rewrite(tank);
    }
}

Tank *Individu::getTank()
{
    return tank;
}

Individu::Individu(Point posinit): QGraphicsItemGroup()
{
    actif = false;

    setPos(posinit.getx(), posinit.gety());
    tank = new Tank(this);
    tank->setZValue(qreal(1));
    addToGroup(tank);

    infos = new Infos(tank, this);
    infos->setZValue(qreal(5));
    addToGroup(infos);
}

void Individu::keyPressEvent(QKeyEvent *event)
{
    if(actif) {

    if(tank->canMove(event)) {
        if(event->key()== Qt::Key_Left) setPos(x() - 5, y());
        if(event->key()== Qt::Key_Right) setPos(x() + 5, y());
        if(event->key()== Qt::Key_Up) setPos(x(), y() - 5);
        if(event->key()== Qt::Key_Down) setPos(x(), y() + 5);

        QList<QGraphicsItem *> collisions;
        QMutableListIterator<QGraphicsItem *> *liste;

        collisions = scene()->collidingItems(tank);
        liste = new QMutableListIterator<QGraphicsItem *>(collisions);

        while (liste->hasNext()) {
            QGraphicsItem *tmp = liste->next();
            if(typeid(*tmp) == typeid(Obstacle)) {
                Obstacle *obs = (Obstacle *) tmp;
                if(obs->getType() != CREVASSE1 && obs->getType() != CREVASSE2 && obs->getType() != CREVASSE3)
                    liste->remove();
            }
            else liste->remove();
        }

        if(collisions.empty()) {
            tank->tankCapDeplacement -= 5;
            if(tank->tankCapDeplacement < 0) {
                if(event->key()== Qt::Key_Left) setPos(x() + 5, y());
                if(event->key()== Qt::Key_Right) setPos(x() - 5, y());
                if(event->key()== Qt::Key_Up) setPos(x(), y() + 5);
                if(event->key()== Qt::Key_Down) setPos(x(), y() - 5);
                tank->tankCapDeplacement += 5;
            }

        }
        else {
            tank->tankCapDeplacement -= 6;
            if(tank->tankCapDeplacement < 0) {
                if(event->key()== Qt::Key_Left) setPos(x() + 5, y());
                if(event->key()== Qt::Key_Right) setPos(x() - 5, y());
                if(event->key()== Qt::Key_Up) setPos(x(), y() + 5);
                if(event->key()== Qt::Key_Down) setPos(x(), y() - 5);
                tank->tankCapDeplacement += 6;
            }

        }
        infos->rewrite(tank);
    }

    }
}

