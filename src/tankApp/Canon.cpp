
#include "Canon.h"

Canon::Canon(int X, int Y, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setPos(X, Y);
}

QRectF Canon::boundingRect() const{

    return QRectF(x(), y(), 20, 20);
}

void Canon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

        painter->fillRect(x() + 10, y() + 9, 7, 3, QBrush(Qt::black));
        painter->drawRect(x() + 10, y() + 9, 7, 3);
}
