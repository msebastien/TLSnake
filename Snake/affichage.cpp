#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"
#include "jeu.h"


void afficherPlateau(struct Plateau p) {
	int i, j;

	// Affichage des murs, des obstacles...
	for (i = 0; i < MAX_LONGUEUR_PLATEAU; i++) {
		for (j = 0; j < MAX_HAUTEUR_PLATEAU; i++) {

			switch (p.Coord[j][i]) {
			case FRUIT:
				printf("%c", FRUIT_CHAR);
				break;

			case MUR:
				printf("%c", MUR_CHAR);
				break;

			default:
				printf("%c", VIDE_CHAR);

			}
			//

		}

	}
}