#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

// FMOD를 사용하기 위한 설정
#include <fmod.h>
#pragma comment (lib, "fmod_vc.lib")

FMOD_SYSTEM *g_System; // FMOD system 변수 선언
FMOD_SOUND *g_Sound[3]; // 3개의 사운드 파일과 연결하기 위함
FMOD_CHANNEL *Channel = NULL; // 채널 수
FMOD_BOOL IsPlaying; // 재생중인지?
float volume = 0.5; // 볼륨 크기

char ID[20];
char PW[20];
long pos = 0;
int len = 0;

int Coin = -1;
int blockCoin = 0;

typedef struct {	// 플레이어
	double HP;		// 체력 = 시간
	int isGround;	// 계단을 밟았는지?
	int coin;		// 획득한 코인 갯수
	int BlockCount; // 밟은 계단 수
	int p_x;		// x위치
	int p_y;		// y위치
	char* Item;		// 상점에서 구매한 아이템
}Player;
struct _coin{
	int c_x;			// 코인 x위치
	int c_y;			// 코인 y위치
	struct _coin *next;	// 다음 코인을 나타내는 포인터
};
struct _block{
	int b_x;			// 계단 x위치
	int b_y;			// 계단 y위치
	struct _block *next;// 다음 블록을 나타내는 포인터
	struct _block *prev;// 이전 블록을 나타내는 포인터
};
typedef struct _coin COIN;
typedef struct _block BLOCK;
Player g_player;

// 버퍼 함수
void gotoxy(int x, int y);
void SetColor(int color);
void SetBackColor(int color, int back);

//색깔 설정 함수 정의 
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
}//커서 숨기는 함수 정의


void main_screen();										// 시작화면
void pressKey(int x, int y);							// 로그인
void Read_User_Data(char* ID, char* PW, int x, int y);	// 회원정보
void Write_User_Data(char* ID, char* PW);				// 종료시 정보저장
void Menu();											// 메인메뉴
void Shop(int coin);									// 게임시작 - 상점
int tutorial();											// 게임시작 - 튜토리얼
void Option();											// 옵션 - 볼륨조절
void GamePlay();										// 실제 게임 화면
void GameOver(BLOCK *b, COIN *c);						// 떨어지거나, 시간초과시 애니메이션
void ReStart();											// 다시하기, 상점, 종료
void ClearView();										// 부분적인 깨짐현상 해결
int wsleep(int *milliseconds, int *a);					// 일정 시간동안 키 입력을 대기한다.

// 시간 함수
void Time(BLOCK *b, COIN *c, double hp);
// 점수 함수
void Score(int B_C); // 밟은 블록 횟수를 받아와 각각 1, 10, 100 ,1000자리로 구분
void Score1(int num); // 1의자리
void Score2(int num); // 10의자리
void Score3(int num); // 100의자리
void Score4(int num); // 1000의자리
void Change_Score(int num, int x, int y); // 0~9 까지 디지털 숫자로 화면 출력


// 플레이어 함수
void Initialize();		// 초기화
void PlayerDraw();		// 화면에 플레이어 출력
void Erase_player();	// 계단 이동시 플레이어 삭제

// 블록 함수 (링크드 리스트)
void CreateBlock(BLOCK* b, COIN *c);					// 블록 생성
void Draw_Block(BLOCK *b);								// 블록 출력
void deleteBlock(BLOCK *b);								// 블록 버퍼 삭제
void Erase_Block(BLOCK *b, int n);						// 화면에서 블록 제거
void MoveBlock(BLOCK *b, COIN *c);						// 플레이어의 키가 입력되었을때 이동
void CountBlock(BLOCK *b, COIN *c, int p_x, int p_y);	// 플레이어가 계단을 밟았는지 확인

// 코인 함수 (링크드 리스트)
void CreateCoin(COIN *c, int x, int y); // 코인 생성
void DrawCoin(COIN *c);					// 코인 출력
void DeleteCoin(COIN *c);				// 코인 버퍼 삭제
void EraseCoin(COIN *c, int n);			// 코인 제거
void GetCoin(COIN *c);					// 플레이어가 코인을 획득했는지 확인

// 사운드 관련 함수
void Init();				// 사운드 초기화
void StopSound();			// 사운드 정지
void VolumeSetSound();		// 볼륨 설정
void SoundUpdate();			// 사운드 업데이트
void Sound_Play(int n);		// 사운드 재생
void Release();				// 사운드 삭제

int main() {
	//랜덤함수 값이 다양한 값이 나오도록 함
	setcursortype(NOCURSOR);
	system("mode con cols=80 lines=25");
	system("title Infinity of Stair"); //실행 타이틀 제목
	srand((unsigned int)time(NULL));
	Init();
	Initialize();
	main_screen(); // 메인화면
	Release();
	return 0;
}

void gotoxy(int x, int y)
{
	COORD pos = { x - 1 , y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//입력한 좌표로 커서를 이동시켜 주는 함수
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
	StopSound(); // 중복재생 방지
	Sound_Play(0); // 배경음 재생
	VolumeSetSound(); // 해당 볼륨 적용
	int x = 23, y = 15;
	SetColor(WHITE);
	gotoxy(x, y);     printf("+--------------------------------+");
	gotoxy(x, y + 1); printf("|           무한의 계단          |");
	gotoxy(x, y + 2); printf("+--------------------------------+");//게임 제목
	for (int i = 1; i <= 25; ++i) {
		SetColor(GRAY);
		gotoxy(1, i);
		printf("▼");
		Sleep(20);
	}//왼쪽 화살표 내려옴
	for (int i = 25; i >= 1; --i) {
		SetColor(GRAY);
		gotoxy(78, i);
		printf("▲");
		Sleep(20);
	}//오른쪽 화살표 올라옴
	SetColor(DARK_YELLOW);
	int a = 30, b = 5;
	gotoxy(a, b); printf("       ■■■"); Sleep(50);
	gotoxy(a, b + 1); printf("     ■■■■■"); Sleep(50);
	gotoxy(a, b + 2); printf("   ■■■■■■■"); Sleep(50);
	gotoxy(a, b + 3); printf(" ■■   ■■   ■■"); Sleep(50);
	gotoxy(a, b + 4); printf("■      ■■      ■"); Sleep(50);
	gotoxy(a, b + 5); printf("        ■■"); Sleep(50);
	gotoxy(a, b + 6); printf("        ■■"); Sleep(50);
	gotoxy(a, b + 7); printf("        ■■"); Sleep(50);
	gotoxy(a, b + 8); printf("        ■■"); Sleep(50);
	gotoxy(a, b + 9); printf("        ■■"); Sleep(50);
	for (int i = 25; i >= 1; --i) {
		SetColor(BLACK);
		gotoxy(78, i);
		printf("▲");
		Sleep(10);
	}//오른쪽 화살표 지움
	for (int i = 1; i <= 25; ++i) {
		SetColor(BLACK);
		gotoxy(1, i);
		printf("▼");
		Sleep(10);
	}//왼쪽 화살표 지움
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
		wsleep(&waitTime, &ent);//1초동안 입력을 기다림(WaitTime==1000 이기때문에 1000=1초)
		if (ent == ' ') {
			ent = 0;
			SetColor(BLACK);
			gotoxy(x, y + 3);
			printf("■■■■■■■■■■■■■■■■■■■■■");
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
					printf("■");
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
			printf("■■■■■■■■■■■■■■■■■■■■■");
			gotoxy(x, y + 4);
			printf("■■■■■■■■■■■■■■■■■■■■■");
			Sleep(500);
			Read_User_Data(ID, PW, x ,y);
			chk = 0;
		}
		if (waitTime <= 0) {
			waitTime = 1000;
		}
		SetColor(BLACK);
		gotoxy(x, y + 3);
		printf("■■■■■■■■■■■■■■■■■■■■■");
		Sleep(500);
	}
	Menu();
}
void Read_User_Data(char* ID, char* PW, int x, int y) {
	FILE *fp;
	fp = fopen("User.txt", "a+");
	if (fp == NULL) {
		printf("실패 - 종료\n");
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
		printf("로그인 정보를 확인하고 있습니다.");
		fgets(str, sizeof(str), fp);
		if (feof(fp)) {
			Sleep(1000);
			SetColor(BLACK);
			gotoxy(x+2, y + 3);
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			Sleep(500);
			SetColor(WHITE);
			gotoxy(x, y + 3);
			printf("로그인 정보가 없습니다. 새로 생성 중입니다.");
			Sleep(1000);
			SetColor(BLACK);
			gotoxy(x, y + 3);
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			Sleep(500);
			strncat(user, "Coin:0", length-1);
			fprintf(fp, "%s", user);
			len = strlen(user);
			pos = ftell(fp);
			Coin = 100;
			SetColor(WHITE);
			gotoxy(x + 13, y + 3);
			printf("생성완료!");
			Sleep(1000);
			SetColor(BLACK);
			gotoxy(x + 5, y + 3);
			printf("■■■■■■■■■");
			Sleep(500);
			break;
		}
		if (strncmp(str, user, length) == 0) {
			len = strlen(str);
			pos = ftell(fp);
			Sleep(1000);
			SetColor(BLACK);
			gotoxy(x, y + 3);
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			Sleep(500);
			SetColor(WHITE);
			gotoxy(x+5, y + 3);
			printf("사용자 정보를 찾았습니다.");
			Sleep(1000);
			char *coin = strchr(str, ':');
			Coin = atoi(coin+1);
			SetColor(BLACK);
			gotoxy(x+4, y + 3);
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			Sleep(1000);
			SetColor(WHITE);
			gotoxy(x + 11, y + 3);
			printf("로그인 완료!");
			Sleep(1000);
			SetColor(BLACK);
			gotoxy(x + 11, y + 3);
			printf("■■■■■■■■■■■");
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
	printf("게임시작");
	gotoxy(x+3, y + 1);
	printf("옵 션");
	gotoxy(x+3, y + 2);
	printf("종 료");
	SetColor(BLUE);
	while (1) {
		gotoxy(x, y);
		printf("");
		printf(" ");
		if (GetAsyncKeyState(VK_UP) & 0x8000) if (y > 18) y--;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) if (y < 20) y++;
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			if (y - 18 == 0) {
				Shop(g_player.coin); // 게임시작
				break;
			}
			else if (y - 18 == 1)Option(); // 옵션
			else { // 종료
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
	system("cls");//화면 초기화 해줌
	system("mode con cols=94 lines=25");//콘솔창 크기 조절
	StopSound();
	int x = 4, y = 3;
	gotoxy(x, y); printf("■■■■■ ■      ■ ■■■■■ ■■■■■ ■■■■   ■■■■■     ■     ■");
	gotoxy(x, y + 1); printf("    ■     ■      ■     ■     ■      ■ ■     ■      ■        ■■    ■ ");
	gotoxy(x, y + 2); printf("    ■     ■      ■     ■     ■      ■ ■■■■       ■       ■  ■   ■");
	gotoxy(x, y + 3); printf("    ■     ■      ■     ■     ■      ■ ■  ■         ■      ■■■■  ■");
	gotoxy(x, y + 4); printf("    ■     ■■■■■     ■     ■■■■■ ■   ■■      ■     ■      ■ ■■■■■");
	y = 5;
	SetColor(VIOLET);
	gotoxy(x, y + 7); printf("How to play?");
	SetColor(SKYBLUE);
	gotoxy(x + 20, y + 7); printf("Follow the stairs!!");
	gotoxy(x + 20, y + 9); printf("Press '→' key to move right");
	gotoxy(x + 20, y + 11); printf("Press '←' key to move left"); Sleep(700);


	SetColor(WHITE);
	y = 8;
	gotoxy(x + 66, y + 15); printf("〓");
	// 발판 생성 -> 캐릭터 이동 -> 발판 생성 -> 지우기 반복
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 66, y + 14); printf("옷"); Sleep(300);
	gotoxy(x + 69, y + 14); printf("〓");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 69, y + 13); printf("옷");
	gotoxy(x + 72, y + 13); printf("〓");
	gotoxy(x + 66, y + 14); printf("  "); Sleep(300);
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 72, y + 12); printf("옷");
	gotoxy(x + 75, y + 12); printf("〓");
	gotoxy(x + 69, y + 13); printf("  "); Sleep(300);
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 75, y + 11); printf("옷");
	gotoxy(x + 78, y + 11); printf("〓");
	gotoxy(x + 72, y + 12); printf("  "); Sleep(300);
	gotoxy(x + 75, y + 10); printf("〓");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 78, y + 10); printf("옷");
	gotoxy(x + 75, y + 11); printf("  "); Sleep(300);
	gotoxy(x + 72, y + 9); printf("〓");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 75, y + 9); printf("옷");
	gotoxy(x + 78, y + 10); printf("  "); Sleep(300);
	gotoxy(x + 69, y + 8); printf("〓");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 72, y + 8); printf("옷");
	gotoxy(x + 75, y + 9); printf("  "); Sleep(300);
	gotoxy(x + 66, y + 7); printf("〓");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 69, y + 7); printf("옷");
	gotoxy(x + 72, y + 8); printf("  "); Sleep(300);
	gotoxy(x + 69, y + 6); printf("〓");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 66, y + 6); printf("옷");
	gotoxy(x + 69, y + 7); printf("  "); Sleep(300);
	gotoxy(x + 72, y + 5); printf("〓");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 69, y + 5); printf("옷");
	gotoxy(x + 66, y + 6); printf("  "); Sleep(300);
	gotoxy(x + 69, y + 4); printf("〓");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 72, y + 4); printf("옷");
	gotoxy(x + 69, y + 5); printf("  "); Sleep(300);
	gotoxy(x + 66, y + 3); printf("〓");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 69, y + 3); printf("옷");
	gotoxy(x + 72, y + 4); printf("  "); Sleep(300);
	gotoxy(x + 69, y + 2); printf("〓");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 66, y + 2); printf("옷");
	gotoxy(x + 69, y + 3); printf("  "); Sleep(300);
	gotoxy(x + 66, y + 1); printf("〓");
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 69, y + 1); printf("옷");
	gotoxy(x + 66, y + 2); printf("  "); Sleep(300);
	Sound_Play(2);
	VolumeSetSound();
	gotoxy(x + 72, y); printf("옷");
	gotoxy(x + 69, y + 1); printf("  "); Sleep(300);
	for (int i = 1; i <= 18; i++) {
		gotoxy(x + 72, y + i - 1); printf("  ");
		gotoxy(x + 72, y + i); printf("옷"); Sleep(100);
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
		printf("■");
		gotoxy(x+i, 25);
		printf("■");
	}
	for (int i = 1; i <= 25; i++) {
		gotoxy(1, y + i);
		printf("■");
		gotoxy(78, y + i);
		printf("■");
	}
	x = 36; y = 2;
	gotoxy(x, y);
	printf("Option");
	gotoxy(27, 8); SetColor(GREEN);
	printf("↑: 볼륨 증가 ◈ MAX 10 ◈");
	gotoxy(27, 10); SetColor(RED);
	printf("↓: 볼륨 감소 ◈ MIN 0  ◈");
	gotoxy(30, 12); SetColor(WHITE);
	printf("ESC : 설정 나가기");
	gotoxy(32, 16);
	printf("소리 볼륨: ");
	while (1)
	{
		gotoxy(44, 16); SetColor(YELLOW);
		printf("%02d", (int)(volume * 10));
		if (GetAsyncKeyState(VK_UP) & 0x8000 && volume < 1.0f) {// 화살표 위쪽 키를 눌렀을 때 
			volume += 0.1f;
			FMOD_Channel_SetVolume(Channel, volume);
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000 && volume > 0.0f) {// 화살표 아래쪽 키를 눌렀을 때 
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
		printf("■");
		gotoxy(x + i, 25);
		printf("■");
	}
	for (int i = 1; i <= 25; i++) {
		gotoxy(1, y + i);
		printf("■");
		gotoxy(78, y + i);
		printf("■");
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
	printf("─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ");
	x = 5; y = 7;
	gotoxy(x, y);
	SetColor(BLUE);
	printf(">");
	x = 8; y = 5;
	SetColor(WHITE);
	gotoxy(x, y);
	printf("┌───────────────────────────────────────────────────┐ ");
	gotoxy(x, y + 1);
	printf("│                                                   │ ");
	gotoxy(x, y +2);
	printf("│  Coin x 2 : 한판동안 획득한 코인을 2배로 얻는다.  │  가격 30 Coin"); // 7
	gotoxy(x, y + 3);
	printf("│                                                   │ ");
	gotoxy(x, y + 4);
	printf("└───────────────────────────────────────────────────┘ ");
	y = 10;
	gotoxy(x, y);
	printf("┌───────────────────────────────────────────────────┐ ");
	gotoxy(x, y + 1);
	printf("│                                                   │ ");
	gotoxy(x, y + 2);
	printf("│  Portion : HP를 50 회복한다.                      │  가격 50 Coin"); // 12
	gotoxy(x, y + 3);
	printf("│                                                   │ ");
	gotoxy(x, y + 4);
	printf("└───────────────────────────────────────────────────┘ ");
	y = 15;
	gotoxy(x, y);
	printf("┌───────────────────────────────────────────────────┐ ");
	gotoxy(x, y + 1);
	printf("│                                                   │ ");
	gotoxy(x, y + 2);
	printf("│  Magic Shoes : 떨어지면 한번 재시작한다.          │  가격 100 Coin"); // 17
	gotoxy(x, y + 3);
	printf("│                                                   │ ");
	gotoxy(x, y + 4);
	printf("└───────────────────────────────────────────────────┘ ");
	x = 36, y = 22;
	gotoxy(x, y);
	printf("나가기"); // 22
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
					printf("Coin이 부족합니다. 코인을 모아주세요.");
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
					printf("Coin이 부족합니다. 코인을 모아주세요.");
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
					printf("Coin이 부족합니다. 코인을 모아주세요.");
				}
			}
			else if (chk == 1 && y - 7 != 15) {
				gotoxy(15, 3);
				printf("하나의 아이템만 구매할 수 있습니다.");
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
	printf("획득한 코인 : %02d,  총 코인 : %02d", g_player.coin, Coin);
	int x = 20, y = 22;
	SetColor(BLUE);
	gotoxy(x, y);
	printf("> ");
	SetColor(WHITE);
	printf(" 다시하기");
	gotoxy(x + 3, y + 1);
	printf("상점");
	gotoxy(x + 3, y + 2);
	printf("메인메뉴");
	gotoxy(x + 3, y + 3);
	printf("종 료");
	SetColor(BLUE);
	while (1) {
		gotoxy(x, y);
		printf("");
		printf(" ");
		if (GetAsyncKeyState(VK_UP) & 0x8000) if (y > 22) y--;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) if (y < 25) y++;
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			Initialize();
			if (y - 22 == 0) GamePlay();// 게임시작
			else if (y - 22 == 1)Shop(Coin); // 메인
			else if (y - 22 == 2)main_screen(); // 메인
			else { // 종료
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
		printf("실패 - 종료\n");
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
	int x = 40, y = 5; // 1 단위
	SetColor(WHITE);
	Change_Score(num, x, y);
}
void Score2(int num) {
	int x = 30, y = 5; // 10 단위
	SetColor(WHITE);
	Change_Score(num, x, y);

}
void Score3(int num) {
	int x = 20, y = 5; // 100 단위
	SetColor(WHITE);
	Change_Score(num, x, y);

}
void Score4(int num) {
	int x = 10, y = 5; // 1000 단위
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
		printf("■■■");
		gotoxy(x, y + 1);
		printf("■  ■");
		gotoxy(x, y + 2);
		printf("■  ■");
		gotoxy(x, y + 3);
		printf("■  ■");
		gotoxy(x, y + 4);
		printf("■■■");
		break;
	case 1:
		gotoxy(x, y);
		printf("  ■■");
		gotoxy(x, y + 1);
		printf("  ■■");
		gotoxy(x, y + 2);
		printf("  ■■");
		gotoxy(x, y + 3);
		printf("  ■■");
		gotoxy(x, y + 4);
		printf("  ■■");
		break;
	case 2:
		gotoxy(x, y);
		printf("■■■");
		gotoxy(x, y + 1);
		printf("    ■");
		gotoxy(x, y + 2);
		printf("■■■");
		gotoxy(x, y + 3);
		printf("■     ");
		gotoxy(x, y + 4);
		printf("■■■");
		break;
	case 3:
		gotoxy(x, y);
		printf("■■■");
		gotoxy(x, y + 1);
		printf("    ■");
		gotoxy(x, y + 2);
		printf("■■■");
		gotoxy(x, y + 3);
		printf("    ■");
		gotoxy(x, y + 4);
		printf("■■■");
		break;
	case 4:
		gotoxy(x, y);
		printf("■  ■");
		gotoxy(x, y + 1);
		printf("■  ■");
		gotoxy(x, y + 2);
		printf("■■■");
		gotoxy(x, y + 3);
		printf("    ■");
		gotoxy(x, y + 4);
		printf("    ■");
		break;
	case 5:
		gotoxy(x, y);
		printf("■■■");
		gotoxy(x, y + 1);
		printf("■    ");
		gotoxy(x, y + 2);
		printf("■■■");
		gotoxy(x, y + 3);
		printf("    ■");
		gotoxy(x, y + 4);
		printf("■■■");
		break;
	case 6:
		gotoxy(x, y);
		printf("■■■");
		gotoxy(x, y + 1);
		printf("■    ");
		gotoxy(x, y + 2);
		printf("■■■");
		gotoxy(x, y + 3);
		printf("■  ■");
		gotoxy(x, y + 4);
		printf("■■■");
		break;
	case 7:
		gotoxy(x, y);
		printf("■■■");
		gotoxy(x, y + 1);
		printf("    ■");
		gotoxy(x, y + 2);
		printf("    ■");
		gotoxy(x, y + 3);
		printf("    ■");
		gotoxy(x, y + 4);
		printf("    ■");
		break;
	case 8:
		gotoxy(x, y);
		printf("■■■");
		gotoxy(x, y + 1);
		printf("■  ■");
		gotoxy(x, y + 2);
		printf("■■■");
		gotoxy(x, y + 3);
		printf("■  ■");
		gotoxy(x, y + 4);
		printf("■■■");
		break;
	case 9:
		gotoxy(x, y);
		printf("■■■");
		gotoxy(x, y + 1);
		printf("■  ■");
		gotoxy(x, y + 2);
		printf("■■■");
		gotoxy(x, y + 3);
		printf("    ■");
		gotoxy(x, y + 4);
		printf("■■■");
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
}//플레이어 찍어주는 함수
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
}//이동한 플레이어 지워주는 함수

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
		wsleep(&waitTime, &ent);//1초동안 입력을 기다림(WaitTime==1000 이기때문에 1000=1초)
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
	//if (0 == ch || 224 == ch) {//방향키를 누르면 한번에 두개의 값이 들어오기 때문에 이 조건을 걸어주지 않으면 루프가 두번 돌게된다
	//	ch = _getch();//방향키를 받는다
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

void Init() {// FMOD 사운드 초기화 및 사운드 로딩
	FMOD_System_Create(&g_System); // FMOD system 객체 생성
	FMOD_System_Init(g_System, 10, FMOD_INIT_NORMAL, NULL); // 10개 음악 재생가능
	FMOD_System_CreateSound(g_System, "main.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[0]); // 배경음악
	FMOD_System_CreateSound(g_System, "Blop.mp3", FMOD_DEFAULT, 0, &g_Sound[1]); // 코인획득음
	FMOD_System_CreateSound(g_System, "effect.mp3", FMOD_DEFAULT, 0, &g_Sound[2]); // 이동시효과음
}
void StopSound(void) {	// 사운드 정지
	FMOD_Channel_Stop(Channel); // 해당 채널의 음악을 정지
}
void VolumeSetSound(void) {	// 사운드 볼륨 설정
	FMOD_Channel_SetVolume(Channel, volume); // 해당 채널의 볼륨을 설정
}
void SoundUpdate(void) {	// 사운드 업데이트
	if (IsPlaying == 1) // 재생중이면?
		FMOD_System_Update(g_System); // 업데이트
}
void Sound_Play(int n) {	// 사운드 재생
	FMOD_System_PlaySound(g_System, g_Sound[n], NULL, 0, &Channel); // n에 해당하는 음악 재생
}
void Release() {	// 사운드 삭제
	int i;
	for (i = 0; i < 3; i++) {
		FMOD_Sound_Release(g_Sound[i]); // FMOD sound 객체 해제
	}
	FMOD_System_Close(g_System); // FMOD system 객체 clsoe
	FMOD_System_Release(g_System); // FMOD system 객체 해제
}
