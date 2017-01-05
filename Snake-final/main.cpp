#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "snake.h"
#include "fruit.h"

void afficher_menu(int *choixMenu)
{
	printf("----------------------\n");
	printf("| Bienvenue dans Snake |\n");
	printf("----------------------\n\n");
	printf("---------------------------- Menu ----------------------------\n\n");
	printf("1 - Mode 1 : Deplacement manuel dans un labyrinthe\n");
	printf("2 - Mode 2 : Serpent en mouvement\n");
	printf("3 - Mode 3 : Serpent en mouvement a travers les murs\n");
	printf("4 - High Score\n");
	printf("5 - Aide\n");
	printf("6 - Sortie\n");
	printf("--------------------------------------------------------------\n\n");
	printf("Quel est votre choix?\n");
	scanf("%d", choixMenu);
}

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
			niveau1();
			break;
		case 2: exit(0);
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
void niveau1() {
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

	Direction1(plateau, serpent, fruit);
}

void niveau2() {
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
	
	Direction2(plateau, serpent, fruit);

}

int main() {
	// DEFINITION DES VARIABLES
	int choixMenu;

	// MENU
	afficher_menu(&choixMenu);
	switch (choixMenu)
	{
	case 1:
		system("cls");
		niveau1();
		break;
	case 2:
		system("cls");
		niveau2();
		break;
	case 3:
		system("cls");
		printf("Vous avez choisi le mode 3.\n\n");
		break;
	case 4:
		system("cls");
		printf("Vous avez choisi de voir les high score.\n\n");
		break;
	case 5:
		system("cls");
		printf("Vous avez choisi l'aide.\n\n");
		printf("Le but du jeu est de manger le plus de pommes avec votre serpent. Celui-ci grandit au fur et a mesure que vous en manger.\nAttention, si vous vous touchez avec le serpent ou si vous touchez un mur vous perdez !\n\nPour vous deplacer utlisez les touches Z, Q, S, D, de votres clavier.\nAppuyez sur espace pour mettre le jeu sur pause.\n\n");
		//retour_Menu();
		break;
	case 6:
		printf("Sortie\n\n");
		return 0;
		break;
	default:
		printf("Vous n'avez pas selectionné un menu qui existe. Veuillez entrer 1, 2, 3, 4, 5 ou 6 svp\n\n");
		break;
	}
	return 0;
}