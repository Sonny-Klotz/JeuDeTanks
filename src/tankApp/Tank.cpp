#include "Tank.h"
#include <QDebug>

Tank::Tank(int X, int Y, QGraphicsItem *parent) : QGraphicsItem(){
    tankEtat = true;
    tankCapDeplacement = LARGEUR / 10;
    tankCanonAngle = 90;
    tankCanonPivot = 0;
    tankNbrObusT2 = 10;
    tankNbrObusT3 = 5;
    setPos(X, Y);
}

QRectF Tank::boundingRect() const{

    return QRectF(x(), y(), 20, 20);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    painter->fillRect(x() + 0, y() + 0, 3, 20, QBrush(Qt::darkGray));
    painter->drawRect(x() + 0, y() + 0, 3, 20);
    painter->fillRect(x() + 3, y() + 2, 14, 16, QBrush(Qt::lightGray));
    painter->drawRect(x() + 3, y() + 2, 14, 16);
    painter->fillRect(x() + 17, y() + 0, 3, 20, QBrush(Qt::darkGray));
    painter->drawRect(x() + 17, y() + 0, 3, 20);

}


void Tank::keyPressEvent(QKeyEvent *event){
    QList<QGraphicsItem *> collisions;
    QMutableListIterator<QGraphicsItem *> *liste;

    qDebug() << pos().x() << pos().y();
    //Les coordonées 0,0 sont dans le coin en haut a gauche de l'ecran
    if(event->key()== Qt::Key_Left && pos().x() >=5){
        setPos(x() - 5, y());

        collisions = scene()->collidingItems(this);
        liste = new QMutableListIterator<QGraphicsItem *>(collisions);
        while (liste->hasNext()) {
            QGraphicsItem *tmp = liste->next();
            if (typeid(*tmp) != typeid(Obstacle) && typeid(*tmp) != typeid(Tank))
                liste->remove();
        }

        if(!collisions.empty())
            setPos(x() + 5, y());
    }

    if(event->key()== Qt::Key_Right && pos().x() <= LARGEUR - 15){
        setPos(x() + 5, y());

        collisions = scene()->collidingItems(this);
        liste = new QMutableListIterator<QGraphicsItem *>(collisions);
        while (liste->hasNext()) {
            QGraphicsItem *tmp = liste->next();
            if (typeid(*tmp) != typeid(Obstacle) && typeid(*tmp) != typeid(Tank))
                liste->remove();
        }

        if(!collisions.empty())
            setPos(x() - 5, y());
    }

    if(event->key()== Qt::Key_Up && pos().y() >=5){
        setPos(x(), y() - 5);

        collisions = scene()->collidingItems(this);
        liste = new QMutableListIterator<QGraphicsItem *>(collisions);
        while (liste->hasNext()) {
            QGraphicsItem *tmp = liste->next();
            if (typeid(*tmp) != typeid(Obstacle) && typeid(*tmp) != typeid(Tank))
                liste->remove();
        }

        if(!collisions.empty())
            setPos(x(), y() + 5);
    }

    if(event->key()== Qt::Key_Down && pos().y() <= HAUTEUR - 15){
        setPos(x(), y() + 5);

        collisions = scene()->collidingItems(this);
        liste = new QMutableListIterator<QGraphicsItem *>(collisions);
        while (liste->hasNext()) {
            QGraphicsItem *tmp = liste->next();
            if (typeid(*tmp) != typeid(Obstacle) && typeid(*tmp) != typeid(Tank))
                liste->remove();
        }

        if(!collisions.empty())
            setPos(x(), y() - 5);
    }

}

