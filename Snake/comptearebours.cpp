#include <stdio.h>
#include <Windows.h>

int main() {
	int time;
	scanf("%d", &time);

	while (time >= 0) {
		system("cls");
		printf("Temps restant : %d", time);
		Sleep(1000);
		time--;
	}
	printf("GAME OVER");
	return 0;
}