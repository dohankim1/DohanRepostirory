#include <iostream>
#include <conio.h>
#include <Windows.h>
int weghit = 5;
int heghit = 5;

int print_title_sceern() {
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
int print_introductiom_screep() {
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
    for (i = 1; i <= weghit; i++) {
        for (j = 1; j <= heghit; j++) {
            if (i == 1 || i == weghit || j == 1 || j == heghit) {
                gotoxy(j * 2, i);
                printf("*");
            }
        }
    }
    char key_input = '0';
    while (1) { // 무한 루프를 돕니다.
        if (_kbhit()) {
            key_input = _getch();
            if (key_input == 27) { // ESC 키를 입력받았을 경우
                break; // 무한 루프를 빠져나갑니다.
            }
        }
    }
    return 0;
}
int main() {
    int game_state = 0;
    int game_run = 1;
    print_title_sceern(); // 처음에 타이틀 화면 출력

    while (game_run) {
        char key_input = '0';
        switch (game_state) {
        case 0:
            key_input = _getch();
            if (key_input == '2') {
                game_state = 2;
            }
            else if (key_input == '1') {
                system("cls"); // 화면을 지우고
                print_game_start(); // 게임 화면 출력
                game_state = 1;
            }
            else if (key_input == '4' || key_input == 27) {
                game_run = 0;
            }
            break;
        case 1:
            // 게임 진행 중인 경우 여기에 코드를 추가할 수 있습니다.
            // ESC 키를 누르면 게임 종료 후 타이틀 화면으로 돌아갑니다.
            if (_kbhit() && _getch() == 27) {
                game_state = 0;
            }
            break;
        case 2:
            print_introductiom_screep();
            key_input = _getch();
            if (key_input == 'y' || key_input == 'Y') {
                game_state = 0;
            }
            break;
        default:
            break;
        }
    }

    return 0;
}