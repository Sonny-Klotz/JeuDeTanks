#ifndef JEU_H
#define JEU_H

#define NJOUEURS 2

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

class Jeu : public QWidget
{
private:
    Joueur joueurs[NJOUEURS];
    Terrain *terrain;
    QGraphicsView *carte;
    QPushButton *obus1;
    QPushButton *obus2;
    QPushButton *obus3;
    QSlider *angleH;
    QSlider *angleV;

public:
    Jeu();
};

#endif // JEU_H
