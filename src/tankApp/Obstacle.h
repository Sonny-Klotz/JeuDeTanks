#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Point.h"
#include "Obus.h"

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QBrush>
#include <QColor>
#include <QPainterPath>

enum TypeObstacle {ARBRE, ROCHER, EAU, CREVASSE1, CREVASSE2, CREVASSE3, RIEN};

class Obstacle : public QGraphicsItem
{
private:
    TypeObstacle type;
    int resistance;
    Point pos;

public:
    Obstacle(TypeObstacle type, Point posinit);
    int getResistance() const;
    void setResistance(int newResistance);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    QPainterPath shape() const;
    TypeObstacle getType() const;

    friend class Obus;
};

#endif // OBSTACLE_H
