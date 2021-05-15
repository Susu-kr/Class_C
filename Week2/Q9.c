/*
	����1.
	��ǻ�Ϳ��Լ� 3�ڸ��� ���ڸ� ���Ƿ� ���ϰ� �ѵ� ����� 3�ڸ��� ���ڸ� �Է��ؼ� ����� Ȯ���Ѵ�.
	���Ǵ� ���ڴ� 1~9���� ���� �ٸ� �����̴�. ���ڰ� ������ �� ��ġ�� Ʋ���� ���� ���� ���
	���ڿ� ��ġ�� ������ ��Ʈ����ũ�� ��� ���ڿ� ��ġ�� ���� Ʋ���� �ƿ��� ���
	������ ���̰� ��Ʈ����ũ ������ ������� �ʴ´�.
	��ǻ�� 2 1 6
	1  8 3 5 out
	2  6 5 9 0S 1B
	3  2 6 4 1S 1B
	4  2 1 6 ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void input_num(int* a);
void computer(int* a);
int comp(int* a, int* b);
int main(void) {
	srand(time(NULL));
	int com[3] = { 0 }; // ��ǻ��
	int input[3] = { 0 }; // �Է�
	int cnt = 1; 
	computer(com);

	while (1) {
		printf("���ڸ� 3�� �Է� �ϼ���\n");
		input_num(input);
		printf("\n%d. ", cnt++);
		if(comp(input, com) == 1) break;
	}
	return 0;
}

void input_num(int* a) {
	for (int i = 0; i < 3; i++) {
		printf("%d��° ���ڸ� �Է��ϼ��� : ", i + 1);
		scanf("%d", &a[i]);
		if (a[i] <= 0 || a[i] >= 10) {
			i--;
			printf("1~9������ ���ڸ� �Է����ּ���.\n");
		}
		else if (i != 0 && a[i] == a[i - 1]) {
			i--;
			printf("���� �ٸ� ���ڸ� �Է����ּ���.\n");
		}
	}
}
void computer(int* a) {
	for (int i = 0; i < 3; i++) {
		a[i] = rand() % 9 + 1;
		if (i != 0 && a[i] == a[i - 1]) i--; // ���ڸ��� ��� ���� �ٸ� ����
	}
}
int comp(int* a, int* b) {
	int B = 0, S = 0;
	for (int i = 0; i < 3; i++) {
		printf("%d ", a[i]);
		for (int j = 0; j < 3; j++) {
			if (a[i] == b[j]) {
				if (i == j) S++;
				else B++;
				break;
			}
		}
	}
	if (S == 0 && B == 0) printf("out\n\n");
	else if (S == 3) {
		printf("����!\t");
		printf("��ǻ�� : ");
		for (int i = 0; i < 3; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
		return 1;
	}
	else printf("%dS %dB\n\n", S, B);
	return 0;
}