#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;


#define N 3
int arr[N][N] = { 0 };
MOUSEMSG msg;
enum chess { none, black, white };

void game();
void printBoard(LPCTSTR who);
void playerMove();
void computerMove();
bool isWin();

int main() {
	srand((unsigned int)time(NULL));
	initgraph(600, 700, NOMINIMIZE);
    setbkcolor(YELLOW);
	cleardevice();

	game();

	getchar();
	closegraph();

	return 0;
}

void game() {
	int winner = 0;
	printBoard(L"游戏开始");

	while (isWin() == false) {
		playerMove();
		cleardevice();
		printBoard(L"电脑下:");
		if (isWin() == true) {
			winner = 1;
			break;
		}
		computerMove();
		cleardevice();
		printBoard(L"玩家下:");
	}

	settextcolor(RED);
	settextstyle(25, 0, L"宋体");
	int x = (600 - textwidth(L"玩家赢!")) / 2;
	int y = 650 + (50 - textheight(L"玩家赢!")) / 2;
	if (winner == 1) {
		outtextxy(x, y, L"玩家赢!");
	}
	else {
		outtextxy(x, y, L"电脑赢!");
	}
}


void printBoard(LPCTSTR who) {
	int x = (600 - textwidth(who)) / 2;
	int y = (50 - textheight(who)) / 2;

	settextcolor(BLACK);
	settextstyle(25, 0, L"宋体");
	outtextxy(x, y, who);

	setlinecolor(BLACK);
	for (int i = 0; i < 4; i++) {
		int h = 50 + 200 * i;
		line(0, h, 600, h);
	}
	line(200, 50, 200, 650);
	line(400, 50, 400, 650);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			switch (arr[i][j])
			{
			case black:
				setfillcolor(BLACK);
				fillcircle(100 + j * 200, 150 + i * 200, 50);
				break;
			case white:
				setfillcolor(WHITE);
				fillcircle(100 + j * 200, 150 + i * 200, 50);
				break;
			default:
				break;
			}
		}
	}
}

void playerMove() {
	while (1) {
		msg = GetMouseMsg();
		if (msg.mkLButton == true) {
			if (msg.x > 0 && msg.x < 200) {
				if (msg.y > 50 && msg.y < 250) {
					if (arr[0][0] == none) arr[0][0] = black;
					else continue;
				}
				else if (msg.y > 250 && msg.y < 450) {
					if (arr[1][0] == none) arr[1][0] = black;
					else continue;
				}
				else if (msg.y > 450 && msg.y < 650) {
					if (arr[2][0] == none) arr[2][0] = black;
					else continue;
				}
				else {
					continue;
				}
			}
			else if (msg.x > 200 && msg.x < 400) {
				if (msg.y > 50 && msg.y < 250) {
					if (arr[0][1] == none) arr[0][1] = black;
					else continue;
				}
				else if (msg.y > 250 && msg.y < 450) {
					if (arr[1][1] == none) arr[1][1] = black;
					else continue;
				}
				else if (msg.y > 450 && msg.y < 650) {
					if (arr[2][1] == none) arr[2][1] = black;
					else continue;
				}
				else {
					continue;
				}
			}
			else {
				if (msg.y > 50 && msg.y < 250) {
					if (arr[0][2] == none) arr[0][2] = black;
					else continue;
				}
				else if (msg.y > 250 && msg.y < 450) {
					if (arr[1][2] == none) arr[1][2] = black;
					else continue;
				}
				else if (msg.y > 450 && msg.y < 650) {
					if (arr[2][2] == none) arr[2][2] = black;
					else continue;
				}
				else {
					continue;
				}
			}
			break;
		}
	}
}

void computerMove() {
	Sleep(1000);
	int x, y;
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (arr[x][y] == none)
		{
			arr[x][y] = white;
			break;
		}
	}
}

bool isWin() {
	for (int i = 0; i < 3; i++) {
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != none) {
			return true;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != none) {
			return true;
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != none) {
		return true;
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != none) {
		return true;
	}

	return false;
}