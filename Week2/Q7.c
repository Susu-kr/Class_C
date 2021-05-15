/*
	문제2. n x n인 2차원 배열에 숫자가 시계방향으로 달팽이 모양으로 채워지도록 작성
	<출력예>   3 x 3       4 x 4
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
	printf("N을 입력하세요 : ");
	scanf("%d", &n);
	int start = 0, x = 0, y = -1, sw = 1;
	for (int i = 0; i < n; i++) { // i가 1증가할때마다 돌아가는 횟수 -1
		for (int j = 0; j < n-i; j++) { // 수평이동
			y += sw;
			start++;
			A[x][y] = start;
		}
		for (int k = 0; k < n-i-1; k++) { // 수직이동
			x += sw;
			start++;
			A[x][y] = start;
		}
		sw *= -1; // 수평 -> 수직 -> (방향전환) -> 수평 -> 수직 -> (방향전환) ...
	}
	printf("%d x %d 달팽이 행렬\n", n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", A[i][j]);
		}
		printf("\n");
	}
}