#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "jeu.h"
#include "main.h"



struct Plateau chargerPlateau(struct Plateau p) {
	int i, j;
	
	// Lignes verticales
	for(i = 0; i < MAX_LIGNE; i++) {	
		p.Coord[i][0] = 281;
		p.Coord[i][50] = 281;
		
	}

	// Lignes horizontales
	for (j = 0; j < MAX_COL; j++) {

		p.Coord[0][j] = 281;
		p.Coord[50][j] = 281;

	}
	// On définit le centre
	p.centre.x = MAX_COL / 2;
	p.centre.y = MAX_LIGNE / 2;

	return p;
}

void creerNiveauUn(struct Plateau p) {
	// Obstacles
	p.Coord[50][125] = MUR;
	p.Coord[32][183] = MUR;
	p.Coord[78][150] = MUR;
	p.Coord[91][124] = MUR;
	p.Coord[52][146] = MUR;
	p.Coord[15][10] = MUR;

	// Fruits
	p.Coord[10][15] = FRUIT;

}

