Ce dossier contient les sources du projet, les résultats du build sont dans target
	tankApp
	tests
	(Rapport)
	(Documentation)

Ouvirir le projet sur QtCreator:
	Ouvrir QtCreator
	FIchier > Ouvrir fichier ou projet > Sélectionner le fichier tankApp.pro

Config des kits (Build) :
Onglet Projets dans Qtcreator (barre sur la gauche)
	debug		/home/user/Bureau/JeuDeTanks/target/bin-debug
	release	/home/user/Bureau/JeuDeTanks/target/bin-deploy

Crea de classes de tests unitaires (debug only) :
	FIchier > Nouveau fichier ou projet > Autres projets > Tests unitaires Qt
	kit:
		debug		/home/user/Bureau/JeuDeTanks/target/test-bin/<Nom de la classe de test>
	modules:
		QtGui, QtWidgets, et QtMultimedia si utilisation de fichiers audio