// 1���� 2�� HonGong Book 100p ~
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// ����ȯ ������
	//int a = 20, b = 3;
	//double res;
	//res = ((double)a / (double)b);
	//printf("a = %d, b = %d\n", a, b);
	//printf("a / b�� ��� : %.1lf\n", res);
	//a = (int)res;
	//printf("(int)%.1lf�� ��� : %d\n", res, a);
	
	// sizeof ������
	//int a = 10;
	//double b = 3.4;

	//printf("int�� ������ ũ�� : %d\n", sizeof(a));
	//printf("double�� ������ ũ�� : %d\n", sizeof(b));
	//printf("������ ����� ũ�� : %d\n", sizeof(10));
	//printf("������ �ᱣ���� ũ�� : %d\n", sizeof(1.5 + 3.4));
	//printf("char �ڷ����� ũ�� : %d\n", sizeof(char));

	// ���մ��� ������
	//int a = 10, b = 20;
	//int res = 2;
	//a += 20;
	//res *= b + 10;
	//printf("a = %d, b = %d\n", a, b);
	//printf("res = %d\n", res);
	
	// �޸� ������
	//int a = 10, b = 20;
	//int res;
	//res = (++a, ++b);
	//printf("a : %d, b : %d\n", a, b);
	//printf("res : %d\n", res);

	//// ���� ������(���� ������) ex) (a > b) ? a(true) : b(false)
	//// ���� 1 ����ڷκ��� ���� 3���� �Է¹޾Ƽ� �� a,b,c�� �����ϰ� ���ǿ����ڸ�
	//// ����ؼ� �̵� ������ ���� ū ���� ����ϴ� ���α׷��� �ۼ��϶�.
	//int a, b, c;
	//printf("�� ������ �Է��ϼ��� : ");
	//scanf("%d%d%d", &a, &b, &c);
	//printf("���� ū �� : %d\n", (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));

	// ��Ʈ������
	// &(����) : �� ��Ʈ�� ��� 1�� ��쿡�� 1�� ����Ѵ�.
	// ^(��Ÿ����) : �� ��Ʈ�� ���� �ٸ� ��츸 1�� ����Ѵ�.
	// |(����) : �� ��Ʈ �߿��� �ϳ��� ���̸� 1�� ����Ѵ�.
	// ~(����) : 1�� 0���� �ٲٰ� 0�� 1�� �ٲ۴�.
	// <<, >> (�̵�) : << �����ڴ� �������� �̵�, >> ���������� �̵�
	//int a = 10, b = 12;
	//printf("a & b : %d\n", a & b);
	//printf("a ^ b : %d\n", a ^ b);
	//printf("a | b : %d\n", a | b);
	//printf("~a : %d\n", ~a);
	//printf("a << 1 : %d\n", a << 1);
	//printf("a >> 2 : %d\n", a >> 2);

	// ������ �켱������ ���� ���� (���� ������ ��->��, ��ȣ �켱)
	// ����(++...) > ����(*,/...) > ���� ������ ���� / ��� > (��Ʈ �̵� ������) > ���� > ��(&&,||) ������ ������

	//int res;
	//res = (sizeof(short) > sizeof(long));
	//res == 0 ? printf("long\n") : printf("short\n");

	//int seats = 70, audience = 65;
	//double rate;
	//rate = ((double)audience / (double)seats) * 100;
	//printf("����� : %.1lf%%\n", rate);

	//int hour, min, sec;
	//double time = 3.76;
	//hour = (int)time;
	//time -= (double)hour;
	//time *= 60;
	//min = (int)time;
	//time -= (double)min;
	//time *= 60;
	//sec = (int)time;
	//printf("3.76�ð��� %d�ð� %d�� %d���Դϴ�.\n", hour, min, sec);

	//double weight, height, BMI;
	//printf("������(kg)�� Ű(cm) �Է� : ");
	//scanf("%lf%lf", &weight, &height);
	//height /= 100; // m ������ ���
	//BMI = weight / (height * height);
	//printf("BMI = %.1lf\n", BMI);
	//(BMI >= 20.0) && (BMI < 25.0) ? printf("ǥ���Դϴ�.") : printf("ü�߰����� �ʿ��մϴ�.");

	// 5�� if��
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
	//printf("���ڸ� �Է��ϼ��� : ");
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
	//printf("�����ѷ��� �Է��ϼ��� : ");
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

	// ���� 1
	// �� ���� ������ �Է� �޾Ƽ� �� ���� ���� ����ϴ� ���α׷� ����
	// ��, ������ ū ������ ���� ���� �� ����� ����ؾ� �Ѵ�.
	// ex) 12 5 -> 7 , 4 16 -> 12
	// 1.1 if ~ else�� �̿�
	// 1.2 ���� �����ڸ� �̿�
	//int num1, num2;
	//printf("�� ���� ������ �Է��ϼ��� : ");
	//scanf("%d%d", &num1, &num2);
	//if (num1 > num2) {
	//	printf("1.1 if ~ else�� �̿��� ��� : %d\n", num1 - num2);
	//}
	//else {
	//	printf("1.1 if ~ else�� �̿��� ��� : %d\n", num2 - num1);
	//}
	//printf("1.2 ���� �����ڸ� �̿��� ��� : %d\n", (num1 > num2) ? num1 - num2 : num2 - num1);

	// ����2. �л��� ��ü ��������� ���ϰ� ������ ����ϴ� ���α׷� �ۼ�
	// �л��� ������ 90�̻� A, 80�̻� B, 70�̻� C, 60 �̻� D, �� �̸��̸� F
	// ���α׷� �����ؼ� ������� ����, ����, ���� ������ �Է¹޴´�.
	// �� ������ ����� ���ϰ�, ������ ������ ����ϴ� ���α׷� �ۼ�.
	// if ~ else
	//int kor, eng, mat;
	//double tot;
	//printf("�� ������ ������ �Է��ϼ��� : ");
	//scanf("%d%d%d", &kor, &eng, &mat);
	//tot = (double)(kor + eng + mat) / 3;
	//if (tot >= 90) {
	//	printf("��� : %.1lf, ���� : A", tot);
	//}
	//else if (tot >= 80 && tot < 90) {
	//	printf("��� : %.1lf, ���� : B", tot);
	//}
	//else if (tot >= 70 && tot < 80) {
	//	printf("��� : %.1lf, ���� : C", tot);
	//}
	//else if (tot >= 60 && tot < 70) {
	//	printf("��� : %.1lf, ���� : D", tot);
	//}
	//else {
	//	printf("��� : %.1lf, ���� : F", tot);
	//}
	
	//int num1, num2, result;
	//char op;
	//printf("��Ģ���� �Է�(����) : ");
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
	//			printf("0���� ���� �� �����ϴ�.");
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
	//		printf("�߸��Է��߽��ϴ�.");
	//		return 0;
	//}
	//printf("%d%c%d = %d", num1, op, num2, result);

	// �ݺ���
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
	
	//����3.
	// � ���� �Է¹޾� �� ���� ���(Factorial)�� ���� ����ϴ� ���α׷�
	// ex) 3! = 3*2*1 = 6 (�ڱ��ڽź��� 1�� �ٿ� ���� ���� ��.)
	//int num, result = 1;
	//printf("���� �Է��ϼ��� : ");
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
	
	// ����4.
	// �� ���� �Է¹޾Ƽ� �� �� ���̿� �����ϴ� ������ ���� ���Ͽ� ����϶�.
	// 3 5 => 3 + 4 + 5 => 12
	// 5 3 => 3 + 4 + 5 => 12
	//int num1, num2, result = 0;
	//printf("�� ���� �Է��ϼ��� : ");
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
	//printf("���� �Է��ϼ��� : ");
	//scanf("%d", &a);
	//while (a < 0) {
	//	printf("���� �Է��ϼ��� : ");
	//	scanf("%d", &a);
	//}
	
	//for(int i = 0; i < 5; i++){
	//	printf("Be happy\n");
	//}
	
	//int i;
	//for (i = 0; i < 10; i++) {
	//	printf("$");
	//}
	
	// ��ø�ݺ���
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

	// ���� 5.
	// ����ڷκ��� ��� ������ �Է¹޾� �� ���� ��� ���Ѵ�.
	// ����ڰ� 0�� �Է��Ҷ����� ��ӵǾ�� �ϸ�, 0�� �ԷµǸ�
	// �Էµ� ��� ������ ���� ����ϰ� �����Ѵ�.
	//int num, result = 0;
	//printf("������ �Է��ϼ��� : ");
	//scanf("%d", &num);
	//while (num != 0) {
	//	result += num;
	//	printf("������ �Է��ϼ��� : ");
	//	scanf("%d", &num);
	//}
	//printf("�Էµ� �������� �� : %d", result);

	//����6.
	// 1 �̻� 100 �̸��� ������ 7�� ����� 9�� ����� ����϶�
	// ��, 7�� ����̸鼭 9�� ����� ������ 1���� ����ؾ� �Ѵ�.
	//int num1, num2, i = 1;
	//printf("����� �Է��ϼ���(2��) : ");
	//scanf("%d%d", &num1, &num2);
	//for (int i = 1; i < 100; i++) {
	//	if (i % num1 == 0) {
	//		printf("%d ", i);
	//	}
	//	else if (i % num2 == 0) {
	//		printf("%d ", i);
	//	}
	//}


	//����7.
	// �������� ����϶�.
	// �� > ������
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
	printf("��ܱ��� ����Ͻðڽ��ϱ�? : ");
	scanf("%d", &input);
	printf("------------------------------------------------------\n");
	while (start < input+1) { // ����ϰ��� �ϴ� �ܱ��� �ݺ�
		for (int i = 1; i < 10; i++) {
			for (int j = start; j < start + 3; j++) { // ���� 3���� ���
				printf("%d x %d = %d\t", j, i, j * i);
				if (j == input) break; // ������ ���� ��� ����.
			}
			printf("\n");
		}
		printf("------------------------------------------------------\n");
		start += 3; // ���� 3���� ���
	}
	return 0;
}