#ifndef INDIVIDU_H
#define INDIVIDU_H

#include "Point.h"
#include "Tank.h"
#include "Infos.h"

#include <QGraphicsItemGroup>

class Individu : public QGraphicsItemGroup
{
private:
    Tank *tank;
    Infos *infos;
public:
    Individu(Point posinit);
    void jouerTour();
    void keyPressEvent(QKeyEvent * event);

};

#endif // INDIVIDU_H
