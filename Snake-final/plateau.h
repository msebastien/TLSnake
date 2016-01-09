#ifndef PLATEAU_H
#define PLATEAU_H

#define BLOCS_HAUTEUR 60
#define BLOCS_LARGEUR 30
#define OBSTACLE '&'

void placerObstacle(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR]);
void afficherPlateau(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], struct Serpent);
void construirePlateau(char plateau[BLOCS_LARGEUR][BLOCS_HAUTEUR], struct Serpent, int *, int *, int *, int *, int *);



#endif /* PLATEAU_H */
