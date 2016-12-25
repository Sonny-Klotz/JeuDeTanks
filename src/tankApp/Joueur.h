#ifndef JOUEUR_H
#define JOUEUR_H

#include <QGraphicsItemGroup>

/*!
 * \brief Classe abstraite servant de base à Individu et Ordinateur
 */
class Joueur : public QGraphicsItemGroup
{
private:
    Tank *tank;


public:
    virtual void jouerTour() = 0;
};

#endif // JOUEUR_H
