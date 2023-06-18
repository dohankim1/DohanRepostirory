#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "text.h"
#include "map.h"

int gameloop1 = 1;
struct Coordinat coord;
struct startsnake snake;

int main()
{
    int gameloop = 1;
    int game_go;
    float currentTime = 0.0f;
    float deltaTime = 0.0f;

    while (gameloop)
    {
        print_title_screen();
        game_go = _getch();
        while (game_go != '1' && game_go != '2' && game_go != '3' && game_go != 27) {
            while (_kbhit()) {
                _getch();
            }
            game_go = _getch();
        }

        switch (game_go) {
        case '1':
            setup(coord, snake);
            gameloop1 = 1;

            while (gameloop1) {
                currentTime = GetTickCount(); // 현재 시간 업데이트
                draw(coord, snake);
                input(snake);
                logic(coord, snake);
                Sleep(100);
                checkCollision(coord, snake);

                deltaTime = (GetTickCount() - currentTime) / 1000; // deltaTime 계산

                if (coord.gameOverFlag) {
                    gameloop1 = 0;
                    gameOver(coord, snake);
                }
            }
            break;
        case '2':
            system("cls");
            print_introduction_screen();
            game_go = _getch();
            while (game_go != 'y' && game_go != 'Y')
            {
                while (_kbhit())
                {
                    _getch();
                }
                game_go = _getch();
            }
            if (game_go == 'y' || game_go == 'Y')
            {
                system("cls");
                gameloop = 1;
            }
            break;

        case '3':
        case 27:
            gameloop = 0;
            break;
        }
    }
    return 0;
}
