#include "Jeu.h"

Jeu::Jeu() : QWidget()
{
    srand(time(NULL));
    //scene : carte avec obstacles et tanks
    scene = new QGraphicsScene(0, 0, 2*LARGEUR, 2*HAUTEUR);

    int x,y;
    ordinateurs = new Ordinateur*[NORDINATEURS];
    for(int i = 0; i < NORDINATEURS; i++) {
        x = rand() % (LARGEUR - 20);
        y = rand() % (HAUTEUR - 20);
        ordinateurs[i] = new Ordinateur(Point(x, y));
        ordinateurs[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        scene->addItem(ordinateurs[i]);
    }
    joueurs = new Individu*[NINDIVIDUS];
    for(int i = 0; i < NINDIVIDUS; i++) {
        x = rand() % (LARGEUR - 20);
        y = rand() % (HAUTEUR - 20);
        joueurs[i] = new Individu(Point(x, y));
        joueurs[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        scene->addItem(joueurs[i]);
    }
    joueurs[0]->setFocus();

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

Jeu::~Jeu()
{
    delete joueurs;
}

void Jeu::mousePressEvent(QMouseEvent *event)
{
    qDebug() << event->x() << event->y();
}
