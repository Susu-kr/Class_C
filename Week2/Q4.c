/*
	문제4.
	문자열을 입력받아서, 문자열이 광고판에서 출력되듯이
	한칸이 옆으로 이동하면서 출력되도록 프로그램을 작성하라. (포인터로)
	ex>
	Hello
	ello~ H
	llo~ He
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
void print_arr(char *ptr, int cnt);
int find_zero(char *ptr, int size);
int main(void) {
	char str[128] = { 0 }; // 문자열 0으로 초기화
	char *ptr = str;
	int cnt = 0, temp; // cnt = 광고글이 아닌 시점
	int size = sizeof(str);
	gets(str);
	cnt = find_zero(str, size);
	while (1) { // 몇번 광고를 보여줄 것인가
		temp = *ptr; // 맨처음 단어 맨뒤로 보내기 위해서
		for (int j = 0; j < cnt - 1; j++) { // 맨처음 단어를 맨뒤로 보내고 한칸씩 왼쪽으로
			ptr[j] = ptr[j + 1];
		}
		ptr[cnt - 1] = temp;
		Sleep(100); // 0.1초간 delay
		system("cls"); // 콘솔창 clear
		print_arr(str, cnt);
	}
	return 0;
}
void print_arr(char *ptr, int cnt) {
	for (int i = 0; i < cnt; i++) {
		printf("%c", *ptr);
		ptr++;
	}
}
int find_zero(char *ptr, int size) {
	for (int j = 0; j < size; j++) {
		if (ptr[j] == 0) {
			return j;
		}
	}
}