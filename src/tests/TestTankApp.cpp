#include <QtTest/QtTest>
#include "../tankApp/Point.h"
#include "../tankApp/Obstacle.h"

class TestTankApp: public QObject
{
    Q_OBJECT
private slots:
//Nom des methodes de test déclarés comme slots
	void getx();
	void setx();
	void getResistance();
};

//On implémente le test, on compare le retour de la méthode avec le résultat attendu
// Tests pour point
void TestTankApp::getx() { // gety est identique
    Point p(0, 1);
    QCOMPARE(p.getx(), 0);
}
void TestTankApp::setx() { // sety est identique
    Point p(0, 0);
    p.setx(1);
    QCOMPARE(p.getx(), 1);
}

void TestTankApp::getResistance() {
	Obstacle o1(ARBRE, Point(0,0));
	Obstacle o2(ROCHER, Point(0,0));
	Obstacle o3(EAU, Point(0,0));
	Obstacle o4(CREVASSE1, Point(0,0));
	Obstacle o5(CREVASSE2, Point(0,0));
	Obstacle o6(CREVASSE3, Point(0,0));
	
	QCOMPARE(o1.getResistance(), 1);
	QCOMPARE(o2.getResistance(), 7);
	QCOMPARE(o3.getResistance(), 10);
	QCOMPARE(o4.getResistance(), -2);
	QCOMPARE(o5.getResistance(), -2);
	QCOMPARE(o6.getResistance(), -2);
}

QTEST_MAIN(TestTankApp)
#include "testtankapp.moc"
