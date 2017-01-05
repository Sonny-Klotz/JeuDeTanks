#include <QApplication>
#include "def.h"
#include "Jeu.h"
#include "Heightmap.h"

/*!
 * \file main.cpp
 * \brief Application Jeu de tanks
 * \author Sonny Klotz - Florian Lienhardt
 *
 * La fonciton main gère l'application.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Jeu *jeu = new Jeu();
    jeu->show();

    return a.exec();
}
