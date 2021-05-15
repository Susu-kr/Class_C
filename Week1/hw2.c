// ���� 4.
// ����Լ��� �̿��ؼ� �ڵ带 �ۼ�.(�ݺ����� �̿��ص� ��)
// ���� �����̰� �Ѹ��� �ִµ� �Ѵ��� ������ ��ü�� �ǰ� �� �Ѵ��� ������ ������ ���´�.
// ���� �¾ ������ ���� �Ѵ��� ������ ��ü�� �ǰ�, �ٽ� �Ѵ� �ڿ� ������ ���´ٰ� �Ҷ�,
// �����̰� �Ŵ� ������ ���´ٰ� �Ҷ�, n���� ��ü �������� ���� ����ϴ� ���α׷� �ۼ�
// (����1 : �����̰� n��ȿ� ���� ���ɼ��� ����.)
// (����2 : �ѹ��� �Ѹ������� ���´�.)
// ���� ������ : O , ���� ������ : o
// 1�� -> o
// 2�� -> O
// 3�� -> O o
// 4�� -> O O o
// 5�� -> O O O o o ...
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int big_snail(int m);
int small_snail(int m);
int main() {
	int year;
	printf("�⵵�� �Է��ϼ��� : ");
	scanf("%d", &year);
	int m = year * 12;
	printf("%d�� -> ���� ������ : %d , ���� ������ : %d, �� ������ �� : %d\n", m, big_snail(m), small_snail(m), big_snail(m) + small_snail(m));
}
int big_snail(int m) {
	if (m == 1 || m == 0) return 0;
	else if (m == 2) return 1;
	else return big_snail(m - 2) + big_snail(m - 1);
}
int small_snail(int m) {
	if (m == 1) return 1;
	else if (m == 2 || m == 0) return 0;
	else return small_snail(m - 2) + small_snail(m - 1);
}