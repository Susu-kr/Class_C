/*
	문제3 배열의 숫자가 다음과 같이 채워지도록 프로그램 작성하시오.
	ex>
	1   1 2   1 2   1 2   1 2   1 2 6   1 2 6   1 2 6   1 2 6
	          3     3     3 5   3 5     3 5 7   3 5 7   3 5 7  ....
			        4     4     4       4       4 8     4 8 9
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	printf("배열의 크기를 입력하세요 : ");
	scanf("%d", &n);
	int arr[10][10] = { 0 };
	int start = 1, x = 0, y = 0;
	while (x != n-1 || y != n-1) {
		if (x == 0 && y == 0) {
			arr[x][y] = start++;
		}
		while (0 < x && 0 <= y && y < n - 1) {
			arr[--x][++y] = start++;
		}
		if (y < n - 1) arr[x][++y] = start++;
		else arr[++x][y] = start++;

		while (0 <= x && x < n - 1 && 0 < y) {
			arr[++x][--y] = start++;
		}
		if (x < n - 1)arr[++x][y] = start++;
		else arr[x][++y] = start++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}