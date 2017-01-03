#ifndef OBUS_H
#define OBUS_H

#include "Obstacle.h"
#include "Point.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QList>
#include <QMutableListIterator>
#include <typeinfo>

class Obus : public QGraphicsItem {
private:
    int typeObus; //Vaut 1, 2 ou 3
    Point impact;

public:
    Obus(int X, int Y,Point destination, int selection, QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Obus();

};

#endif // OBUS_H
