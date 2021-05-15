#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void Sorting(char* p1, char* p2);

int main(void) {
	char str1[32], str2[32], str3[32];
	printf("세 단어 입력 : ");
	scanf("%s %s %s", str1, str2, str3);
	Sorting(str1, str2);
	Sorting(str2, str3);
	Sorting(str1, str2);
	printf("%s %s %s", str1, str2, str3);
}

void Sorting(char* p1, char* p2) {
	char* temp[32];
	while (*p1 != '\0') {
		if (strcmp(p1, p2) > 0) {
			strcpy(temp, p1);
			strcpy(p1, p2);
			strcpy(p2, temp);
			break;
		}
		else if (strcmp(p1, p2) == 0) {
			p1++;
			p2++;
		}
		else {
			break;
		}
	}
}
