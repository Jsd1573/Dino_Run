#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

using namespace std;

char tempmap[10][10];

char map1[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,3,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,2,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
char map2[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,3,0,0,0,0,3,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,2,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,3,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

void HideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void gotoxy(int x, int y) // 커서 위치 옮기는 함수
{
	COORD POS = { x ,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), POS);

}

int KeyControl()
{
	 char temp = _getch();
	 
	 if (temp == 'w')
	 {
		 return UP;  // 0
	 }
	 else if (temp == 's')
	 {
		 return DOWN;  // 1
	 }
	 else if (temp == 'a')
	 {
		 return LEFT;  // 2
	 }
	 else if (temp == 'd')
	 {
		 return RIGHT; // 3
	 }
	 else if (temp == ' ')
	 {
		 return SUBMIT; // 4
	 }
}

void TitleDraw()
{
	cout << endl;
	cout << endl;
	cout << endl;
	printf("	###    #  ##     #     ##         ####     #    #  ##     # \n");
	printf("	#  #   #  # #    #    #  #        #   #    #    #  # #    # \n");
	printf("	#   #  #  #  #   #   #    #       #    #   #    #  #  #   # \n");
	printf("	#   #  #  #   #  #   #    #       #####    #    #  #   #  # \n");
	printf("	#  #   #  #    # #    #  #        #    #   #    #  #    # # \n");
	printf("	###    #  #     ##     ##         #     #    ##    #     ## \n");
	cout << endl;
	cout << endl;
	cout << endl;

}

int MenuDraw()
{
	int x = 34;
	int y = 12;

	gotoxy(x-2, y);
	cout << "> 게임 시작";
	gotoxy(x, y+1);
	cout << "게임 정보";
	gotoxy(x, y+2);
	cout << "게임 종료";

	while(1)
	{
		int n = KeyControl();

			switch (n)
			{
				case UP :
				{
					if (y >12)
					{
						gotoxy(x - 2, y);
						printf(" ");
						gotoxy(x - 2, --y);
						printf(">");
					}
					break;
				}
				case DOWN :
				{
					if (y < 14)
					{
						gotoxy(x - 2, y);
						printf(" ");
						gotoxy(x - 2, ++y);
						printf(">");
					}
					break;
				}

				case SUBMIT:
				{
					return y - 12;
				}
			}
	}
}

void InfoDraw()
{
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("                                   [조작법]\n\n");
	printf("                              이동 : W, A, S, D\n");
	printf("                              선택 : 스페이스바 \n\n");
	printf("                  스페이스바를 누르면 메인화면으로 이동합니다.");
	while(1)
	{
		if (KeyControl() == SUBMIT)
		{
			break;								// infodraw함수에 while 문을 적지않으면 
		}										// 메뉴에서 infodraw를 호출해도 거의 바로 즉시 다시 메뉴 화면으로 돌아가게 되던데 
	}											// 왜 이런지 그리고 왜 while문을 적으면 바로 즉시 메뉴화면으로 돌아가지않고 infodraw함수로 호출한 화면이 나와서 유지되는지


}

void MapDraw(int *x, int *y)
{
	system("cls");

	int i, j; // 세로 가로

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			char temp = tempmap[i][j];

			if (temp == 0)  // 공백
			{
				cout << "  ";
			}
			else if (temp == 1)  // 벽
			{
				cout << "■";
			}
			else if (temp == 2)  // 플레이어
			{
				cout << "☆";
				*x = j+4;
				*y = i;
				
			}
			else if (temp == 3)  // 박스
			{
				cout << "□";
			}
			
		}
		cout << endl;
	}
	// Sleep(3000);
	
}

 void Move(int * x, int * y, int _x, int _y)
 {
	 gotoxy(*x, *y);
	 printf("  ");

	 gotoxy(*x +_x, *y + _y);
	 printf("☆");

	 *x = *x + _x;
	 *y = *y + _y;
 }

int maplistdraw()
{
	int x = 34;
	int y = 12;

	system("cls");
	printf("\n\n\n\n\n\n\n\n\n");
	printf("                                 [맵선택] \n\n");

	gotoxy(x - 2, y);
	printf("> 1 단계");
	gotoxy(x, y + 1);
	printf("2 단계");
	gotoxy(x, y + 2);
	printf(" 뒤로");

	while (1)
	{
		int n = KeyControl();
		switch (n)
		{
			case UP:
			{
				if (y > 12)
				{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
				}
				break;
			}
			case DOWN:
			{
				if (y < 14)
				{
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT:
			{
				return y - 12;
			}

		}
	}
}

void Gloop(int mapcode)
{
	int x = 0;
	int y = 0;

	int playing = 1;

	if (mapcode == 0)
	{
		memcpy(tempmap, map1, sizeof(tempmap));
	}
	else if (mapcode == 1)
	{
		memcpy(tempmap, map2, sizeof(tempmap));
	}

	MapDraw(&x,&y);

	while (playing)
	{
		switch (KeyControl())
		{
			case UP: Move(&x, &y, 0, -1 );
			break;

			case DOWN : Move(&x, &y,0, +1);
			break;

			case LEFT : Move(&x, &y,-2 , 0);
			break;

			case RIGHT : Move(&x, &y,+2, 0);
			break;
		}
	}

}


int main()
{
	 HideCursor();
	 
	  while (1)
	  {
	  	TitleDraw();
	  
	  	int menucode = MenuDraw();
	  	
	  	if (menucode == 0)
	  	{
			int n = maplistdraw();
			if (n == 0)
			{
				Gloop(0);
			}
			else if (n == 1)
			{
				Gloop(1);
			}
	 		// MapDraw();
			// Move();

	  	}
	  	else if (menucode == 1)
	  	{
	  		InfoDraw();
	  	}
	  	else if (menucode == 2)
	  	{
	  		return 0;		// return문의 기능에는 값을 반환하는것도 있지만 자신이 속해있는 함수를 종료시키는 기능도 있습니다.
	  	}
	  	system("cls");
	  
	  }
	
	return 0;
}

