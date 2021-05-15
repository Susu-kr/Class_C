#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//void input_arr(double *pa, int size);
//void output_arr(double *pa, int size);
//double find_max(double *pa, int size);
//char* my_strcpy(char* pd, char* ps);
//char* my_strcat(char* pd, char* ps);
//int my_strlen(char* ps);
//int my_strcmp(char* pa, char* pb);
char* change(char* pd, char* ps, char* ch);
int main(void) {
	//double arr[5];
	//double max;
	//int size = sizeof(arr) / sizeof(arr[0]);
	//input_arr(arr, size);
	//output_arr(arr, size);
	//max = find_max(arr, size);
	//printf("배열의 최대값 : %.1lf\n", max);

	//int ch;
	//ch = getchar();
	//printf("입력한 문자 : ");
	//putchar(ch);
	//putchar('\n');
	//int i = 0;
	//while (1) {
	//	int ch = getchar();
	//	if (-1 == ch) break;
	//	printf("%d\n", i++);
	//}
	//char ch;
	//for (int i = 0; i < 5; i++) {
	//	scanf("%c", &ch);
	//	printf("%c\n", ch);
	//}
	//int res;
	//char ch;
	//while (1) {
	//	res = scanf("%c", &ch);
	//	if (res == EOF)break;
	//	printf("%d ", ch);
	//}
	//int num, grade;
	//printf("학번 입력 : ");
	//scanf("%d", &num);
	//getchar();
	//printf("학점 입력 : ");
	//grade = getchar();
	//printf("학번 : %d, 학점 : %c", num, grade);

	//char szBuf[12] = { "apple" };
	//char* pszData = "apple";
	//printf(" %d \n", szBuf == pszData);
	//char ch;
	//getchar();
	//scanf("%*c"); // 한번읽고 버림
	//fgetc(stdin); 
	//fputs("ashdjasdgqywud", stdout);

	//char str1[80] = "strawberry";
	//char str2[80] = "apple";
	//char* ps1 = "banana";
	//char* ps2 = str2;
	//printf("최초 문자열 : %s\n", str1);
	//strcpy(str1, str2);
	//printf("바뀐 문자열 : %s\n", str1);
	//strcpy(str1, ps1);
	//printf("바뀐 문자열 : %s\n", str1);
	//strcpy(str1, ps2);
	//printf("바뀐 문자열 : %s\n", str1);
	//strcpy(str1, "banana");
	//printf("바뀐 문자열 : %s\n", str1);

	//char szBuf[12] = { "apple" };
	//char* pszData = szBuf;
	//strncpy(pszData, "source", 2);
	//printf("%s\n", szBuf);
	//char str[80] = "straw";
	//strcat(str, "berry");
	//printf("%s\n", str);
	//strncat(str, "piece", 3);
	//printf("%s\n", str);
	
	//char szBuf[256] = "";
	//szBuf[0] = '\0';

	//char str[80] = "strawberry";
	//char str2[80] = "berrystraw";
	//printf("바꾸기 전 문자열 str : %s\n", str);
	//printf("바꾸기 전 문자열 str 길이 : %d\n", my_strlen(str));
	//printf("바꾸기 전 문자열 str2: %s\n", str2);
	//printf("바꾸기 전 문자열 str2 길이 : %d\n", my_strlen(str2));
	//printf("바꾸기 전 문자열 비교 str vs str2: %d\n", my_strcmp(str, str2));
	//my_strcpy(str, "apple");
	//my_strcat(str, "pie");
	//my_strcpy(str2, "kiwi");
	//my_strcat(str2, "jucie");

	//printf("바꾼 후 문자열 str : %s\n", str);
	//printf("바꾼 후 문자열 str 길이 : %d\n", my_strlen(str));
	//printf("바꾼 후 문자열 str2: %s\n", str2);
	//printf("바꾼 후 문자열 str2 길이 : %d\n", my_strlen(str2));
	//printf("바꾼 후 문자열 비교 str vs str2: %d\n", my_strcmp(str, str2));
	char szBuf[32] = { "I am a boy." };
	change(szBuf, "boy", "girl");
	printf("%s\n", szBuf);
	return 0;
}
char* change(char* pd, char* ps, char* ch) {
	char* p;
	char temp[32];
	if ((p = strstr(pd, ps)) != NULL) {
		strcpy(temp, p + strlen(ps));
		strcpy(p, ch);
		strcat(pd, temp);
	}
	return p;
}
//char* my_strcpy(char* pd, char* ps) { // 복사
//	char* po = pd;
//	while (*ps != '\0') {
//		*pd = *ps;
//		pd++;
//		ps++;
//	}
//	*pd = '\0';
//	return po;
//}
//char* my_strcat(char* pd, char* ps) { // 맨뒤에 붙이기
//	char* po = pd;
//	while (*pd != '\0') {
//		pd++;
//	}
//	while (*ps != '\0') {
//		*pd = *ps;
//		pd++;
//		ps++;
//	}
//	*pd = '\0';
//	return po;
//}
//int my_strlen(char* ps) {
//	int cnt = 0;
//	while (*ps != '\0') {
//		cnt++;
//		ps++;
//	}
//	return cnt;
//}
//int my_strcmp(char* pa, char* pb) {
//	while ((*pa == *pb) && (*pa != '\0')) {
//		pa++;
//		pb++;
//	}
//	if (*pa > *pb) return 1;
//	else if (*pa < *pb) return -1;
//	else return 0;
//}
//
//void input_arr(double *pa, int size) {
//	printf("%d개의 실수값 입력 : ", size);
//	for (int i = 0; i < size; i++) {
//		scanf("%lf", pa + i);
//	}
//}
//void output_arr(double *pa, int size) {
//	printf("입력된 배열 : ");
//	for (int i = 0; i < size; i++) {
//		printf("%.1lf ", pa[i]);
//		// pa + i == &(*(pa + i));
//		// *(pa + i) == pa[i];
//	}
//	printf("\n");
//}
//double find_max(double *pa, int size) {
//	double max;
//	max = pa[0];
//	for (int i = 1; i < size; i++) {
//		if (pa[i] > max) max = pa[i];
//	}
//	return max;
//}