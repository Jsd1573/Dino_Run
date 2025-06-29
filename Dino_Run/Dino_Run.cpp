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
    printf("	          ######  ####    ####    #    ####   ######\n");
    printf("	          #      #       #       # #   #   #  #     \n");
    printf("	          #      #      #        # #   #    # #     \n");
    printf("	          ######  ####  #       #   #  #   #  ######\n");
    printf("	          #           # #       #####  ####   #     \n");
    printf("	          #           #  #     #     # #      #     \n");
    printf("	          ######  ####    #### #     # #      ######\n");
    cout << endl;
    cout << endl;
    cout << endl;

}

class Setting
{
public :
    void setConsleSize(int width, int height)
    {
        HWND console = GetConsoleWindow();
        RECT r;
        GetWindowRect(console, &r);
        MoveWindow(console, r.left, r.top, width, height, TRUE);
    }


};



class Maze
{
public:
    static const int rows = 10;
    static const int cols = 15;

    char map1[rows][cols + 1] =
    {
        "###############",
        "#P     #     E#",
        "# ### ##### ###",
        "#   #     #   #",
        "### # ### ### #",
        "#   #   #     #",
        "# ##### ##### #",
        "#     #     # #",
        "##K## ##### # #",
        "###############"
    };

    static const int rows2 = 20;
    static const int cols2 = 25;

    char map2[rows2][cols2 + 1] =
    {
        "#########################",
        "#P      #               #",
        "# ### ##### ###### #### #",
        "#   # #       #### ## # #",
        "### #  #### # #       ###",
        "#   ## ##  ## ##### #   #",
        "# ####    #      ##  ## #",
        "#    ###### ######### # #",
        "####     # K ##       # #",
        "###  ### ## ##  ####### #",
        "#     ##  #####    ##   #",
        "## ## ## ##     ## ## ###",
        "##  #    #####   ####   #",
        "###  ###    ## #     ## #",
        "#   ##### # ## ##### #  #",
        "# ##  #   #      #     E#",
        "# ###### ###   # ### # ##",
        "#  ##     ## ###   # ## #",
        "##    ###    #####      #",
        "#########################"
    };


    void draw(int x)
    {
        switch (x)
        {
        case 1: for (int i = 0; i < rows; ++i)
        {
            gotoxy(0, i);
            cout << map1[i];
        }
              break;

        case 2: for (int i = 0; i < rows2; ++i)
        {

            gotoxy(0, i);
            cout << map2[i];
        }
              break;

        }
    }
};

class Player
{
public:
    int x = 1;              //Player 시작 지점
    int y = 1;

    void Reset()
    {
        x = 1;
        y = 1;
    }

    void draw(Maze& maze, int x)
    {
        switch (x)
        {
        case 1: maze.map1[y][x] = 'p';
            gotoxy(x, y);
            cout << 'P';
            break;

        case 2: maze.map2[y][x] = 'p';
            x = 1;
            y = 1;
            gotoxy(x, y);
            cout << 'P';
            break;
        }
    }

    int move(Maze& maze, int dx, int dy, int s)                                                                      // Maze 클래스의 maze 객체를 매개변수로 넣음으로써 maze객체의 정보를 한꺼번에 함수에 전달
    {

        int newX = x + dx;
        int newY = y + dy;
        char next;

        switch (s)
        {
        case 1: next = maze.map1[newY][newX];

            if (next == '#')
            {
                return 0;                                                                                                                // if문은 조건이 참일경우 에만 내용을 실행  조건이 거짓일 경우 if문은 건너뛰고 다음 문장 실행
            }

            if (next == 'K')
            {
                gotoxy(x, y); cout << ' ';
                maze.map1[y][x] = ' ';
                x = newX;
                y = newY;
                maze.map1[y][x] = 'P';
                gotoxy(x, y); cout << 'P';

                return 1;
            }

            if (next == 'E')
            {
                return 2;
            }

            gotoxy(x, y); cout << ' ';
            maze.map1[y][x] = ' ';
            x = newX;
            y = newY;
            maze.map1[y][x] = 'P';
            gotoxy(x, y); cout << 'P';

            break;




        case 2: next = maze.map2[newY][newX];
             
            

            if (next == '#')
            {
                return 0;           // if문은 조건이 참일경우 에만 내용을 실행  조건이 거짓일 경우 if문은 건너뛰고 다음 문장 실행
            }

            if (next == 'K')
            {
                gotoxy(x, y); cout << ' ';
                maze.map2[y][x] = ' ';
                x = newX;
                y = newY;
                maze.map2[y][x] = 'P';
                gotoxy(x, y); cout << 'P';

                return 1;
            }

            if (next == 'E')
            {
                return 2;
            }

            gotoxy(x, y); cout << ' ';
            maze.map2[y][x] = ' ';
            x = newX;
            y = newY;
            maze.map2[y][x] = 'P';
            gotoxy(x, y); cout << 'P';

            break;
        }


        // return 0;
    }

};

class Menu
{
public:
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
        gotoxy(x, y + 1);
        cout << "게임 정보";
        gotoxy(x, y + 2);
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

            case SUBMIT: return y - 12;

            }
        }



    }
};

// ------------------- Game 클래스 -------------------
class Game
{
public:
    Setting setting;
    Maze maze;
    Player player;
    Menu menu;
    int running = 1;

    void run()
    {
        setting.setConsleSize(700, 600);

        while (1)
        {
            TitleDraw();
            int menucode = menu.draw(34, 12);

            if (menucode == 0)  // 게임 시작
            {
                break;                                                                           // break 문은 반복문(for, while등등)이나 switch문을 즉시 종료시키는데 사용되는 제어문
            }                                                                                        // break 가 실행되면 ,해당 블록을 빠져나와 다음 코드로 흐름이 이동, break 문은 가장 가까운 반복문이나 switch문을 탈출
            else if (menucode == 1)     // 게임 정보
            {
                menu.InfoDraw();
            }
            else if (menucode == 2)     // 게임 종료
            {
                return;                                                                                     // return문의 기능에는 값을 반환하는것도 있지만 자신이 속해있는 '함수를' 종료시키는 기능도 있습니다.
            }
        }
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

         system("cls");                                              // 기존에 출력되어 있던 타이틀이나 메뉴 를 전부 정리해주기위해 사용
         maze.draw(1);                                               // maze객체의 draw함수를 호출
         player.draw(maze, 1);                                       // player객체의 draw함수를 호출하면서 maze객체를 인수로 전달

        int win = 0;

        int clear = 0;

        int stage = 1;

        while (running)
        {
            int input = Keycontrol();
       
       
            switch (input)
            {
            case UP: win = player.move(maze, 0, -1, stage); break;
            case DOWN: win = player.move(maze, 0, 1, stage);  break;
            case LEFT: win = player.move(maze, -1, 0, stage); break;
            case RIGHT: win = player.move(maze, 1, 0, stage);  break;
            
            }
       
            if (win == 1)           // 열쇠 획득
            {
                gotoxy(0, Maze :: rows + 2);
                cout << "열쇠 획득"; 
                clear++;
                
            }
       
            if (win == 2 && clear == 1)     // 탈출 로직
            {
                system("cls");
                gotoxy(0,0);
                cout <<"다음 스테이지";
                stage++;
                Sleep(1000
                );
                break;
            }
           
            
        }

        system("cls");
        maze.draw(2);
        player.draw(maze, 2);
        player.Reset();


        while (running)
        {
            int input = Keycontrol();


            switch (input)
            {
            case UP: win = player.move(maze, 0, -1, stage); break;
            case DOWN: win = player.move(maze, 0, 1, stage);  break;
            case LEFT: win = player.move(maze, -1, 0, stage); break;
            case RIGHT: win = player.move(maze, 1, 0, stage);  break;
            }

            if (win == 1)
            {
                gotoxy(0, Maze::rows2 + 2);
                cout << "열쇠 획득";
                clear++;
            }

            if (win == 2 && clear == 2)
            {
                system("cls");
                gotoxy(0,0);
                cout <<"탈출 성공!";
                running = 0;
            }

        }

       // gotoxy(0, Maze::rows + 4);
    }
};

// ------------------- main -------------------
int main()

{
    Game game;      // Game 이라는 클래스(자료형)를 사용하는 game이라는 객체를 생성하는 문구
    game.run();     // game 이라는 객체의 run()함수를 호출
    return 0;
}


