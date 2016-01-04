#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define HAUT 72
#define BAS 80
#define GAUCHE 75
#define DROITE 77
#define MAX_LONGUEUR_PLATEAU 250
#define MAX_HAUTEUR_PLATEAU 50

struct Point {
	int x;
	int y;
};

struct Snake {
	struct Point posTete;
	struct Point queue[100];
	int longueur; // Longueur de la queue
	int direction;
	int vie;
	int fruits;
};

struct Plateau {
	int Coord[MAX_HAUTEUR_PLATEAU][MAX_LONGUEUR_PLATEAU];
	struct Point centre;
};

// Charge les donn�es du plateau
void chargerPlateau() {
	int i, j;
	struct Plateau carte;

	// Cr�ation des murs correspondant aux limites du plateau.
	for(i = 0; i < MAX_LONGUEUR_PLATEAU; i++) {
		for(j = 0; j < MAX_HAUTEUR_PLATEAU; i++) {
			carte.Coord[0][i] = 1;
			carte.Coord[MAX_HAUTEUR_PLATEAU][i] = 1;

			carte.Coord[j][0] = 1;
			carte.Coord[j][MAX_LONGUEUR_PLATEAU] = 1;

		}
	}
}


// G�n�re le labyrinthe sur le plateau. 
struct Plateau genererLabyrinthe() {
	//TO DO
}
int main() {
	chargerPlateau();
	return 0;
}