#ifndef ORDINATEUR_H
#define ORDINATEUR_H

#include "Point.h"
#include "Tank.h"

#include <QGraphicsItemGroup>

class Ordinateur : public QGraphicsItemGroup
{
private:
    Tank *tank;
public:
    Ordinateur(Point posinit);
    void jouerTour();
};

#endif // ORDINATEUR_H
