#include "Jeu.h"

Jeu::Jeu() : QWidget()
{
    srand(time(NULL));
    //scene : carte avec obstacles et tanks
    scene = new QGraphicsScene(0, 0, LARGEUR, HAUTEUR);

    int x,y;
    ordinateurs = new Ordinateur*[NORDINATEURS];
    for(int i = 0; i < NORDINATEURS; i++) {
        x = rand() % (LARGEUR - 20);
        y = rand() % (HAUTEUR - 20);
        ordinateurs[i] = new Ordinateur(Point(x, y));
        ordinateurs[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        ordinateurs[i]->setZValue(5);
        scene->addItem(ordinateurs[i]);
    }
    joueurs = new Individu*[NINDIVIDUS];
    for(int i = 0; i < NINDIVIDUS; i++) {
        x = rand() % (LARGEUR - 20);
        y = rand() % (HAUTEUR - 20);
        joueurs[i] = new Individu(Point(x, y));
        joueurs[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        joueurs[i]->setZValue(5);
        scene->addItem(joueurs[i]);
    }
    joueurs[0]->setFocus(); //init au premier joueur arbitrairement pour l'instant

    terrain = new Terrain();
    terrain->initObstacles(scene);

    QGraphicsView *carte = new QGraphicsView(scene, this);
    scene->setBackgroundBrush(QBrush(QColor::fromRgb(197, 133, 61)));


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

    angleH->setMaximum(359);
    angleV->setMaximum(89);
    connect(angleH, SIGNAL(valueChanged(int)), joueurs[0], SLOT(modifPivot(int))); //car c'est le joueur ayant le focus
    connect(angleV, SIGNAL(valueChanged(int)), joueurs[0], SLOT(modifAngle(int)));

    connect(obus1, SIGNAL(pressed()), joueurs[0], SLOT(tirerObus1()));
    connect(obus2, SIGNAL(pressed()), joueurs[0], SLOT(tirerObus2()));
    connect(obus3, SIGNAL(pressed()), joueurs[0], SLOT(tirerObus3()));


}

Jeu::~Jeu()
{
    delete terrain;
}


