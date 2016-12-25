#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include "Obstacle.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

#define MAXVAL 3

using std::cout;
using std::endl;

TypeObstacle heightToObs1(int i);

class Heightmap
{
private:
    int **map;
    int largeur;
    int hauteur;

public:
    Heightmap(int hauteur, int largeur);
    Heightmap(const Heightmap& h);
    ~Heightmap();
    void afficher();
    Heightmap& operator=(const Heightmap &h);

    friend TypeObstacle heightToObs1(int i);
    friend void initMethod1(Heightmap *h);
    friend class Terrain;
};

#endif // HEIGHTMAP_H
