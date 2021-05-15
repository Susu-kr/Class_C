#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void Prime(int a);
void in_arr(int **mat, int n, int size);

int main(void) {
	int N = 0;
	printf("> 양수 입력 : ");
	scanf("%d", &N);
	int size = N / 5;
	int **matrix = (int **)malloc(size * sizeof(int *));
	in_arr(matrix, N, size);

	for (int i = 0; i < 4; i++) {
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}
void in_arr(int **mat, int n, int size) {
	int cur = 2, last = 0;
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			last = n - cur;
			mat[i] = (int *)malloc(last * sizeof(int));
		}
		else mat[i] = (int *)malloc(5 * sizeof(int));
		cur += 5;
	}
	cur = 2;
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			for (int j = 0; j < last; j++) {
				mat[i][j] = cur++;
				Prime(mat[i][j]);
			}
		}
		else {
			for (int j = 0; j < 5; j++) {
				mat[i][j] = cur++;
				Prime(mat[i][j]);
			}
		}
		printf("\n");
	}
}

void Prime(int a) {
	for (int div = 2; div <= sqrt(a); div++) {
		if (a % div == 0) {
			printf("\tX");
			return;
		}
	}
	printf("\t%d", a);
	return;
}
