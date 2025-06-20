#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
void titleDraw()
{
	// system(mode con cols = 56 lines = 20);
	 printf("\n\n\n\n");
	printf("    ###     #   ##    #      #          # ##    #   #   ##    #  \n");
	printf("    #  #    #   # #   #    #   #        #   #   #   #   # #   #  \n");
	printf("    #   #   #   #  #  #   #     #       # ##    #   #   #  #  #  \n");
	printf("    #  #    #   #   # #    #   #        #  #    #   #   #   # #  \n");
	printf("    ###     #   #    ##      #          #   #    ###    #    ##  \n");
}

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

void gotoxy(int x , int y )
{
	 COORD pos = {x, y};		// 커서 위치를 저장하는 구조체
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int menuDraw()
{
	int x = 24;
	int y = 12;
	gotoxy(x + 5, y);
	cout << "> 게 임 시 작" << endl;
	gotoxy(x + 8 , y + 1);
	cout << "> 종 료" << endl;
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case 72 : 
		{
			gotoxy(x + 5, y);
			printf(" ");
			gotoxy(x - 2, --y);
			printf(">");
		}
		break;
		}
	}
	return 0;
}

int keyControl()
{
	int x = 5, y = 5;
	int c;
	 while (1)
	 {
	 	c = _getch();			// getch()함수를 호출하고 그 값을 변수 c에 저장
	 	system("cls");			// 흔적 지우는 함수
	 	if (c == 224)			// 현재 변수 c에 저장된 값이 224와 같으면 참을 실행
	 	{
	 		c = _getch();
	 		switch (c)
	 		{
			case 72: return 72; break;	//y--;	//cout << "위쪽"; break;
			case 80: return 80; break;	//y++;	//cout << "아래쪽"; break;
			case 75: return 75; break;	//x--;	//cout << "왼쪽"; break;
			case 77: return 77; break;	//x++;	//cout << "오른쪽"; break;
	 		}
	 	}
	 	// gotoxy(x, y);
	 	// cout << "a";
	 }
}

int main()
{
	// MapDraw();  // MapDraw 함수에서 설정된 맵을 불러옴

	 // gotoxy(5, 5);
	 // cout << "■";

	// int keyCode = KeyControl();
	// cout << "입력한 키 값 : " << keyCode;

	//.  int x = 0, y = 0;
	//.  int c;
	//.  while (1)
	//.  {
	//. 	 c = _getch();
	//. 	 if (c == )
	//. 
	//.  }

	// int i = _getch();  // getch함수 호출 및 i에 224값을 받고
	// if (i == 224)      // 여기서 i가 224면 
	// {
	// 	i = _getch();  // getch 가 한번 더 호출 및 i에 한번더 호출된값이 들어감
	// 	 cout << i;    // 그것을 출력
	// }

	

	titleDraw();
	menuDraw();
	MapDraw();
}
