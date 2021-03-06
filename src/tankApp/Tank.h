#ifndef TANK_H
#define TANK_H

#include "def.h"
#include "Obstacle.h"
#include "Infos.h"
#include "Segment.h"
#include "Canon.h"

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QPainter>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QMutableListIterator>
#include <typeinfo>
#include <QPointF>

class Tank: public QGraphicsItem
{
private:
    bool tankEtat; //vrais si non-detruit faux si detruit
    int tankCapDeplacement; //initialisé à L/10
    int tankCanonAngle; // allant de 0 à  90
    int tankCanonPivot; // allant de 0 à 359
    int tankNbrObusT2; //initialisé à 10
    int tankNbrObusT3; //initialisé à 5
    bool vertical; //verifie le sens du tank
    Canon *canon;

public:
    Tank(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool canMove(QKeyEvent *event);
    void setCanonPivot(int newPivot);
    void setCanonAngle(int newAngle);
    Point impactpos();
    QPointF qtimpactpos();
    bool getTankEtat() const;
    void setTankEtat(bool newEtat);

    friend class Individu;
    friend class Ordinateur;
    friend class Infos;
};
#endif // TANK_H
