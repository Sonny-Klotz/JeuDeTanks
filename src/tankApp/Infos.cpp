#include "Infos.h"

Infos::Infos(Tank *t, QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setPos(pos().x() - 20, pos().y() - 15);
    setPlainText(QString::number(t->tankCapDeplacement) + ' ' +
                 QString::number(t->tankNbrObusT2) + ' ' +
                 QString::number(t->tankNbrObusT3) + ' ' +
                 QString::number(t->tankCanonAngle) + ' ' +
                 QString::number(t->tankCanonPivot));
    setDefaultTextColor(Qt::black);
    setFont(QFont("arial",7));
}

void Infos::rewrite(Tank *t)
{
    setPlainText(QString::number(t->tankCapDeplacement) + ' ' +
                 QString::number(t->tankNbrObusT2) + ' ' +
                 QString::number(t->tankNbrObusT3) + ' ' +
                 QString::number(t->tankCanonAngle) + ' ' +
                 QString::number(t->tankCanonPivot));
}
