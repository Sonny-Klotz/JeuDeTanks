#include <QtTest/QtTest>
#include "../tankApp/Point.h"

class TestTankApp: public QObject
{
    Q_OBJECT
private slots:
//Nom des methodes de test déclarés comme slots
	void getx();
	void gety();
};

//On implémente le test, on compare le retour de la méthode avec le résultat attendu
void TestTankApp::getx()
{
    Point p(0, 1);
    QCOMPARE(p.getx(), 0);
}

void TestTankApp::gety()
{
    Point p(0, 1);
    QCOMPARE(p.gety(), 1);
}

QTEST_MAIN(TestTankApp)
#include "testtankapp.moc"
