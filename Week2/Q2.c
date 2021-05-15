/*
	문제2.
	문자열을 입력받아서, 문자열이 광고판에서 출력되듯이
	한칸이 옆으로 이동하면서 출력되도록 프로그램을 작성하라.
	ex>
	Hello
	ello~ H
	llo~ He
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <Windows.h>
int main(void) {
	char str[128] = { 0 }; // 문자열 0으로 초기화
	int cnt = 0, temp; // cnt = 광고글이 아닌 시점
	printf("문자열을 입력하세요 : ");
	gets(str);
	for (int j = 0; j < sizeof(str); j++) {
		if (str[j] == 0) {
			cnt = j;
			break;
		}
	}
	while(1){ // 몇번 광고를 보여줄 것인가
		puts(str);
		temp = str[0]; // 맨처음 단어 맨뒤로 보내기 위해서
		for (int j = 0; j < cnt-1; j++) { // 맨처음 단어를 맨뒤로 보내고 한칸씩 왼쪽으로
			str[j] = str[j + 1];
		}
		str[cnt - 1] = temp;
		Sleep(1000); // 0.1초간 delay
		system("cls"); // 콘솔창 clear
	}
	return 0;
}