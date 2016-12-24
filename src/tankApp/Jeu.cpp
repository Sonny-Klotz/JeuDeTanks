#include "Jeu.h"

Jeu::Jeu() : QWidget()
{
    //scene : carte avec obstacles et tanks
    scene = new QGraphicsScene(0, 0, LARGEUR, HAUTEUR, this);
    /* ici on ajoutera a "scene" les elements d'un new Terrain() et les new MyTank()
     * pour pouvoir les afficher */

    terrain = new Terrain();
    scene->addItem(terrain);
    terrain->initObstacles();

    QGraphicsView *carte = new QGraphicsView(scene, this);
    scene->setBackgroundBrush(QBrush(QColor::fromRgb(197, 133, 61)));


    // positionnement des widgets
    QHBoxLayout *obusLayout = new QHBoxLayout();
    QPushButton *obus1 = new QPushButton("OBUS 1", this);
    QPushButton *obus2 = new QPushButton("OBUS 2", this);
    QPushButton *obus3 = new QPushButton("OBUS 3", this);
    obusLayout->addWidget(obus1);
    obusLayout->addWidget(obus2);
    obusLayout->addWidget(obus3);

    QHBoxLayout *anglesLayout = new QHBoxLayout();
    QSlider *angleH = new QSlider(Qt::Horizontal, this);
    QSlider *angleV = new QSlider(Qt::Vertical, this);
    anglesLayout->addWidget(angleH);
    anglesLayout->addWidget(angleV);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(carte);
    layout->addLayout(anglesLayout);
    layout->addLayout(obusLayout);
    setLayout(layout);
}
