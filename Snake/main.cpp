#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//D�finition des touches directionnelles
#define HAUT 72
#define BAS 80
#define GAUCHE 75
#define DROITE 77
//D�finition des dimensions du plateau
#define MAX_LONGUEUR_PLATEAU 252
#define MAX_HAUTEUR_PLATEAU 52

//Structure de base pour les coordonn�es d'un point
struct Point {
	int x;
	int y;
};

//La structure principale pour le serpent
struct Snake {
	struct Point posTete; //Position de la t�te
	struct Point queue[100]; //Les points appartenant � la queue seront stock�s dans ce tableau
	int longueur; // Longueur de la queue
	int direction; //Direction du serpent
	int vie; //Nombre de vies du serpent
	int fruits; //Nombre de fruits aval�s
};

//La structure d�terminant le plateau via une matrice 
struct Plateau {
	int Coord[MAX_HAUTEUR_PLATEAU][MAX_LONGUEUR_PLATEAU]; 
	struct Point centre; //Le serpent apparait � ce point, situ� � peu pr�s au centre du plateau
};

//Proc�dure chargeant le plateau, d�finissant les murs
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

	// 

}

//Structure g�n�rant le labyrinthe
struct Plateau genererLabyrinthe() {

}
int main() {
	chargerPlateau();
	return 0;
}

/*A AVOIR
	- Une structure donnant le remplissage du labyrinthe par des obstacles
	- Une structure donnant l'emplacement des frutis (petit a)
	- Une structure g�n�rant des fruits al�atoirement
	- Une structure dirigeant le serpent
	- Le menu
	- L'affichage du labyrinthe
	- Le main*/