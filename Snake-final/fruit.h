#ifndef FRUIT_H
#define FRUIT_H

#define VIDE 0
#define FRUIT 64

#define BLOCS_HAUTEUR 60
#define BLOCS_LARGEUR 30

#define MIN_X 0
#define MIN_Y 0
#define MAX_X (BLOCS_HAUTEUR - 1)
#define MAX_Y (BLOCS_LARGEUR - 1)


//Structure demandant les coordonnées x et y d'un fruit
struct Fruit {
	int x, y;
};

int Random(int, int);
Fruit Fruit_manger(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], struct Fruit);
void afficherFruit(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], struct Fruit);
void effacerFruit(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], struct Serpent, int *, int *, int *, int *, int *);

#endif /* FRUIT_H */
