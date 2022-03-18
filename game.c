#include "view.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15

#define UP 0x48
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d
#define SPACE ' '
#define ESC 0x1b
#define P 112
#define Q 113

int Delay = 50;
int health = 3;
int numDelay = 500;
int comp[100];
int user[100];
int print_x = 73;
int print_y = 6;
int j = 0;
int hint = 3;

void gotoxy(int x, int y);
void textcolor(int fg_color, int bg_color);
void removeCursor(void);
void showCursor(void);
void gameMain(void);
void tutorial();
void drawBoard();
void user_box(int x, int y);
void gameDefault(int stage);
void randNumber(int stage);
void printNumber(int num);
void move_box(int beforeX, int beforeY, int x, int y);
void choiceNumber(int x, int y);
int compare(int stage);
void show_health();
int gameover();
void showHint();

void gotoxy(int x, int y) {//내가 원하는 위치로 커서 이동
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void textcolor(int fg_color, int bg_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}
void removeCursor(void) { // 커서를 안보이게 한다
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void showCursor(void) { // 커서를 보이게 한다
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void drawBoard() {		// 시작 배경 판 그리기
	int x = 5, y = 4;
	gotoxy(x, y); printf("■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x, y + 1); printf("■              ■              ■              ■");//7칸
	gotoxy(x, y + 2); printf("■      ■      ■    ■■■    ■    ■■■    ■");
	gotoxy(x, y + 3); printf("■    ■■      ■        ■    ■        ■    ■");
	gotoxy(x, y + 4); printf("■      ■      ■    ■■■    ■    ■■■    ■");
	gotoxy(x, y + 5); printf("■      ■      ■    ■        ■        ■    ■");
	gotoxy(x, y + 6); printf("■    ■■■    ■    ■■■    ■    ■■■    ■");
	gotoxy(x, y + 7); printf("■              ■              ■              ■");
	gotoxy(x, y + 8); printf("■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x, y + 9); printf("■              ■              ■              ■");
	gotoxy(x, y + 10); printf("■    ■  ■    ■    ■■■    ■    ■        ■");
	gotoxy(x, y + 11); printf("■    ■  ■    ■    ■        ■    ■        ■");
	gotoxy(x, y + 12); printf("■    ■■■■  ■    ■■■    ■    ■■■    ■");
	gotoxy(x, y + 13); printf("■        ■    ■        ■    ■    ■  ■    ■");
	gotoxy(x, y + 14); printf("■        ■    ■    ■■■    ■    ■■■    ■");
	gotoxy(x, y + 15); printf("■              ■              ■              ■");
	gotoxy(x, y + 16); printf("■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x, y + 17); printf("■              ■              ■              ■");
	gotoxy(x, y + 18); printf("■    ■■■    ■    ■■■    ■    ■■■    ■");
	gotoxy(x, y + 19); printf("■        ■    ■    ■  ■    ■    ■  ■    ■");
	gotoxy(x, y + 20); printf("■        ■    ■    ■■■    ■    ■■■    ■");
	gotoxy(x, y + 21); printf("■        ■    ■    ■  ■    ■        ■    ■");
	gotoxy(x, y + 22); printf("■        ■    ■    ■■■    ■        ■    ■");
	gotoxy(x, y + 23); printf("■              ■              ■              ■");
	gotoxy(x, y + 24); printf("■■■■■■■■■■■■■■■■■■■■■■■■■");
}

void tutorial() {	//두번째 화면
	while (1) {
		if (kbhit()) break;
		int x = 2, y = 2;
		gotoxy(x + 15, y - 1); printf("기억력 게임");
		gotoxy(x + 15, y + 1); printf("1. 판에 한 칸씩 랜덤으로 반짝입니다.");
		gotoxy(x + 15, y + 3); printf("2. 반짝이는 순서를 기억합니다 ");
		gotoxy(x + 15, y + 5); printf("3. 방향키와 스페이스바를 이용하여 순서대로 입력합니다.");
		gotoxy(x + 15, y + 7); printf("4. 힌트는 3번이고 다시한번 보여줍니다.");
		gotoxy(x + 15, y + 9); printf("5. 스테이지가 넘어 갈수록 난이도가 어려워집니다. ");
		gotoxy(x + 15, y + 11); printf("6. 스테이지 5개 마다 힌트와 목숨이 1개 추가됩니다.");
		gotoxy(x + 27, y + 13); printf("조 작 법");
		gotoxy(x + 15, y + 14); printf("UP                        △");
		gotoxy(x + 15, y + 15); printf("LEFT / RIGHT            ◁  ▷");
		gotoxy(x + 15, y + 16); printf("DOWN                      ▽");
		gotoxy(x + 15, y + 17); printf("선택                     SPACE");
		gotoxy(x + 15, y + 18); printf("힌트                     P");
		gotoxy(x + 15, y + 19); printf("설명보기                 Q");
		gotoxy(x + 15, y + 20); printf("종료                     ESC");
		gotoxy(x + 23, y + 22); printf("Enter Any Key to Start");
	}
	while (kbhit()) getch();
}
void gameDefault(int stage) {	//기본판 생성/체력/ 입력수
	gotoxy(1, 1); printf("STAGE %d", stage);
	drawBoard();
	gotoxy(60, 5); printf("health");
	show_health();
	gotoxy(60, 10); printf("입력한 숫자 ");
}
void user_box(int x, int y) {	//선택 네모 기본
	textcolor(RED2, BLACK);
	gotoxy(x, y); printf("□□□□□□□");
	gotoxy(x, y + 1); printf("□"); gotoxy(x + 12, y + 1); printf("□");
	gotoxy(x, y + 2); printf("□"); gotoxy(x + 12, y + 2); printf("□");
	gotoxy(x, y + 3); printf("□"); gotoxy(x + 12, y + 3); printf("□");
	gotoxy(x, y + 4); printf("□"); gotoxy(x + 12, y + 4); printf("□");
	gotoxy(x, y + 5); printf("□"); gotoxy(x + 12, y + 5); printf("□");
	gotoxy(x, y + 6); printf("□□□□□□□");
	textcolor(WHITE, BLACK);

}
void randNumber(int stage) {	//랜덤넘버 생성
	for (int i = 0; i < stage; i++) {
		int random_number;
		random_number = rand() % 9 + 1;
		comp[i] = random_number;
		printNumber(comp[i]);
		Sleep(Delay);
	}
}
void printNumber(int num) {	//숫자 반짝
	int randcolor;
	int x, y;
	randcolor = rand() % 13 + 1;
	switch (num) {
	case 1:
		textcolor(randcolor, BLACK);
		x = 7, y = 5;
		gotoxy(x, y); printf("□□□□□□□");
		gotoxy(x, y + 1); printf("□□□  □□□");
		gotoxy(x, y + 2); printf("□□    □□□");
		gotoxy(x, y + 3); printf("□□□  □□□");
		gotoxy(x, y + 4); printf("□□□  □□□");
		gotoxy(x, y + 5); printf("□□      □□");
		gotoxy(x, y + 6); printf("□□□□□□□");
		Sleep(numDelay);
		textcolor(WHITE, BLACK);
		drawBoard();
		break;
	case 2:
		textcolor(randcolor, BLACK);
		x = 23, y = 5;
		gotoxy(x, y); printf("□□□□□□□");
		gotoxy(x, y + 1); printf("□□      □□");
		gotoxy(x, y + 2); printf("□□□□  □□");
		gotoxy(x, y + 3); printf("□□      □□");
		gotoxy(x, y + 4); printf("□□  □□□□");
		gotoxy(x, y + 5); printf("□□      □□");
		gotoxy(x, y + 6); printf("□□□□□□□");
		Sleep(numDelay);
		textcolor(WHITE, BLACK);
		drawBoard();
		break;
	case 3:
		textcolor(randcolor, BLACK);
		x = 39, y = 5;
		gotoxy(x, y); printf("□□□□□□□");
		gotoxy(x, y + 1); printf("□□      □□");
		gotoxy(x, y + 2); printf("□□□□  □□");
		gotoxy(x, y + 3); printf("□□      □□");
		gotoxy(x, y + 4); printf("□□□□  □□");
		gotoxy(x, y + 5); printf("□□      □□");
		gotoxy(x, y + 6); printf("□□□□□□□");
		Sleep(Delay + 300);
		textcolor(WHITE, BLACK);
		drawBoard();
		break;
	case 4:
		textcolor(randcolor, BLACK);
		x = 7, y = 13;
		gotoxy(x, y); printf("□□□□□□□");
		gotoxy(x, y + 1); printf("□□  □  □□");
		gotoxy(x, y + 2); printf("□□  □  □□");
		gotoxy(x, y + 3); printf("□□        □");
		gotoxy(x, y + 4); printf("□□□□  □□");
		gotoxy(x, y + 5); printf("□□□□  □□");
		gotoxy(x, y + 6); printf("□□□□□□□");
		Sleep(Delay + 300);
		textcolor(WHITE, BLACK);
		drawBoard();
		break;
	case 5:
		textcolor(randcolor, BLACK);
		x = 23, y = 13;
		gotoxy(x, y); printf("□□□□□□□");
		gotoxy(x, y + 1); printf("□□      □□");
		gotoxy(x, y + 2); printf("□□  □□□□");
		gotoxy(x, y + 3); printf("□□      □□");
		gotoxy(x, y + 4); printf("□□□□  □□");
		gotoxy(x, y + 5); printf("□□      □□");
		gotoxy(x, y + 6); printf("□□□□□□□");
		Sleep(Delay + 300);
		textcolor(WHITE, BLACK);
		drawBoard();
		break;
	case 6:
		textcolor(randcolor, BLACK);
		x = 39, y = 13;
		gotoxy(x, y); printf("□□□□□□□");
		gotoxy(x, y + 1); printf("□□  □□□□");
		gotoxy(x, y + 2); printf("□□  □□□□");
		gotoxy(x, y + 3); printf("□□      □□");
		gotoxy(x, y + 4); printf("□□  □  □□");
		gotoxy(x, y + 5); printf("□□      □□");
		gotoxy(x, y + 6); printf("□□□□□□□");
		Sleep(Delay + 300);
		textcolor(WHITE, BLACK);
		drawBoard();
		break;
	case 7:
		textcolor(randcolor, BLACK);
		x = 7, y = 21;
		gotoxy(x, y); printf("□□□□□□□");
		gotoxy(x, y + 1); printf("□□      □□");
		gotoxy(x, y + 2); printf("□□□□  □□");
		gotoxy(x, y + 3); printf("□□□□  □□");
		gotoxy(x, y + 4); printf("□□□□  □□");
		gotoxy(x, y + 5); printf("□□□□  □□");
		gotoxy(x, y + 6); printf("□□□□□□□");
		Sleep(Delay + 300);
		textcolor(WHITE, BLACK);
		drawBoard();
		break;
	case 8:
		textcolor(randcolor, BLACK);
		x = 23, y = 21;
		gotoxy(x, y); printf("□□□□□□□");
		gotoxy(x, y + 1); printf("□□      □□");
		gotoxy(x, y + 2); printf("□□  □  □□");
		gotoxy(x, y + 3); printf("□□      □□");
		gotoxy(x, y + 4); printf("□□  □  □□");
		gotoxy(x, y + 5); printf("□□      □□");
		gotoxy(x, y + 6); printf("□□□□□□□");
		Sleep(Delay + 300);
		textcolor(WHITE, BLACK);
		drawBoard();
		break;
	case 9:
		textcolor(randcolor, BLACK);
		x = 39, y = 21;
		gotoxy(x, y); printf("□□□□□□□");
		gotoxy(x, y + 1); printf("□□      □□");
		gotoxy(x, y + 2); printf("□□  □  □□");
		gotoxy(x, y + 3); printf("□□      □□");
		gotoxy(x, y + 4); printf("□□□□  □□");
		gotoxy(x, y + 5); printf("□□□□  □□");
		gotoxy(x, y + 6); printf("□□□□□□□");
		Sleep(Delay + 300);
		textcolor(WHITE, BLACK);
		drawBoard();
		break;
	}
}
void choiceNumber(int x, int y) {	//숫자 맞추는 함수
	int a = 60, b = 11;
	if (x == 7) {
		if (y == 5) {
			user[j] = 1;
		}
		else if (y == 13) {
			user[j] = 4;
		}
		else if (y == 21) {
			user[j] = 7;
		}
	}
	else if (x == 23) {
		if (y == 5) {
			user[j] = 2;
		}
		else if (y == 13) {
			user[j] = 5;
		}
		else if (y == 21) {
			user[j] = 8;
		}
	}
	else if (x == 39) {
		if (y == 5) {
			user[j] = 3;
		}
		else if (y == 13) {
			user[j] = 6;
		}
		else if (y == 21) {
			user[j] = 9;
		}
	}
	gotoxy(a + j * 2, b + 1); printf("%d ", user[j]);
}
void move_box(int beforeX, int beforeY, int x, int y) {
	gotoxy(beforeX, beforeY); printf("              ");
	gotoxy(beforeX, beforeY + 1); printf("  "); gotoxy(beforeX + 12, beforeY + 1); printf("  ");
	gotoxy(beforeX, beforeY + 2); printf("  "); gotoxy(beforeX + 12, beforeY + 2); printf("  ");
	gotoxy(beforeX, beforeY + 3); printf("  "); gotoxy(beforeX + 12, beforeY + 3); printf("  ");
	gotoxy(beforeX, beforeY + 4); printf("  "); gotoxy(beforeX + 12, beforeY + 4); printf("  ");
	gotoxy(beforeX, beforeY + 5); printf("  "); gotoxy(beforeX + 12, beforeY + 5); printf("  ");
	gotoxy(beforeX, beforeY + 6); printf("              ");
	user_box(x, y);
}
int compare(int stage) {	//숫자 비교
	j = 0;
	for (int i = 0; i < stage; i++) {
		if (comp[i] != user[i]) {
			health--;
			return 1;
		}
	}
	return 0;
}
void show_health() {		// 현재체력
	int x = 60, y = 6;
	int cnt = 0;
	gotoxy(x, y); printf("                          ");
	for (int i = 0; i < health; i++) {
		x = 60, y = 6;
		gotoxy(x + cnt, y); printf("♥ ");
		cnt += 2;
	}
}
int gameover() {		//게임 오버

	system("cls");
	int x = 5, y = 0;
	textcolor(15, 0);
	gotoxy(x, y); printf("■■■■■    ■■■    ■      ■  ■■■■■");
	gotoxy(x, y + 1); printf("■      ■  ■■  ■■  ■■  ■■  ■");
	gotoxy(x, y + 2); printf("■          ■      ■  ■■■■■  ■");
	gotoxy(x, y + 3); printf("■  ■■■  ■      ■  ■  ■  ■  ■■■■");
	gotoxy(x, y + 4); printf("■      ■  ■■■■■  ■      ■  ■");
	gotoxy(x, y + 5); printf("■      ■  ■      ■  ■      ■  ■");
	gotoxy(x, y + 6); printf("■■■■■  ■      ■  ■      ■  ■■■■■");

	gotoxy(x, y + 8); printf("  ■■■    ■      ■  ■■■■■  ■■■■■");
	gotoxy(x, y + 9); printf("■■  ■■  ■      ■  ■          ■      ■");
	gotoxy(x, y + 10); printf("■      ■  ■      ■  ■          ■      ■");
	gotoxy(x, y + 11); printf("■      ■  ■      ■  ■■■■    ■■■■■");
	gotoxy(x, y + 12); printf("■      ■  ■■  ■■  ■          ■■■");
	gotoxy(x, y + 13); printf("■■  ■■    ■■■    ■          ■  ■■");
	gotoxy(x, y + 14); printf("  ■■■        ■      ■■■■■  ■    ■■");

	gotoxy(x, y + 16); printf("■■■  ■■■    ■      ■■  ■■■        ■■    ■■■");
	gotoxy(x, y + 17); printf("■      ■  ■  ■  ■  ■      ■      ■    ■  ■  ■    ");
	gotoxy(x, y + 18); printf("■■■  ■■■  ■■■  ■      ■■■        ■■■  ■■");
	gotoxy(x, y + 19); printf("    ■  ■      ■  ■  ■      ■      ■    ■■    ■  ");
	gotoxy(x, y + 20); printf("■■■  ■      ■  ■    ■■  ■■■        ■  ■  ■■■");
	gotoxy(x, y + 22); printf("■■■  ■■■    ■■      ■■■  ■  ■  ■  ■■■");
	gotoxy(x, y + 23); printf("■      ■      ■      ■  ■      ■  ■        ■");
	gotoxy(x, y + 24); printf("■■    ■■■  ■          ■■      ■    ■    ■");
	gotoxy(x, y + 25); printf("■          ■  ■      ■  ■      ■  ■  ■    ■");
	gotoxy(x, y + 26); printf("■■■  ■■■    ■■      ■■■  ■  ■  ■    ■");
	while (1) {
		if (kbhit() == 1) {
			char c1; c1 = getch();
			switch (c1) {
			case SPACE:
				return 1;	//다시하기
				break;
			case ESC:
				exit(1);	//안하기
				break;
			}
		}
	}
}
void showHint() {
	gotoxy(60, 25); printf("HINT = %d", hint);
	gotoxy(60, 27); printf("Hint = P");
	gotoxy(60, 28); printf("MANUAL / PAUSE= Q");
}


void gameMain() {
	title();		//메인 타이틀
	system("cls");
	tutorial();		//설명
	system("cls");
}

void gameStart(int x, int y) {

}
int main() {
	int stage = 1;
	int i, beforeX, beforeY;
	int x = 23, y = 13;

	removeCursor();
	srand(time(NULL));

	gameMain(23,13);

	while (1) {
		showStage(stage);
		system("cls");
		gameDefault(1); //판그리고 스테이지 쓰기
		randNumber(stage);	//번호 생성 + 숫자 프린트
		user_box(x, y);
		showHint();
		while (1) {
			beforeX = x, beforeY = y;
			if (kbhit() == 1) {
				char c1; c1 = getch();
				switch (c1) {
				case UP:
					if (y <= 5)	break;
					else {
						y -= 8;
						break;
					}
				case DOWN:
					if (y >= 21) break;
					else {
						y += 8;
						break;
					}
				case LEFT:
					if (x <= 7) break;
					else {
						x -= 16;
						break;
					}
				case RIGHT:
					if (x >= 39) break;
					else {
						x += 16;
						break;
					}
				case ESC:
					exit(1);
					break;
				case P:
					if (hint > 0) {
						for (i = 0; i < stage; i++) {
							printNumber(comp[i]);
						}
						hint--;
						showHint();
					}
					break;
				case Q:
					system("cls");
					tutorial();
					system("cls");
					gameDefault(stage);
					user_box(x, y);
					showHint();
					break;
				case SPACE:
					choiceNumber(x, y);
					j++;
					break;
				}	//스위치문 끝
				move_box(beforeX, beforeY, x, y);	//이전 선택 상자 지우기
			}
			if (j == stage) {
				if (compare(stage)) {	//틀리면 실행
					show_health();
					gotoxy(60, 15); printf("틀렸습니다.");
					if (health == 0) {
						break;
					}
					for (i = 0; i < stage; i++) {
						printNumber(comp[i]);
					}
					gotoxy(60, 12); printf("                                 ");
					gotoxy(60, 15); printf("                                ");

					Sleep(Delay);
				}
				else {
					break;
				}
			}
		}//while 끝
		if (health == 0) {
			if (gameover()) {//다시하기
				stage = 1;
				health = 3;
				hint = 3;
			}
		}
		else {
			stage++;
			Delay -= 10;
			if (stage % 5 == 0) {
				hint++;
				health++;
			}
		}
	}
}