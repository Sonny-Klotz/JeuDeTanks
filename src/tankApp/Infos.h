#ifndef INFOS_H
#define INFOS_H

#include "Tank.h"

#include <QGraphicsTextItem>
#include <QString>

/*!
 * \brief Widget contenant les informations d'un tank
 */
class Infos : public QGraphicsTextItem
{
public:
    Infos(Tank *t, QGraphicsItem *parent = 0);
    void rewrite(Tank *t);

    friend class Individu;
    friend class Ordinateur;
};

#endif // INFOS_H
