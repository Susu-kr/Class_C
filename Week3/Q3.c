/*
	����3.
	99.txt ������ ����� ���⿡ �������� �����ϴ� ���α׷��� �ۼ�.
	�� ���Ͽ��� ���ϴ� �������� ����ϴ� ���α׷��� �ۼ�.
	ex> 99.txt
		2 x 1 = 2
		2 x 2 = 4
		...

		����� ���ϴ� �������� ? 2
		2��
		=====================
		2 x 1 = 2
		2 x 2 = 4
		...
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *fp;
	fp = fopen("data\\99.txt", "w+");
	if (fp == NULL) {
		printf("������ ������ ���߽��ϴ�.\n");
		return 1;
	}
	int num1 = 2, num2 = 1;
	int pos = 0;
	int offset[10], lastOff[10];
	offset[num1] = pos;
	while (1) {
		fprintf(fp,"%d x %d = %d\n", num1, num2, num1 * num2);
		num2++;
		if (num2 == 10 && num1 < 10) {
			pos = ftell(fp);
			lastOff[num1] = pos;
			num1++;
			if (num1 == 10)break;
			offset[num1] = pos;
			num2 = 1;
		}
	}
	int N;
	char str[20];
	printf("����� ���ϴ� �������� ? ");
	scanf("%d", &N);
	printf("%d��\n", N);
	pos = offset[N];
	fseek(fp, pos, SEEK_SET);
	while (pos < lastOff[N]) {
		fgets(str, sizeof(str), fp);
		printf("%s", str);
		pos = ftell(fp);
	}
	fclose(fp);
	return 0;
}