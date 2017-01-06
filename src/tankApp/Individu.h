#ifndef INDIVIDU_H
#define INDIVIDU_H

#include "def.h"
#include "Point.h"
#include "Tank.h"
#include "Jeu.h"
#include "Obus.h"

#include <QGraphicsItemGroup>
#include <QTimer>

class Individu : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT

private:
    bool actif; //true si c'est son tour de jouer
    Tank *tank;
    Infos *infos;

public slots:
    void modifPivot(int newPivot);
    void modifAngle(int newAngle);

public:
    Individu(Point posinit);
    void keyPressEvent(QKeyEvent * event);
    void tirerObus1();
    void tirerObus2();
    void tirerObus3();
    Tank *getTank();

    friend class Jeu;
};

#endif // INDIVIDU_H
