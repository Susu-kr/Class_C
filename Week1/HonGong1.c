#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcpy

int main() {
	/*
	//// : Source Code
	//printf("Be Happy!\n"); // \n : new line
	//printf("My\tfriend\n"); // \t : tab
	//printf("Goot\bd\tchance\n"); // \b : BackSpace
	//printf("Cow\rW\a\n"); // \r : Carrige Return (�� ������ �̵�), \a : Alert

	//// ������� ���� 4byte = 32bit, �Ǽ� 8byte = 64bit, ���� 4byte = 32bit
	//printf("%d %d %d\n", 10, 20, 10+20); // %d : ����
	//printf("%lf %f\n", 3.4, 4.5f); // %f : �Ҽ��� ���� 6�ڸ�
	//printf("%.1f\n", 3.45); // %.1f : �Ҽ��� ���� 1�ڸ� ©���� �� �ݿø�
	//printf("%.10f\n", 3.4); // %.10f : �Ҽ��� ���� 10�ڸ�

	//printf("%d %d %d\n", 12, 014, 0xc);	// 12 -> 10���� : 10 , 8���� : 014 , 16���� : 0xc
	//printf("%o %x %X\n", 12, 12, 12); // %o : 10 -> 8, %x : 10 -> 16, %X : 10 -> 16(�빮��)

	//printf("%.1f\n", 1e6); // ���� ������ �Ǽ��� �Ҽ��� ���·� ���
	//printf("%.7f\n", 3.14e-5); // �Ҽ��� ���� 7�ڸ����� ���
	//printf("%le\n", 0.0000314); // �Ҽ��� ������ �Ǽ��� ���� ���·� ���
	//printf("%.2le\n", 0.0000314); // ���� ���·� �Ҽ��� ���� ��° �ڸ����� ���

	//printf("%c\n", 'A'); // %c : ���� ���
	//printf("%s\n", "A"); // %s : ���ڿ� ���
	//printf("%c %s\n", '1', "ABCD");

	//// char(1byte) <= short(2byte) <= int(4byte) <= long(4byte) <= long long(8byte)
	//int a, b, c;
	//{
	//	// { } ������ ���� �ܺο��� ���x { } �ȿ�����
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

	//unsigned int u_a; // unsigned �ڷ����� �׻� ����� �����ϰ� %u�� ���
	//u_a = 2147483647;
	//printf("%d\n", u_a);
	//printf("%u\n", u_a + 1);
	//u_a = 4294967295;
	//printf("%d\n", u_a); // u_a = -1
	//printf("%u\n", u_a); // u_a = 4294967295

	//float ft = 1.234567890123456789; // float = .7 ���� ��ȿ����
	//double db = 1.234567890123456789; // double = .15���� ��ȿ����
	//printf("%.20f\n%.20f\n", ft, db);

	////char fruit[6] = "apple"; char���� �迭���·� ���� ���ڿ� ���� (�Ǹ������� NULL�������� ���ڿ� + 1)
	//char fruit[20] = "strawberry";
	//printf("%s\n%s %s\n", fruit, fruit , "jam");
	//strcpy(fruit, "banana"); // ���ڿ� ����
	//printf("%s\n", fruit);

	//// const �ڷ��� ������ = ��; ����� ���ÿ� �ʱ�ȭ + �� ���� x

	//int k = 0;
	//k += 1;
	//k += 2;
	//k += 3;
	//printf("a : %d\n", k);
	//int kor = 70, eng = 80, mat = 90;
	//int tot = 0;
	//tot = kor + eng + mat;
	//printf("���� : %d, ���� : %d, ���� : %d\n", kor, eng, mat);
	//printf("���� : %d\n", tot);

	//// scanf
	//int num1;
	//scanf("%d", &num1);
	//printf("�Էµ� �� : %d\n", num1);

	//int age;
	//double height;
	//printf("���̿� Ű�� �Է��ϼ��� : ");
	//scanf("%d%lf", &age, &height);
	//printf("���̴� %d��, Ű�� %.1fcm�Դϴ�.\n", age, height);

	//char grade;
	//char name[20];
	//printf("���� �Է� : ");
	//scanf("%c", &grade);
	//printf("�̸� �Է� : ");
	//scanf("%s", name);
	//printf("%s�� ������ %c�Դϴ�.\n", name, grade);

	
	//char fruit[20];
	//int cnt;
	//printf("�����ϴ� ���� : ");
	//scanf("%s", fruit);
	//printf("�� �� : ");
	//scanf("%d", &cnt);
	//printf("%s�� %d�� �帳�ϴ�.\n", fruit, cnt);
	//char ch;
	//printf("���� �Է� : ");
	//scanf(" %c", &ch);
	//printf("%c������ �ƽ�Ű �ڵ� ���� %d�Դϴ�.", ch, ch);

	//// ���� 1
	//float d1, d2, d3;
	//printf("�Ǽ� �Է� 1 (eǥ���) : ");
	//scanf("%f", &d1);
	//printf("�Էµ� �Ǽ� : %f\n�Ǽ� �Է� 2 (eǥ���) : ", d1);
	//scanf("%f", &d2);
	//printf("�Էµ� �Ǽ� : %f\n�Ǽ� �Է� 3 (eǥ���) : ", d2);
	//scanf("%f", &d3);
	//printf("�Էµ� �Ǽ� : %f\n", d1);

	
	////����2
	////����ڷκ��� ������ ��(second)�� �Է¹޾� '��:��:��' �������� ����ϴ� ���α׷�
	////��, �� �� , �� , �ʴ� ��� ���ڸ� ������ ǥ��.
	////���ڸ� ������ ��쿡�� �տ� 0�� �ٿ� ����ؾ� �Ѵ�.
	////ex) �Է� : 4000
	////	��� : 4000�ʴ� 01�ð� 06�� 40�� �Դϴ�.
	

	//int input, sec, min, hour;
	//printf("�Է� : ");
	//scanf("%d", &input);
	//hour = input / 3600;
	//min = input % 3600 / 60;
	//sec = input % 3600 % 60;
	//printf("��� : %d�ʴ� %02d�ð� %02d�� %02d�� �Դϴ�.", input, hour, min, sec);
	
	//int a = 5, b = 5;
	//int pre, post;
	//printf("�ʱ갪 a = %d, b = %d\n", a, b);
	//pre = (++a) * 3;
	//post = (b++) * 3;
	//printf("������ : (++a) * 3 = %d, ������ : (b++) * 3 = %d", pre, post);

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

	//	����3.
	//	������ nInput, nTotal�� ����ؼ� 3������ ������ �Է¹ް� ����� ����ϴ� ���α׷��� �ۼ��϶�.

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
	// ���� 4
	// ����ڷκ��� ���� 3���� �Է¹޾Ƽ� �� a,b,c�� �����ϰ�
	// ���ǿ����ڸ� ����ؼ� �̵� ������ ���� ū ���� ����ϴ� ���α׷�
	//int a, b, c, res;
	//scanf("%d%d%d", &a, &b, &c);
	//res = (a > b) ? a : b ;
	//res = (res > c) ? res : c;
	//printf("%d\n", res);
	
	// ���� 5
	// �ΰ� ������ 100���̶� �����ϰ�, ��踦 �Ѱ��Ǹ� �Ǹ� ������ 20�� ����ȴ�.
	// � ����� ������ �� �� N�Ⱓ �Ϸ翡 M���� ��踦 �ǿ��ٸ� 
	// ������ �󸶳� ����, ��� ���� �� �� �ִ°�? (N = 20, M = 1 ������� ������ ���� ��)
	// �پ�� �ð� : 00�� 00�� 00��
	// ��� ���� : 00�� 00�� 00�� 00��
	int N, M;
	scanf("%d%d", &N, &M);
	int deg = N * 365 * M * 20;
	int life = 100 * 365 * 1440 - deg;
	int life_age, life_day, life_hour, life_min;
	int deg_day, deg_hour, deg_min;
	deg_day = deg / 1440;
	deg_hour = deg % 1440 / 60;
	deg_min = deg % 1440 % 60;
	printf("�پ�� �ð� : %02d�� %02d�� %02d��\n", deg_day, deg_hour, deg_min);
	life_age = life / 525600;
	life_day = life % 525600 / 1440;
	life_hour = life % 525600 % 1440 / 60;
	life_min = life % 525600 % 1440 % 60;
	printf("��� ���� : %02d�� %02d�� %02d�� %02d��\n", life_age, life_day, life_hour, life_min);
	return 0;
}