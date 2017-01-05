#include "Obus.h"

void Obus::move()
{
    if(impact.getx() == init.getx()) {
        if(y() != qreal(impact.gety())) {
            if(impact.gety() - init.gety() > 0) setPos(x(), y() + 1);
            else setPos(x(), y() - 1);
        }
        else delete this;
    }
    else if(impact.gety() == init.gety()) {
        if(y() != qreal(impact.gety())) {
            if(impact.getx() - init.getx() > 0) setPos(x() + 1, y());
            else setPos(x() - 1, y());
        }
        else delete this;
    }
    else {
        int pente = (impact.gety() - init.gety()) / (impact.getx() - init.getx());
        if(pente == 0) {
            pente = (impact.getx() - init.getx()) / (impact.gety() - init.gety());
            if(y() != qreal(impact.gety())) {
                if(impact.gety() - init.gety() > 0) setPos(x() + pente, y() + 1);
                else setPos(x() - pente, y() - 1);
            }
            else delete this;
        }
        else {
            if(x() != qreal(impact.getx())) {
                if(impact.getx() - init.getx() > 0) setPos(x() + 1, y() + pente);
                else setPos(x() - 1, y() - pente);
            }
            else delete this;
        }
    }
}

Obus::Obus(int X, int Y,Point destination,int selection, QGraphicsItem *parent) : QGraphicsItem(parent), init(X, Y), impact(destination)
{
    typeObus = selection; // vaut 1, 2 ou 3 en fonction du bouton selectionnée
    setPos(X,Y);
    setZValue(qreal(6));
}

QRectF Obus::boundingRect() const
{
    return QRectF(0, 0, 5, 5);
}

void Obus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(typeObus == 1){painter->setBrush(QBrush(Qt::yellow)); painter->drawEllipse(QRectF(0, 0, 5, 5));}
    if(typeObus == 2){painter->setBrush(QBrush(Qt::darkYellow)); painter->drawEllipse(QRectF(0, 0, 5, 5));}
    if(typeObus == 3){painter->setBrush(QBrush(Qt::red)); painter->drawEllipse(QRectF(0, 0, 5, 5));}

}

Obus::~Obus(){
    Obstacle *obs;
    TypeObstacle type;

    if(typeObus == 1) {
        type = CREVASSE1;
        obs = new Obstacle (type, Point(impact.getx() - 3, impact.gety() - 3));
    }
    else if(typeObus == 2) {
        type = CREVASSE2;
        obs = new Obstacle (type, Point(impact.getx() - 10, impact.gety() - 10));
    }
    else{
        type = CREVASSE3;
        obs = new Obstacle (type, Point(impact.getx() - 14, impact.gety() - 14));
    }

    obs->setZValue(qreal(0));
    scene()->addItem(obs);
}

