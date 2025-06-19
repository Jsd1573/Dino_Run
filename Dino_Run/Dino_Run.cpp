#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int MapDraw()
{
	int array[7][6]
	{
		{1,1,1,1,0,0,},
		{1,0,0,1,0,0,},
		{1,0,0,1,1,1,},
		{1,0,0,0,0,1,},
		{1,0,0,0,0,1,},
		{1,0,0,1,1,1,},
		{1,1,1,1,0,0,}

	};

	int rows = sizeof(array) / sizeof(array[0]);  // 5
	int cols = sizeof(array[0]) / sizeof(array[0][0]);  // 5

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (array[i][j] == 1)
			{
				cout << "■";
			}
			else
			{
				cout << "  ";
			}
		}

		cout << endl;
	}
	return 0;
}

void gotoxy(int x, int y)
{
	COORD pos = {x, y};		// 커서 위치를 저장하는 구조체
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	// MapDraw();  // MapDraw 함수에서 설정된 맵을 불러옴

	gotoxy(10, 3);
	cout << "■";


}
