#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int long_ch = 0, temp = 0;
	char ch;
	while (1) {
		ch = getchar();
		if (ch == -1) break;
		if (ch == '\n') {
			if (long_ch < temp) long_ch = temp;
			temp = 0;
		}
		else temp++;
	}
	printf("가장 긴 단어의 길이 : %d", long_ch);
	return 0;
}