#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	/*
		문장을 입력받고 대문자를 찾아 소문자로 바꾸는 프로그램을 작성
		문장 입력 : DON'T Worry, Be Happy~
		바뀐 문장 : don't worry, be happy~
		바뀐 문자 수 : 7
	*/
	char str[50];
	int cnt = 0;
	printf("문장 입력 : ");
	gets(str);
	for (int i = 0; i < sizeof(str); i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			str[i] += 32;
			cnt++;
		}
	}
	printf("바뀐 문장 : %s\n", str);
	printf("바뀐 문자 수 : %d\n", cnt);
	return 0;
}