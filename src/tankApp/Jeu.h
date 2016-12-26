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

class Jeu : public QWidget
{
private:
    Terrain *terrain;
    Ordinateur **ordinateurs;
    Individu **joueurs;

public:
    Jeu();
    ~Jeu();
    QGraphicsScene *scene;
    void mousePressEvent(QMouseEvent *event);
};

#endif // JEU_H
