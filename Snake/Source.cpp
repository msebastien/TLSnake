#include <stdio.h>

void main() {
	//On crée le tableau
	char plateau[30][60];
	int i,j;

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

	for (i = 0; i < 30; i++) {
		for (j = 0; j < 60; j++) {
			printf("%c", plateau[i][j]);
		}
		printf("\n");
	}
}