/*
	����2.
	�� ���� 10���� ���� �� �ִ� �κ��丮�� �ִ�.
	������ ���� �߿䵵�� �ְ� ���԰� �ٸ���.
	�߿䵵�� ���� ���� �������� ���� �� �ֵ��� ���α׷��� �ۼ��϶�.

	�̸�			�߿䵵		����
	kar98k		7			4
	�Ķ�����		10			2
	������		7			4
	�ҹ��		6			6
	����			2			10
	����			3			5

	���
	�߿䵵 1���� : 24
			kar98k	7	4
			�Ķ�����	10	2
			������	7	4
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
	printf("������ ������ �κ��丮�� ���Ը� �Է��ϼ��� : ");
	scanf("%d%d", &N, &K);
	Item *item = (Item*)malloc(sizeof(Item) * N);
	memset(item, 0, sizeof(Item)*N);
	input_Item(item, N);
	Cal_Max_Priority(item, N, K);
	free(item);
	return 0;
}
void input_Item(Item *I, int cnt) {
	printf("�̸� �߿䵵 ����\n");
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
		if (Bag[r][c] == 0)break; //Ż��
		if (Bag[r][c] == Bag[r - 1][c]) { // ������ �ȵ����.
			r--;
			get[r] = 0;
		}
		else { // ������ �� ���
			r--;
			c -= item[r].weight;
			get[r] = 1;
		}
	}
	printf("�߿䵵 1���� : %d\n", Bag[N][K]);
	// ����ϴ� �κ� �ٽ�
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