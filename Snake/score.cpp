#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "Header.h"

#define TETE 79
#define QUEUE 178

#define VIDE 0
#define FRUIT 64
#define MUR 219
#define OBSTACLE '&'

#define TAILLE_MAX 100
#define BLOCS_HAUTEUR 60
#define BLOCS_LARGEUR 30

#define MIN_X 0
#define MIN_Y 0
#define MAX_X (BLOCS_HAUTEUR - 1)
#define MAX_Y (BLOCS_LARGEUR - 1)
#define MAX_QUEUE_SERPENT 200

//Fonction générant un nombre entier aléatoire appartenant à l'intervalle [a ; b]
int Random(int a, int b){
	return rand() % (b-a)+a;
}

//Structure demandant les coordonnées x et y d'un fruit
struct Fruit {
	int x, y;
};

//Fonction qui génère aléatoirement des fruits, prenant la structure fruit pour les coordonnées et faisant appel à la fonction Random
Fruit Fruit_manger(char plateau[30][60], Fruit fruit){
	int rand;
	while (plateau[fruit.y][fruit.x] == '&') {
		fruit.x = Random(1, 60);
		fruit.y = Random(1, 30);
	}
	return fruit;
}

//Fonction qui affiche un fruit sur un plateau en utilisant la structure Fruit
void afficherFruit(char plateau[30][60], Fruit fruit){
	plateau[fruit.y][fruit.x] = 'F';
}

//Structure demandant les coordonnées x et y de la tete du serpent
struct Tete_serpent {
	int x, y;
};

//Structure demandant les coordonnées x et y d'un morceau de la queue du serpent
struct Partie_Queue_serpent {
	int x, y;
};

//Structure demandant la longueur de la queue et plaçant les différents morceaux (à l'aide de la structure Partie_Queue_serpent) dans un tableau de structures
struct Queue_serpent {
	int longueur_queue;
	struct Partie_Queue_serpent tab[MAX_QUEUE_SERPENT];
};

//Structure rassemblant les structures Tete_Serpent et Queue_Serpent et demandant le nombre de fruits mangés
struct Serpent {
	struct Tete_serpent tete;
	struct Queue_serpent queue;
	int fruits;
};

void effacerFruit(char plateau[30][60], struct Serpent serpent, int *fruit_1, int *fruit_2, int *fruit_3, int *fruit_4, int *fruit_5){
	if (((serpent.tete.y == 12) && (serpent.tete.x == 18)) || (*fruit_1 == 1)){
		plateau[12][18] = VIDE;
		*fruit_1 = 1;
	}
	if (((serpent.tete.y == 27) && (serpent.tete.x == 42)) || (*fruit_2 == 1)){
		plateau[27][42] = VIDE;
		*fruit_2 = 1;
	}
	if (((serpent.tete.y == 28) && (serpent.tete.x == 48)) || (*fruit_3 == 1)){
		plateau[28][48] = VIDE;
		*fruit_3 = 1;
	}
	if (((serpent.tete.y == 17) && (serpent.tete.x == 22)) || (*fruit_4 == 1)){
		plateau[17][22] = VIDE;
		*fruit_4 = 1;
	}
	if (((serpent.tete.y == 14) && (serpent.tete.x == 48)) || (*fruit_5 == 1)){
		plateau[14][48] = VIDE;
		*fruit_5 = 1;
	}
}

void placerFruit(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], struct Serpent s) {
	if (s.fruits >= 5) {

		srand(time(NULL));

		int hasard_x = 0;
		int hasard_y = 0;

		do
		{
			hasard_x = (rand() % (MAX_X - MIN_X + 1)) + MIN_X;
			hasard_y = (rand() % (MAX_Y - MIN_Y + 1)) + MIN_Y;
		} while (plateau[hasard_x][hasard_y] != VIDE);

		plateau[hasard_x][hasard_y] = FRUIT;
	}
	else {
		plateau[12][18] = FRUIT;
		plateau[27][42] = FRUIT;
		plateau[28][48] = FRUIT;
		plateau[17][22] = FRUIT;
		plateau[14][48] = FRUIT;
	}
}

//Fonction qui, en utilisant le plateau, génèrera 4 obstacles aux coordonnées indiquées. Ces obstacles seront mortels pour le serpent
void placerObstacle(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR]) {
	plateau[7][14] = OBSTACLE;
	plateau[15][45] = OBSTACLE;
	plateau[20][50] = OBSTACLE;
	plateau[10][10] = OBSTACLE;
}

Serpent GrandirQueue(Serpent s) {
	int x, y;
	y = s.queue.tab[s.queue.longueur_queue - 1].y - s.queue.tab[s.queue.longueur_queue - 2].y;
	x = s.queue.tab[s.queue.longueur_queue - 1].x - s.queue.tab[s.queue.longueur_queue - 2].x;
	s.queue.tab[s.queue.longueur_queue].y = s.queue.tab[(s.queue.longueur_queue)-1].y + y;
	s.queue.tab[s.queue.longueur_queue].x = s.queue.tab[(s.queue.longueur_queue)-1].x + x;
	s.queue.longueur_queue = s.queue.longueur_queue + 1;
	return s;
};


//Fonction permettant, en ayant le plateau et en utilisant la structure Serpent, notre serpent de se déplacer à gauche
Serpent deplacer_gauche(char plateau[30][60], Serpent serpent) {
	int i, x, y, save_x, save_y; //save_x et save_y nous permettront de garder les coordonnées des morceaux de queue
	x = serpent.tete.x;
	y = serpent.tete.y;
	serpent.tete.x--; //Deplacement à gauche

	for (i = 0; i<serpent.queue.longueur_queue; i++) {
		save_x = serpent.queue.tab[i].x;
		save_y = serpent.queue.tab[i].y;
		serpent.queue.tab[i].x = x;
		serpent.queue.tab[i].y = y;
		x = save_x;
		y = save_y;
	}
	return serpent;
}

//Fonction permettant, en ayant le plateau et en utilisant la structure Serpent, notre serpent de se déplacer à droite
Serpent deplacer_droite(char plateau[30][60], Serpent serpent) {
	int i, x, y, save_x, save_y; //save_x et save_y nous permettront de garder les coordonnées des morceaux de queue
	x = serpent.tete.x;
	y = serpent.tete.y;
	serpent.tete.x++; //Deplacement à droite

	for (i = 0; i<serpent.queue.longueur_queue; i++) {
		save_x = serpent.queue.tab[i].x;
		save_y = serpent.queue.tab[i].y;
		serpent.queue.tab[i].x = x;
		serpent.queue.tab[i].y = y;
		x = save_x;
		y = save_y;
	}
	return serpent;
}

//Fonction permettant, en ayant le plateau et en utilisant la structure Serpent, notre serpent de se déplacer en haut
Serpent deplacer_haut(char plateau[30][60], Serpent serpent) {
	int i, x, y, save_x, save_y; //save_x et save_y nous permettront de garder les coordonnées des morceaux de queue
	x = serpent.tete.x;
	y = serpent.tete.y;
	serpent.tete.y--; //Deplacement en haut

	for (i = 0; i < serpent.queue.longueur_queue; i++) {
		save_x = serpent.queue.tab[i].x;
		save_y = serpent.queue.tab[i].y;
		serpent.queue.tab[i].x = x;
		serpent.queue.tab[i].y = y;
		x = save_x;
		y = save_y;
	}
	return serpent;
}

//Fonction permettant, en ayant le plateau et en utilisant la structure Serpent, notre serpent de se déplacer en bas
Serpent deplacer_bas(char plateau[30][60], Serpent serpent) {
	int i, x, y, save_x, save_y; //save_x et save_y nous permettront de garder les coordonnées des morceaux de queue
	x = serpent.tete.x;
	y = serpent.tete.y;
	serpent.tete.y++; //Deplacement en bas

	for (i = 0; i<serpent.queue.longueur_queue; i++) {
		save_x = serpent.queue.tab[i].x;
		save_y = serpent.queue.tab[i].y;
		serpent.queue.tab[i].x = x;
		serpent.queue.tab[i].y = y;
		x = save_x;
		y = save_y;
	}
	return serpent;
}

//Fonction permettant, en utilisant le plateau et la structure Serpent, d'afficher le serpent dans le plateau
void afficheSerpent(char plateau[30][60], Serpent serpent) {
	int i;
	plateau[serpent.tete.y][serpent.tete.x] = TETE;
	for (i = 0; i < serpent.queue.longueur_queue; i++) {
		plateau[serpent.queue.tab[i].y][serpent.queue.tab[i].x] = QUEUE;
	}
}

//Fonction permettant d'afficher le plateau entier, en faisant appel au plateau et à la structure Serpent, tout en affichant le serpent (afficheSerpent)
void afficherPlateau(char plateau[30][60], Serpent serpent) {
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

void construirePlateau(char plateau[30][60], Serpent serpent, int *fruit_1, int *fruit_2, int *fruit_3, int *fruit_4, int *fruit_5) {

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

/*L'une des fonctions primordiales. En utilisant le tableau (ici appelé t), les structures Serpent et Fruit principalement. Elle permet, à l'aide d'un switch,
de faire bouger le serpent. L'utilisateur choisit une touche selon Z Q S ou D et la fonction fait appel aux précédentes fonctions pour le faire tourner et avancer.
On intègre également deux variables score et mort à 0. Le score augmente en fonction des fruits mangés, la mort passe à 1 si le serpent touche un mur ou sa queue.
Si mort = 1, le jeu fait appel au game over (fonction ci-après), sinon, il relance la boucle while(1) qui est la boucle infinie faisant appel au switch.
Un compte à rebours est également présent, car le serpent meurt si compte_rebours = 0.*/
void Direction(char t[30][60], Serpent serpent, Fruit fruit) {
	int score = 0, mort = 0, compteur_fruits = 5, fruit_1, fruit_2, fruit_3, fruit_4, fruit_5, delai = 0, i;
	int compte_rebours = 150;
	fruit_1 = fruit_2 = fruit_3 = fruit_4 = fruit_5 = 0;
	while (1) {
		while (mort == 0 && compteur_fruits > 0) {
			while ((kbhit()==0) && mort == 0) {
				construirePlateau(t, serpent, &fruit_1, &fruit_2, &fruit_3, &fruit_4, &fruit_5);
				printf("Temps restant : %d secondes \n", compte_rebours);
				printf("Vous avez %d points \n", score);

				delai = delai++;
				if (delai == 10) {
					compte_rebours--;
					delai = 0;
				}
				Sleep(100);
				if (compte_rebours == 0) {
					mort = 1;
				}
			}
			if(mort == 0){
				char touche = getch();
				switch (touche) {
				case 'z':
					if (!(((serpent.tete.y - 1) == (serpent.queue.tab[0].y)) && ((serpent.tete.x) == (serpent.queue.tab[0].x)))) {
						serpent = deplacer_haut(t, serpent);
					}
					break;
				case 's':
					if (!(((serpent.tete.y + 1) == (serpent.queue.tab[0].y)) && ((serpent.tete.x) == (serpent.queue.tab[0].x)))) {
						serpent = deplacer_bas(t, serpent);
					}
					break;
				case 'q':
					if (!(((serpent.tete.y) == (serpent.queue.tab[0].y)) && ((serpent.tete.x - 1) == (serpent.queue.tab[0].x)))) {
						serpent = deplacer_gauche(t, serpent);
					}
					break;
				case 'd':
					if (!(((serpent.tete.y) == (serpent.queue.tab[0].y)) && ((serpent.tete.x + 1) == (serpent.queue.tab[0].x)))) {
						serpent = deplacer_droite(t, serpent);
					}
					break;
				default:
					break;
				}
				if (t[serpent.tete.y][serpent.tete.x] == FRUIT) {
					printf("\a");
					compteur_fruits--;
					score = score++;
					serpent = GrandirQueue(serpent);
				}
				for (i = 0; i < serpent.queue.longueur_queue; i++){}
					if (serpent.tete.y == serpent.queue.tab[i].y){
						if (serpent.tete.x == serpent.queue.tab[i].x) {
							mort = 1;
						}
					}
				if (serpent.tete.y == 0 || serpent.tete.y == 29 || serpent.tete.x == 0 || serpent.tete.x == 59) {
					mort = 1;
				}
				if (t[serpent.tete.y][serpent.tete.x] == '&') {
					mort = 1;
				}
			}
		}
		afficherGameOver(score, serpent);
	}
}

void reinitialisation(Serpent serpent) {
	serpent.queue.longueur_queue = 3;
	serpent.tete.x = 10;
	serpent.tete.y = 5;

	for (int i = 0; i < serpent.queue.longueur_queue; i++)
	{
		serpent.queue.tab[i].x = 10 - i - 1;
		serpent.queue.tab[i].y = 5;
	}
}

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

void niveau_debutant() {
	char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR];
	Serpent serpent;
	Fruit fruit;
	fruit.x = 13;
	fruit.y = 13;
	//Fruit_manger(plateau, fruit);

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