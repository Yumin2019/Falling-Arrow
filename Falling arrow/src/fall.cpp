
#include<Windows.h>
#include<iostream>
#include"Text.h"
#include"fall.h"
using namespace std;


extern POINT arr[25];
extern POINT tPlayerPos;

extern int score;
extern int cnt;
extern int speed;


int arrowColor = 1;
int game = 1;


enum COLOR {
	BLACK, BLUE, GREEN, OC, RED, JAJU, YELLOW, WHITE, GRAY
	, DEEP_BLUE, DEEP_GREEN, DEEP_OC, DEEP_RED, DEEP_JAJU, DEEP_YELLOW,
	DEEP_WHITE
};

void printScore()
{
	TextColor(DEEP_YELLOW);
	gotoxy(0, 0, "���� : "); printf("%d", score); 
}
void arrowMove()
{
	color();
	for (int i = 0; i < cnt; i++)
	{
		gotoxy(arr[i].x, arr[i].y, " ");
		arr[i].y++;
		if (arr[i].y == tPlayerPos.y && arr[i].x == tPlayerPos.x) {
			game = 0; return; // ���� ����
		}

		if (arr[i].y == 30) {
			//ȭ�� ���� �Լ�ó��.
			arrowMake(i);
		}

		
		
		gotoxy(arr[i].x, arr[i].y, "��");
	}
}

void moveRight()
{
	tPlayerPos.x++;
}
void moveLeft()
{
	tPlayerPos.x--;
}


void movePlayer(char input)
{
	//cout << " tPlayerPos.x : " << tPlayerPos.x << " tPlayerPos.y " << tPlayerPos.y << endl;
	// �̸� �ش� ��ġ�� �����ְ� �ٽ� ��´�.

	gotoxy(tPlayerPos.x, tPlayerPos.y, " ");


	switch (input)
	{
	case 'A':
	case 'a':
		moveLeft();
		if (tPlayerPos.x == -1) tPlayerPos.x = 0;
		break;
	case 'd':
	case 'D':
		moveRight();
		if (tPlayerPos.x == 25) tPlayerPos.x = 24;
		break;
	}

	TextColor(DEEP_RED);
	gotoxy(tPlayerPos.x, tPlayerPos.y, "��");


}


void arrowMake(int i) // �����
{

	 // 0 ~ 24
	// 2�� ����� �ƴϸ� �ٽ� �̱�
	arr[i].x = rand() % 25;
	arr[i].y = rand()%3 +1; // ���ںκ� ���� 1~3 �߿� �ϳ�

}

void color()
{
	switch (arrowColor)
	{
	case 1:
		TextColor(DEEP_WHITE);
		break;
	case 2:
		TextColor(DEEP_JAJU);
		break;
	case 3:
		TextColor(DEEP_OC);
		break;
	case 4:
		TextColor(DEEP_YELLOW);
		break;
	}
}
void arrowColorChange()
{
	arrowColor++;
	if (arrowColor == 5)
		arrowColor = 1;
}

