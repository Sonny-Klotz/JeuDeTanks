#Jeu de tanks

Une description brève.

##Construction

Prérequis pour compiler : qmake=> "sudo apt-get install qt-sdk"

* Compil appli : "make tankApp" (exécute les tests, s'ils passent, construit l'exécutable)
* Compil tests : "make tests"
* Rapport : "make rapport"
* Documentation : "make documentation"
* Nettoyage :
	* "make clean" supprime les binaires '.o'
	* "make distclean" nettoyage complet (supprime tous les fichiers construits à la compilation)

##Développement
Consignes a suivre lors du developpement :
* Toujours documenter les fichiers ".h" au style [Doxygen](http://franckh.developpez.com/tutoriels/outils/doxygen/)
* Pour chaque classe ecrite, créer les tests unitaires pour les methodes :
	* [Vue d'ensemble](http://doc.qt.io/qt-5/qtest-overview.html) et [tutoriel](http://doc.qt.io/qt-5/qttestlib-tutorial1-example.html).
	* Ajouter un nouveau fichier au projet tests, utiliser le squelette
* Modifier le .gitignore et le Makefile pour gérer les nouveaux fichiers ajoutés. [Tuto makefile](http://gl.developpez.com/tutoriel/outil/makefile/)

##Execution

* Application : "make"
* Tests : "make run-tests"
* Rapport : "make rapport"
* Documentation : "make documentation"

##Utilisation

##Auteurs
###Florian Lienhardt
* [github](https://github.com/FloLienhardt)

###Sonny Klotz
* [github](https://github.com/Sonny-Klotz)
