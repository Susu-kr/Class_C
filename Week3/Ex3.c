#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cracker {
	int price;
	int calories;
};

int main(void) {
	struct cracker A;
	printf("바사삭의 가격과 열량을 입력하세요 : ");
	scanf("%d%d", &(A.price), &(A.calories));
	printf("바사삭의 가격 : %d원\n", A.price);
	printf("바사삭의 열량 : %dkcal\n", A.calories);
	return 0;
}
