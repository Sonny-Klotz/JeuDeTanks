#include "Heightmap.h"

TypeObstacle heightToObs1(int i)
{
    TypeObstacle t;
    switch(i)
    {
        case(0): t = EAU; break;
        case(1): t = ARBRE; break;
        case(2): t = ROCHER; break;
        default: break;
    }
    return t;
}

void initMethod1(Heightmap *h)
{
    srand(time(NULL));

    int i,j, height;
    for(i = 0; i < h->hauteur ; i++)
    {
        for(j = 0; j < h->largeur; j++)
        {
            height =  rand() % MAXVAL;
            if(heightToObs1(height) == EAU || heightToObs1(height) == ROCHER )
            {
                height =  rand() % MAXVAL;
                if(heightToObs1(height) == EAU)
                    height =  rand() % MAXVAL;
            }
            h->map[i][j] = height;
        }
    }
}

Heightmap::Heightmap(int hauteur, int largeur)
{
    this->largeur = largeur;
    this->hauteur = hauteur;

    map = new int*[hauteur];
    int i,j;
    for(i = 0; i < hauteur; i++)
        map[i] = new int[largeur];

    for(i = 0; i < hauteur; i++)
        for(j = 0; j < largeur; j++)
            map[i][j] = -1;

    initMethod1(this);
}

Heightmap::Heightmap(const Heightmap &h)
{
    hauteur = h.largeur;
    largeur = h.largeur;

    map = new int*[hauteur];
    int i,j;
    for(i = 0; i < hauteur; i++)
        map[i] = new int[largeur];

    for(i = 0; i < hauteur; i++)
        for(j = 0; j < largeur; j++)
            map[i][j] = h.map[i][j];
}

Heightmap::~Heightmap()
{
    int i;
    for(i = 0; i < hauteur; i++)
        delete[] map[i];
    delete[] map;

    map = NULL;
}

void Heightmap::afficher()
{

    int i,j;
    for(i = 0; i < hauteur ; i++)
    {
        for(j = 0; j < largeur; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

Heightmap& Heightmap::operator=(const Heightmap &h)
{
    hauteur = h.largeur;
    largeur = h.largeur;


    int i,j;
    if(map == NULL)
    {
        map = new int*[hauteur];
        for(i = 0; i < hauteur; i++)
            map[i] = new int[largeur];
    }

    for(i = 0; i < hauteur; i++)
        for(j = 0; j < largeur; j++)
            map[i][j] = h.map[i][j];

    return *this;
}
