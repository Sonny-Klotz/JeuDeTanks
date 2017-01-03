#ifndef JEU_H
#define JEU_H

#include "def.h"
#include "Individu.h"
#include "Ordinateur.h"
#include "Terrain.h"
#include "Tank.h"

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QBrush>
#include <QColor>
#include <stdlib.h>
#include <time.h>

#include <QDebug>

class Jeu : public QWidget
{
    Q_OBJECT

private:
    Terrain *terrain;
    Ordinateur **ordinateurs;
    Individu **joueurs;
    QSlider *angleH;
    QSlider *angleV;
    QPushButton *obus1;
    QPushButton *obus2;
    QPushButton *obus3;

public slots:
    void sliderValue(int k);
    void boutonObus();

public:
    Jeu();
    ~Jeu();
    QGraphicsScene *scene;
};

#endif // JEU_H
