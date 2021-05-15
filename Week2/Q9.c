/*
	문제1.
	컴퓨터에게서 3자리의 숫자를 임의로 정하게 한뒤 사용자 3자리의 숫자를 입력해서 결과를 확인한다.
	사용되는 숫자는 1~9까지 서로 다른 숫자이다. 숫자가 있지만 그 위치가 틀렸을 때는 볼을 출력
	숫자와 위치가 맞으면 스트라이크를 출력 숫자와 위치가 전부 틀리면 아웃을 출력
	무엇이 볼이고 스트라이크 인지는 출력하지 않는다.
	컴퓨터 2 1 6
	1  8 3 5 out
	2  6 5 9 0S 1B
	3  2 6 4 1S 1B
	4  2 1 6 정답
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void input_num(int* a);
void computer(int* a);
int comp(int* a, int* b);
int main(void) {
	srand(time(NULL));
	int com[3] = { 0 }; // 컴퓨터
	int input[3] = { 0 }; // 입력
	int cnt = 1; 
	computer(com);

	while (1) {
		printf("숫자를 3번 입력 하세요\n");
		input_num(input);
		printf("\n%d. ", cnt++);
		if(comp(input, com) == 1) break;
	}
	return 0;
}

void input_num(int* a) {
	for (int i = 0; i < 3; i++) {
		printf("%d번째 숫자를 입력하세요 : ", i + 1);
		scanf("%d", &a[i]);
		if (a[i] <= 0 || a[i] >= 10) {
			i--;
			printf("1~9까지의 숫자를 입력해주세요.\n");
		}
		else if (i != 0 && a[i] == a[i - 1]) {
			i--;
			printf("서로 다른 숫자를 입력해주세요.\n");
		}
	}
}
void computer(int* a) {
	for (int i = 0; i < 3; i++) {
		a[i] = rand() % 9 + 1;
		if (i != 0 && a[i] == a[i - 1]) i--; // 세자리수 모두 서로 다른 숫자
	}
}
int comp(int* a, int* b) {
	int B = 0, S = 0;
	for (int i = 0; i < 3; i++) {
		printf("%d ", a[i]);
		for (int j = 0; j < 3; j++) {
			if (a[i] == b[j]) {
				if (i == j) S++;
				else B++;
				break;
			}
		}
	}
	if (S == 0 && B == 0) printf("out\n\n");
	else if (S == 3) {
		printf("정답!\t");
		printf("컴퓨터 : ");
		for (int i = 0; i < 3; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
		return 1;
	}
	else printf("%dS %dB\n\n", S, B);
	return 0;
}