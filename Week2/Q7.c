/*
	����2. n x n�� 2���� �迭�� ���ڰ� �ð�������� ������ ������� ä�������� �ۼ�
	<��¿�>   3 x 3       4 x 4
			  1  2  3    1  2  3  4
			  8  9  4    12 13 14 5
			  7  6  5    11 16 15 6
			             10 9  8  7  
*/                                    

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	int A[10][10] = { 0 };
	printf("N�� �Է��ϼ��� : ");
	scanf("%d", &n);
	int start = 0, x = 0, y = -1, sw = 1;
	for (int i = 0; i < n; i++) { // i�� 1�����Ҷ����� ���ư��� Ƚ�� -1
		for (int j = 0; j < n-i; j++) { // �����̵�
			y += sw;
			start++;
			A[x][y] = start;
		}
		for (int k = 0; k < n-i-1; k++) { // �����̵�
			x += sw;
			start++;
			A[x][y] = start;
		}
		sw *= -1; // ���� -> ���� -> (������ȯ) -> ���� -> ���� -> (������ȯ) ...
	}
	printf("%d x %d ������ ���\n", n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", A[i][j]);
		}
		printf("\n");
	}
}