#Jeu de tanks

Une description brève.

##Construction

Prérequis pour compiler : qmake=> "sudo apt-get install qt-sdk"

* Compil appli : "make"
* Compil tests : "make tests"
* Nettoyage :
	* "make clean" supprime les binaires '.o'
	* "make distclean" nettoyage complet (supprime tous les fichiers construits à la compilation)
	
##Execution

* Application : "make run" // make run compile automatiquement si ce n'est pas deja fait
* Tests : "make run-tests" // idem

##Développement

* Test : pour ajouter un test, il faut ajouter dans tests.pro le .cpp // et le include dans TestTankApp.cpp

* Tank : 
	* etat : detruit ou non
	* coords : Point
	* capacite : pour le deplacement (init a L/10)
	* canon : angle et pivot
	* obus : illimite type1, 10 t2 et 5 t3
	* fonctions :
	changer angles / tirer / deplacer / explosion.
	Pour tirer et deplacer, on informe le terrain,
	ce sera lui qu'il traite (vu qu'il a connaissace des
	autres objets)

* Obus : caracterise par son type
	* type 1 : -2 resistance,  diametre impact 5 pixels
	* type 2 : -5 resistance, 20 pixels
	* type 3 : -10 resistance, 28 pixels

* Segment : composé de deux Point

* Obstacles : caracterise par degre resistance
	* arbre 1 bloque le tank vert
	* roche 7 bloque le tank gris
	* crevasse -2 ne bloque pas retire de la capacite
	* eau NMAX bloque le tank bleu

* Terrain :
	* taille : L*C  pixels
	* { obstacles }
	* fonctions :
		* deplacer (verif obstacles)
		* tirer (segment trajectoire, calcul Point impact,
		 , deplace l'obus suivant la trajectoire, detruire a l'impact)

* Joueur (classe de base) :
	* individu et ordinateur (classes filles)
	* fct principale  -> renvoie une commande
	* cmd	
		* 3 actions
			* pivot
			* angle tir
			* tir obus 1-2 ou 3
		* fleches : deplcement

* main : 1 fenetre -> 3 boutons (1 par action du joueur) + terrain
	* instanciation : terrain et joueurs
	* label	: affiché sur le tank
		* IA ou joueur + n° du joueur
		* en evidence si c'et son tour
		* capacite du tank
	* deroulement du jeu (while au - 2 tanks en marche)
		* on attend des commandes
		* on les traite
		* on passe a l'autre joueur quand obus tiré

##Utilisation

##Auteurs
###Florian Lienhardt
* [github](https://github.com/FloLienhardt)

###Sonny Klotz
* [github](https://github.com/Sonny-Klotz)
