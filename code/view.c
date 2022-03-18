#include <windows.h>
#include <stdio.h>

void cls(int bg_color, int text_color) // 화면 지우기
{
	char cmd[100];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);
	system(cmd);
}

void title() {	//첫 화면
	int x = 2;
	int y = 2;
	int Delay = 100;
	textcolor(12, 11);
	gotoxy(x, y - 1); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□"); Sleep(Delay);
	gotoxy(x, y + 0); printf("□■□□□■□■■■■□■□□□■□□■■□□■■■□□■□□□■□"); Sleep(Delay);
	gotoxy(x, y + 1); printf("□■■□■■□■□□□□■■□■■□■□□■□■□□■□■□□□■□"); Sleep(Delay);
	gotoxy(x, y + 2); printf("□■□■□■□■■■□□■□■□■□■□□■□■□□■□□■□■□□"); Sleep(Delay);
	gotoxy(x, y + 3); printf("□■□□□■□■□□□□■□□□■□■□□■□■■■□□□□■□□□"); Sleep(Delay);
	gotoxy(x, y + 4); printf("□■□□□■□■□□□□■□□□■□■□□■□■□□■□□□■□□□"); Sleep(Delay);
	gotoxy(x, y + 5); printf("□■□□□■□■■■■□■□□□■□□■■□□■□□■□□□■□□□"); Sleep(Delay);
	gotoxy(x, y + 6); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□"); Sleep(Delay);
	gotoxy(x + 5, y + 7); printf("□□■■□□□□□■■□□□□■□□□■□□□■■■■□"); Sleep(Delay);
	gotoxy(x + 5, y + 8); printf("□■□□■□□□■□□■□□□■■□■■□□□■□□□□"); Sleep(Delay);
	gotoxy(x + 5, y + 9); printf("□■□□□□□□■□□■□□□■□■□■□□□■■■□□"); Sleep(Delay);
	gotoxy(x + 5, y + 10); printf("□■□■■□□□■■■■□□□■□□□■□□□■□□□□"); Sleep(Delay);
	gotoxy(x + 5, y + 11); printf("□■□□■□□□■□□■□□□■□□□■□□□■□□□□"); Sleep(Delay);
	gotoxy(x + 5, y + 12); printf("□□■■□□□□■□□■□□□■□□□■□□□■■■■□"); Sleep(Delay);
	gotoxy(x + 5, y + 13); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□"); Sleep(Delay);
	textcolor(15, 0);
	gotoxy(x + 20, y + 15); printf("Please Enter Any Key to Start");
	textcolor(12, 11);
	for (int cnt = 0;; cnt++) {
		if (kbhit()) break;
		if (cnt % 100 == 0) {
			gotoxy(x, y + 0); printf("□■□□□■□■■■■□■□□□■□□■■□□■■■□□■□□□■□");
			gotoxy(x, y + 1); printf("□■■□■■□■□□□□■■□■■□■□□■□■□□■□■□□□■□"); Sleep(Delay);
			gotoxy(x, y + 2); printf("□■□■□■□■■■□□■□■□■□■□□■□■□□■□□■□■□□"); Sleep(Delay);
			gotoxy(x, y + 3); printf("□■□□□■□■□□□□■□□□■□■□□■□■■■□□□□■□□□"); Sleep(Delay);
			gotoxy(x, y + 4); printf("□■□□□■□■□□□□■□□□■□■□□■□■□□■□□□■□□□"); Sleep(Delay);
			gotoxy(x, y + 5); printf("□■□□□■□■■■■□■□□□■□□■■□□■□□■□□□■□□□"); Sleep(Delay);
			gotoxy(x, y + 6); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□"); Sleep(Delay);
			gotoxy(x + 5, y + 7); printf("□□■■□□□□□■■□□□□■□□□■□□□■■■■□"); Sleep(Delay);
			gotoxy(x + 5, y + 8); printf("□■□□■□□□■□□■□□□■■□■■□□□■□□□□"); Sleep(Delay);
			gotoxy(x + 5, y + 9); printf("□■□□□□□□■□□■□□□■□■□■□□□■■■□□"); Sleep(Delay);
			gotoxy(x + 5, y + 10); printf("□■□■■□□□■■■■□□□■□□□■□□□■□□□□"); Sleep(Delay);
			gotoxy(x + 5, y + 11); printf("□■□□■□□□■□□■□□□■□□□■□□□■□□□□"); Sleep(Delay);
			gotoxy(x + 5, y + 12); printf("□□■■□□□□■□□■□□□■□□□■□□□■■■■□"); Sleep(Delay * 20);
		}
		else {
			gotoxy(x, y + 0); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			gotoxy(x, y + 1); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			gotoxy(x, y + 2); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			gotoxy(x, y + 3); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			gotoxy(x, y + 4); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			gotoxy(x, y + 5); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			gotoxy(x, y + 6); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			gotoxy(x + 5, y + 7); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			gotoxy(x + 5, y + 8); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			gotoxy(x + 5, y + 9); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			gotoxy(x + 5, y + 10); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			gotoxy(x + 5, y + 11); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			gotoxy(x + 5, y + 12); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
		}
	}
	textcolor(15, 0);
	while (kbhit()) getch();

}


void showStage(int stage) {		//문제 출제
	system("cls");
	int x = 5, y = 13;
	gotoxy(x, y); printf("■■■■■  ■■■■■    ■■■    ■■■■■  ■■■■■");
	gotoxy(x, y + 1); printf("■              ■      ■■  ■■  ■      ■  ■");
	gotoxy(x, y + 2); printf("■              ■      ■      ■  ■          ■");
	gotoxy(x, y + 3); printf("■■■■■      ■      ■      ■  ■  ■■■  ■■■■");
	gotoxy(x, y + 4); printf("        ■      ■      ■■■■■  ■      ■  ■");
	gotoxy(x, y + 5); printf("        ■      ■      ■      ■  ■      ■  ■");
	gotoxy(x, y + 6); printf("■■■■■      ■      ■      ■  ■■■■■  ■■■■■");
	x = 65, y = 13;
	for (int num = stage; num > 0; num /= 10) {

		switch (num % 10) {
		case 0:
			gotoxy(x, y + 1); printf("  □");
			gotoxy(x, y + 2); printf("□  □");
			gotoxy(x, y + 3); printf("□  □");
			gotoxy(x, y + 4); printf("□  □");
			gotoxy(x, y + 5); printf("  □");
			break;
		case 1:
			gotoxy(x, y + 1); printf("  □");
			gotoxy(x, y + 2); printf("□□");
			gotoxy(x, y + 3); printf("  □");
			gotoxy(x, y + 4); printf("  □");
			gotoxy(x, y + 5); printf("□□□");
			break;
		case 2:
			gotoxy(x, y + 1); printf("□□□");
			gotoxy(x, y + 2); printf("    □");
			gotoxy(x, y + 3); printf("□□□");
			gotoxy(x, y + 4); printf("□");
			gotoxy(x, y + 5); printf("□□□");
			break;
		case 3:
			gotoxy(x, y + 1); printf("□□□");
			gotoxy(x, y + 2); printf("    □");
			gotoxy(x, y + 3); printf("□□□");
			gotoxy(x, y + 4); printf("    □");
			gotoxy(x, y + 5); printf("□□□");
			break;
		case 4:
			gotoxy(x, y + 1); printf("□  □");
			gotoxy(x, y + 2); printf("□  □");
			gotoxy(x, y + 3); printf("□□□□");
			gotoxy(x, y + 4); printf("    □");
			gotoxy(x, y + 5); printf("    □");
			break;
		case 5:
			gotoxy(x, y + 1); printf("□□□");
			gotoxy(x, y + 2); printf("□");
			gotoxy(x, y + 3); printf("□□□");
			gotoxy(x, y + 4); printf("    □");
			gotoxy(x, y + 5); printf("□□□");
			break;
		case 6:
			gotoxy(x, y + 1); printf("□");
			gotoxy(x, y + 2); printf("□");
			gotoxy(x, y + 3); printf("□□□");
			gotoxy(x, y + 4); printf("□  □");
			gotoxy(x, y + 5); printf("□□□");
			break;
		case 7:
			gotoxy(x, y + 1); printf("□□□");
			gotoxy(x, y + 2); printf("    □");
			gotoxy(x, y + 3); printf("    □");
			gotoxy(x, y + 4); printf("    □");
			gotoxy(x, y + 5); printf("    □");
			break;
		case 8:
			gotoxy(x, y + 1); printf("□□□");
			gotoxy(x, y + 2); printf("□  □");
			gotoxy(x, y + 3); printf("□□□");
			gotoxy(x, y + 4); printf("□  □");
			gotoxy(x, y + 5); printf("□□□");
			break;
		case 9:
			gotoxy(x, y + 1); printf("□□□");
			gotoxy(x, y + 2); printf("□  □");
			gotoxy(x, y + 3); printf("□□□");
			gotoxy(x, y + 4); printf("    □");
			gotoxy(x, y + 5); printf("    □");
			break;
		}
		x += 8;
	}
	Sleep(1000);
}