#include "Tank.h"

Tank::Tank(int X, int Y) :QGraphicsItem(){
    tankEtat = true;
    tankCapDeplacement = 70; //à remplacer par la variable longuer/10
    tankCanonAngle = 90;
    tankCanonPivot = 0;
    tankNbrObusT2 = 10;
    tankNbrObusT3 = 5;
    coordX=X;
    coordY=Y;
}

QRectF Tank::boundingRect() const{

    return QRectF(coordX,coordY,20,20);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    QBrush brush(Qt::blue);
    painter->fillRect(coordX+0,coordY+0,3,18,brush);
    painter->drawRect(coordX+0,coordY+0,3,18);
    QBrush brush2(Qt::blue);
    painter->fillRect(coordX+3,coordY+1,10,16,brush2);
    painter->drawRect(coordX+3,coordY+1,10,16);
    QBrush brush3(Qt::blue);
    painter->fillRect(coordX+13,coordY+0,3,18,brush3);
    painter->drawRect(coordX+13,coordY+0,3,18);

}


void Tank::keyPressEvent(QKeyEvent *event){

    //Les coordonées 0,0 sont dans le coin en haut a gauche de l'ecran
    if(event->key()== Qt::Key_Left){
        setPos(x()-1,y());
        qDebug() <<"toucher G";
    }

    if(event->key()== Qt::Key_Right){
        setPos(x()+1,y());
        qDebug() <<"toucher D";
    }

    if(event->key()== Qt::Key_Up){
        setPos(x(),y()-1);
        qDebug() <<"toucher H";
    }

    if(event->key()== Qt::Key_Down){
        setPos(x(),y()+1);
        qDebug() <<"toucher B";
    }

}

