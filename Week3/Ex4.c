#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *ifp, *ofp, *bfp;
	char a_name[20];
	char b_name[20];
	int res = 0;
	ifp = fopen("data\\a.txt", "r");
	if (ifp == NULL) {
		printf("�Է� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}
	bfp = fopen("data\\b.txt", "w");
	if (bfp == NULL) {
		printf("������ ������ ���߽��ϴ�.\n");
		return 1;
	}
	ofp = fopen("data\\c.txt", "w");
	if (ofp == NULL) {
		printf("��� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}
	while (1) {
		scanf("%s", b_name);
		if (strcmp(b_name, "end") == 0) break;
		else fprintf(bfp, "%s\n", b_name);

		fseek(ifp, 0, SEEK_SET);
		while (1) {
			fgets(a_name, sizeof(a_name), ifp);
			if (feof(ifp)) {
				fprintf(ofp, "%s\n", b_name);
				break;
			}
			a_name[strlen(a_name) - 1] = '\0';
			if (strcmp(a_name, b_name) == 0) {
				printf("�Է��� �ܾ �ߺ��Դϴ�.\n");
				break;
			}
		}
	}
	fclose(ifp);
	fclose(bfp);
	fclose(ofp);
	return 0;
}