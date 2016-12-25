#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Point.h"

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QBrush>
#include <QColor>

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
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
};

#endif // OBSTACLE_H
