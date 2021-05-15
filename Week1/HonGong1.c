#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcpy

int main() {
	/*
	//// : Source Code
	//printf("Be Happy!\n"); // \n : new line
	//printf("My\tfriend\n"); // \t : tab
	//printf("Goot\bd\tchance\n"); // \b : BackSpace
	//printf("Cow\rW\a\n"); // \r : Carrige Return (맨 앞으로 이동), \a : Alert

	//// 상수에서 정수 4byte = 32bit, 실수 8byte = 64bit, 문자 4byte = 32bit
	//printf("%d %d %d\n", 10, 20, 10+20); // %d : 정수
	//printf("%lf %f\n", 3.4, 4.5f); // %f : 소수점 이하 6자리
	//printf("%.1f\n", 3.45); // %.1f : 소수점 이하 1자리 짤리는 값 반올림
	//printf("%.10f\n", 3.4); // %.10f : 소수점 이하 10자리

	//printf("%d %d %d\n", 12, 014, 0xc);	// 12 -> 10진수 : 10 , 8진수 : 014 , 16진수 : 0xc
	//printf("%o %x %X\n", 12, 12, 12); // %o : 10 -> 8, %x : 10 -> 16, %X : 10 -> 16(대문자)

	//printf("%.1f\n", 1e6); // 지수 형태의 실수를 소수점 형태로 출력
	//printf("%.7f\n", 3.14e-5); // 소수점 이하 7자리까지 출력
	//printf("%le\n", 0.0000314); // 소수점 형태의 실수를 지수 형태로 출력
	//printf("%.2le\n", 0.0000314); // 지수 형태로 소수점 이하 둘째 자리까지 출력

	//printf("%c\n", 'A'); // %c : 문자 상수
	//printf("%s\n", "A"); // %s : 문자열 상수
	//printf("%c %s\n", '1', "ABCD");

	//// char(1byte) <= short(2byte) <= int(4byte) <= long(4byte) <= long long(8byte)
	//int a, b, c;
	//{
	//	// { } 내부의 것을 외부에서 사용x { } 안에서만
	//	int a, c;
	//	a = 11;
	//	c = 99;
	//	printf("a = %d, c = %d\n", a, c);
	//}
	//double da;
	//a = 10;
	//b = a;
	//c = a + 20;
	//da = 3.5;
	//printf("a = %d, b = %d, c = %d, da = %.1f\n", a, b, c, da);

	//char ch1, ch2; // char : -128 ~ 127 -> ASCII CODE 0~127 (48 ~ 57 : 0 ~ 9 , 65 ~ 90 : A ~ Z, 97 ~ 122 : a ~ z)
	//ch1 = 'A';
	//ch2 = 65;
	//printf("ch1 = %c %d, ch2 = %c %d\n", ch1, ch1, ch2, ch2);

	//short sh = 32767;
	//int in = 2147483647;
	//long ln = 2147483647;
	//long long lln = 123451234512345;
	//printf("sh = %d, in = %d, ln = %ld, lln = %lld\n", sh, in, ln, lln);

	//unsigned int u_a; // unsigned 자료형은 항상 양수만 저장하고 %u로 출력
	//u_a = 2147483647;
	//printf("%d\n", u_a);
	//printf("%u\n", u_a + 1);
	//u_a = 4294967295;
	//printf("%d\n", u_a); // u_a = -1
	//printf("%u\n", u_a); // u_a = 4294967295

	//float ft = 1.234567890123456789; // float = .7 까지 유효숫자
	//double db = 1.234567890123456789; // double = .15까지 유효숫자
	//printf("%.20f\n%.20f\n", ft, db);

	////char fruit[6] = "apple"; char형을 배열형태로 만들어서 문자열 생성 (맨마지막에 NULL문자포함 문자열 + 1)
	//char fruit[20] = "strawberry";
	//printf("%s\n%s %s\n", fruit, fruit , "jam");
	//strcpy(fruit, "banana"); // 문자열 복사
	//printf("%s\n", fruit);

	//// const 자료형 변수형 = 값; 선언과 동시에 초기화 + 값 변경 x

	//int k = 0;
	//k += 1;
	//k += 2;
	//k += 3;
	//printf("a : %d\n", k);
	//int kor = 70, eng = 80, mat = 90;
	//int tot = 0;
	//tot = kor + eng + mat;
	//printf("국어 : %d, 영어 : %d, 수학 : %d\n", kor, eng, mat);
	//printf("총점 : %d\n", tot);

	//// scanf
	//int num1;
	//scanf("%d", &num1);
	//printf("입력된 값 : %d\n", num1);

	//int age;
	//double height;
	//printf("나이와 키를 입력하세요 : ");
	//scanf("%d%lf", &age, &height);
	//printf("나이는 %d살, 키는 %.1fcm입니다.\n", age, height);

	//char grade;
	//char name[20];
	//printf("학점 입력 : ");
	//scanf("%c", &grade);
	//printf("이름 입력 : ");
	//scanf("%s", name);
	//printf("%s의 학점은 %c입니다.\n", name, grade);

	
	//char fruit[20];
	//int cnt;
	//printf("좋아하는 과일 : ");
	//scanf("%s", fruit);
	//printf("몇 개 : ");
	//scanf("%d", &cnt);
	//printf("%s를 %d개 드립니다.\n", fruit, cnt);
	//char ch;
	//printf("문자 입력 : ");
	//scanf(" %c", &ch);
	//printf("%c문자의 아스키 코드 값은 %d입니다.", ch, ch);

	//// 문제 1
	//float d1, d2, d3;
	//printf("실수 입력 1 (e표기법) : ");
	//scanf("%f", &d1);
	//printf("입력된 실수 : %f\n실수 입력 2 (e표기법) : ", d1);
	//scanf("%f", &d2);
	//printf("입력된 실수 : %f\n실수 입력 3 (e표기법) : ", d2);
	//scanf("%f", &d3);
	//printf("입력된 실수 : %f\n", d1);

	
	////문제2
	////사용자로부터 정수로 초(second)를 입력받아 '시:분:초' 형식으로 출력하는 프로그램
	////단, 각 시 , 분 , 초는 모두 두자리 정수로 표시.
	////한자리 숫자인 경우에는 앞에 0을 붙여 출력해야 한다.
	////ex) 입력 : 4000
	////	출력 : 4000초는 01시간 06분 40초 입니다.
	

	//int input, sec, min, hour;
	//printf("입력 : ");
	//scanf("%d", &input);
	//hour = input / 3600;
	//min = input % 3600 / 60;
	//sec = input % 3600 % 60;
	//printf("출력 : %d초는 %02d시간 %02d분 %02d초 입니다.", input, hour, min, sec);
	
	//int a = 5, b = 5;
	//int pre, post;
	//printf("초깃값 a = %d, b = %d\n", a, b);
	//pre = (++a) * 3;
	//post = (b++) * 3;
	//printf("전위형 : (++a) * 3 = %d, 후위형 : (b++) * 3 = %d", pre, post);

	//int a = 30;
	//int res;
	//res = (a > 10) && (a < 20);
	//printf("(a > 10) && (a < 20) : %d\n", res);
	//res = (a < 10) || (a > 20);
	//printf("(a < 10) || (a > 20) : %d\n", res);
	//res = !(a >= 30);
	//printf("!(a >= 30) : %d\n", res);

	//double a = 4.0, b = 1.2;
	//printf("%.1lf + %.1lf = %.1lf\n", a, b, a + b);
	//printf("%.1lf - %.1lf = %.1lf\n", a, b, a - b);
	//printf("%.1lf * %.1lf = %.1lf\n", a, b, a * b);
	//printf("%.1lf / %.1lf = %.1lf\n", a, b, a / b);

	//	문제3.
	//	변수는 nInput, nTotal만 사용해서 3과목의 점수를 입력받고 평균을 출력하는 프로그램을 작성하라.

	//int nInput;
	//double nTotal = 0.0;
	//scanf("%d", &nInput);
	//nTotal += nInput;
	//scanf("%d", &nInput);
	//nTotal += nInput;
	//scanf("%d", &nInput);
	//nTotal += nInput;
	//printf("%.1lf\n", nTotal / 3.0);

	//int kor = 3, eng = 5, mat = 4;
	//int credits;
	//int res;
	//double kscore = 3.8, escore = 4.4, mscore = 5.9;
	//double grade;

	//credits = kor + eng + mat;
	//grade = (kor * kscore + eng * escore + mat * mscore) / credits;
	//res = (credits >= 10) && (grade > 4.0);
	//printf("%d\n", res);
	*/
	// 문제 4
	// 사용자로부터 정수 3개를 입력받아서 각 a,b,c에 저장하고
	// 조건연산자를 사용해서 이들 변수중 가장 큰 값을 출력하는 프로그램
	//int a, b, c, res;
	//scanf("%d%d%d", &a, &b, &c);
	//res = (a > b) ? a : b ;
	//res = (res > c) ? res : c;
	//printf("%d\n", res);
	
	// 문제 5
	// 인간 수명이 100년이라 가정하고, 담배를 한개피를 피면 수명이 20분 단축된다.
	// 어떤 사람이 성인이 된 후 N년간 하루에 M개피 담배를 피웠다면 
	// 수명은 얼마나 단축, 몇살 까지 살 수 있는가? (N = 20, M = 1 결과값을 가지고 서로 비교)
	// 줄어든 시간 : 00일 00시 00분
	// 기대 수명 : 00살 00일 00시 00분
	int N, M;
	scanf("%d%d", &N, &M);
	int deg = N * 365 * M * 20;
	int life = 100 * 365 * 1440 - deg;
	int life_age, life_day, life_hour, life_min;
	int deg_day, deg_hour, deg_min;
	deg_day = deg / 1440;
	deg_hour = deg % 1440 / 60;
	deg_min = deg % 1440 % 60;
	printf("줄어든 시간 : %02d일 %02d시 %02d분\n", deg_day, deg_hour, deg_min);
	life_age = life / 525600;
	life_day = life % 525600 / 1440;
	life_hour = life % 525600 % 1440 / 60;
	life_min = life % 525600 % 1440 % 60;
	printf("기대 수명 : %02d살 %02d일 %02d시 %02d분\n", life_age, life_day, life_hour, life_min);
	return 0;
}