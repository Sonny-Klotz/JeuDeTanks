#include "Obstacle.h"

Obstacle::Obstacle(TypeObstacle type, Point posinit): pos(posinit.getx(), posinit.gety())
{
    this->type = type;
    switch(type) {
    case(ARBRE): resistance = 1; break;
    case(ROCHER): resistance = 7; break;
    case(EAU): resistance = 10; break;
    case(CREVASSE1):
    case(CREVASSE2):
    case(CREVASSE3):
        resistance = -2;
        break;
    default: break;
    }
}

int Obstacle::getResistance() const{ return resistance; }

QRectF Obstacle::boundingRect() const
{
    QRectF *rect;
    switch(type) {
        case(ARBRE): rect = new QRectF(pos.getx(), pos.gety(), 15, 15); break;
        case(ROCHER): rect = new QRectF(pos.getx(), pos.gety(), 10, 10); break;
        case(EAU): rect = new QRectF(pos.getx(), pos.gety(), 20, 20); break;
        case(CREVASSE1): rect = new QRectF(pos.getx(), pos.gety(), 5, 5); break;
        case(CREVASSE2): rect =  new QRectF(pos.getx(), pos.gety(), 20, 20); break;
        case(CREVASSE3): rect =  new QRectF(pos.getx(), pos.gety(), 25, 25); break;
        default: rect = NULL; break;
    }
    return *rect;
}

void Obstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(type) {
        case(ARBRE): {
            painter->setBrush(QBrush(QColor::fromRgb(83, 178, 68)));
            painter->drawEllipse(QRectF(pos.getx(), pos.gety(), 20, 20));
            break; }
        case(ROCHER): {
            painter->setBrush(QBrush(QColor::fromRgb(170, 170, 170)));
            painter->drawRoundedRect(QRectF(pos.getx(), pos.gety(), 15, 15), 5, 5);
            break; }
        case(EAU): {
            painter->setBrush(QBrush(QColor::fromRgb(21, 90, 164)));
            painter->drawEllipse(QRectF(pos.getx(), pos.gety() + 5, 50, 40));
            break; }
        case(CREVASSE1): {
            painter->setBrush(QBrush(QColor::fromRgb(89,36,22)));
            painter->drawEllipse(QRectF(pos.getx(), pos.gety(), 5, 5));
            break; }
        case(CREVASSE2): {
            painter->setBrush(QBrush(QColor::fromRgb(89,36,22)));
            painter->drawEllipse(QRectF(pos.getx(), pos.gety(), 20, 20));
            break; }
        case(CREVASSE3): {
            painter->setBrush(QBrush(QColor::fromRgb(89,36,22)));
            painter->drawEllipse(QRectF(pos.getx(), pos.gety(), 25, 25));
            break; }
        default: break;
    }

}
