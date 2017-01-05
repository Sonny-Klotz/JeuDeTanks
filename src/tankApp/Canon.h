#ifndef CANON_H
#define CANON_H

#include "def.h"
#include "Obstacle.h"
#include "Infos.h"

//Pas sure si tout les include sont necessaire, enplus tu vas devoire faire une liste de canons

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QPainter>
#include <QGraphicsScene>
#include <QList>
#include <QMutableListIterator>
#include <typeinfo>

class Canon: public QGraphicsItem{
private:

public:
    Canon(int X,int Y, QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // CANON_H
