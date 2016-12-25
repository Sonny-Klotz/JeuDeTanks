#ifndef JEU_H
#define JEU_H

#define NINDIVIDUS 1
#define NORDINATEURS 1

#include "def.h"
#include "Terrain.h"
#include "Joueur.h"
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
