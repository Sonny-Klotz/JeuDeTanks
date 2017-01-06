#include "Jeu.h"

void Jeu::changeTourObus1()
{
    joueurs[tour - NORDINATEURS]->tirerObus1();
    changerTourOrdi(0);
}

void Jeu::changeTourObus2()
{
    joueurs[tour - NORDINATEURS]->tirerObus2();
    changerTourOrdi(0);
}

void Jeu::changeTourObus3()
{
    joueurs[tour - NORDINATEURS]->tirerObus3();
    changerTourOrdi(0);
}
/*
void Jeu::redonneFocus()
{
    angleH->clearFocus();
    angleV->clearFocus();

    if(tour >= NORDINATEURS) {
        joueurs[tour - NORDINATEURS]->setFocus();
        qDebug() << joueurs[tour - NORDINATEURS]->hasFocus();
    }
}*/

Jeu::Jeu() : QWidget()
{
    srand(time(NULL));

    scene = new QGraphicsScene(0, 0, LARGEUR, HAUTEUR);

    int x,y;
    ordinateurs = new Ordinateur*[NORDINATEURS];
    for(int i = 0; i < NORDINATEURS; i++) {
        x = rand() % (LARGEUR - 20);
        y = rand() % (HAUTEUR - 20);
        ordinateurs[i] = new Ordinateur(Point(x, y));
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
    premierTour();

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

    for(int i = 0; i < NINDIVIDUS; i++) {
        connect(angleH, SIGNAL(valueChanged(int)), joueurs[i], SLOT(modifPivot(int)));
        connect(angleV, SIGNAL(valueChanged(int)), joueurs[i], SLOT(modifAngle(int)));
    }

    connect(obus1, SIGNAL(pressed()), this, SLOT(changeTourObus1()));
    connect(obus2, SIGNAL(pressed()), this, SLOT(changeTourObus2()));
    connect(obus3, SIGNAL(pressed()), this, SLOT(changeTourObus3()));
/*
    connect(angleH, SIGNAL(sliderReleased()), this, SLOT(redonneFocus()));
    connect(angleV, SIGNAL(sliderReleased()), this, SLOT(redonneFocus())); */

}

Jeu::~Jeu()
{
    delete terrain;
}

void Jeu::premierTour()
{
    tour = rand() % (NORDINATEURS + NINDIVIDUS);

    if(tour < NORDINATEURS) {
        ordinateurs[tour]->jouerTour(this);
    }
    else {
        joueurs[tour - NORDINATEURS]->setFocus();
        joueurs[tour - NORDINATEURS]->actif = true;
    }
}

void Jeu::changerTourOrdi(int nbre)
{
    if(nbre == NORDINATEURS + NINDIVIDUS - 1) {
        cout << "Fin de partie" << endl;
        exit(EXIT_SUCCESS);
    }

    qDebug() << nbre;
    tour = (tour + 1) % (NORDINATEURS + NINDIVIDUS);
    if(tour < NORDINATEURS && ordinateurs[tour]->getTank()->getTankEtat()) {
        ordinateurs[tour]->jouerTour(this);
    }
    else if(tour >= NORDINATEURS && joueurs[tour - NORDINATEURS]->getTank()->getTankEtat()){
        joueurs[tour - NORDINATEURS]->setFocus();
        joueurs[tour - NORDINATEURS]->actif = true;
    }
    else {
        changerTourOrdi(++nbre);
    }
}
