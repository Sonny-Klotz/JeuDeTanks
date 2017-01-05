
#include "Canon.h"

Tank::Tank(/*int X, int Y,*/ QGraphicsItem *parent) : QGraphicsItem(parent){
    CanonEtat = true;
    //setPos(X, Y);
}

QRectF Tank::boundingRect() const{

    return QRectF(x(), y(), 6, 2);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

        painter->fillRect(x(), y(), 6, 2, QBrush(Qt::darkGray));
        painter->drawRect(x(), y(), 6, 2);
}
