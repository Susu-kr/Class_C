#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char name[10];
	int age = 0;
	printf("이름 : ");
	scanf("%s", &name);
	printf("나이 : ");
	scanf("%d", &age);
	printf("%s 님의 나이는 %d살 입니다.", name, age);
	return 0; 
}