#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void input_nums(int *lotto_nums, int size);
void print_nums(int *lotto_nums, int size);

int main(void) {
	int lotto_nums[6];
	int size = sizeof(lotto_nums) / sizeof(lotto_nums[0]);
	input_nums(lotto_nums, size);
	print_nums(lotto_nums, size);
	return 0;
}

void input_nums(int *lotto_nums, int size) {
	for (int i = 0; i < size; i++) {
		printf("��ȣ �Է� : ");
		scanf("%d", lotto_nums + i);
		if ((lotto_nums[i]) < 0 || (lotto_nums[i]) > 45) {
			printf("�߸��� �ζ� ��ȣ�Դϴ�. �ٽ� �Է��ϼ���. \n");
			i--;
			continue;
		}
		else {
			for (int j = 0; j < i; j++) { // ���� ��ȣ Ȯ��
				if (lotto_nums[j] == lotto_nums[i]) {
					printf("���� ��ȣ�� �ֽ��ϴ�!\n");
					i--;
					break;
				}
				else if (lotto_nums[j] > lotto_nums[i]) {
					int temp = lotto_nums[j];
					lotto_nums[j] = lotto_nums[i];
					lotto_nums[i] = temp;
				}
			}
		}
	}
}
void print_nums(int *lotto_nums, int size) {
	printf("�ζ� ��ȣ : ");
	for (int i = 0; i < size; i++) {
		printf("%d ", lotto_nums[i]);
	}
	printf("\n");
}