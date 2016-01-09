#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "snake.h"
#include "fruit.h"

/*
* Procédure : afficherGameOver
*
* Paramètres : score : un entier représentant le nombre de fruits mangés.
*              serpent : une structure constituée de toutes les données en rapport avec le serpent.
* Resultat : Affiche l'écran de Game Over.
*
*/
void afficherGameOver(int score, Serpent serpent) {
	system("cls");
	int choix = 0;
	while (choix != 2) {

		printf("				/^\/^\                                      \n");
		printf("              _|__|  O|                                     \n");
		printf("     \/     /~     \_/ \                                    \n");
		printf("      \____|__________/  \                                  \n");
		printf("             \_______      \                                \n");
		printf("                     `\     \                 \             \n");
		printf("                       |     |                  \           \n");
		printf("                      /      /                    \         \n");
		printf("                     /     /                       \\       \n");
		printf("                   /      /                         \ \     \n");
		printf("                  /     /                            \  \   \n");
		printf("                /     /             _----_            \   \ \n");
		printf("               /     /           _-~      ~-_         |   | \n");
		printf("              (      (        _-~    _--_    ~-_     _/   | \n");
		printf("               \      ~-____-~    _-~    ~-_    ~-_-~    /  \n");
		printf("                 ~-_           _-~          ~-_       _-~   \n");
		printf("                    ~--______-~                ~-___-~      \n");
		printf("=========================GAME OVER !=========================\n");

		printf("\t \t Votre score est : %d \n \n", score);
		printf("\t \t \t QUE VOULEZ VOUS FAIRE ?\n \n");
		printf("\t \t 1) Rejouer\n \n");
		printf("\t \t 2) Quitter\n \n");
		scanf("%d", &choix);
		switch (choix) {
		case 1:
			reinitialisation(serpent);
			niveau_debutant();
			break;
		case 2:
			break;
		default:
			afficherGameOver(score, serpent);
			break;
		}
	}
	exit(0);
}

/*
* Procédure : niveau_debutant
*	Initialise le niveau et donc la position du serpent, la possibilité de le déplacer, ...
*/
void niveau_debutant() {
	char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR];
	Serpent serpent;
	Fruit fruit;
	fruit.x = 13;
	fruit.y = 13;

	serpent.queue.longueur_queue = 3;
	serpent.tete.x = 10;
	serpent.tete.y = 5;

	for (int i = 0; i < serpent.queue.longueur_queue; i++)
	{
		serpent.queue.tab[i].x = 10 - i - 1;
		serpent.queue.tab[i].y = 5;
	}

	Direction(plateau, serpent, fruit);
}

int main() {
	niveau_debutant();
	return 0;
}