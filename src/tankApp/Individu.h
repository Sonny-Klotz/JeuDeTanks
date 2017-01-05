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
    Tank *tank;
    Infos *infos;

public slots:
    void modifPivot(int newPivot);
    void modifAngle(int newAngle);
    void tirerObus1();
    void tirerObus2();
    void tirerObus3();

public:
    Individu(Point posinit);
    void keyPressEvent(QKeyEvent * event);

    friend class Jeu;
};

#endif // INDIVIDU_H
