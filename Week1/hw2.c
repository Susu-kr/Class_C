// 문제 4.
// 재귀함수를 이용해서 코드를 작성.(반복문을 이용해도 됨)
// 새끼 달팽이가 한마리 있는데 한달이 지나면 성체가 되고 또 한달이 지나면 새끼를 낳는다.
// 새로 태어난 달팽이 역시 한달이 지나면 성체가 되고, 다시 한달 뒤에 새끼를 낳는다고 할때,
// 달팽이가 매달 새끼를 낳는다고 할때, n년후 전체 달팽이의 수를 출력하는 프로그램 작성
// (가정1 : 달팽이가 n년안에 죽을 가능성은 없다.)
// (가정2 : 한번에 한마리씩만 낳는다.)
// 성인 달팽이 : O , 새끼 달팽이 : o
// 1달 -> o
// 2달 -> O
// 3달 -> O o
// 4달 -> O O o
// 5달 -> O O O o o ...
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int big_snail(int m);
int small_snail(int m);
int main() {
	int year;
	printf("년도를 입력하세요 : ");
	scanf("%d", &year);
	int m = year * 12;
	printf("%d달 -> 성인 달팽이 : %d , 새끼 달팽이 : %d, 총 달팽이 수 : %d\n", m, big_snail(m), small_snail(m), big_snail(m) + small_snail(m));
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