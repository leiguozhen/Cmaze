#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

#define height 43//23
#define width 59//38
#define road  0
#define wall 1
#define entry 3
#define Exit   4
#define flag   5
#define unflag 6

#define UP  72
#define DOWN  80
#define RIGHT  77
#define LEFT   75

int nrow = 1;
int ncol = 2;

int map[height + 2][width + 2];
int sign[height + 2][width + 2] = {road};
vector<int> Dir;

void gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(hOut, c);
}

int dir[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
//void print(int x, int y)
//{
//	gotoxy(2 * y - 2, x - 1);
//	if (map[x][y] == wall)
//		std::cout << "¡ö";
//	else if (map[x][y] == road) std::cout << "  ";
//	else if (map[x][y] == exit) std::cout << "³ö";
//	else if (map[x][y] == entry)std::cout << "Èë";
//}