#ifndef INDIVIDU_H
#define INDIVIDU_H

#include "Point.h"
#include "Joueur.h"

class Individu : public Joueur
{
public:
    Individu(Point posinit);
    void jouerTour();
    void keyPressEvent(QKeyEvent * event);

};

#endif // INDIVIDU_H
