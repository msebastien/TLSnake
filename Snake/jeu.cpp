#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "jeu.h"

struct Plateau chargerPlateau() {
	int i, j;
	struct Plateau carte;

	// Création des murs (1) correspondant aux limites du plateau.
	for(i = 0; i < MAX_LONGUEUR_PLATEAU; i++) {
		for(j = 0; j < MAX_HAUTEUR_PLATEAU; i++) {
			carte.Coord[0][i] = 1;
			carte.Coord[MAX_HAUTEUR_PLATEAU][i] = MUR;

			carte.Coord[j][0] = 1;
			carte.Coord[j][MAX_LONGUEUR_PLATEAU] = MUR;

		}
	}
	
	// On définit le centre
	carte.centre.x = MAX_LONGUEUR_PLATEAU - (MAX_LONGUEUR_PLATEAU / 2);
	carte.centre.y = MAX_HAUTEUR_PLATEAU - (MAX_HAUTEUR_PLATEAU / 2);

	// Création du 1er Niveau
	creerNiveauUn(carte);

	return carte;
}



// On crée un niveau avec des murs (=obstacles) : Niveau 1.
void creerNiveauUn(struct Plateau p) {
	
	// Obstacles
	p.Coord[50][125] = MUR;
	p.Coord[32][183] = MUR;
	p.Coord[78][150] = MUR;
	p.Coord[91][124] = MUR;
	p.Coord[52][146] = MUR;
	p.Coord[23][50] = MUR;

	// Fruits
	p.Coord[79][136] = FRUIT;

	}