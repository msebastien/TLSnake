#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "snake.h"
#include "fruit.h"


//Fonction qui, en utilisant le plateau, génèrera 4 obstacles aux coordonnées indiquées. Ces obstacles seront mortels pour le serpent
void placerObstacle(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR]) {
	plateau[7][14] = OBSTACLE;
	plateau[15][45] = OBSTACLE;
	plateau[20][50] = OBSTACLE;
	plateau[10][10] = OBSTACLE;
}



//Fonction permettant d'afficher le plateau entier, en faisant appel au plateau et à la structure Serpent, tout en affichant le serpent (afficheSerpent)
void afficherPlateau(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent serpent) {
	int i, j;
	afficheSerpent(plateau, serpent);
	// Affichage du plateau
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 60; j++) {
			printf("%c", plateau[i][j]);
		}
		printf("\n"); // Saut de ligne après plateau
	}

}

void construirePlateau(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent serpent, int *fruit_1, int *fruit_2, int *fruit_3, int *fruit_4, int *fruit_5) {

	int i, j;
	system("cls");

	// Génération des bordures du plateau
	for (i = 0; i < 30; i++) {
		plateau[i][0] = 219;
		plateau[i][59] = 219;
	}

	for (j = 0; j < 60; j++) {
		plateau[0][j] = 219;
		plateau[29][j] = 219;
	}

	for (i = 1; i < 29; i++) {
		for (j = 1; j < 59; j++) {
			plateau[i][j] = 0;
		}
	}
	plateau[12][18] = FRUIT;
	plateau[27][42] = FRUIT;
	plateau[28][48] = FRUIT;
	plateau[17][22] = FRUIT;
	plateau[14][48] = FRUIT;

	effacerFruit(plateau, serpent, fruit_1, fruit_2, fruit_3, fruit_4, fruit_5);
	placerObstacle(plateau);
	afficherPlateau(plateau, serpent);
}