#ifndef ORDINATEUR_H
#define ORDINATEUR_H

#include "Point.h"
#include "Tank.h"
#include"Jeu.h"

#include <QList>
#include <QGraphicsItemGroup>
#include <cmath>
#include <typeinfo>
#include <QTimer>
#include <QObject>

class Ordinateur : public QGraphicsItemGroup
{
private:
    Tank *tank;

public:
    Ordinateur(Point posinit);
    void jouerTour();
    Tank *getTank();
};

#endif // ORDINATEUR_H
