#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int binary[20] = { 0, };
	int decimal, pos = 0;

	printf("10������ �Է��ϼ��� : ");
	scanf("%d", &decimal);
	printf("10���� %d �� �������� ", decimal);

	while (decimal != 0) {
		binary[pos++] = decimal % 2;
		decimal /= 2;
	}
	for (int i = pos - 1; i >= 0; i--) {
		printf("%d", binary[i]);
	}
	printf(" �Դϴ�."); 
	return 0;
}