#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
	문제1. 다음과 같은 A배열이 주어질때 다음과 같은 B배열과 같은 형태가 되도록
	프로그램만들고 출력하세요.
	 A배열                                     B배열
	  2x4                                         4x2
	    			   					          5 1    7 4 1
	1 2 3 4	 1 2 3   ---------------------->      6 2    8 5 2
	5 6 7 8  4 5 6   ---------------------->      7 3    9 6 3
	         7 8 9   ---------------------->      8 4
*/

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	int A[10][10] = { 0 };
	int B[10][10] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	printf("A배열\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			B[i][j] = A[n-j-1][i];
		}
	}
	printf("\nB배열\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	return 0;
}