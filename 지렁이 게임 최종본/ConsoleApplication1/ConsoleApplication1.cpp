#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "hamsu.h"
#include "map.h"

int gameloop1 = 1;

int main()
{
    int gameloop = 1;
    int game_go;
    int title;
    
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
            setup();
            gameloop1 = 1;

            while (gameloop1) {
                draw();
                input();
                logic();
                Sleep(100);
                checkCollision(); 

                if (gameOverFlag) {
                    gameloop1 = 0;
                    gameOver();
                }
            }
            break;
        case '2':
            system("cls");
            print_introduction_screen();
            game_go = _getch();
            while (game_go != 'y' && game_go != 'Y') {
                while (_kbhit()) {
                    _getch(); 
                }
                game_go = _getch();
            }
            if (game_go == 'y' || game_go == 'Y') {
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