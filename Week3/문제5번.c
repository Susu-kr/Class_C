#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** solution(int **mat, int size);
void Print(int **mat, int size);
int** input(int **mat, int size);

int main(void) {
	int N;
	while (1) {
		printf("����� ũ�⸦ �Է��ϼ��� : ");
		scanf("%d", &N);
		if (N < 3 || N > 50) { 
			printf("����� ũ��� 3�̻� 50�����Դϴ�.\n");
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
		printf("%d�� ���ڸ� �Է��ϼ��� : ", i + 1);
		for (int j = 0; j < size; j++) {
			scanf("%d", &mat[i][j]);
			if (mat[i][j] < 1 || mat[i][j] >10000) {
				printf("�� ���Ҵ� 1 �̻� 10,000 ������ �ڿ��� �Դϴ�.\n");
				printf("%d�� %d������ ���ڸ� ���Է��ϼ��� : ", i+1 , j + 1);
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
	for (int i = 0; i < size; i++) { // result_mat 0���� �ʱ�ȭ
		for (int j = 0; j < size; j++) {
			result_mat[i][j] = 0;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) { // �� ����
				result_mat[i][j] += mat[i][k];
			}
			for (int k = 0; k < size; k++) { // �� ����
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