#include "Obus.h"

Obus::Obus(int X, int Y,Point destination,int selection, QGraphicsItem *parent) : QGraphicsItem(){
    typeObus = selection; // vaut 1, 2 ou 3 en fonction du bouton selectionnée
    impact = destination;
    setPos(X,Y);
}

QRectF Obus::boundingRect() const{

    return QRectF(x(), y(), 1, 1);
}

void Obus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(typeObus == 1){painter->fillRect(x(), y(), 1, 1, QBrush(Qt::yellow));}
    if(typeObus == 2){painter->fillRect(x(), y(), 1, 1, QBrush(Qt::darkYellow));}
    if(typeObus == 3){painter->fillRect(x(), y(), 1, 1, QBrush(Qt::red));}

}

Obus::~Obus(){
    if(typeObus == 1){new Obstacle (CREVASSE1, impact);}
    if(typeObus == 2){new Obstacle (CREVASSE2, impact);}
    if(typeObus == 3){new Obstacle (CREVASSE3, impact);}
}

