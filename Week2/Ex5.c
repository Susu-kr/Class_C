#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 32
char* change(char* pd, char* ps, char* ch);
int main(void) {
	char szBuf[SIZE] = { "I am a boy. I'm happy" };
	printf("%s\n", szBuf);
	change(szBuf, "boy", "girl");
	printf("%s\n", szBuf);
	return 0;
}
char* change(char* pd, char* ps, char* ch) {
	char* p;
	char temp[SIZE];
	if ((p = strstr(pd, ps)) != NULL) {
		strcpy(temp, p + strlen(ps));
		strcpy(p, ch);
		strcat(pd, temp);
	}
	return pd;
}