#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Définition des touches directionnelles
#define HAUT 72
#define BAS 80
#define GAUCHE 75
#define DROITE 77
//Définition des dimensions du plateau
#define MAX_LONGUEUR_PLATEAU 252
#define MAX_HAUTEUR_PLATEAU 52

//Structure de base pour les coordonnées d'un point
struct Point {
	int x;
	int y;
};

//La structure principale pour le serpent
struct Snake {
	struct Point posTete; //Position de la tête
	struct Point queue[100]; //Les points appartenant à la queue seront stockés dans ce tableau
	int longueur; // Longueur de la queue
	int direction; //Direction du serpent
	int vie; //Nombre de vies du serpent
	int fruits; //Nombre de fruits avalés
};

//La structure déterminant le plateau via une matrice 
struct Plateau {
	int Coord[MAX_HAUTEUR_PLATEAU][MAX_LONGUEUR_PLATEAU]; 
	struct Point centre; //Le serpent apparait à ce point, situé à peu près au centre du plateau
};

//Procédure chargeant le plateau, définissant les murs
void chargerPlateau() {
	int i, j;
	struct Plateau carte;

	// Création des murs correspondant aux limites du plateau.
	for(i = 0; i < MAX_LONGUEUR_PLATEAU; i++) {
		for(j = 0; j < MAX_HAUTEUR_PLATEAU; i++) {
			carte.Coord[0][i] = 1;
			carte.Coord[MAX_HAUTEUR_PLATEAU][i] = 1;

			carte.Coord[j][0] = 1;
			carte.Coord[j][MAX_LONGUEUR_PLATEAU] = 1;

		}
	}

	// 

}

//Structure générant le labyrinthe
struct Plateau genererLabyrinthe() {

}
int main() {
	chargerPlateau();
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