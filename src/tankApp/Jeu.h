#ifndef JEU_H
#define JEU_H

#define NJOUEURS 2

#include "def.h"
#include "Terrain.h"
#include "Joueur.h"

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
public:
    Jeu();
    QGraphicsScene *scene;
};

#endif // JEU_H
