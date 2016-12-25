#ifndef TANK_H
#define TANK_H

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QPainter>
#include <QDebug>
#include <QGraphicsScene>

class Tank: public QGraphicsItem{
private:
    bool tankEtat; //vrais si non-detruit faux si detruit
    int tankCapDeplacement; //initialisé à L/10
    int tankCanonAngle; // allant de 0 à 180 °
    int tankCanonPivot; // allant de 0 à 360 )
    int tankNbrObusT2; //initialisé à 10
    int tankNbrObusT3; //initialisé à 5
    int coordX;
    int coordY;
public:
    Tank();
    Tank(int X,int Y);
    void keyPressEvent(QKeyEvent * event);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


};
#endif // TANK_H
