/*
	����3.
	����ڷκ��� ���ڿ��� �Է¹޾Ƽ� ����ϴ� ���α׷� �ۼ�
	���ڿ� �Է� �ޱ����� ����ڷ� ���� ���ڿ��� �ִ� ���̿� ���� ������ ���� �Է¹ް�
	�� ���� ��ŭ �޸� ������ �������� �Ҵ��� ���ڿ��� �Է¹޾� ����ϵ��� �Ѵ�.
	Ư�� ���ڰ� �Էµ� ������ �ݺ��ϵ��� �Ѵ�.("Quit" -> ����)
	����Ҷ� ������ ���� �ܾ� ������ ���ڿ��� ������ �ֵ��� �Ѵ�.
	ex) I am happy.
	-> happy am I
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int N;
	char *str = NULL;

	while (1) {
		int N;
		printf("���ڿ��� �ִ� ���̸� �Է��ϼ��� : ");
		scanf("%d", &N);
		str = (char *)malloc(N+1);
		if (str == NULL) {
			printf("# �޸𸮰� �����մϴ�. \n");
			exit(0);
		}
		getchar();
		printf("���ڿ��� �Է��ϼ��� : ");
		fgets(str, N+1, stdin);
		if (strlen(str) < N || str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = '\0';
		else while (getchar() != '\n');
		if (strcmp(str, "Quit") == 0) {
			free(str);
			break;
		}
		for (int i = N - 1; i >= 0; i--) {
			if (str[i] == ' ') {
				printf("%s ", str + i + 1);
				str[i] = 0;
			}
			else if (i == 0) {
				printf("%s\n", str);
			}
		}
		free(str);
	}
	free(str);
}