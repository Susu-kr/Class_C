/*
	문제4.
	파일 복사 프로그램 만들기
	복사할 파일명과 복사후 생성되는 파일명을 입력받아서 파일의 내용을 복사하는 프로그램 작성.
	단. txt 파일뿐만 아니라 이미지 파일등의 모든 종류의 파일에 다 동일하게 적용할 수 있어야 한다.
	복사 진행 과정을 백분율로 화면에 표시해주도록 하고, 한번에 4바이트씩 복사하도록 한다.
	(4바이트 이하의 데이터에 대한 처리가 필요)

	복사할 파일 : source.txt
	생성된 파일 : dest.txt

	복사중 : 12%
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>
int main(void) {
	char source[20];
	char dest[20];
	printf("원본 파일이름 : ");
	scanf("%s", source);
	printf("복사 파일이름 : ");
	scanf("%s", dest);
	FILE *fp, *dp;
	fp = fopen(source, "rb");
	if (fp == NULL) {
		printf("파일을 불러오지 못했습니다.\n");
		return 1;
	}
	dp = fopen(dest, "wb");
	if (dp == NULL) {
		printf("파일을 만들지 못했습니다.\n");
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
			printf("복사중 : %.2lf%%\n", (double)pos / (double)last * 100);
			num = 0;
		}
	}
	system("cls");
	printf("복사완료 : %.2lf%%\n", (double)pos / (double)last * 100);
	fclose(fp);
	return 0;
}