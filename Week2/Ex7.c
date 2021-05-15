#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	char mark1[5][5] = { 0 };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j)mark1[i][j] = 'X';
			else {
				mark1[i][j] = 'O';
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%c ", mark1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	char mark2[5][5] = { 0 };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j || i + j == 4) mark2[i][j] = 'X';
			else {
				mark2[i][j] = 'O';
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%c ", mark2[i][j]);
		}
		printf("\n");
	}
	return 0;
}