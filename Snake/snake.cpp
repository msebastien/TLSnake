#include <stdlib.h>
#include <stdio.h>
#include "jeu.h"

//Définition des touches directionnelles
#define HAUT 72
#define BAS 80
#define GAUCHE 75
#define DROITE 77

// TO DO : CONTROLE, VIE, COLLISIONS...

struct Plateau spawnSnake(struct Plateau p) {
	struct Snake snake;
	p.Coord[p.centre.y][p.centre.x] = 2;
	snake.direction = 1; // Vers le haut
	snake.fruits = 0;
	snake.longueur = 2;
	snake.vie = 3;
	return p;
}

struct Point bouger() {
	
}