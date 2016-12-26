#include "Infos.h"

Infos::Infos(Tank *t): QGraphicsTextItem()
{
    setPos(2*t->x() - 25, 2*t->y() - 15);
    setPlainText(QString::number(t->tankCapDeplacement) + ' ' +
                 QString::number(t->tankNbrObusT2) + ' ' +
                 QString::number(t->tankNbrObusT3) + ' ' +
                 QString::number(t->tankCanonAngle) + ' ' +
                 QString::number(t->tankCanonPivot));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("arial",8));
}
