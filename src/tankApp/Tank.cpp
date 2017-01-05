#include "Tank.h"

void Tank::setCanonPivot(int newPivot)
{
    tankCanonPivot = newPivot;
}

void Tank::setCanonAngle(int newAngle)
{
    tankCanonAngle = newAngle;
}

QPointF Tank::qtimpactpos()
{
    Segment trajectoire(Point(scenePos().x() + 10, scenePos().y() + 10), tankCanonPivot, tankCanonAngle);
    return QPointF(trajectoire.getp2().getx(), trajectoire.getp2().gety());
}

Point Tank::impactpos()
{
    Segment trajectoire(Point(scenePos().x() + 10, scenePos().y() + 10), tankCanonPivot, tankCanonAngle);
    return Point(trajectoire.getp2().getx(), trajectoire.getp2().gety());
}

Tank::Tank(QGraphicsItem *parent) : QGraphicsItem(parent){
    tankEtat = true;
    tankCapDeplacement = LARGEUR / 10;
    tankCanonAngle = 0;
    tankCanonPivot = 0;
    tankNbrObusT2 = 10;
    tankNbrObusT3 = 5;
    vertical = true;
}

QRectF Tank::boundingRect() const{

    return QRectF(x(), y(), 20, 20);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(vertical == true){
        painter->fillRect(x() + 1, y() + 0, 3, 20, QBrush(Qt::darkGray));
        painter->drawRect(x() + 1, y() + 0, 3, 20);
        painter->fillRect(x() + 4, y() + 2, 14, 16, QBrush(Qt::lightGray));
        painter->drawRect(x() + 4, y() + 2, 14, 16);
        painter->fillRect(x() + 18, y() + 0, 3, 20, QBrush(Qt::darkGray));
        painter->drawRect(x() + 18, y() + 0, 3, 20);
        painter->drawEllipse(QPointF(x() + 11, y() + 10),5,5);
    }

    if(vertical == false){
        painter->fillRect(x() + 0, y() + 1, 20, 3, QBrush(Qt::darkGray));
        painter->drawRect(x() + 0, y() + 1, 20, 3);
        painter->fillRect(x() + 2, y() + 4, 16, 14, QBrush(Qt::lightGray));
        painter->drawRect(x() + 2, y() + 4, 16, 14);
        painter->fillRect(x() + 0, y() + 18, 20, 3, QBrush(Qt::darkGray));
        painter->drawRect(x() + 0, y() + 18, 20, 3);
        painter->drawEllipse(QPointF(x() + 10, y() + 11),5,5);
    }
}

bool Tank::canMove(QKeyEvent *event)
{
    bool libre = true;
    QList<QGraphicsItem *> collisions;
    QMutableListIterator<QGraphicsItem *> *liste;

    if(event->key()== Qt::Key_Left){
        setPos(x() - 5, y());

        collisions = scene()->collidingItems(this);
        liste = new QMutableListIterator<QGraphicsItem *>(collisions);
        while (liste->hasNext()) {
            QGraphicsItem *tmp = liste->next();
            if(typeid(*tmp) == typeid(Obstacle)) {
                Obstacle *obs = (Obstacle *) tmp;
                if(obs->getType() == CREVASSE1 || obs->getType() == CREVASSE2 || obs->getType() == CREVASSE3)
                    liste->remove();
            }
            if (typeid(*tmp) != typeid(Obstacle) && typeid(*tmp) != typeid(Tank))
                liste->remove();
        }

        if(!collisions.empty() || scenePos().x() < 0)
            libre = false;

        setPos(x() + 5, y());
        vertical = false;
    }

    if(event->key()== Qt::Key_Right){
        setPos(x() + 5, y());

        collisions = scene()->collidingItems(this);
        liste = new QMutableListIterator<QGraphicsItem *>(collisions);
        while (liste->hasNext()) {
            QGraphicsItem *tmp = liste->next();
            if(typeid(*tmp) == typeid(Obstacle)) {
                Obstacle *obs = (Obstacle *) tmp;
                if(obs->getType() == CREVASSE1 || obs->getType() == CREVASSE2 || obs->getType() == CREVASSE3)
                    liste->remove();
            }
            if (typeid(*tmp) != typeid(Obstacle) && typeid(*tmp) != typeid(Tank))
                liste->remove();
        }
        if(!collisions.empty() || scenePos().x() > LARGEUR - 20)
            libre = false;

        setPos(x() - 5, y());
        vertical = false;
    }

    if(event->key()== Qt::Key_Up){
        setPos(x(), y() - 5);

        collisions = scene()->collidingItems(this);
        liste = new QMutableListIterator<QGraphicsItem *>(collisions);
        while (liste->hasNext()) {
            QGraphicsItem *tmp = liste->next();
            if(typeid(*tmp) == typeid(Obstacle)) {
                Obstacle *obs = (Obstacle *) tmp;
                if(obs->getType() == CREVASSE1 || obs->getType() == CREVASSE2 || obs->getType() == CREVASSE3)
                    liste->remove();
            }
            if (typeid(*tmp) != typeid(Obstacle) && typeid(*tmp) != typeid(Tank))
                liste->remove();
        }
        if(!collisions.empty() || scenePos().y() < 0)
            libre = false;

        setPos(x(), y() + 5);
        vertical = true;
    }

    if(event->key()== Qt::Key_Down){
        if(vertical == true){vertical = false;}
        setPos(x(), y() + 5);

        collisions = scene()->collidingItems(this);
        liste = new QMutableListIterator<QGraphicsItem *>(collisions);
        while (liste->hasNext()) {
            QGraphicsItem *tmp = liste->next();
            if(typeid(*tmp) == typeid(Obstacle)) {
                Obstacle *obs = (Obstacle *) tmp;
                if(obs->getType() == CREVASSE1 || obs->getType() == CREVASSE2 || obs->getType() == CREVASSE3)
                    liste->remove();
            }
            if (typeid(*tmp) != typeid(Obstacle) && typeid(*tmp) != typeid(Tank))
                liste->remove();
        }
        if(!collisions.empty() || scenePos().y() > HAUTEUR - 20)
            libre = false;

        setPos(x(), y() - 5);
        vertical = true;

    }

    return libre;
}

