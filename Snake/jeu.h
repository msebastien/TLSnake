#ifndef JEU_H
#define JEU_H

#define MAX_COL 50
#define MAX_LIGNE 25
#define FRUIT 0
#define MUR 1


//Structure de base pour les coordonn�es d'un point
struct Point {
	int x;
	int y;
};

//La structure principale pour le serpent
struct Snake {
	struct Point posTete; //Position de la t�te
	struct Point queue[100]; //Les points appartenant � la queue seront stock�s dans ce tableau
	int longueur; // Longueur de la queue
	int direction; //Direction du serpent
	int vie; //Nombre de vies du serpent
	int fruits; //Nombre de fruits aval�s
};

//La structure d�terminant le plateau via une matrice 
struct Plateau {
	int Coord[MAX_LIGNE][MAX_COL];
	struct Point centre; //Le serpent apparait � ce point, situ� � peu pr�s au centre du plateau
};

struct Plateau chargerPlateau(struct Plateau);
void creerNiveauUn(struct Plateau);

#endif /* JEU_H */