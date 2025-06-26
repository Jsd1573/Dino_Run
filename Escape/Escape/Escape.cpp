#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SUBMIT 32

using namespace std;

void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int Keycontrol()
{
    int temp = _getch();

    if (temp == 224)
    {
        temp = _getch();

        if (temp == 72)
        {
            return UP;
        }
        else if (temp == 80)
        {
            return DOWN;
        }
        else if (temp == 75)
        {
            return LEFT;
        }
        else if (temp == 77)
        {
            return RIGHT;
        }
        else if (temp == 32)
        {
            return SUBMIT;
        }
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



class Maze
{
public : 
	static const int rows = 10;
	static const int cols = 15;

    char map[rows][cols + 1] =
    {
        "###############",
        "#P     #     E#",
        "# ### ##### ###",
        "#   #     #   #",
        "### # ### ### #",
        "#   #   #     #",
        "# ##### ##### #",
        "#     #     # #",
        "# ### ##### # #",
        "###############"
    };

    void draw()
    {
        for (int i = 0; i < rows; ++i)
        {
            gotoxy(0, i);
            cout << map[i];
        }
    }
       
};

class Player
{
public : 
    int x = 1;
    int y = 1;

  //  void draw(Maze& maze)
  //  {
  //     //  maze.map[y][x] = 'p';
  //      gotoxy(x, y);
  //      cout << 'p';
  //  }

    int move(Maze& maze, int dx, int dy)
    {
        int newX = x + dx;
        int newY = y + dy;
        char next = maze.map[newY][newX];

        if (next == '#')
        {
            return 0;           // if문은 조건이 참일경우 에만 내용을 실행  조건이 거짓일 경우 if문은 건너뛰고 다음 문장 실행
        }
      
        if (next == 'E')
        {
            return 1;
        }

        gotoxy(x, y); cout << ' ';
        maze.map[y][x] = ' ';
        x = newX;
        y = newY;
        maze.map[y][x] = 'P';
        gotoxy(x, y); cout << 'P';

        
        return 0;
    }
};

class Menu
{
public : 
    void InfoDraw()
    {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("                                   [조작법]\n\n");
        printf("                              이동 : W, A, S, D\n");
        printf("                              선택 : 스페이스바 \n\n");
        printf("                  스페이스바를 누르면 메인화면으로 이동합니다.");


        while (1)
        {
            if (Keycontrol() == SUBMIT)
            {
                system("cls");
                break;
            }
        }
    }
    int draw(int x, int y)
    {
        gotoxy(x - 2, y);
        cout << "> 게임 시작";
        gotoxy(x, y+1) ;
        cout << "게임 정보";
        gotoxy(x, y +2);
        cout << "게임 종료";

        while (1)
        {
            int n = Keycontrol();

            switch (n)
            {
            case UP:
                if (y > 12)
                {
                    gotoxy(x - 2, y);
                    printf(" ");
                    gotoxy(x - 2, --y);
                    printf(">");
                }
                break;

            case DOWN:
                 if (y < 14)
                {
                    gotoxy(x - 2, y);
                    printf(" ");
                    gotoxy(x - 2, ++y);
                    printf(">");
                }
                break;

            case SUBMIT : return y - 12;
                    
            }
        }



    }
};

// ------------------- Game 클래스 -------------------
class Game
{
public:
    Maze maze;
    Player player;
    Menu menu;
    int running = 1;

    void run()
    {
        
        while (1)
        {
            TitleDraw();
            int menucode = menu.draw(34,12);
        
            if (menucode == 0)  // 게임 시작
            {
                break;      // break 문은 반복문(for, while등등)이나 switch문을 즉시 종료시키는데 사용되는 제어문
            }                 // break 가 실행되면 ,해당 블록을 빠져나와 다음 코드로 흐름이 이동, break 문은 가장 가까운 반복문이나 switch문을 탈출
            else if (menucode == 1)     // 게임 정보
            {
                menu.InfoDraw();
            }
            else if (menucode == 2)     // 게임 종료
            {
                return;         // return문의 기능에는 값을 반환하는것도 있지만 자신이 속해있는 '함수를' 종료시키는 기능도 있습니다.
            }
        }

        system("cls");              // 기존에 출력되어 있던 타이틀이나 메뉴 를 전부 정리해주기위해 사용
        maze.draw();            // maze객체의 draw함수를 호출
       //  player.draw(maze);      // player객체의 draw함수를 호출하면서 maze객체를 인수로 전달

        while (running)
        {
            int input = Keycontrol();
            int win = 0;

            switch (input)
            {
            case UP : win = player.move(maze, 0, -1); break;
            case DOWN : win = player.move(maze, 0, 1);  break;
            case LEFT : win = player.move(maze, -1, 0); break;
            case RIGHT : win = player.move(maze, 1, 0);  break;
            }

            if (win)
            {
                gotoxy(0, Maze::rows + 2);
                cout << "🎉 탈출 성공! 🎉";
                running = 0;
            }
        }

        gotoxy(0, Maze::rows + 4);
    }
};

// ------------------- main -------------------
int main()
{
    Game game;      // Game 이라는 클래스(자료형)를 사용하는 game이라는 객체를 생성하는 문구
    game.run();     // game 이라는 객체의 run()함수를 호출
    return 0;
}

