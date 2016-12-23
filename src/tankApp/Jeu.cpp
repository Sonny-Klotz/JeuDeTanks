#include "Jeu.h"

Jeu::Jeu() : QWidget()
{
    // scene : carte avec obstacles et tanks
    QGraphicsScene *scene = new QGraphicsScene(0, 0, LARGEUR, HAUTEUR, this);
    /* ici on ajoutera a "scene" les elements d'un new Terrain() et les new MyTank()
     * pour pouvoir les afficher */
    carte = new QGraphicsView(scene, this);


    // positionnement des widgets
    QHBoxLayout *obusLayout = new QHBoxLayout();
    obus1 = new QPushButton("OBUS 1", this);
    obus2 = new QPushButton("OBUS 2", this);
    obus3 = new QPushButton("OBUS 3", this);
    obusLayout->addWidget(obus1);
    obusLayout->addWidget(obus2);
    obusLayout->addWidget(obus3);

    QHBoxLayout *anglesLayout = new QHBoxLayout();
    angleH = new QSlider(Qt::Horizontal, this);
    angleV = new QSlider(Qt::Vertical, this);
    anglesLayout->addWidget(angleH);
    anglesLayout->addWidget(angleV);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(carte);
    layout->addLayout(anglesLayout);
    layout->addLayout(obusLayout);
    setLayout(layout);
}
