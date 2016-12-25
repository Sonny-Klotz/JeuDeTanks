#ifndef ORDINATEUR_H
#define ORDINATEUR_H

#include "Point.h"
#include "Joueur.h"

class Ordinateur : public Joueur
{
public:
    Ordinateur(Point posinit);
    void jouerTour();
};

#endif // ORDINATEUR_H
