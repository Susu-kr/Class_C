#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

// FMOD�� ����ϱ� ���� ����
#include <fmod.h>
#pragma comment (lib, "fmod_vc.lib")

FMOD_SYSTEM *g_System; // FMOD system ���� ����
FMOD_SOUND *g_Sound[3]; // 3���� ���� ���ϰ� �����ϱ� ����
FMOD_CHANNEL *Channel = NULL; // ä�� ��
FMOD_BOOL IsPlaying; // ���������?
float volume = 0.5; // ���� ũ��

char ID[20];
char PW[20];
long pos = 0;
int len = 0;

int Coin = -1;
int blockCoin = 0;

typedef struct {	// �÷��̾�
	double HP;		// ü�� = �ð�
	int isGround;	// ����� ��Ҵ���?
	int coin;		// ȹ���� ���� ����
	int BlockCount; // ���� ��� ��
	int p_x;		// x��ġ
	int p_y;		// y��ġ
	char* Item;		// �������� ������ ������
}Player;
struct _coin{
	int c_x;			// ���� x��ġ
	int c_y;			// ���� y��ġ
	struct _coin *next;	// ���� ������ ��Ÿ���� ������
};
struct _block{
	int b_x;			// ��� x��ġ
	int b_y;			// ��� y��ġ
	struct _block *next;// ���� ����� ��Ÿ���� ������
	struct _block *prev;// ���� ����� ��Ÿ���� ������
};
typedef struct _coin COIN;
typedef struct _block BLOCK;
Player g_player;

// ���� �Լ�
void gotoxy(int x, int y);
void SetColor(int color);
void SetBackColor(int color, int back);

//���� ���� �Լ� ���� 
enum
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VIOLET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
}; 
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}//Ŀ�� ����� �Լ� ����


void main_screen();										// ����ȭ��
void pressKey(int x, int y);							// �α���
void Read_User_Data(char* ID, char* PW, int x, int y);	// ȸ������
void Write_User_Data(char* ID, char* PW);				// ����� ��������
void Menu();											// ���θ޴�
void Shop(int coin);									// ���ӽ��� - ����
int tutorial();											// ���ӽ��� - Ʃ�丮��
void Option();											// �ɼ� - ��������
void GamePlay();										// ���� ���� ȭ��
void GameOver(BLOCK *b, COIN *c);						// �������ų�, �ð��ʰ��� �ִϸ��̼�
void ReStart();											// �ٽ��ϱ�, ����, ����
void ClearView();										// �κ����� �������� �ذ�
int wsleep(int *milliseconds, int *a);					// ���� �ð����� Ű �Է��� ����Ѵ�.

// �ð� �Լ�
void Time(BLOCK *b, COIN *c, double hp);
// ���� �Լ�
void Score(int B_C); // ���� ��� Ƚ���� �޾ƿ� ���� 1, 10, 100 ,1000�ڸ��� ����
void Score1(int num); // 1���ڸ�
void Score2(int num); // 10���ڸ�
void Score3(int num); // 100���ڸ�
void Score4(int num); // 1000���ڸ�
void Change_Score(int num, int x, int y); // 0~9 ���� ������ ���ڷ� ȭ�� ���


// �÷��̾� �Լ�
void Initialize();		// �ʱ�ȭ
void PlayerDraw();		// ȭ�鿡 �÷��̾� ���
void Erase_player();	// ��� �̵��� �÷��̾� ����

// ��� �Լ� (��ũ�� ����Ʈ)
void CreateBlock(BLOCK* b, COIN *c);					// ��� ����
void Draw_Block(BLOCK *b);								// ��� ���
void deleteBlock(BLOCK *b);								// ��� ���� ����
void Erase_Block(BLOCK *b, int n);						// ȭ�鿡�� ��� ����
void MoveBlock(BLOCK *b, COIN *c);						// �÷��̾��� Ű�� �ԷµǾ����� �̵�
void CountBlock(BLOCK *b, COIN *c, int p_x, int p_y);	// �÷��̾ ����� ��Ҵ��� Ȯ��

// ���� �Լ� (��ũ�� ����Ʈ)
void CreateCoin(COIN *c, int x, int y); // ���� ����
void DrawCoin(COIN *c);					// ���� ���
void DeleteCoin(COIN *c);				// ���� ���� ����
void EraseCoin(COIN *c, int n);			// ���� ����
void GetCoin(COIN *c);					// �÷��̾ ������ ȹ���ߴ��� Ȯ��

// ���� ���� �Լ�
void Init();				// ���� �ʱ�ȭ
void StopSound();			// ���� ����
void VolumeSetSound();		// ���� ����
void SoundUpdate();			// ���� ������Ʈ
void Sound_Play(int n);		// ���� ���
void Release();				// ���� ����

int main() {
	//�����Լ� ���� �پ��� ���� �������� ��
	setcursortype(NOCURSOR);
	system("mode con cols=80 lines=25");
	system("title Infinity of Stair"); //���� Ÿ��Ʋ ����
	srand((unsigned int)time(NULL));
	Init();
	Initialize();
	main_screen(); // ����ȭ��
	Release();
	return 0;
}

void gotoxy(int x, int y)
{
	COORD pos = { x - 1 , y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//�Է��� ��ǥ�� Ŀ���� �̵����� �ִ� �Լ�
void SetColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void SetBackColor(int color, int back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | (back << 4));
}
int wsleep(int *milliseconds, int *a)
{
	while (_kbhit() == 0)
	{
		if (*milliseconds <= 0) return -1;
		Sleep(10);
		*milliseconds -= 10;
	}
	*a = _getch();
	return *a;
}
void main_screen() {
	system("mode con cols=80 lines=25");
	system("cls");
	StopSound(); // �ߺ���� ����
	Sound_Play(0); // ����� ���
	VolumeSetSound(); // �ش� ���� ����
	int x = 23, y = 15;
	SetColor(WHITE);
	gotoxy(x, y);     printf("+--------------------------------+");
	gotoxy(x, y + 1); printf("|           ������ ���          |");
	gotoxy(x, y + 2); printf("+--------------------------------+");//���� ����
	for (int i = 1; i <= 25; ++i) {
		SetColor(GRAY);
		gotoxy(1, i);
		printf("��");
		Sleep(20);
	}//���� ȭ��ǥ ������
	for (int i = 25; i >= 1; --i) {
		SetColor(GRAY);
		gotoxy(78, i);
		printf("��");
		Sleep(20);
	}//������ ȭ��ǥ �ö��
	SetColor(DARK_YELLOW);
	int a = 30, b = 5;
	gotoxy(a, b); printf("       ����"); Sleep(50);
	gotoxy(a, b + 1); printf("     ������"); Sleep(50);
	gotoxy(a, b + 2); printf("   ��������"); Sleep(50);
	gotoxy(a, b + 3); printf(" ���   ���   ���"); Sleep(50);
	gotoxy(a, b + 4); printf("��      ���      ��"); Sleep(50);
	gotoxy(a, b + 5); printf("        ���"); Sleep(50);
	gotoxy(a, b + 6); printf("        ���"); Sleep(50);
	gotoxy(a, b + 7); printf("        ���"); Sleep(50);
	gotoxy(a, b + 8); printf("        ���"); Sleep(50);
	gotoxy(a, b + 9); printf("        ���"); Sleep(50);
	for (int i = 25; i >= 1; --i) {
		SetColor(BLACK);
		gotoxy(78, i);
		printf("��");
		Sleep(10);
	}//������ ȭ��ǥ ����
	for (int i = 1; i <= 25; ++i) {
		SetColor(BLACK);
		gotoxy(1, i);
		printf("��");
		Sleep(10);
	}//���� ȭ��ǥ ����
	if (Coin == -1)	pressKey(x, y);
	else Menu();
}
void pressKey(int x, int y) {
	int chk = 1;
	int waitTime = 1000;
	int *ent = 0;
	while (chk) {
		SetColor(RED);
		gotoxy(x, y + 3);
		printf("    <PRESS Space KEY TO START>");
		wsleep(&waitTime, &ent);//1�ʵ��� �Է��� ��ٸ�(WaitTime==1000 �̱⶧���� 1000=1��)
		if (ent == ' ') {
			ent = 0;
			SetColor(BLACK);
			gotoxy(x, y + 3);
			printf("����������������������");
			SetColor(WHITE);
			gotoxy(x + 8, y + 3);
			printf(" ID : ");
			scanf("%s", ID);
			Sleep(100);
			gotoxy(x + 8, y + 4);
			printf(" PW : ");
			int i = 0;
			while (1) {
				SetColor(WHITE);
				gotoxy(x + 14 + i, y + 4);
				char check = _getch();
				if (check == 13) break;
				if (check == 8) {
					gotoxy(x + 14 + i, y + 4);
					SetColor(BLACK);
					printf("��");
					if(i != 0) i--;
				}
				else {
					PW[i] = check;
					printf("*");
					i++;
				}
			}
			SetColor(BLACK);
			gotoxy(x, y + 3);
			printf("����������������������");
			gotoxy(x, y + 4);
			printf("����������������������");
			Sleep(500);
			Read_User_Data(ID, PW, x ,y);
			chk = 0;
		}
		if (waitTime <= 0) {
			waitTime = 1000;
		}
		SetColor(BLACK);
		gotoxy(x, y + 3);
		printf("����������������������");
		Sleep(500);
	}
	Menu();
}
void Read_User_Data(char* ID, char* PW, int x, int y) {
	FILE *fp;
	fp = fopen("User.txt", "a+");
	if (fp == NULL) {
		printf("���� - ����\n");
		exit(1);
	}
	char str[40] = "";
	char user[40] = "";
	strcat(user, ID);
	strcat(user, PW);
	int length = strlen(user);
	while (1) {
		SetColor(WHITE);
		gotoxy(x+2, y + 3);
		printf("�α��� ������ Ȯ���ϰ� �ֽ��ϴ�.");
		fgets(str, sizeof(str), fp);
		if (feof(fp)) {
			Sleep(1000);
			SetColor(BLACK);
			gotoxy(x+2, y + 3);
			printf("�������������������������������");
			Sleep(500);
			SetColor(WHITE);
			gotoxy(x, y + 3);
			printf("�α��� ������ �����ϴ�. ���� ���� ���Դϴ�.");
			Sleep(1000);
			SetColor(BLACK);
			gotoxy(x, y + 3);
			printf("�����������������������������������������");
			Sleep(500);
			strncat(user, "Coin:0", length-1);
			fprintf(fp, "%s", user);
			len = strlen(user);
			pos = ftell(fp);
			Coin = 100;
			SetColor(WHITE);
			gotoxy(x + 13, y + 3);
			printf("�����Ϸ�!");
			Sleep(1000);
			SetColor(BLACK);
			gotoxy(x + 5, y + 3);
			printf("����������");
			Sleep(500);
			break;
		}
		if (strncmp(str, user, length) == 0) {
			len = strlen(str);
			pos = ftell(fp);
			Sleep(1000);
			SetColor(BLACK);
			gotoxy(x, y + 3);
			printf("�������������������������������");
			Sleep(500);
			SetColor(WHITE);
			gotoxy(x+5, y + 3);
			printf("����� ������ ã�ҽ��ϴ�.");
			Sleep(1000);
			char *coin = strchr(str, ':');
			Coin = atoi(coin+1);
			SetColor(BLACK);
			gotoxy(x+4, y + 3);
			printf("�������������������������������");
			Sleep(1000);
			SetColor(WHITE);
			gotoxy(x + 11, y + 3);
			printf("�α��� �Ϸ�!");
			Sleep(1000);
			SetColor(BLACK);
			gotoxy(x + 11, y + 3);
			printf("������������");
			Sleep(500);
			break;
		}
	}
	fclose(fp);
}
void Menu() {
	int x = 34, y = 18;
	SetColor(BLUE);
	gotoxy(x, y);
	printf("> ");
	SetColor(WHITE);
	printf("���ӽ���");
	gotoxy(x+3, y + 1);
	printf("�� ��");
	gotoxy(x+3, y + 2);
	printf("�� ��");
	SetColor(BLUE);
	while (1) {
		gotoxy(x, y);
		printf("");
		printf(" ");
		if (GetAsyncKeyState(VK_UP) & 0x8000) if (y > 18) y--;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) if (y < 20) y++;
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			if (y - 18 == 0) {
				Shop(g_player.coin); // ���ӽ���
				break;
			}
			else if (y - 18 == 1)Option(); // �ɼ�
			else { // ����
				Write_User_Data(ID, PW);
				exit(1);
			}
		}
		gotoxy(x, y);
		printf(">");
		Sleep(50);
	}

}
int tutorial() {
	system("cls");//ȭ�� �ʱ�ȭ ����
	system("mode con cols=94 lines=25");//�ܼ�â ũ�� ����
	StopSound();
	int x = 4, y = 3;
	gotoxy(x, y); printf("������ ��      �� ������ ������ �����   ������     ��     ��");
	gotoxy(x, y + 1); printf("    ��     ��      ��     ��     ��      �� ��     ��      ��        ���    �� ");
	gotoxy(x, y + 2); printf("    ��     ��      ��     ��     ��      �� �����       ��       ��  ��   ��");
	gotoxy(x, y + 3); printf("    ��     ��      ��     ��     ��      �� ��  ��         ��      �����  ��");
	gotoxy(x, y + 4); printf("    ��     ������     ��     ������ ��   ���      ��     ��      �� ������");
	y = 5;
	SetColor(VIOLET);
	gotoxy(x, y + 7); printf("How to play?");
	SetColor(SKYBLUE);
	gotoxy(x + 20, y + 7); printf("Follow the stairs!!");
	gotoxy(x + 20, y + 9); printf("Press '��' key to move right");
	gotoxy(x + 20, y + 11); printf("Press '��' key to move left"); Sleep(700);


	SetColor(WHITE);
	y = 8;
	gotoxy(x + 66, y + 15); printf("��");
	// ���� ���� -> ĳ���� �̵� -> ���� ���� -> ����� �ݺ�
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 66, y + 14); printf("��"); Sleep(300);
	gotoxy(x + 69, y + 14); printf("��");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 69, y + 13); printf("��");
	gotoxy(x + 72, y + 13); printf("��");
	gotoxy(x + 66, y + 14); printf("  "); Sleep(300);
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 72, y + 12); printf("��");
	gotoxy(x + 75, y + 12); printf("��");
	gotoxy(x + 69, y + 13); printf("  "); Sleep(300);
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 75, y + 11); printf("��");
	gotoxy(x + 78, y + 11); printf("��");
	gotoxy(x + 72, y + 12); printf("  "); Sleep(300);
	gotoxy(x + 75, y + 10); printf("��");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 78, y + 10); printf("��");
	gotoxy(x + 75, y + 11); printf("  "); Sleep(300);
	gotoxy(x + 72, y + 9); printf("��");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 75, y + 9); printf("��");
	gotoxy(x + 78, y + 10); printf("  "); Sleep(300);
	gotoxy(x + 69, y + 8); printf("��");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 72, y + 8); printf("��");
	gotoxy(x + 75, y + 9); printf("  "); Sleep(300);
	gotoxy(x + 66, y + 7); printf("��");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 69, y + 7); printf("��");
	gotoxy(x + 72, y + 8); printf("  "); Sleep(300);
	gotoxy(x + 69, y + 6); printf("��");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 66, y + 6); printf("��");
	gotoxy(x + 69, y + 7); printf("  "); Sleep(300);
	gotoxy(x + 72, y + 5); printf("��");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 69, y + 5); printf("��");
	gotoxy(x + 66, y + 6); printf("  "); Sleep(300);
	gotoxy(x + 69, y + 4); printf("��");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 72, y + 4); printf("��");
	gotoxy(x + 69, y + 5); printf("  "); Sleep(300);
	gotoxy(x + 66, y + 3); printf("��");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 69, y + 3); printf("��");
	gotoxy(x + 72, y + 4); printf("  "); Sleep(300);
	gotoxy(x + 69, y + 2); printf("��");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 66, y + 2); printf("��");
	gotoxy(x + 69, y + 3); printf("  "); Sleep(300);
	gotoxy(x + 66, y + 1); printf("��");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 69, y + 1); printf("��");
	gotoxy(x + 66, y + 2); printf("  "); Sleep(300);
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 72, y); printf("��");
	gotoxy(x + 69, y + 1); printf("  "); Sleep(300);
	for (int i = 1; i <= 18; i++) {
		gotoxy(x + 72, y + i - 1); printf("  ");
		gotoxy(x + 72, y + i); printf("��"); Sleep(100);
	}
	gotoxy(x + 72, y + 17); printf("  ");
	gotoxy(x + 72, y + 18); printf("  ");
	gotoxy(x + 73, y + 18); printf(">+O"); Sleep(100);

	SetColor(WHITE);
	gotoxy(x + 20, y + 15); printf("Press Space Bar key to Start!!");

	while (1) {
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)GamePlay();
	}
	return 0;
}
void Option() {
	system("cls");
	int x = 0, y = 0;
	SetColor(DARK_YELLOW);
	for (int i = 1; i <= 78; i++) {
		gotoxy(x+i, 1);
		printf("��");
		gotoxy(x+i, 25);
		printf("��");
	}
	for (int i = 1; i <= 25; i++) {
		gotoxy(1, y + i);
		printf("��");
		gotoxy(78, y + i);
		printf("��");
	}
	x = 36; y = 2;
	gotoxy(x, y);
	printf("Option");
	gotoxy(27, 8); SetColor(GREEN);
	printf("��: ���� ���� �� MAX 10 ��");
	gotoxy(27, 10); SetColor(RED);
	printf("��: ���� ���� �� MIN 0  ��");
	gotoxy(30, 12); SetColor(WHITE);
	printf("ESC : ���� ������");
	gotoxy(32, 16);
	printf("�Ҹ� ����: ");
	while (1)
	{
		gotoxy(44, 16); SetColor(YELLOW);
		printf("%02d", (int)(volume * 10));
		if (GetAsyncKeyState(VK_UP) & 0x8000 && volume < 1.0f) {// ȭ��ǥ ���� Ű�� ������ �� 
			volume += 0.1f;
			FMOD_Channel_SetVolume(Channel, volume);
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000 && volume > 0.0f) {// ȭ��ǥ �Ʒ��� Ű�� ������ �� 
			volume -= 0.1f;
			FMOD_Channel_SetVolume(Channel, volume);
		}
		if (GetAsyncKeyState(VK_ESCAPE) < 0) {
			main_screen();
		}
		Sleep(50);
	}
	SetColor(WHITE);
}
void Shop(int coin) {
	system("mode con cols=80 lines=25");
	system("cls");
	int x = 0, y = 0;
	SetColor(DARK_YELLOW);
	for (int i = 1; i <= 78; i++) {
		gotoxy(x + i, 1);
		printf("��");
		gotoxy(x + i, 25);
		printf("��");
	}
	for (int i = 1; i <= 25; i++) {
		gotoxy(1, y + i);
		printf("��");
		gotoxy(78, y + i);
		printf("��");
	}
	x = 5; y = 3;
	SetColor(RED);
	gotoxy(x, y);
	printf("Store");
	x = 65;
	SetColor(YELLOW);
	gotoxy(x, y);
	printf("Coin : %05d", Coin);
	x = 2; y = 4;
	SetColor(WHITE);
	gotoxy(x, y);
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ");
	x = 5; y = 7;
	gotoxy(x, y);
	SetColor(BLUE);
	printf(">");
	x = 8; y = 5;
	SetColor(WHITE);
	gotoxy(x, y);
	printf("���������������������������������������������������������������������������������������������������������� ");
	gotoxy(x, y + 1);
	printf("��                                                   �� ");
	gotoxy(x, y +2);
	printf("��  Coin x 2 : ���ǵ��� ȹ���� ������ 2��� ��´�.  ��  ���� 30 Coin"); // 7
	gotoxy(x, y + 3);
	printf("��                                                   �� ");
	gotoxy(x, y + 4);
	printf("���������������������������������������������������������������������������������������������������������� ");
	y = 10;
	gotoxy(x, y);
	printf("���������������������������������������������������������������������������������������������������������� ");
	gotoxy(x, y + 1);
	printf("��                                                   �� ");
	gotoxy(x, y + 2);
	printf("��  Portion : HP�� 50 ȸ���Ѵ�.                      ��  ���� 50 Coin"); // 12
	gotoxy(x, y + 3);
	printf("��                                                   �� ");
	gotoxy(x, y + 4);
	printf("���������������������������������������������������������������������������������������������������������� ");
	y = 15;
	gotoxy(x, y);
	printf("���������������������������������������������������������������������������������������������������������� ");
	gotoxy(x, y + 1);
	printf("��                                                   �� ");
	gotoxy(x, y + 2);
	printf("��  Magic Shoes : �������� �ѹ� ������Ѵ�.          ��  ���� 100 Coin"); // 17
	gotoxy(x, y + 3);
	printf("��                                                   �� ");
	gotoxy(x, y + 4);
	printf("���������������������������������������������������������������������������������������������������������� ");
	x = 36, y = 22;
	gotoxy(x, y);
	printf("������"); // 22
	x = 5, y = 7;
	int chk = 0;
	while (1) {
		gotoxy(x, y);
		printf("");
		printf(" ");
		SetColor(WHITE);
		if (GetAsyncKeyState(VK_UP) & 0x8000) if (y > 7) y -= 5;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) if (y < 22) y += 5;
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			if (y - 7 == 0 && chk == 0) {
				if (Coin >= 30) {
					g_player.Item = "double coin";
					Coin -= 30;
					chk = 1;
				}
				else {
					gotoxy(15, 3);
					printf("Coin�� �����մϴ�. ������ ����ּ���.");
				}
			}
			else if (y - 7 == 5 && chk == 0) {
				if (Coin >= 50) {
					g_player.Item = "portion";
					Coin -= 50;
					chk = 1;
				}
				else {
					gotoxy(15, 3);
					printf("Coin�� �����մϴ�. ������ ����ּ���.");
				}
			}
			else if (y - 7 == 10 && chk == 0) {
				if (Coin >= 100) {
					g_player.Item = "magic shoes";
					Coin -= 100;
					chk = 1;
				}
				else {
					gotoxy(15, 3);
					printf("Coin�� �����մϴ�. ������ ����ּ���.");
				}
			}
			else if (chk == 1 && y - 7 != 15) {
				gotoxy(15, 3);
				printf("�ϳ��� �����۸� ������ �� �ֽ��ϴ�.");
			}
			else if (y - 7 == 15) {
				tutorial();
				break;
			}
			SetColor(YELLOW);
			gotoxy(65, 3);
			printf("Coin : %05d", Coin);
		}
		SetColor(BLUE);
		gotoxy(x, y);
		printf(">");
		Sleep(100);
	}
}
void GamePlay() {
	system("mode con cols=55 lines=41");
	BLOCK *g_block = malloc(sizeof(BLOCK));
	g_block->next = NULL;
	g_block->prev = NULL;
	COIN *g_coin = malloc(sizeof(COIN));
	g_coin->next = NULL;
	for (int i = 0; i < 20; i++) {
		CreateBlock(g_block, g_coin);
	}
	Draw_Block(g_block);
	DrawCoin(g_coin);
	PlayerDraw();
	Time(g_block, g_coin, g_player.HP);
	Score(g_player.BlockCount);
	while (1) {
		MoveBlock(g_block, g_coin);
		ClearView();
		Time(g_block, g_coin, g_player.HP);
		Score(g_player.BlockCount);
		CreateBlock(g_block, g_coin);
	}
}
void GameOver(BLOCK *b, COIN *c) {
	StopSound();
	SoundUpdate();
	gotoxy(g_player.p_x + 1, g_player.p_y);
	for (int i = 0; i < 3; i++) {
		SetColor(RED);
		gotoxy(g_player.p_x + 2, g_player.p_y);
		printf("     ");
		Sleep(100);
		gotoxy(g_player.p_x + 2, g_player.p_y);
		printf("! !");
		Sleep(100);
	}

	SetColor(WHITE);
	for (int i = g_player.p_y; i < 41; i++) {
		gotoxy(g_player.p_x, i + 1);
		printf("0");
		gotoxy(g_player.p_x, i + 2);
		printf("|");
		gotoxy(g_player.p_x, i + 3);
		printf(" ");
		gotoxy(g_player.p_x, i + 4);
		printf("|");
		gotoxy(g_player.p_x, i);
		printf(" ");
		gotoxy(g_player.p_x, i + 1);
		printf(" ");
		gotoxy(g_player.p_x, i + 2);
		printf(" ");
		gotoxy(g_player.p_x, i + 3);
		printf(" ");
		Sleep(50);
	}
	deleteBlock(b);
	DeleteCoin(c);
	ReStart();
}
void ReStart() {
	system("cls");
	gotoxy(20, 19);
	SetColor(RED);
	printf("Game Over !!");
	if (strcmp(g_player.Item, "double coin") == 0) {
		g_player.coin *= 2;
		g_player.Item = "";
	}
	Coin += g_player.coin;
	gotoxy(15, 21);
	SetColor(YELLOW);
	printf("ȹ���� ���� : %02d,  �� ���� : %02d", g_player.coin, Coin);
	int x = 20, y = 22;
	SetColor(BLUE);
	gotoxy(x, y);
	printf("> ");
	SetColor(WHITE);
	printf(" �ٽ��ϱ�");
	gotoxy(x + 3, y + 1);
	printf("����");
	gotoxy(x + 3, y + 2);
	printf("���θ޴�");
	gotoxy(x + 3, y + 3);
	printf("�� ��");
	SetColor(BLUE);
	while (1) {
		gotoxy(x, y);
		printf("");
		printf(" ");
		if (GetAsyncKeyState(VK_UP) & 0x8000) if (y > 22) y--;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) if (y < 25) y++;
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			Initialize();
			if (y - 22 == 0) GamePlay();// ���ӽ���
			else if (y - 22 == 1)Shop(Coin); // ����
			else if (y - 22 == 2)main_screen(); // ����
			else { // ����
				Write_User_Data(ID, PW);
				exit(1);
			}
		}
		gotoxy(x, y);
		printf(">");
		Sleep(50);
	}
}
void ClearView() {
	gotoxy(1, 1);
	printf("                                                           ");
	gotoxy(1, 4);
	printf("                                                           ");
	for (int i = 10; i <= 20; i++) {
		gotoxy(1, i);
		printf("                                                           ");
	}
}
void Write_User_Data(char* ID, char* PW) {
	FILE *fp;
	fp = fopen("User.txt", "r+");
	if (fp == NULL) {
		printf("���� - ����\n");
		exit(1);
	}
	char user[40] = "";
	strcat(user, ID);
	strcat(user, PW);
	strcat(user, "Coin:");
	char coin[5] = "";
	sprintf(coin, "%d", Coin);
	strcat(user, coin);
	strcat(user, "\n");
	fseek(fp, pos - len - 1, SEEK_SET);
	fwrite(user, 1, strlen(user)-1, fp);
	fclose(fp);
}

void Time(BLOCK *b, COIN *c,double hp) {
	int x = 3, y = 2;
	int HP = (int)hp / 2;
	for (int i = x; i <= x + HP; i++) {
		SetBackColor(RED, 12);
		gotoxy(i, y);
		printf(" ");
		gotoxy(i, y + 1);
		printf(" ");
	}
	for (int i = 64; i >= x + HP; i--) {
		SetBackColor(BLACK, 0);
		gotoxy(i, y);
		printf(" ");
		gotoxy(i, y + 1);
		printf(" ");
	}
	if (HP == 0) {
		if (strcmp(g_player.Item, "portion") == 0) {
			Sleep(100);
			Time(b, c, hp);
			g_player.HP = 50.0;
			g_player.Item = "";
		}
		else {
			GameOver(b, c);
		}
	}
}
void Score1(int num) {
	int x = 40, y = 5; // 1 ����
	SetColor(WHITE);
	Change_Score(num, x, y);
}
void Score2(int num) {
	int x = 30, y = 5; // 10 ����
	SetColor(WHITE);
	Change_Score(num, x, y);

}
void Score3(int num) {
	int x = 20, y = 5; // 100 ����
	SetColor(WHITE);
	Change_Score(num, x, y);

}
void Score4(int num) {
	int x = 10, y = 5; // 1000 ����
	SetColor(WHITE);
	Change_Score(num, x, y);
}
void Score(int B_C) {
	int num1, num2, num3, num4;
	num1 = B_C % 10;
	num2 = (B_C / 10) % 10;
	num3 = (B_C / 100) % 10;
	num4 = (B_C / 1000) % 10;
	Score1(num1);
	Score2(num2);
	Score3(num3);
	Score4(num4);
}
void Change_Score(int num, int x, int y) {
	switch (num) {
	case 0:
		gotoxy(x, y);
		printf("����");
		gotoxy(x, y + 1);
		printf("��  ��");
		gotoxy(x, y + 2);
		printf("��  ��");
		gotoxy(x, y + 3);
		printf("��  ��");
		gotoxy(x, y + 4);
		printf("����");
		break;
	case 1:
		gotoxy(x, y);
		printf("  ���");
		gotoxy(x, y + 1);
		printf("  ���");
		gotoxy(x, y + 2);
		printf("  ���");
		gotoxy(x, y + 3);
		printf("  ���");
		gotoxy(x, y + 4);
		printf("  ���");
		break;
	case 2:
		gotoxy(x, y);
		printf("����");
		gotoxy(x, y + 1);
		printf("    ��");
		gotoxy(x, y + 2);
		printf("����");
		gotoxy(x, y + 3);
		printf("��     ");
		gotoxy(x, y + 4);
		printf("����");
		break;
	case 3:
		gotoxy(x, y);
		printf("����");
		gotoxy(x, y + 1);
		printf("    ��");
		gotoxy(x, y + 2);
		printf("����");
		gotoxy(x, y + 3);
		printf("    ��");
		gotoxy(x, y + 4);
		printf("����");
		break;
	case 4:
		gotoxy(x, y);
		printf("��  ��");
		gotoxy(x, y + 1);
		printf("��  ��");
		gotoxy(x, y + 2);
		printf("����");
		gotoxy(x, y + 3);
		printf("    ��");
		gotoxy(x, y + 4);
		printf("    ��");
		break;
	case 5:
		gotoxy(x, y);
		printf("����");
		gotoxy(x, y + 1);
		printf("��    ");
		gotoxy(x, y + 2);
		printf("����");
		gotoxy(x, y + 3);
		printf("    ��");
		gotoxy(x, y + 4);
		printf("����");
		break;
	case 6:
		gotoxy(x, y);
		printf("����");
		gotoxy(x, y + 1);
		printf("��    ");
		gotoxy(x, y + 2);
		printf("����");
		gotoxy(x, y + 3);
		printf("��  ��");
		gotoxy(x, y + 4);
		printf("����");
		break;
	case 7:
		gotoxy(x, y);
		printf("����");
		gotoxy(x, y + 1);
		printf("    ��");
		gotoxy(x, y + 2);
		printf("    ��");
		gotoxy(x, y + 3);
		printf("    ��");
		gotoxy(x, y + 4);
		printf("    ��");
		break;
	case 8:
		gotoxy(x, y);
		printf("����");
		gotoxy(x, y + 1);
		printf("��  ��");
		gotoxy(x, y + 2);
		printf("����");
		gotoxy(x, y + 3);
		printf("��  ��");
		gotoxy(x, y + 4);
		printf("����");
		break;
	case 9:
		gotoxy(x, y);
		printf("����");
		gotoxy(x, y + 1);
		printf("��  ��");
		gotoxy(x, y + 2);
		printf("����");
		gotoxy(x, y + 3);
		printf("    ��");
		gotoxy(x, y + 4);
		printf("����");
		break;
	}
}

void Initialize()
{
	g_player.p_x = 30;
	g_player.p_y = 34;
	g_player.HP = 100.00;
	g_player.isGround = 1;
	g_player.coin = 0;
	g_player.BlockCount = 0;
	g_player.Item = "";
}

void PlayerDraw() {
	SetColor(WHITE);
	gotoxy(g_player.p_x, g_player.p_y);
	printf("O");
	gotoxy(g_player.p_x, g_player.p_y + 1);
	printf("|");
	gotoxy(g_player.p_x, g_player.p_y + 2);
	printf("|");
	gotoxy(g_player.p_x, g_player.p_y + 3);
	printf("|");
}//�÷��̾� ����ִ� �Լ�
void Erase_player() {
	SetColor(WHITE);
	gotoxy(g_player.p_x, g_player.p_y);
	printf("  ");
	gotoxy(g_player.p_x, g_player.p_y + 1);
	printf("  ");
	gotoxy(g_player.p_x, g_player.p_y + 2);
	printf("  ");
	gotoxy(g_player.p_x, g_player.p_y + 3);
	printf("  ");
}//�̵��� �÷��̾� �����ִ� �Լ�

void CreateBlock(BLOCK * b, COIN *c) {
	if (b->next == NULL) {
		BLOCK *newB = malloc(sizeof(BLOCK));
		newB->b_x = 1;
		newB->b_y = 40;
		newB->next = NULL;
		newB->prev = b;
		b->next = newB;
	}
	else {
		BLOCK *cur = b->next;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		BLOCK *newB = malloc(sizeof(BLOCK));
		if (cur->b_x == 1 && cur->b_y > 38) {
			newB->b_x = 1;
			newB->b_y = cur->b_y - 1;
			newB->next = NULL;
			newB->prev = cur;
			cur->next = newB;
		}
		else if (cur->b_y == 38 && cur->b_x == 1) {
			newB->b_x = 21;
			newB->b_y = 37;
			newB->next = NULL;
			newB->prev = cur;
			cur->next = newB;
		}
		else if (cur->b_y <= 37) {
			int num = rand() % 2;
			if (num == 0) {
				if (cur->b_x <= 7) {
					newB->b_x = cur->b_x + 7;
					newB->b_y = cur->b_y - 1;
					newB->next = NULL;
					newB->prev = cur;
					cur->next = newB;
				}
				else {
					newB->b_x = cur->b_x - 7;
					newB->b_y = cur->b_y - 1;
					newB->next = NULL;
					newB->prev = cur;
					cur->next = newB;
				}
			}
			else if (num == 1) {
				if (cur->b_x >= 48) {
					newB->b_x = cur->b_x - 7;
					newB->b_y = cur->b_y - 1;
					newB->next = NULL;
					newB->prev = cur;
					cur->next = newB;
				}
				else {
					newB->b_x = cur->b_x + 7;
					newB->b_y = cur->b_y - 1;
					newB->next = NULL;
					newB->prev = cur;
					cur->next = newB;
				}
			}
			num = rand() % 10;
			if (num == 3) {
				CreateCoin(c, newB->b_x, newB->b_y);
			}
		}
	}
}
void Draw_Block(BLOCK *b) {
	SetColor(GRAY);
	BLOCK *cur = b->next;
	while (cur != NULL) {
		if (cur->b_x > 0 && cur->b_x < 55) {
			if (cur->b_x == 1) {
				gotoxy(cur->b_x, cur->b_y);
				printf("#######################################################");
			}
			else {
				gotoxy(cur->b_x, cur->b_y);
				printf("#####");
			}
		}
		cur = cur->next;
	}
}
void deleteBlock(BLOCK *b) {
	BLOCK *cur = b;
	BLOCK *next;
	while (cur != NULL) {
		next = cur->next;
		free(cur);
		cur = next;
	}
}
void Erase_Block(BLOCK *b, int n) {
	SetColor(GRAY);
	BLOCK *cur = b->next;
	while (cur != NULL) {
		gotoxy(cur->b_x, cur->b_y);
		printf("                                                         ");
		cur = cur->next;
	}

	cur = b->next;
	b->next = cur->next;
	cur->next->prev = b;
	BLOCK *next = cur->next;
	free(cur);
	cur = next;

	while (cur != NULL) {
		if (cur->b_x != 1) {
			if (n == 75)cur->b_x += 7;
			else cur->b_x -= 7;
		}
		cur->b_y += 1;
		cur = cur->next;
	}

}
void MoveBlock(BLOCK *b, COIN *c) {
	int chk = 1;
	int waitTime = 1000;
	int *ent = 0;
	while (chk) {
		wsleep(&waitTime, &ent);//1�ʵ��� �Է��� ��ٸ�(WaitTime==1000 �̱⶧���� 1000=1��)
		if (ent == 75 || ent == 77) {
			Sound_Play(2);
			VolumeSetSound();
			g_player.HP += 0.01;
			if (ent == 75) {
				SetColor(BLUE);
				gotoxy(g_player.p_x + 2, g_player.p_y);
				printf("- -");
				gotoxy(g_player.p_x + 2, g_player.p_y + 1);
				printf("- -");
				gotoxy(g_player.p_x + 2, g_player.p_y);
				Sleep(10);
				printf("   ");
				gotoxy(g_player.p_x + 2, g_player.p_y + 1);
				printf("   ");
				Erase_player();
				g_player.p_x -= 7;
				if (blockCoin > 0)GetCoin(c);
				PlayerDraw();
				Sleep(10);
				Erase_player();
				g_player.p_x += 7;
				Erase_Block(b, 75);
				if (blockCoin > 0)EraseCoin(c, 75);
			}
			else if (ent == 77) {
				gotoxy(g_player.p_x - 2, g_player.p_y);
				SetColor(BLUE);
				printf("- -");
				gotoxy(g_player.p_x - 2, g_player.p_y + 1);
				printf("- -");
				gotoxy(g_player.p_x - 2, g_player.p_y);
				Sleep(10);
				printf("   ");
				gotoxy(g_player.p_x - 2, g_player.p_y + 1);
				printf("   ");
				Erase_player();
				g_player.p_x += 7;
				if (blockCoin > 0)GetCoin(c);
				PlayerDraw();
				Sleep(10);
				Erase_player();
				g_player.p_x -= 7;
				Erase_Block(b, 77);
				if (blockCoin > 0)EraseCoin(c, 77);
			}
			chk = 0;
		}
		if (waitTime <= 0) {
			waitTime = 1000;
			int i = 0;
			if (g_player.BlockCount % 5 == 0) i += 50;
			waitTime -= i;
		}
		g_player.HP -= 1;
		Time(b, c, g_player.HP);
		Draw_Block(b);
		if (blockCoin > 0)DrawCoin(c);
		PlayerDraw();
		if (ent == 75 || ent == 77) CountBlock(b, c, g_player.p_x, g_player.p_y);
	}
	//int ch = _getch();
	//if (0 == ch || 224 == ch) {//����Ű�� ������ �ѹ��� �ΰ��� ���� ������ ������ �� ������ �ɾ����� ������ ������ �ι� ���Եȴ�
	//	ch = _getch();//����Ű�� �޴´�
	//}
	//switch (ch)
	//{
	//case 75:
	//	SetColor(BLUE);
	//	gotoxy(g_player.p_x + 2, g_player.p_y);
	//	printf("- -");
	//	gotoxy(g_player.p_x + 2, g_player.p_y + 1);
	//	printf("- -");
	//	gotoxy(g_player.p_x + 2, g_player.p_y);
	//	Sleep(50);
	//	printf("   ");
	//	gotoxy(g_player.p_x + 2, g_player.p_y + 1);
	//	printf("   ");
	//	Erase_player();
	//	g_player.p_x -= 7;
	//	if (blockCoin > 0)GetCoin(c);
	//	PlayerDraw();
	//	Sleep(50);
	//	Erase_player();
	//	g_player.p_x += 7;
	//	Erase_Block(b, 75);
	//	if (blockCoin > 0)EraseCoin(c, 75);
	//	break;
	//case 77:
	//	gotoxy(g_player.p_x - 2, g_player.p_y);
	//	SetColor(BLUE);
	//	printf("- -");
	//	gotoxy(g_player.p_x - 2, g_player.p_y + 1);
	//	printf("- -");
	//	gotoxy(g_player.p_x - 2, g_player.p_y);
	//	Sleep(50);
	//	printf("   ");
	//	gotoxy(g_player.p_x - 2, g_player.p_y + 1);
	//	printf("   ");
	//	Erase_player();
	//	g_player.p_x += 7;
	//	if (blockCoin > 0)GetCoin(c);
	//	PlayerDraw();
	//	Sleep(50);
	//	Erase_player();
	//	g_player.p_x -= 7;
	//	Erase_Block(b, 77);
	//	if (blockCoin > 0)EraseCoin(c, 77);
	//	break;
	//}
	//Draw_Block(b);
	//if (blockCoin > 0)DrawCoin(c);
	//PlayerDraw();
	//if (ch == 75 || ch == 77) CountBlock(b, c, g_player.p_x, g_player.p_y);
}
void CountBlock(BLOCK *b, COIN *c, int x, int y) {
	BLOCK *cur = b->next;
	cur = cur->next;
	cur = cur->next;
	if (cur->b_x >= 28 && cur->b_x <= 32 || cur->b_x == 1) {
		g_player.isGround = 1;
		g_player.BlockCount++;
		if (g_player.HP < 98) g_player.HP += 2.0;
	}
	else {
		if (strcmp(g_player.Item, "magic shoes") == 0) {
			g_player.Item = "";
			GamePlay();
		}
		else {
			g_player.isGround = 0;
			GameOver(b, c);
		}
	}
}

void CreateCoin(COIN *c, int x, int y) {
	blockCoin++;
	if (c->next == NULL) {
		COIN *newC = malloc(sizeof(COIN));
		newC->c_x = x + 2;
		newC->c_y = y - 1;
		c->next = newC;
		newC->next = NULL;
	}
	else {
		COIN *cur = c->next;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		COIN *newC = malloc(sizeof(COIN));
		newC->c_x = x + 2;
		newC->c_y = y - 1;
		cur->next = newC;
		newC->next = NULL;
	}
}
void DrawCoin(COIN *c) {
	SetColor(YELLOW);
	COIN *cur = c->next;
	while (cur != NULL) {
		if (cur->c_x > 2 && cur->c_x < 52) {
			gotoxy(cur->c_x, cur->c_y);
			printf("$");
		}
		cur = cur->next;
	}
}
void DeleteCoin(COIN *c) {
	COIN *cur = c;
	COIN *next;
	while (cur != NULL) {
		next = cur->next;
		free(cur);
		cur = next;
	}
}
void EraseCoin(COIN *c, int n) {
	SetColor(YELLOW);
	COIN *cur = c->next;
	while (cur != NULL) {
		gotoxy(cur->c_x, cur->c_y);
		printf(" ");
		cur = cur->next;
	}
	cur = c->next;
	while (cur != NULL) {
		if (n == 75)cur->c_x += 7;
		else cur->c_x -= 7;
		cur->c_y += 1;
		cur = cur->next;
	}
}
void GetCoin(COIN *c) {
	COIN *cur = c->next;
	if (cur != NULL) {
		if (cur->c_x == g_player.p_x && cur->c_y == 36) {
			Sound_Play(1);
			VolumeSetSound();
			blockCoin--;
			g_player.coin++;
			if (blockCoin != 0)c->next = cur->next;
			else c->next = NULL;
			free(cur);
		}
	}
}

void Init() {// FMOD ���� �ʱ�ȭ �� ���� �ε�
	FMOD_System_Create(&g_System); // FMOD system ��ü ����
	FMOD_System_Init(g_System, 10, FMOD_INIT_NORMAL, NULL); // 10�� ���� �������
	FMOD_System_CreateSound(g_System, "main.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[0]); // �������
	FMOD_System_CreateSound(g_System, "Blop.mp3", FMOD_DEFAULT, 0, &g_Sound[1]); // ����ȹ����
	FMOD_System_CreateSound(g_System, "effect.mp3", FMOD_DEFAULT, 0, &g_Sound[2]); // �̵���ȿ����
}
void StopSound(void) {	// ���� ����
	FMOD_Channel_Stop(Channel); // �ش� ä���� ������ ����
}
void VolumeSetSound(void) {	// ���� ���� ����
	FMOD_Channel_SetVolume(Channel, volume); // �ش� ä���� ������ ����
}
void SoundUpdate(void) {	// ���� ������Ʈ
	if (IsPlaying == 1) // ������̸�?
		FMOD_System_Update(g_System); // ������Ʈ
}
void Sound_Play(int n) {	// ���� ���
	FMOD_System_PlaySound(g_System, g_Sound[n], NULL, 0, &Channel); // n�� �ش��ϴ� ���� ���
}
void Release() {	// ���� ����
	int i;
	for (i = 0; i < 3; i++) {
		FMOD_Sound_Release(g_Sound[i]); // FMOD sound ��ü ����
	}
	FMOD_System_Close(g_System); // FMOD system ��ü clsoe
	FMOD_System_Release(g_System); // FMOD system ��ü ����
}
