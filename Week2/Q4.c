/*
	����4.
	���ڿ��� �Է¹޾Ƽ�, ���ڿ��� �����ǿ��� ��µǵ���
	��ĭ�� ������ �̵��ϸ鼭 ��µǵ��� ���α׷��� �ۼ��϶�. (�����ͷ�)
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
	char str[128] = { 0 }; // ���ڿ� 0���� �ʱ�ȭ
	char *ptr = str;
	int cnt = 0, temp; // cnt = ������� �ƴ� ����
	int size = sizeof(str);
	gets(str);
	cnt = find_zero(str, size);
	while (1) { // ��� ���� ������ ���ΰ�
		temp = *ptr; // ��ó�� �ܾ� �ǵڷ� ������ ���ؼ�
		for (int j = 0; j < cnt - 1; j++) { // ��ó�� �ܾ �ǵڷ� ������ ��ĭ�� ��������
			ptr[j] = ptr[j + 1];
		}
		ptr[cnt - 1] = temp;
		Sleep(100); // 0.1�ʰ� delay
		system("cls"); // �ܼ�â clear
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