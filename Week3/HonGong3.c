#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
void FileOpen_WriteTest(char* filename);
void FileOpen_ReadTest(char* filename);
int main(void) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	FileOpen_WriteTest("data\\b.txt");
	FileOpen_ReadTest("data\\b.txt");
	_CrtDumpMemoryLeaks();
	return 0;
}

void FileOpen_WriteTest(char* filename) {
	FILE *fp;
	//char str[] = "banana";
	int arr[10] = { 13, 10, 13, 13, 10, 26, 13, 10, 13, 10 };
	fp = fopen(filename, "wb");
	if (fp == NULL) {
		printf("파일이 열리지 않았습니다.\n");
		return;
	}
	for (int i = 0; i < 10; i++) {
		fputc(arr[i],fp);
	}
	
	//int i = 0;
	//while (str[i] != '\0') {
	//	fputc(str[i], fp);
	//	i++;
	//}
	fputc('\n', fp);

	fclose(fp);
}

void FileOpen_ReadTest(char* filename) {
	FILE *fp;
	int ch;
	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("파일이 열리지 않았습니다.\n");
		return;
	}
	ch = fgetc(fp);
	while (ch != EOF) {
		//putchar(ch);
		printf("%4d", ch);
		ch = fgetc(fp);
	}
	fclose(fp);
}