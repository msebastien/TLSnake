#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fruit.h"
#include "snake.h"

/*
* Fonction : Random
*		retourne un nombre al�atoire
* Param�tres : a : un 1er entier
*              b : un 2�me entier
* Resultat : Un nombre entier al�atoire appartenant � l'intervalle [a ; b]
*
*/
int Random(int a, int b) {
	return rand() % (b - a) + a;
}


/*
* Fonction : Fruit_manger
*		retourne la structure du fruit
* Param�tres : plateau : une matrice de caract�res repr�sentant le plateau de jeu.
*              fruit : une structure constitu�e de toutes les donn�es en rapport avec le fruit.
* Resultat : Une fois qu'un fruit est mang�, cette fonction replace al�atoirement un fruit de coordonn�es (x, y)
*
*/
Fruit Fruit_manger(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Fruit fruit) {

	while (plateau[fruit.y][fruit.x] == '&') {
		fruit.x = Random(1, BLOCS_LARGEUR);
		fruit.y = Random(1, BLOCS_HAUTEUR);
	}
	return fruit;
}

/*
* Proc�dure : afficherFruit
*	
* Param�tres : plateau : une matrice de caract�res repr�sentant le plateau de jeu.
*              fruit : une structure constitu�e de toutes les donn�es en rapport avec le fruit.
* Resultat : affiche un fruit dans une des cases du plateau.
*
*/
void afficherFruit(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Fruit fruit) {
	plateau[fruit.y][fruit.x] = 'F';
}

/*
* Proc�dure : effacerFruit
*
* Param�tres : plateau : une matrice de caract�res repr�sentant le plateau de jeu.
*              serpent : une structure constitu�e de toutes les donn�es en rapport avec le serpent.
*			   *fruit_1 : Un pointeur pour le fruit 1.
*              *fruit_2 : Un pointeur pour le fruit 2.
*              *fruit_3 : Un pointeur pour le fruit 3.
*              *fruit_4 : Un pointeur pour le fruit 4.
*              *fruit_5 : Un pointeur pour le fruit 5.
* Resultat : efface l'un des 5 fruits en fonction de la t�te du serpent et si la case contient bien un fruit.
*
*/
void effacerFruit(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], struct Serpent serpent, int *fruit_1, int *fruit_2, int *fruit_3, int *fruit_4, int *fruit_5) {
	if (((serpent.tete.y == 12) && (serpent.tete.x == 18)) || (*fruit_1 == 1)) {
		plateau[12][18] = VIDE;
		*fruit_1 = 1;
	}
	if (((serpent.tete.y == 27) && (serpent.tete.x == 42)) || (*fruit_2 == 1)) {
		plateau[27][42] = VIDE;
		*fruit_2 = 1;
	}
	if (((serpent.tete.y == 28) && (serpent.tete.x == 48)) || (*fruit_3 == 1)) {
		plateau[28][48] = VIDE;
		*fruit_3 = 1;
	}
	if (((serpent.tete.y == 17) && (serpent.tete.x == 22)) || (*fruit_4 == 1)) {
		plateau[17][22] = VIDE;
		*fruit_4 = 1;
	}
	if (((serpent.tete.y == 14) && (serpent.tete.x == 48)) || (*fruit_5 == 1)) {
		plateau[14][48] = VIDE;
		*fruit_5 = 1;
	}
}