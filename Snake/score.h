#ifndef SNAKE_H
#define SNAKE_H

#define TETE 79
#define QUEUE 178
#define VIDE 0
#define FRUIT 64
#define OBSTACLE 219
#define TAILLE_MAX 100
#define BLOCS_HAUTEUR 60
#define BLOCS_LARGEUR 30
#define MIN_X 0
#define MIN_Y 0
#define MAX_X (BLOCS_HAUTEUR - 1)
#define MAX_Y (BLOCS_LARGEUR - 1)

 struct Serpent;
 void construirePlateau(char plateau[30][60], Serpent serpent, int fruit_1, int fruit_2, int fruit_3, int fruit_4, int fruit_5);
 void placerFruit(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], struct Serpent s);
void placerObstacle(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR]);
Serpent deplacer_gauche(char plateau[30][60], Serpent serpent);
Serpent deplacer_droite(char plateau[30][60], Serpent serpent);
Serpent deplacer_haut(char plateau[30][60], Serpent serpent);
Serpent deplacer_bas(char plateau[30][60], Serpent serpent);
void afficherGameOver(int score, Serpent serpent);
void niveau_debutant();


#endif