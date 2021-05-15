#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(char* type, void* a, void* b);
int main(void) {
	int age[2];
	double height[2];
	printf("첫 번째 사람의 나이와 키 입력 : ");
	scanf("%d %lf", &age[0], &height[0]);
	printf("두 번째 사람의 나이와 키 입력 : ");
	scanf("%d%lf", &age[1], &height[1]);
	swap("int", &age[0], &age[1]);
	swap("double", &height[0], &height[1]);

	printf("첫 번째 사람의 나이와 키 : %d, %.1lf\n", age[0], height[0]);
	printf("두 번째 사람의 나이와 키 : %d, %.1lf\n", age[1], height[1]);

	return 0;
}

void swap(char* type, void* a, void* b) {
	if (type == "int") {
		int temp = *(int *)a;
		*(int *)a = *(int *)b;
		*(int *)b = temp;
	}
	else if(type == "double"){
		double temp = *(double *)a;
		*(double *)a = *(double *)b;
		*(double *)b = temp;
	}
}