#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int **matrix = (int **)malloc(4 * sizeof(int *));
	for (int i = 0; i < 4; i++) {
		matrix[i] = (int *)malloc(5 * sizeof(int));
	}
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			matrix[i][j] = cnt++;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 4; i++) {
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}