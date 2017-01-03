#include "Tank.h"

Tank::Tank(int X, int Y, QGraphicsItem *parent) : QGraphicsItem(){
    tankEtat = true;
    tankCapDeplacement = LARGEUR / 10;
    tankCanonAngle = 90;
    tankCanonPivot = 0;
    tankNbrObusT2 = 10;
    tankNbrObusT3 = 5;
    vertical = true;
    setPos(X, Y);
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

void Tank::keyPressEvent(QKeyEvent *event){
    QList<QGraphicsItem *> collisions;
    QMutableListIterator<QGraphicsItem *> *liste;
    this->setTransformOriginPoint(10,10);

    if(event->key()== Qt::Key_Left && pos().x() >=5){
        if(vertical == true){vertical = false;}
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
        else
            infos->setPos(infos->x() - 10, infos->y());
    }

    if(event->key()== Qt::Key_Right && pos().x() <= LARGEUR - 15){
        if(vertical == true){vertical = false;}
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
        else
            infos->setPos(infos->x() + 10, infos->y());
    }

    if(event->key()== Qt::Key_Up && pos().y() >=5){
        if(vertical == false){vertical = true;}
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
        else
            infos->setPos(infos->x(), infos->y() - 10);
    }

    if(event->key()== Qt::Key_Down && pos().y() <= HAUTEUR - 15){
        if(vertical == false){vertical = true;}
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
        else
            infos->setPos(infos->x(), infos->y() + 10);
    }

}

