#ifndef TERRAIN_H
#define TERRAIN_H

#include "def.h"
#include "Heightmap.h"
#include "Obstacle.h"
#include "Point.h"

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QList>
#include <QMutableListIterator>
#include <typeinfo>

#define LARGEUR 700
#define HAUTEUR 400
#define S_MOY_OBS 242
#define DENSITE 0.07

class Terrain : public QGraphicsItemGroup

{
private:
    Heightmap *h;
    int nObstacles;

public:
    Terrain();
    ~Terrain();
    void initObstacles();
};

#endif // TERRAIN_H
