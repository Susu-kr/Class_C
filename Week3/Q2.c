/*
	문제2.
	총 무게 10까지 담을 수 있는 인벤토리가 있다.
	아이템 마다 중요도가 있고 무게가 다르다.
	중요도가 제일 높게 아이템을 담을 수 있도록 프로그램을 작성하라.

	이름			중요도		무게
	kar98k		7			4
	후라이팬		10			2
	스코프		7			4
	뚝배기		6			6
	샷건			2			10
	지도			3			5

	출력
	중요도 1순위 : 24
			kar98k	7	4
			후라이팬	10	2
			스코프	7	4
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _item Item;

struct _item {
	int priority;
	int weight;
	char name[20];
};

void input_Item(Item *I, int cnt);
void Cal_Max_Priority(Item *I, int cnt, int w);
int MAX(int a, int b);

int main(void) {
	int N, K;
	printf("물건의 갯수와 인벤토리의 무게를 입력하세요 : ");
	scanf("%d%d", &N, &K);
	Item *item = (Item*)malloc(sizeof(Item) * N);
	memset(item, 0, sizeof(Item)*N);
	input_Item(item, N);
	Cal_Max_Priority(item, N, K);
	free(item);
	return 0;
}
void input_Item(Item *I, int cnt) {
	printf("이름 중요도 무게\n");
	for (int i = 0; i < cnt; i++) {
		scanf("%s%d%d", I[i].name, &(I[i].priority), &(I[i].weight));
	}
}
void Cal_Max_Priority(Item *item, int N, int K) {
	int **Bag = (int**)malloc((N+1) * sizeof(int*));
	for (int i = 0; i <= N; i++) {
		Bag[i] = (int*)malloc((K+1) * sizeof(int));
		memset(Bag[i], 0, sizeof(int) * (K + 1));
	}
	int *get = (int*)malloc(N * sizeof(int));
	memset(get, 0, sizeof(int) * N);
	int p, w;
	for (int i = 1; i <= N; i++) {
		p = item[i - 1].priority;
		w = item[i - 1].weight;
		for (int j = 1; j <= K; j++) {
			if (w > j) Bag[i][j] = Bag[i - 1][j];
			else {
				Bag[i][j] = MAX(Bag[i - 1][j], p + Bag[i - 1][j - w]);
			}
		}
	}
	int r = N, c = K;
	while (1) {
		if (Bag[r][c] == 0)break; //탈출
		if (Bag[r][c] == Bag[r - 1][c]) { // 물건이 안들어간경우.
			r--;
			get[r] = 0;
		}
		else { // 물건이 들어간 경우
			r--;
			c -= item[r].weight;
			get[r] = 1;
		}
	}
	printf("중요도 1순위 : %d\n", Bag[N][K]);
	// 출력하는 부분 다시
	for (int i = 0; i < N; i++) {
		if (get[i] != 0) printf("%10s%5d%5d\n", item[i].name, item[i].priority, item[i].weight);
	}
	free(get);
	for (int i = 0; i <= N; i++) {
		free(Bag[i]);
	}
	free(Bag);
}

int MAX(int a, int b) {
	return a > b ? a : b;
}