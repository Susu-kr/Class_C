/*
	����4.
	���� ���� ���α׷� �����
	������ ���ϸ�� ������ �����Ǵ� ���ϸ��� �Է¹޾Ƽ� ������ ������ �����ϴ� ���α׷� �ۼ�.
	��. txt ���ϻӸ� �ƴ϶� �̹��� ���ϵ��� ��� ������ ���Ͽ� �� �����ϰ� ������ �� �־�� �Ѵ�.
	���� ���� ������ ������� ȭ�鿡 ǥ�����ֵ��� �ϰ�, �ѹ��� 4����Ʈ�� �����ϵ��� �Ѵ�.
	(4����Ʈ ������ �����Ϳ� ���� ó���� �ʿ�)

	������ ���� : source.txt
	������ ���� : dest.txt

	������ : 12%
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>
int main(void) {
	char source[20];
	char dest[20];
	printf("���� �����̸� : ");
	scanf("%s", source);
	printf("���� �����̸� : ");
	scanf("%s", dest);
	FILE *fp, *dp;
	fp = fopen(source, "rb");
	if (fp == NULL) {
		printf("������ �ҷ����� ���߽��ϴ�.\n");
		return 1;
	}
	dp = fopen(dest, "wb");
	if (dp == NULL) {
		printf("������ ������ ���߽��ϴ�.\n");
		return 1;
	}

	char buffer[5] = { 0, };
	fseek(fp, 0, SEEK_END);
	int count, pos = 0, last = ftell(fp);
	int num = 0;
	rewind(fp);
	while (pos < last) {
		count = fread(buffer, sizeof(char), 4, fp);
		fwrite(buffer, sizeof(char), count, dp);
		pos = ftell(dp);
		memset(buffer, 0, 5);
		num++;
		if (num == last % 1000) {
			system("cls");
			printf("������ : %.2lf%%\n", (double)pos / (double)last * 100);
			num = 0;
		}
	}
	system("cls");
	printf("����Ϸ� : %.2lf%%\n", (double)pos / (double)last * 100);
	fclose(fp);
	return 0;
}