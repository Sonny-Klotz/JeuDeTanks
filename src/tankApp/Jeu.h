#ifndef JEU_H
#define JEU_H

#include "def.h"
#include "Joueur.h"
#include "Terrain.h"
#include "Individu.h"
#include "Ordinateur.h"
#include "Tank.h"

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QBrush>
#include <QColor>
#include <stdlib.h>
#include <time.h>

class Jeu : public QWidget
{
private:
    Terrain *terrain;
    Joueur **joueurs;

public:
    Jeu();
    ~Jeu();
    QGraphicsScene *scene;
};

#endif // JEU_H
