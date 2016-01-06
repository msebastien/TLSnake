#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "jeu.h"
#include "affichage.h"
#include "main.h"


int main() {
	struct Plateau carte;
	
	chargerPlateau(carte);
	
	//creerNiveauUn(carte);

	afficherPlateau(carte);
		


	return 0;	
	
}

/*A AVOIR
	- Une structure donnant le remplissage du labyrinthe par des obstacles
	- Une structure donnant l'emplacement des frutis (petit a)
	- Une structure générant des fruits aléatoirement
	- Une structure dirigeant le serpent
	- Le menu
	- L'affichage du labyrinthe
	- Le main*/