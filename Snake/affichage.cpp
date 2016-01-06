#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"
#include "jeu.h"


void afficherPlateau(struct Plateau p) {
	int i, j;

	// Affichage des murs, des obstacles...
	for (i = 0; i < MAX_LIGNE; i++) {
		for (j = 0; j < MAX_COL; j++) {

			switch (p.Coord[i][j]) {
			case FRUIT:
				printf("%c", FRUIT_CHAR);
				
			case MUR:
				printf("%c", MUR_CHAR);

			default:
				printf("%c", VIDE_CHAR);

			}
			//

		}

	}
	printf("\n");
}