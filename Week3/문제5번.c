#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** solution(int **mat, int size);
void Print(int **mat, int size);
int** input(int **mat, int size);

int main(void) {
	int N;
	while (1) {
		printf("행렬의 크기를 입력하세요 : ");
		scanf("%d", &N);
		if (N < 3 || N > 50) { 
			printf("행렬의 크기는 3이상 50이하입니다.\n");
		}
		else break;
	}
	int **matrix = (int **)malloc(N * sizeof(int *));
	for (int i = 0; i < N; i++) {
		matrix[i] = (int *)malloc(N * sizeof(int));
	}
	input(matrix, N);
	matrix = solution(matrix, N);
	Print(matrix, N);
	for (int i = 0; i < N; i++) {
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}

int** input(int **mat, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d행 숫자를 입력하세요 : ", i + 1);
		for (int j = 0; j < size; j++) {
			scanf("%d", &mat[i][j]);
			if (mat[i][j] < 1 || mat[i][j] >10000) {
				printf("각 원소는 1 이상 10,000 이하의 자연수 입니다.\n");
				printf("%d행 %d열부터 숫자를 재입력하세요 : ", i+1 , j + 1);
				j--;
			}
		}
	}
	return mat;
}

int** solution(int **mat, int size) {
	int **result_mat = (int **)malloc(size * sizeof(int *));
	for (int i = 0; i < size; i++) {
		result_mat[i] = (int *)malloc(size * sizeof(int));
	}
	for (int i = 0; i < size; i++) { // result_mat 0으로 초기화
		for (int j = 0; j < size; j++) {
			result_mat[i][j] = 0;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) { // 행 덧셈
				result_mat[i][j] += mat[i][k];
			}
			for (int k = 0; k < size; k++) { // 열 덧셈
				result_mat[i][j] += mat[k][j];
			}
			result_mat[i][j] -= mat[i][j];
		}
	}
	return result_mat;
}

void Print(int **mat, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
}