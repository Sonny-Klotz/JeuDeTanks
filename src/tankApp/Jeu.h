#ifndef JEU_H
#define JEU_H

#include "def.h"
#include "Individu.h"
#include "Ordinateur.h"
#include "Terrain.h"
#include "Tank.h"

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QBrush>
#include <QColor>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <QThread>

#include <QDebug>

using std::cout;
using std::endl;

class Jeu : public QWidget
{
    Q_OBJECT

private:
    int tour;
    Terrain *terrain;
    Ordinateur **ordinateurs;
    Individu **joueurs;
    QSlider *angleH;
    QSlider *angleV;
    QPushButton *obus1;
    QPushButton *obus2;
    QPushButton *obus3;

public slots:
    void changeTourObus1();
    void changeTourObus2();
    void changeTourObus3();
    //void redonneFocus();

public:
    Jeu();
    ~Jeu();
    QGraphicsScene *scene;
    void premierTour();
    void changerTourOrdi();
    bool testFinPartie();
};

#endif // JEU_H
