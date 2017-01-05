#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "snake.h"
#include "fruit.h"
#include "plateau.h"
#include "main.h"

/*
* Fonction : GrandirQueue
*
* Param�tres : serpent : une structure constitu�e de toutes les donn�es en rapport avec le serpent.
* Resultat : Agrandie la queue du serpent de 1 �l�ment.
*/
Serpent GrandirQueue(Serpent s) {
	int x, y;
	y = s.queue.tab[s.queue.longueur_queue - 1].y - s.queue.tab[s.queue.longueur_queue - 2].y;
	x = s.queue.tab[s.queue.longueur_queue - 1].x - s.queue.tab[s.queue.longueur_queue - 2].x;
	s.queue.tab[s.queue.longueur_queue].y = s.queue.tab[(s.queue.longueur_queue) - 1].y + y;
	s.queue.tab[s.queue.longueur_queue].x = s.queue.tab[(s.queue.longueur_queue) - 1].x + x;
	s.queue.longueur_queue = s.queue.longueur_queue + 1;
	return s;
}

/*
* Proc�dure : reinitialisation
*
* Param�tres : serpent : une structure constitu�e de toutes les donn�es en rapport avec le serpent.
* Resultat : R�initialise la position du serpent (apr�s un game over par exemple)
*
*/
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


/*
* Fonction : deplacer_gauche
*			retourne la structure du serpent
* Param�tres : plateau : une matrice de caract�res repr�sentant le plateau de jeu.
*              serpent : une structure constitu�e de toutes les donn�es en rapport avec le serpent.
* Resultat : D�place le serpent vers la gauche
*/
Serpent deplacer_gauche(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent serpent) {
	int i, x, y, save_x, save_y; //save_x et save_y nous permettront de garder les coordonn�es des morceaux de queue
	x = serpent.tete.x;
	y = serpent.tete.y;
	serpent.tete.x--; //Deplacement � gauche

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

/*
* Fonction : deplacer_droite
*			retourne la structure du serpent
* Param�tres : plateau : une matrice de caract�res repr�sentant le plateau de jeu.
*              serpent : une structure constitu�e de toutes les donn�es en rapport avec le serpent.
* Resultat : D�place le serpent vers la droite
*/
Serpent deplacer_droite(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent serpent) {
	int i, x, y, save_x, save_y; //save_x et save_y nous permettront de garder les coordonn�es des morceaux de queue
	x = serpent.tete.x;
	y = serpent.tete.y;
	serpent.tete.x++; //Deplacement � droite

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

/*
* Fonction : deplacer_haut
*			retourne la structure du serpent
* Param�tres : plateau : une matrice de caract�res repr�sentant le plateau de jeu.
*              serpent : une structure constitu�e de toutes les donn�es en rapport avec le serpent.
* Resultat : D�place le serpent vers le haut
*/
Serpent deplacer_haut(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent serpent) {
	int i, x, y, save_x, save_y; //save_x et save_y nous permettront de garder les coordonn�es des morceaux de queue
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

/*
* Fonction : deplacer_bas
*			retourne la structure du serpent
* Param�tres : plateau : une matrice de caract�res repr�sentant le plateau de jeu.
*              serpent : une structure constitu�e de toutes les donn�es en rapport avec le serpent.
* Resultat : D�place le serpent vers le bas
*/
Serpent deplacer_bas(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent serpent) {
	int i, x, y, save_x, save_y; //save_x et save_y nous permettront de garder les coordonn�es des morceaux de queue
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

/*
* Proc�dure : afficheSerpent
*	
* Param�tres : plateau : une matrice de caract�res repr�sentant le plateau de jeu.
*              serpent : une structure constitu�e de toutes les donn�es en rapport avec le serpent.
* Resultat : Affiche le serpent sur le plateau.
*/
void afficheSerpent(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent serpent) {
	int i;
	plateau[serpent.tete.y][serpent.tete.x] = TETE;
	for (i = 0; i < serpent.queue.longueur_queue; i++) {
		plateau[serpent.queue.tab[i].y][serpent.queue.tab[i].x] = QUEUE;
	}
}


/*
* Proc�dure : Direction
*
* Param�tres : plateau : une matrice de caract�res repr�sentant le plateau de jeu.
*              serpent : une structure constitu�e de toutes les donn�es en rapport avec le serpent.
*			   fruit : une structure constitu�e de toutes les donn�es en rapport avec le fruit.
*
* Resultat : Lorsque l'on appuie sur les touches Z, Q, S ou D, le serpent se d�place. On int�gre �galement deux variables score et mort � 0. Le score augmente en fonction des fruits mang�s, la mort passe � 1 si le serpent touche un mur ou sa queue.
* Si mort = 1, le jeu fait appel au game over (fonction ci-apr�s), sinon, il relance la boucle while(1) qui est la boucle infinie faisant appel au switch.
* Un compte � rebours est �galement pr�sent, car le serpent meurt si compte_rebours = 0.
*/
void Direction1(char t[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent serpent, Fruit fruit) {
	int score = 0, mort = 0, compteur_fruits = 5, fruit_1, fruit_2, fruit_3, fruit_4, fruit_5, delai = 0, i;
	int compte_rebours = 150;
	fruit_1 = fruit_2 = fruit_3 = fruit_4 = fruit_5 = 0;
	
	while (1) {
		while (mort == 0 && compteur_fruits > 0) {
			construirePlateau(t, serpent, &fruit_1, &fruit_2, &fruit_3, &fruit_4, &fruit_5);
			while ((kbhit() == 0) && mort == 0) {	
				printf("                  Temps restant : %2i\r", compte_rebours);

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
				for (i = 0; i < serpent.queue.longueur_queue; i++) {}
				if (serpent.tete.y == serpent.queue.tab[i].y) {
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
		afficherGameOver(score, serpent);
		}
}

void Direction2(char t[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent serpent, Fruit fruit) {
	int score = 0, mort = 0, compteur_fruits = 5, fruit_1, fruit_2, fruit_3, fruit_4, fruit_5, delai = 0, i;
	int compte_rebours = 150;
	fruit_1 = fruit_2 = fruit_3 = fruit_4 = fruit_5 = 0;

	while (1) {
		while (mort == 0 && compteur_fruits > 0) {
			construirePlateau(t, serpent, &fruit_1, &fruit_2, &fruit_3, &fruit_4, &fruit_5);

			while ((kbhit() == 0) && mort == 0) {
				printf("               Temps restant : %2i\r", compte_rebours);
				//printf("%2i\r", temps);

				// COMPTE A REBOURS
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
			char touche = getch();
			switch (touche) {
			case 'z':
				if (!(((serpent.tete.y - 1) == (serpent.queue.tab[0].y)) && ((serpent.tete.x) == (serpent.queue.tab[0].x)))) {
					serpent = deplacer_haut(t, serpent);
					while (kbhit() == 0) {
						serpent = deplacer_haut(t, serpent);
						
					}
					touche = getch();
				}
				break;
			case 's':
				if (!(((serpent.tete.y + 1) == (serpent.queue.tab[0].y)) && ((serpent.tete.x) == (serpent.queue.tab[0].x)))) {
					serpent = deplacer_bas(t, serpent);
					while (kbhit() == 0) {
						serpent = deplacer_bas(t, serpent);
					}
					touche = getch();
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

				if (t[serpent.tete.y][serpent.tete.x] == FRUIT) {
					printf("\a");
					compteur_fruits--;
					score = score++;
					serpent = GrandirQueue(serpent);
				}
				for (i = 0; i < serpent.queue.longueur_queue; i++) {}
				if (serpent.tete.y == serpent.queue.tab[i].y) {
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