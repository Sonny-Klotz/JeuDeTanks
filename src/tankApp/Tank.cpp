#include "Tank.h"

Tank::Tank(int X, int Y) : QGraphicsItem(){
    tankEtat = true;
    tankCapDeplacement = LARGEUR / 10;
    tankCanonAngle = 90;
    tankCanonPivot = 0;
    tankNbrObusT2 = 10;
    tankNbrObusT3 = 5;
    coordX=X;
    coordY=Y;
}

QRectF Tank::boundingRect() const{

    return QRectF(coordX,coordY,20,20);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    painter->fillRect(coordX+0,coordY+0,3,20,QBrush(Qt::darkGray));
    painter->drawRect(coordX+0,coordY+0,3,20);
    painter->fillRect(coordX+3,coordY+2,14,16,QBrush(Qt::lightGray));
    painter->drawRect(coordX+3,coordY+2,14,16);
    painter->fillRect(coordX+17,coordY+0,3,20,QBrush(Qt::darkGray));
    painter->drawRect(coordX+17,coordY+0,3,20);

}


void Tank::keyPressEvent(QKeyEvent *event){
    QList<QGraphicsItem *> collisions;
    QMutableListIterator<QGraphicsItem *> *liste;

    //Les coordonées 0,0 sont dans le coin en haut a gauche de l'ecran
    if(event->key()== Qt::Key_Left && scenePos().x() >= 5){
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

    if(event->key()== Qt::Key_Right && scenePos().x() <= LARGEUR - 25){
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

    if(event->key()== Qt::Key_Up && y() >= 5){
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

    if(event->key()== Qt::Key_Down && y() <= HAUTEUR - 25){
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

