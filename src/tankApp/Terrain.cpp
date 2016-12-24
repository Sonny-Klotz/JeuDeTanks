#include "Terrain.h"

Terrain::Terrain()
{
    Heightmap *h = new Heightmap(HAUTEUR, LARGEUR);
    int nObstacles = DENSITE*LARGEUR*HAUTEUR/S_MOY_OBS;

    int i;
    Point *tmppos;
    Obstacle *tmpobs;
    TypeObstacle typeObs;
    for(i = 0; i < nObstacles; i++)
    {
        tmppos = new Point(rand() % LARGEUR, rand() % HAUTEUR);
        typeObs = heightToObs1(h->map[tmppos->gety()][tmppos->getx()]);
        tmpobs = new Obstacle(typeObs, *tmppos);


        switch(typeObs)
        {
            case(EAU): tmpobs->setZValue(qreal(2)); break;
            case(ROCHER): tmpobs->setZValue(qreal(3)); break;
            case(ARBRE): tmpobs->setZValue(qreal(4)); break;
            default: break;
        }

        addToGroup(tmpobs);
    }
}
