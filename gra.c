#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void print(char table[3][3]) {
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			printf("%c ", table[k][j]);
		}
		printf("\n");
	}
}
void ruch(int x, int y) {
	do
	{
		scanf("%d", &x);
		scanf("%d", &y);
		if (x >= 0 && x <= 2 && y >= 0 && y <= 2) {
			break;
		}
		printf("Podaj poprawne wspó³rzêdne (z zakresu od 1 do 3)");
	} while (1);
}
int win(char table[3][3]) {
	char c;
	int j = 0;
	for (int i = 0; i < 3; i++) {
		c = table[i][j];
		if (c != '-') {
			if ((c == table[i][j + 1]) && (c == table[i][j + 2])) {
				return 1;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		c = table[j][i];
		if (c != '-') {
			if ((c == table[j + 1][i]) && (c == table[j + 2][i])) {
				return 1;
			}
		}
	}
	if (table[0][0] != '-'&&table[0][0] == table[1][1] && table[0][0] == table[2][2]) {
		return 1;
	}
	if (table[0][2] != '-'&&table[0][2] == table[1][1] && table[0][2] == table[2][0]) {
		return 1;
	}
	return 0;
}
int main() {
	int x1;
	int y1;
	int x2 = 0;
	int y2 = 0;
	char table[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			table[i][j] = '-';
		}
	}
	for (int i = 0; i < 4; i++) {
		printf("Gracz 1 (X) podaje wspó³rzêdne, najpierw x potem y;");
		do
		{
			scanf("%d", &x1);
			scanf("%d", &y1);
			x1--;
			y1--;
			if (x1 >= 0 && x1 <= 2 && y1 >= 0 && y1 <= 2 && table[x1][y1] == '-') {
				break;
			}
			printf("Podaj poprawne wspó³rzêdne (z zakresu od 1 do 3) pustego pola");
		} while (1);
		table[x1][y1] = 'X';
		system("cls");
		print(table);
		if (win(table)) {
			printf("Gracz 1 wygrywa");
			return 1;
		}
		printf("Gracz 2 (O) podaje wspó³rzêdne, najpierw x potem y;");
		do
		{
			scanf("%d", &x2);
			scanf("%d", &y2);
			x2--;
			y2--;
			if (x2 >= 0 && x2 <= 2 && y2 >= 0 && y2 <= 2 && table[x2][y2] == '-') {
				break;
			}
			printf("Podaj poprawne wspó³rzêdne (z zakresu od 1 do 3) pustego pola");
		} while (1);
		table[x2][y2] = 'O';
		system("cls");
		print(table);
		if (win(table)) {
			printf("Gracz 2 wygrywa!");
			return 2;
		}
	}
	printf("Gracz 1 (X) podaje wspó³rzêdne, najpierw x potem y");
	do
	{
		scanf("%d", &x1);
		scanf("%d", &y1);
		x1--;
		y1--;
		if (x1 >= 0 && x1 <= 2 && y1 >= 0 && y1 <= 2 && table[x1][y1] == '-') {
			break;
		}
		printf("Podaj poprawne wspó³rzêdne (z zakresu od 1 do 3) pustego pola");
	} while (1);
	table[x1][y1] = 'X';
	system("cls");
	print(table);
	if (win(table)) {
		printf("Gracz 1 wygrywa");
		return 1;
	}
}
//1.funkcja wykonaj ruch