#include "Terrain.h"

Terrain::Terrain()
{
    h = new Heightmap(HAUTEUR, LARGEUR);
    nObstacles = DENSITE*LARGEUR*HAUTEUR/S_MOY_OBS;
}

Terrain::~Terrain()
{
    delete h;
}

void Terrain::initObstacles(QGraphicsScene *scene)
{
    int i = 0;
    Point *tmppos;
    Obstacle *tmpobs;
    TypeObstacle typeObs;

    QList<QGraphicsItem *> collisions;
    QMutableListIterator<QGraphicsItem *> *liste;
    while(i < nObstacles)
    {
        tmppos = new Point(rand() % (LARGEUR - 15) , rand() % (HAUTEUR - 15));
        typeObs = heightToObs1(h->map[tmppos->gety()][tmppos->getx()]);
        tmpobs = new Obstacle(typeObs, *tmppos);

        collisions = scene->collidingItems(tmpobs);
        liste = new QMutableListIterator<QGraphicsItem *>(collisions);
        while (liste->hasNext()) {
            QGraphicsItem *tmp = liste->next();
            if (typeid(*tmp) != typeid(Obstacle) && typeid(*tmp) != typeid(Tank))
                liste->remove();
        }
        if(collisions.empty())
        {
            switch(typeObs)
            {
                case(EAU): tmpobs->setZValue(qreal(2)); break;
                case(ROCHER): tmpobs->setZValue(qreal(3)); break;
                case(ARBRE): tmpobs->setZValue(qreal(4)); break;
                default: break;
            }

            scene->addItem(tmpobs);
            i++;
        }
    }
}
