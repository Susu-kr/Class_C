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
		printf("번호 입력 : ");
		scanf("%d", lotto_nums + i);
		if ((lotto_nums[i]) < 0 || (lotto_nums[i]) > 45) {
			printf("잘못된 로또 번호입니다. 다시 입력하세요. \n");
			i--;
			continue;
		}
		else {
			for (int j = 0; j < i; j++) { // 같은 번호 확인
				if (lotto_nums[j] == lotto_nums[i]) {
					printf("같은 번호가 있습니다!\n");
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
	printf("로또 번호 : ");
	for (int i = 0; i < size; i++) {
		printf("%d ", lotto_nums[i]);
	}
	printf("\n");
}