#include <iostream>
#include <conio.h>
#include <Windows.h>

int weight = 5;
int height = 5;

int print_title_screen() {
    std::cout << "**********************************************\n";
    std::cout << "*                                            *\n";
    std::cout << "*                                            *\n";
    std::cout << "*                지렁이 게임                 *\n";
    std::cout << "*               (Snake  Bite)                *\n";
    std::cout << "*                                            *\n";
    std::cout << "*                                            *\n";
    std::cout << "*   1.게임 시작                              *\n";
    std::cout << "*   2.게임 설명                              *\n";
    std::cout << "*   3.게임 랭킹 보기                         *\n";
    std::cout << "*   4.게임 종료 (esc)                        *\n";
    std::cout << "**********************************************\n";
    return 0;
}

int print_introduction_screen() {
    std::cout << "**********************************************\n";
    std::cout << "    게임 설명 화면입니다.                    *\n";
    std::cout << "    지렁이 먹으면 클지도?                    *\n";
    std::cout << "    시대는 멀리 멀리 발전한다?.              *\n";
    std::cout << "**********************************************\n";
    std::cout << "    타이틀 화면 ㄱ?(Y/N)                     *\n";
    return 0;
}

void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int print_game_start() {
    int i, j;
    for (i = 1; i <= weight; i++) {
        for (j = 1; j <= height; j++) {
            if (i == 1 || i == weight || j == 1 || j == height) {
                gotoxy(j * 2, i);
                std::cout << "* ";
            }
            else {
                std::cout << "  ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}

int main() {
    int game_state = 0;
    int game_run = 1;

    while (game_run) {
        char key_input = '0';
        switch (game_state) {
        case 0:
            print_title_screen();
            key_input = _getch();
            while (key_input != '1' && key_input != '2' && key_input != '3' && key_input != '4' && key_input != 27) {
                key_input = _getch();
            }
            if (key_input == '1')
                game_state = 1;
            else if (key_input == '2')
                game_state = 2;
            else if (key_input == '4' || key_input == 27)
                game_run = 0;
            break;
        case 1:
            system("cls");
            print_game_start();
            std::cout << "esc를 누르면 타이틀 화면으로 돌아갑니다.\n";
            key_input = _getch();
            while (key_input != 27) {
                key_input = _getch();
            }
            if (key_input == 27)
                game_state = 0;
                break;
        case 2:
            print_introduction_screen();
            key_input = 0;
            while (key_input != 'y' && key_input != 'Y') {
                key_input = _getch();
            }
            if (key_input == 'y' || key_input == 'Y')
                game_state = 0;
            break;
        default:
            break;
        }
    }
    return 0;
}

