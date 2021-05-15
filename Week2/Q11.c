/*
	문제3.
	사용자로부터 문자열을 입력받아서 출력하는 프로그램 작성
	문자열 입력 받기전에 사용자로 부터 문자열의 최대 길이에 대한 정보를 먼저 입력받고
	그 길이 만큼 메모리 공간을 동적으로 할당해 문자열을 입력받아 출력하도록 한다.
	특정 문자가 입력될 때까지 반복하도록 한다.("Quit" -> 종료)
	출력할때 다음과 같이 단어 단위로 문자열을 뒤집어 주도록 한다.
	ex) I am happy.
	-> happy am I
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int N;
	char *str = NULL;

	while (1) {
		int N;
		printf("문자열의 최대 길이를 입력하세요 : ");
		scanf("%d", &N);
		str = (char *)malloc(N+1);
		if (str == NULL) {
			printf("# 메모리가 부족합니다. \n");
			exit(0);
		}
		getchar();
		printf("문자열을 입력하세요 : ");
		fgets(str, N+1, stdin);
		if (strlen(str) < N || str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = '\0';
		else while (getchar() != '\n');
		if (strcmp(str, "Quit") == 0) {
			free(str);
			break;
		}
		for (int i = N - 1; i >= 0; i--) {
			if (str[i] == ' ') {
				printf("%s ", str + i + 1);
				str[i] = 0;
			}
			else if (i == 0) {
				printf("%s\n", str);
			}
		}
		free(str);
	}
	free(str);
}