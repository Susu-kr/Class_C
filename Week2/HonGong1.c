#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void) {
	//int arr[5]; // 배열 0 ~ 4까지 생성
	//int arr2[5] = {0}; // 모든 배열 0으로 초기화
	//int arr3[] = { 1,2,3 }; // [] 뒤에 { } 개수만큼 배열 생성하고 초기화
	//arr[0] = 10;
	//arr[1] = 20;
	//arr[2] = arr[0] + arr[1];
	//scanf("%d", &arr[3]);

	//for (int i = 0; i < 5; i++) {
	//	printf("%d\n", arr[i]);
	//	//printf("%d\n", arr2[i]);
	//}
	//int score[5];
	//int count = sizeof(score) / sizeof(score[0]);
	//// 배열 요소의 개수(5) = 배열 전체 크기(20바이트) / 배열 하나의 크기 (4바이트)
	//int A[3] = { 1,2,3 };
	//int B[10];
	//for (int i = 0; i < 10; i++) {
	//	B[i] = A[i % 3];
	//}
	//for (int i = 0; i < 10; i++) {
	//	printf(" %d", B[i]);
	//}

	//char str[80];
	//printf("문자열 입력 : ");
	//scanf("%s", str /* &str[0] */);
	//printf("입력 후 문자열 : %s\n", str);
	//printf("문자열 입력 : ");
	//scanf("%s", str);
	//printf("입력 후 문자열 : %s\n", str);
	//char str1[80] = "jam";
	//char str2[80];
	//strcpy(str1, "tiger"); // strcpy(a , b) => a가 b보다 커야함.
	//strcpy(str2, str1);
	//printf("%s, %s\n", str1, str2);
	//char str[80];
	//printf("문자열 입력 : ");
	//gets(str);
	//puts("입력된 문자열 : ");
	//puts(str);
	
	//int a = 0;
	//int *pa = NULL;
	//pa = &a;
	//*pa = 10;
	//printf("a : %d ", a);
	//printf("&a : %d\n", &a);
	//printf("*pa : %d ", *pa);
	//printf("pa : %d\n", pa);

	//int a = 10, b = 15, total;
	//double avg;
	//int *pa, *pb;
	//int *pt = &total;
	//double *pg = &avg;

	//pa = &a;
	//pb = &b;
	//*pt = *pa + *pb;
	//*pg = *pt / 2.0;
	//
	//printf("두 정수의 값 : %d, %d\n", *pa, *pb);
	//printf("두 정수의 합 : %d\n", *pt);
	//printf("두 정수의 평균 : %.1lf\n", *pg);

	//int a = 10, b = 20;
	//const int *pa = &a;

	//printf("변수 a 값 : %d\n", *pa);
	//pa = &b;
	//printf("변수 b 값 : %d\n", *pa);
	//pa = &a;
	//a = 20;
	//printf("변수 a 값 : %d\n", *pa);

	//char ch;
	//int in;
	//double db;

	//char *pc = &ch;
	//int *pi = &in;
	//double *pd = &db;
	//printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
	//printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
	//printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));
	//printf("char * 포인터의 크기 : %d\n", sizeof(pc));
	//printf("int * 포인터의 크기 : %d\n", sizeof(pi));
	//printf("double * 포인터의 크기 : %d\n", sizeof(pd));
	//printf("char * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pc));
	//printf("int * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pi));
	//printf("double * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pd));
	//int arr[5] = { 0 };
	//&arr == arr; // 100
	//(&arr + 1) == (arr)+1 * sizeof(int); // : 104

	//int arr[3];
	//*(arr + 0) = 10;
	//*(arr + 1) = *(arr + 0) + 10;
	//scanf("%d", (arr + 2));
	//for (int i = 0; i < 3; i++) {
	//	printf("%5d", *(arr + i));
	//}

	/*int arr[3];
	int arr2[3];
	int *pa = arr;
	int *pb = arr2;
	*pa = 10;
	*pb = 10;
	*(pa + 1) = 20;
	*(pb + 1) = 20;
	pa[2] = pa[0] + pa[1];
	pb[2] = pb[0] + pb[1];
	for (int i = 0; i < 3; i++) {
		printf("%d ", (*pa)++);
		printf("%d\n", ++(*pb));
	}
*/
	int arr[5] = { 10, 20, 30, 40, 50 };
	int *pa = arr;
	int *pb = pa + 3;
	printf("pa : %u\n", pa);
	printf("pb : %u\n", pb);
	pa++;
	printf("pb - pa : %u\n", pb - pa);
	printf("앞에 있는 배열 요소의 값 출력 : ");
	if (pa < pb) printf("%d\n", *pa);
	else printf("%d\n", *pb);
	int *pc = arr;
	for (int i = 0; i < 5; i++) {
		printf("%d ", *pc);
		pc++;
	}
	return 0;
}