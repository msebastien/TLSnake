#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "Header.h"
#define TETE 79
#define QUEUE 178
#define TAILLE_MAX 100

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//On pose la tete du serpent
struct Tete_serpent {
	int x, y;
};

//On pose les parties de la queue du serpent
struct Partie_Queue_serpent {
	int x, y;
};

//On pose la queue en globalité
struct Queue_serpent {
	int longueur_queue;
	struct Partie_Queue_serpent tab[40];
};

//On rassemble pour avoir le serpent complet
struct Serpent {
	struct Tete_serpent tete;
	struct Queue_serpent queue;
};

Serpent deplacer_gauche (char plateau[30][60], Serpent serpent){
	int i, x, y, save_x, save_y; //save_x et save_y nous permettront de garder les coordonnées des morceaux de queue
	x = serpent.tete.x;
	y = serpent.tete.y;
	serpent.tete.x--; //Deplacement à gauche

	for (i = 0; i<serpent.queue.longueur_queue; i++){
		save_x = serpent.queue.tab[i].x;
		save_y = serpent.queue.tab[i].y;
		serpent.queue.tab[i].x = x;
		serpent.queue.tab[i].y = y;
		x = save_x;
		y = save_y;
	}
	return serpent;
}

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

void afficheSerpent(char plateau[30][60], Serpent serpent){
	int i;
	plateau[serpent.tete.y][serpent.tete.x] = TETE;
	for (i = 0; i < serpent.queue.longueur_queue; i++){
		plateau[serpent.queue.tab[i].y][serpent.queue.tab[i].x] = QUEUE;
	}
}

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

void Direction(char t[30][60], Serpent serpent) {
	while (1)
	{
		while (!kbhit()) {
		}
		char touche = getch();
		//t[serpent.tete.x][serpent.tete.y] = TETE;		
		switch (touche) {
		case 'z':
			serpent = deplacer_haut(t, serpent);
			break;
		case 's':
			serpent = deplacer_bas(t, serpent);
			break;
		case 'q':
			serpent = deplacer_gauche(t, serpent);
			break;
		case 'd':
			serpent = deplacer_droite(t, serpent);
			break;
		default:
			break;
		}
		system("cls");
		construirePlateau(t, serpent);
	}
}

void construirePlateau(char plateau[30][60], Serpent serpent) {

	int i, j;

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
	afficherPlateau(plateau, serpent);
}

int main() {
	char plateau[30][60];
	Serpent serpent;
	serpent.queue.longueur_queue = 3;
	serpent.tete.x = 30;
	serpent.tete.y = 15;

	for (int i = 0; i < serpent.queue.longueur_queue; i++)
	{
		serpent.queue.tab[i].x = 30-i-1;
		serpent.queue.tab[i].y = 15;
	}

	construirePlateau(plateau, serpent);
	Direction(plateau, serpent);
	return 0;
}