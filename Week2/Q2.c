/*
	����2.
	���ڿ��� �Է¹޾Ƽ�, ���ڿ��� �����ǿ��� ��µǵ���
	��ĭ�� ������ �̵��ϸ鼭 ��µǵ��� ���α׷��� �ۼ��϶�.
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
	char str[128] = { 0 }; // ���ڿ� 0���� �ʱ�ȭ
	int cnt = 0, temp; // cnt = ������� �ƴ� ����
	printf("���ڿ��� �Է��ϼ��� : ");
	gets(str);
	for (int j = 0; j < sizeof(str); j++) {
		if (str[j] == 0) {
			cnt = j;
			break;
		}
	}
	while(1){ // ��� ���� ������ ���ΰ�
		puts(str);
		temp = str[0]; // ��ó�� �ܾ� �ǵڷ� ������ ���ؼ�
		for (int j = 0; j < cnt-1; j++) { // ��ó�� �ܾ �ǵڷ� ������ ��ĭ�� ��������
			str[j] = str[j + 1];
		}
		str[cnt - 1] = temp;
		Sleep(1000); // 0.1�ʰ� delay
		system("cls"); // �ܼ�â clear
	}
	return 0;
}