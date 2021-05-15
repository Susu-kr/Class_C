// 1주차 2일 HonGong Book 100p ~
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// 형변환 연산자
	//int a = 20, b = 3;
	//double res;
	//res = ((double)a / (double)b);
	//printf("a = %d, b = %d\n", a, b);
	//printf("a / b의 결과 : %.1lf\n", res);
	//a = (int)res;
	//printf("(int)%.1lf의 결과 : %d\n", res, a);
	
	// sizeof 연산자
	//int a = 10;
	//double b = 3.4;

	//printf("int형 변수의 크기 : %d\n", sizeof(a));
	//printf("double형 변수의 크기 : %d\n", sizeof(b));
	//printf("정수형 상수의 크기 : %d\n", sizeof(10));
	//printf("수식의 결괏값의 크기 : %d\n", sizeof(1.5 + 3.4));
	//printf("char 자료형의 크기 : %d\n", sizeof(char));

	// 복합대입 연산자
	//int a = 10, b = 20;
	//int res = 2;
	//a += 20;
	//res *= b + 10;
	//printf("a = %d, b = %d\n", a, b);
	//printf("res = %d\n", res);
	
	// 콤마 연산자
	//int a = 10, b = 20;
	//int res;
	//res = (++a, ++b);
	//printf("a : %d, b : %d\n", a, b);
	//printf("res : %d\n", res);

	//// 조건 연산자(삼항 연산자) ex) (a > b) ? a(true) : b(false)
	//// 문제 1 사용자로부터 정수 3개를 입력받아서 각 a,b,c에 저장하고 조건연산자를
	//// 사용해서 이들 변수중 가장 큰 값을 출력하는 프로그램을 작성하라.
	//int a, b, c;
	//printf("세 정수를 입력하세요 : ");
	//scanf("%d%d%d", &a, &b, &c);
	//printf("가장 큰 수 : %d\n", (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));

	// 비트연산자
	// &(논리곱) : 두 비트가 모두 1인 경우에만 1로 계산한다.
	// ^(배타논리합) : 두 비트가 서로 다른 경우만 1로 계산한다.
	// |(논리합) : 두 비트 중에서 하나라도 참이면 1로 계산한다.
	// ~(부정) : 1은 0으로 바꾸고 0은 1로 바꾼다.
	// <<, >> (이동) : << 연산자는 왼쪽으로 이동, >> 오른쪽으로 이동
	//int a = 10, b = 12;
	//printf("a & b : %d\n", a & b);
	//printf("a ^ b : %d\n", a ^ b);
	//printf("a | b : %d\n", a | b);
	//printf("~a : %d\n", ~a);
	//printf("a << 1 : %d\n", a << 1);
	//printf("a >> 2 : %d\n", a >> 2);

	// 연산자 우선순위와 연산 방향 (순위 같으면 왼->오, 괄호 우선)
	// 단항(++...) > 이항(*,/...) > 삼항 연산자 순서 / 산술 > (비트 이동 연산자) > 관계 > 논리(&&,||) 연산자 순서로

	//int res;
	//res = (sizeof(short) > sizeof(long));
	//res == 0 ? printf("long\n") : printf("short\n");

	//int seats = 70, audience = 65;
	//double rate;
	//rate = ((double)audience / (double)seats) * 100;
	//printf("입장률 : %.1lf%%\n", rate);

	//int hour, min, sec;
	//double time = 3.76;
	//hour = (int)time;
	//time -= (double)hour;
	//time *= 60;
	//min = (int)time;
	//time -= (double)min;
	//time *= 60;
	//sec = (int)time;
	//printf("3.76시간은 %d시간 %d분 %d초입니다.\n", hour, min, sec);

	//double weight, height, BMI;
	//printf("몸무게(kg)과 키(cm) 입력 : ");
	//scanf("%lf%lf", &weight, &height);
	//height /= 100; // m 단위로 계산
	//BMI = weight / (height * height);
	//printf("BMI = %.1lf\n", BMI);
	//(BMI >= 20.0) && (BMI < 25.0) ? printf("표준입니다.") : printf("체중관리가 필요합니다.");

	// 5장 if문
	//int a = 20, b = 0;
	//if (a > 10) 
	//{
	//	b = a;
	//}
	//printf("a : %d, b : %d\n", a, b);

	//int a = 0, b = 0;
	//if (a > 0) b = 1;
	//else if (a == 0) b = 2;
	//else b = 3;
	//printf("b : %d\n", b);

	//int a;
	//printf("숫자를 입력하세요 : ");
	//scanf("%d", &a);
	//if (a < 0)
	//{
	//	a = -a;
	//}
	//printf("a : %d\n", a);
	//if (a % 2 == 0)
	//{
	//	a = 2;
	//}
	//else 
	//{
	//	a = 1;
	//}
	//printf("a : %d\n", a);

	//int chest;
	//printf("가슴둘레를 입력하세요 : ");
	//scanf("%d", &chest);
	//char size;
	//if (chest <= 90) {
	//	size = 'S';
	//}
	//else if (chest > 90 && chest <= 100) {
	//	size = 'M';
	//}
	//else {
	//	size = 'L';
	//}
	//printf("size : %c\n", size);

	//double height = 179.5, weight = 75.0;
	//if (height >= 187.5 && weight < 80.0) {
	//	printf("ok\n");
	//}
	//else {
	//	printf("cancle\n");
	//}

	// 문제 1
	// 두 개의 정수를 입력 받아서 두 수의 차를 출력하는 프로그램 구현
	// 단, 무조건 큰 수에서 작은 수를 뺀 결과를 출력해야 한다.
	// ex) 12 5 -> 7 , 4 16 -> 12
	// 1.1 if ~ else를 이용
	// 1.2 조건 연산자를 이용
	//int num1, num2;
	//printf("두 개의 정수를 입력하세요 : ");
	//scanf("%d%d", &num1, &num2);
	//if (num1 > num2) {
	//	printf("1.1 if ~ else를 이용한 결과 : %d\n", num1 - num2);
	//}
	//else {
	//	printf("1.1 if ~ else를 이용한 결과 : %d\n", num2 - num1);
	//}
	//printf("1.2 조건 연산자를 이용한 결과 : %d\n", (num1 > num2) ? num1 - num2 : num2 - num1);

	// 문제2. 학생의 전체 평균점수를 구하고 학점을 출력하는 프로그램 작성
	// 학생의 성적이 90이상 A, 80이상 B, 70이상 C, 60 이상 D, 그 미만이면 F
	// 프로그램 실행해서 순서대로 국어, 영어, 수학 점수를 입력받는다.
	// 세 과목의 평균을 구하고, 적절한 학점을 출력하는 프로그램 작성.
	// if ~ else
	//int kor, eng, mat;
	//double tot;
	//printf("세 과목의 점수를 입력하세요 : ");
	//scanf("%d%d%d", &kor, &eng, &mat);
	//tot = (double)(kor + eng + mat) / 3;
	//if (tot >= 90) {
	//	printf("평균 : %.1lf, 학점 : A", tot);
	//}
	//else if (tot >= 80 && tot < 90) {
	//	printf("평균 : %.1lf, 학점 : B", tot);
	//}
	//else if (tot >= 70 && tot < 80) {
	//	printf("평균 : %.1lf, 학점 : C", tot);
	//}
	//else if (tot >= 60 && tot < 70) {
	//	printf("평균 : %.1lf, 학점 : D", tot);
	//}
	//else {
	//	printf("평균 : %.1lf, 학점 : F", tot);
	//}
	
	//int num1, num2, result;
	//char op;
	//printf("사칙연산 입력(정수) : ");
	//scanf("%d %c %d", &num1, &op, &num2);
	//switch (op) {
	//	case '+':
	//		result = num1 + num2;
	//		break;
	//	case '-':
	//		result = num1 - num2;
	//		break;
	//	case '/':
	//		if (num2 == 0) {
	//			printf("0으로 나눌 수 없습니다.");
	//			return 0;
	//		}
	//		else {
	//			result = num1 / num2;
	//			break;
	//		}
	//	case '*':
	//		result = num1 * num2;
	//		break;
	//	default:
	//		printf("잘못입력했습니다.");
	//		return 0;
	//}
	//printf("%d%c%d = %d", num1, op, num2, result);

	// 반복문
	//int a = 1;
	//while (a < 10) {
	//	a = a * 2;
	//	printf("a = %d\n", a);
	//}
	//int k = 1;
	//for (int i = 0; i < 3; i++) {
	//	k *= 2;
	//}
	//printf("k = %d\n", k);
	
	//문제3.
	// 어떤 수를 입력받아 그 수의 계승(Factorial)을 구해 출력하는 프로그램
	// ex) 3! = 3*2*1 = 6 (자기자신부터 1씩 줄여 전부 곱한 값.)
	//int num, result = 1;
	//printf("수를 입력하세요 : ");
	//scanf("%d", &num);
	//for (int i = num; i > 0; i--) {
	//	result *= i;
	//	printf("For : num = %d, result = %d\n", i, result);
	//}
	//result = 1;
	//while (num > 0) {
	//	result *= num;
	//	printf("While : num = %d, result = %d\n", num, result);
	//	num--;
	//}
	
	// 문제4.
	// 두 수를 입력받아서 두 수 사이에 존재하는 정수의 합을 구하여 출력하라.
	// 3 5 => 3 + 4 + 5 => 12
	// 5 3 => 3 + 4 + 5 => 12
	//int num1, num2, result = 0;
	//printf("두 수를 입력하세요 : ");
	//scanf("%d%d", &num1, &num2);
	//if (num1 > num2) {
	//	for (int i = num2; i <= num1; i++) {
	//		result += i;
	//		printf("%d + ", i);
	//	}
	//	printf("= %d\n", result);
	//	result = 0;
	//	while (num1 >= num2) {
	//		result += num2;
	//		printf("%d + ", num2);
	//		num2++;
	//	}
	//	printf("= %d\n", result);
	//}
	//else {
	//	for (int i = num1; i <= num2; i++) {
	//		result += i;
	//		printf("%d + ", i);
	//	}
	//	printf("= %d\n", result);
	//	result = 0;
	//	while (num1 <= num2) {
	//		result += num1;
	//		printf("%d + ", num1);
	//		num1++;
	//	}
	//	printf("= %d\n", result);
	//}
	
	//int a;
	//printf("수를 입력하세요 : ");
	//scanf("%d", &a);
	//while (a < 0) {
	//	printf("수를 입력하세요 : ");
	//	scanf("%d", &a);
	//}
	
	//for(int i = 0; i < 5; i++){
	//	printf("Be happy\n");
	//}
	
	//int i;
	//for (i = 0; i < 10; i++) {
	//	printf("$");
	//}
	
	// 중첩반복문
	//int i, j;
	//for (i = 0; i < 3; i++) {
	//	for (j = 0; j < 5; j++) {
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	
	//for(int i = 1; i < 10; i++){
	//	for (int j = 1; j < 10; j++) {
	//		printf("%d x %d = %d\n", i, j, i*j);
	//	}
	//}

	// 문제 5.
	// 사용자로부터 계속 정수를 입력받아 그 값을 계속 더한다.
	// 사용자가 0을 입력할때까지 계속되어야 하며, 0이 입력되면
	// 입력된 모든 정수의 합을 출력하고 종료한다.
	//int num, result = 0;
	//printf("정수를 입력하세요 : ");
	//scanf("%d", &num);
	//while (num != 0) {
	//	result += num;
	//	printf("정수를 입력하세요 : ");
	//	scanf("%d", &num);
	//}
	//printf("입력된 정수들의 합 : %d", result);

	//문제6.
	// 1 이상 100 미만인 정수중 7의 배수와 9의 배수를 출력하라
	// 단, 7의 배수이면서 9의 배수인 정수는 1번만 출력해야 한다.
	//int num1, num2, i = 1;
	//printf("배수를 입력하세요(2개) : ");
	//scanf("%d%d", &num1, &num2);
	//for (int i = 1; i < 100; i++) {
	//	if (i % num1 == 0) {
	//		printf("%d ", i);
	//	}
	//	else if (i % num2 == 0) {
	//		printf("%d ", i);
	//	}
	//}


	//문제7.
	// 구구단을 출력하라.
	// 예 > 구구단
	// ----------------------------------------
	// 2 x 1 = 2  3 x 1 = 3  4 x 1 = 4
	// ...
	// 2 x 9 = 18 3 x 9 = 27 4 x 9 = 36
	// -----------------------------------------
	// 5 x 1 = 5  6 x 1 = 6  7 x 1 = 7
	// ...
	// 5 x 9 = 45 6 x 9 = 54 7 x 9 = 63
	// ----------------------------------------
	// 8 x 1 = 8  9 x 1 = 9
	// ...
	// 8 x 9 = 72 9 x 9 = 81
	// -----------------------------------------
	int start = 2, input;
	printf("몇단까지 출력하시겠습니까? : ");
	scanf("%d", &input);
	printf("------------------------------------------------------\n");
	while (start < input+1) { // 출력하고자 하는 단까지 반복
		for (int i = 1; i < 10; i++) {
			for (int j = start; j < start + 3; j++) { // 숫자 3개씩 출력
				printf("%d x %d = %d\t", j, i, j * i);
				if (j == input) break; // 마지막 단일 경우 종료.
			}
			printf("\n");
		}
		printf("------------------------------------------------------\n");
		start += 3; // 숫자 3개씩 출력
	}
	return 0;
}