/*
	문제1.
	번호, 이름, 학점을 입력 받을 수 있는 구조체를 만들고, 임의의 학생에 대한 데이터를 입력 받아 출력하는 코드를 만든다.
	학점 순으로 정렬하여 출력하도록
	1. 입력 - 학생 번호, 이름, 성적순으로 입력
	2. 출력 - 성적에 따라 정렬된 형태로 출력
	3. 검색 - 이름으로 해당 학생의 번호, 이름, 성적을 출력
	> 조건1. 번호 중복x, 이름 중복 가능
	> 조건2. 검색 .. 이름 검색 .. 먼저 찾은거 출력 -> 추가 출력
	4. 종료 - 프로그램 종료



	1. 메모리 할당
	2. 자기 참조 구조체 활용
	(ex :| |A|90|next| , | |B|80|next| , | |C|85|next|
	=> | |A|90|next| -> | |C|85|next| -> | |B|80|NULL|
	3. 입력, 출력, 검색은 각각 개별 함수로 구현한다.
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
		printf("1. 입력\n");
		printf("2. 출력\n");
		printf("3. 검색\n");
		printf("4. 종료\n");
		printf("번호를 입력하세요 : ");
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
			printf("잘못된 입력입니다. 다시 입력하세요. \n");
			continue;
		}
	}
	return 0;
}

void showList(List *st) {
	printf("전체 학생을 점수순으로 출력합니다. \n");
	List *cur = st->next;
	while (cur != NULL) {
		printf("번호 : %d, 이름 : %s, 성적 : %d\n", cur->ID, cur->name, cur->grade);
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
		printf("번호 이름 학점순으로 입력하세요 : ");
		scanf("%d%s%d", &(newST->ID), newST->name, &(newST->grade));
		newST->next = NULL;
		st->next = newST;
	}
	else {
		List *cur = st->next;
		int chk = 1;
		while (chk) {
			List *newST = malloc(sizeof(List));
			printf("번호 이름 학점순으로 입력하세요 : ");
			scanf("%d%s%d", &(newST->ID), newST->name, &(newST->grade));
			while (cur != NULL) {
				if (newST->ID == cur->ID) {
					printf("이미 존재하는 ID입니다. 다른 ID를 입력해 주세요.\n");
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
	printf("찾고자 하는 학생의 이름을 입력하세요 : ");
	char f_name[20];
	int cnt = 0;
	scanf("%s", f_name);
	List *cur = st->next;
	while (cur != NULL) {
		if (strcmp(cur->name, f_name) == 0) {
			printf("번호 : %d, 이름 : %s, 점수 : %d\n", cur->ID, cur->name, cur->grade);
			cnt++;
		}
		cur = cur->next;
	}
	if (cnt == 0) printf("찾고자 하는 이름의 학생이 없습니다.\n");
}