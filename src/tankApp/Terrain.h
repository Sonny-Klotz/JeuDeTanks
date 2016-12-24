#ifndef TERRAIN_H
#define TERRAIN_H

#include "def.h"
#include "Heightmap.h"
#include "Obstacle.h"
#include "Point.h"
#include "Jeu.h"

#include <QGraphicsItemGroup>

#define LARGEUR 700
#define HAUTEUR 400
#define S_MOY_OBS 242
#define DENSITE 0.07

extern Jeu *jeu;

class Terrain : public QGraphicsItemGroup
{
public:
    Terrain();
};

#endif // TERRAIN_H
