#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct student{
//	int num;
//	double grade;
//};
//struct profile {
//	char name[20];
//	int age;
//	double height;
//	char *intro;
//};
//
//struct profile {
//	int age;
//	double height;
//};
//struct student {
//	struct profile pf;
//	int id;
//	double grade;
//};

//struct student {
//	int id;
//	char name[20];
//	double grade;
//};

//struct vision {
//	double left;
//	double right;
//};
//struct vision exchange(struct vision robot);

//struct score {
//	int kor;
//	int eng;
//	int math;
//};

//struct address {
//	char name[20];
//	int age;
//	char tel[20];
//	char addr[80];
//};
//void print_list(struct address *lp);

struct list {
	int num;
	struct list *next;
};

int main(void) {
	//struct student s1;
	//s1.num = 2;
	//s1.grade = 2.7;
	//printf("�й� : %d\n", s1.num);
	//printf("���� : %.1lf\n", s1.grade);
	//printf("struct s1�� ������ : %d\n", sizeof(s1));

	//struct profile yuni;
	//strcpy(yuni.name, "������");
	//yuni.age = 17;
	//yuni.height = 164.5;
	//yuni.intro = (char *)malloc(80);
	//printf("�ڱ�Ұ� : ");
	//gets(yuni.intro);
	//printf("�̸� : %s\n", yuni.name);
	//printf("���� : %d\n", yuni.age);
	//printf("Ű : %.1lf\n", yuni.height);
	//printf("�ڱ�Ұ� : %s\n", yuni.intro);

	//struct student yuni;
	//yuni.pf.age = 17;
	//yuni.pf.height = 164.5;
	//yuni.id = 315;
	//yuni.grade = 4.3;

	//printf("���� : %d\n", yuni.pf.age);
	//printf("Ű : %.1lf\n", yuni.pf.height);
	//printf("�й� : %d\n", yuni.id);
	//printf("���� : %.1lf\n", yuni.grade);

	//struct student s1 = { 315, "ȫ�浿", 2.4 },
	//			   s2 = { 316, "�̼���", 3.7 },
	//			   s3 = { 317, "�������", 4.4 };
	//struct student max;

	//max = s1;
	//if (s2.grade > max.grade) max = s2;
	//if (s3.grade > max.grade) max = s3;
	//printf("�й� : %d\n", max.id);
	//printf("�̸� : %s\n", max.name);
	//printf("���� : %.1lf\n", max.grade);
	//struct vision robot;
	//printf("�÷� �Է� : ");
	//scanf("%lf%lf", &(robot.left), &(robot.right));
	//robot = exchange(robot);
	//printf("�ٲ� �÷� : %.1lf, %.1lf\n", robot.left, robot.right);
	//struct score yuni = { 90, 80, 70 };
	//struct score *ps = &yuni;

	//printf("���� : %d\n", (*ps).kor);
	//printf("���� : %d\n", ps->eng);
	//printf("���� : %d\n", ps->math);
	//struct address list[5] = {
	//	{"ȫ�浿", 23, "111-1111", "�︪�� ����"},
	//	{"�̼���", 35, "222-2222", "���� ��õ��"},
	//	{"�庸��", 19, "333-3333", "�ϵ� û����"},
	//	{"������", 15, "444-4444", "�泲 õ��"},
	//	{"���߱�", 45, "555-5555", "Ȳ�ص� ����"}
	//};
	//struct address list[3];
	//for (int i = 0; i < 3; i++) {
	//	scanf("%s%d%s%s", list[i].name, list[i].age, list[i].tel, list[i].addr);
	//}
	//print_list(list);

	struct list a = { 10, 0 }, b = { 20,0 }, c = { 30,0 };
	struct list *head = &a, *current;

	a.next = &b;
	b.next = &c;

	printf("head -> num : %d\n", head->num);
	printf("head -> next -> num : %d\n", head->next->num);

	printf("list all : ");
	current = head;
	while (current != NULL) {
		printf("%d ", current->num);
		current = current->next;
	}

	printf("\n");
	return 0;
}

//void print_list(struct address *lp) {
//	for (int i = 0; i < 5; i++) {
//		printf("%10s%5d%15s%20s\n", (lp + i)->name, (lp + i)->age, (lp + i)->tel, (lp + i)->addr);
//	}
//}
//struct vision exchange(struct vision robot)
//{
//	double temp;
//	temp = robot.left;
//	robot.left = robot.right;
//	robot.right = temp;
//	return robot;
//}
//int main(void) {
//	char temp[80];
//	char *str[3];
//	
//	for (int i = 0; i < 3; i++) {
//		printf("���ڿ��� �Է��ϼ��� : ");
//		gets(temp);
//		str[i] = (char *)malloc(strlen(temp) + 1);
//		strcpy(str[i], temp);
//	}
//
//	for (int i = 0; i < 3; i++) {
//		printf("%s\n", str[i]);
//	}
//	for (int i = 0; i < 3; i++) {
//		free(str[i]);
//	}
//	return 0;
//}

//void main(int argc, char **argv) {
//	if (argc > 0) {
//		for (int i = 1; i < argc; i++) {
//			printf("%s\n", argv[i]);
//		}
//	}
//	return;
//}