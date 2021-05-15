/*
	����1.
	��ȣ, �̸�, ������ �Է� ���� �� �ִ� ����ü�� �����, ������ �л��� ���� �����͸� �Է� �޾� ����ϴ� �ڵ带 �����.
	���� ������ �����Ͽ� ����ϵ���
	1. �Է� - �л� ��ȣ, �̸�, ���������� �Է�
	2. ��� - ������ ���� ���ĵ� ���·� ���
	3. �˻� - �̸����� �ش� �л��� ��ȣ, �̸�, ������ ���
	> ����1. ��ȣ �ߺ�x, �̸� �ߺ� ����
	> ����2. �˻� .. �̸� �˻� .. ���� ã���� ��� -> �߰� ���
	4. ���� - ���α׷� ����



	1. �޸� �Ҵ�
	2. �ڱ� ���� ����ü Ȱ��
	(ex :| |A|90|next| , | |B|80|next| , | |C|85|next|
	=> | |A|90|next| -> | |C|85|next| -> | |B|80|NULL|
	3. �Է�, ���, �˻��� ���� ���� �Լ��� �����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list List;
struct list {
	int ID;
	int grade;
	char name[20];
	struct list *next;
};

void input(List *st);
void swapList(List *st1, List *st2);
void SortList(List *st, int size);
void SearchList(List *st);
int ListSize(List *st);
void deleteList(List *st);
void showList(List *st);
int main(void) {
	int N;
	int size = 0;
	List *ST = malloc(sizeof(List));
	ST->ID = 0;
	ST->grade = 0;
	strcpy(ST->name, "HEAD");
	ST->next = NULL;
	while (1) {
		printf("--------------------------------------------------------\n");
		printf("1. �Է�\n");
		printf("2. ���\n");
		printf("3. �˻�\n");
		printf("4. ����\n");
		printf("��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &N);
		while (getchar() != '\n');
		printf("--------------------------------------------------------\n");
		if (N == 4) {
			deleteList(ST);
			break;
		}
		else if (N == 1) {
			input(ST);
			size = ListSize(ST);
			SortList(ST, size);
		}
		else if (N == 2) {
			showList(ST);
		}
		else if (N == 3) {
			SearchList(ST);
		}
		else {
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���. \n");
			continue;
		}
	}
	return 0;
}

void showList(List *st) {
	printf("��ü �л��� ���������� ����մϴ�. \n");
	List *cur = st->next;
	while (cur != NULL) {
		printf("��ȣ : %d, �̸� : %s, ���� : %d\n", cur->ID, cur->name, cur->grade);
		cur = cur->next;
	}

}

void deleteList(List *st) {
	List *cur = st;
	List *next;
	while (cur != NULL) {
		next = cur->next;
		free(cur);
		cur = next;
	}
}
int ListSize(List *st) {
	List *cur = st;
	int cnt = 0;
	while (cur != NULL) {
		cnt++;
		cur = cur->next;
	}
	return cnt;
}

void input(List *st) {
	if (st->next == NULL) {
		List *newST = malloc(sizeof(List));
		printf("��ȣ �̸� ���������� �Է��ϼ��� : ");
		scanf("%d%s%d", &(newST->ID), newST->name, &(newST->grade));
		newST->next = NULL;
		st->next = newST;
	}
	else {
		List *cur = st->next;
		int chk = 1;
		while (chk) {
			List *newST = malloc(sizeof(List));
			printf("��ȣ �̸� ���������� �Է��ϼ��� : ");
			scanf("%d%s%d", &(newST->ID), newST->name, &(newST->grade));
			while (cur != NULL) {
				if (newST->ID == cur->ID) {
					printf("�̹� �����ϴ� ID�Դϴ�. �ٸ� ID�� �Է��� �ּ���.\n");
					free(newST);
					cur = st->next;
					break;
				}
				if (cur->next == NULL) {
					newST->next = NULL;
					cur->next = newST;
					chk = 0;
					break;
				}
				cur = cur->next;
			}
		}
	}
}

void swapList(List *st1, List *st2) {
	List temp = *st1;
	st1->ID = st2->ID;
	st2->ID = temp.ID;
	st1->grade = st2->grade;
	st2->grade = temp.grade;
	strcpy(st1->name, st2->name);
	strcpy(st2->name, temp.name);
}
void SortList(List *st, int size) {
	List *cur = st->next;
	for (int i = 0; i < size - 1; i++) {
		if (cur->next == NULL)break;
		for (int j = 0; j < size - 2 - i; j++) {
			if (cur->grade < cur->next->grade) {
				swapList(cur, cur->next);
			}
			cur = cur->next;
		}
		cur = st->next;
	}
}

void SearchList(List *st) {
	printf("ã���� �ϴ� �л��� �̸��� �Է��ϼ��� : ");
	char f_name[20];
	int cnt = 0;
	scanf("%s", f_name);
	List *cur = st->next;
	while (cur != NULL) {
		if (strcmp(cur->name, f_name) == 0) {
			printf("��ȣ : %d, �̸� : %s, ���� : %d\n", cur->ID, cur->name, cur->grade);
			cnt++;
		}
		cur = cur->next;
	}
	if (cnt == 0) printf("ã���� �ϴ� �̸��� �л��� �����ϴ�.\n");
}