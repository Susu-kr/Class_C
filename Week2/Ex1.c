#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	/*
		������ �Է¹ް� �빮�ڸ� ã�� �ҹ��ڷ� �ٲٴ� ���α׷��� �ۼ�
		���� �Է� : DON'T Worry, Be Happy~
		�ٲ� ���� : don't worry, be happy~
		�ٲ� ���� �� : 7
	*/
	char str[50];
	int cnt = 0;
	printf("���� �Է� : ");
	gets(str);
	for (int i = 0; i < sizeof(str); i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			str[i] += 32;
			cnt++;
		}
	}
	printf("�ٲ� ���� : %s\n", str);
	printf("�ٲ� ���� �� : %d\n", cnt);
	return 0;
}