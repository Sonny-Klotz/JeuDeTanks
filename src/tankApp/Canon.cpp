
#include "Canon.h"

Canon::Canon(int X, int Y, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setPos(X, Y);
}

QRectF Canon::boundingRect() const{

    return QRectF(x(), y(), 6, 2);
}

void Canon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

        painter->fillRect(x(), y(), 6, 2, QBrush(Qt::darkGray));
        painter->drawRect(x(), y(), 6, 2);
}
