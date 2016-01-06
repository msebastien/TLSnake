#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void Menu_Niveaux() {
	int choix_Niveau = 0;

	while (choix_Niveau != 5) {
		printf("\n \n \n \t \t \t ===== NIVEAUX =====\n \n \n");
		printf("\t \t 1) NIVEAU DEBUTANT\n \n");
		printf("\t \t 2) NIVEAUX INTERMEDIAIRES\n \n");
		printf("\t \t 3) NIVEAUX AVANCES\n \n");
		printf("\t \t 4) SCORE PARFAIT\n \n");
		printf("\t \t 5) RETOUR \n \n");
		printf("\t \t Entrez le numero correspondant a un niveau, selon votre choix : ");

		scanf("%d", &choix_Niveau);
		switch (choix_Niveau) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			printf("\n \n \t \t BUG DANS LA MATRICE : ce que vous avez entre est incorrect...\n \n \n");
			break;
		}
	}
}

void Aide() {
	int retour_menuPrincipal = 1;

	while (retour_menuPrincipal != 0) {
		printf("\n \n \n \t \t \t ===== COMMENT JOUER =====\n \n \n");
		printf("\t \t Deplacez votre serpent avec les fleches directionnelles de votre clavier.\n \n");
		printf("\t \t Mangez les fruits afin de grandir :>\n");
		printf("\t \t Mais attention, la mort rode... Certains murs, certains obstacles, et meme votre propre corps peuvent vous tuer :<\n");
		printf("\t \t Les points sont calcules differemment en fonction du niveau :\n");
		printf("\t \t \t NIVEAU DEBUTANT : 5 points par metre de queue\n");
		printf("\t \t \t NIVEAUX INTERMEDIAIRES : 5 points par metre de queue plus un point par seconde en vie. Un bonus de 100 point est donne au passage de niveau\n");
		printf("\t \t \t NIVEAUX AVANCES : 10 points par metre de queue plus un point par seconde en vie. Bonus de 100 points au passage de niveau\n");
		printf("\t \t \t SCORE PARFAIT : Regardez l'ordinateur effectuer un score parfait\n");
		printf("\t \t Appuyez sur 0 pour revenir au menu principal : ");

		scanf("%d", &retour_menuPrincipal);

		switch (retour_menuPrincipal) {
		case 0 : 
			break;
		default: 
			printf("\n \n \t \t BUG DANS LA MATRICE : ce que vous avez entre est incorrect...\n \n \n");
			break;
		}
	}
}

void Credits() {
	int retour_menu_principal = 1;

	while (retour_menu_principal != 0) {
		printf("\n \n \n \t \t \t ===== CREDITS =====\n \n \n");
		printf("\t \t JEU REALISE PAR\n \n");
		printf("\t \t \t MAES SEBASTIEN\n \n");
		printf("\t \t \t GUFFROY CYRIL\n \n");
		printf("\t \t ETUDIANTS EN PREMIERE ANNEE A TELECOM LILLE\n \n");
		printf("\t \t Dans le cadre du projet de fin de module de B23\n \n");
		printf("\t \t Appuyez sur 0 pour revenir au menut principal : ");

		scanf("%d", &retour_menu_principal);

		switch (retour_menu_principal) {
		case 0:
			break;
		default:
			printf("\n \n \t \t BUG DANS LA MATRICE : ce que vous avez entre est incorrect...\n \n \n");
			break;
		}	
	}
}

int Menu_Principal() {
	int choix_MenuPrincipal = 0;

	while (choix_MenuPrincipal != 4) {
		printf("\n \n \n \t \t \t ===== MENU ====\n \n \n");
		printf("\t \t 1) NIVEAUX\n \n");
		printf("\t \t 2) AIDE\n \n");
		printf("\t \t 3) CREDITS\n \n");
		printf("\t \t 4) QUITTER\n \n");
		printf("\t \t Entrez le numero correspondant a un element du menu, selon votre choix : ");

		scanf("%d", &choix_MenuPrincipal);
		switch (choix_MenuPrincipal) {
			case 1:
				Menu_Niveaux();
				break;
			case 2:
				Aide();
				break;
			case 3:
				Credits();
				break;
			case 4:
				break;
			default: 
				printf("\n \n \t \t BUG DANS LA MATRICE : ce que vous avez entre est incorrect...\n \n \n");
				Menu_Principal();
				break;
		}
	}
	printf("A bientot :>\n");
	return 0;
}

int main() {
	Menu_Principal();
	return 0;
}