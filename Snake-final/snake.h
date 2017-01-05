#ifndef SNAKE_H
#define SNAKE_H

#include "plateau.h"

#define MAX_QUEUE_SERPENT 200
#define TETE 79
#define QUEUE 178

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
typedef struct Serpent Serpent;

Serpent GrandirQueue(Serpent);
void afficheSerpent(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent);
void Direction1(char t[BLOCS_LARGEUR][BLOCS_HAUTEUR], struct Serpent, struct Fruit);
void Direction2(char t[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent, Fruit);
void reinitialisation(Serpent);

Serpent deplacer_gauche(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent);
Serpent deplacer_droite(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent);
Serpent deplacer_haut(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent);
Serpent deplacer_bas(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], Serpent);

#endif /* SNAKE_H */
