#ifndef TERRAIN_H
#define TERRAIN_H

#include "def.h"
#include "Heightmap.h"
#include "Obstacle.h"
#include "Point.h"
#include "Joueur.h"

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QList>
#include <QMutableListIterator>
#include <typeinfo>

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
