#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include "Text.h"
#include "fall.h"
using namespace std;

enum COLOR {
	BLACK, BLUE, GREEN, OC, RED, JAJU, YELLOW, WHITE, GRAY
	, DEEP_BLUE, DEEP_GREEN, DEEP_OC, DEEP_RED, DEEP_JAJU, DEEP_YELLOW,
	DEEP_WHITE
};

POINT arr[50];
POINT tPlayerPos;

extern int game;
int score = 1;
int cnt = 15;
int speed = 80;

int main()
{
	system("title Falling ARROW");
	system("mode con cols=50 lines=30"); // 0 ~ 24      0 ~ 29

	/* Ŀ�� ���ֱ� */

	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);







	char input;


	for (int i = 0; i < cnt; i++)
	{
		int j = rand() % 25; // 0 ~ 24
		while (j % 2 != 0) j = rand() % 25; // 2�� ����� �ƴϸ� �ٽ� �̱�
		arr[i].x = j;
		arr[i].y = 1; // ��������.
	}

	TextColor(DEEP_YELLOW);
	gotoxy(0, 0, "���� : "); cout << score; 
	
	TextColor(DEEP_JAJU);
	cout << "                      Color : C  ";
	TextColor(DEEP_OC); 
	cout << "Pause: P";

	tPlayerPos = { 12, 29 };  //24�� ��. 0

	TextColor(DEEP_RED);
	gotoxy(tPlayerPos.x, tPlayerPos.y, "��");

	

	srand((unsigned)time(NULL)); // seed

	

	while (true)
	{
		


		if (_kbhit())
		{
			input = _getch();
			if (input == 224) input = _getch(); // ����Ű��� �߰� Ű�� �ϳ� �� ���� (���߿� ó��)

			switch (input)
			{
			case 'p':
			case 'P':
				while (1) { if (_kbhit()) break; } // ���߱� 
				break;
			case 'C':
			case 'c':
				arrowColorChange();
				break;
			}


			movePlayer(input);
			arrowMove();
		}
		else
			arrowMove();


		Sleep(speed);

		if (speed >= 60)
		{// 40���� ������.
			if (score % 200 == 0)
				speed -= 20;
		}
	
		switch (score) // ���̵� ����.
		{
		case 300:
		case 600:
		case 700:
		case 800:
			cnt += 2;
			break;
		case 900:
		case 1100:
		case 1300:
		case 1500:
			speed -= 5; // 20����
		case 1600:
			cnt += 4; 
			break;
		case 1700:
		case 1800:
		case 1900:
		case 2000:
				cnt++; // cnt ++;

			break;
			
		}

		if (game == 0) break;
		printScore();

		score++;

	}

	system("cls");

	while (_kbhit())
		_getch();

	while (1)
	{
		gotoxy(8, 14, "");
		printf("����� SCORE : %d", score);
		if (_kbhit()) break;
	}
	gotoxy(7, 29, "");
	
	system("pause");
	return 0;
}
