#include <iostream>
#include <conio.h>
#include <Windows.h>
int weghit = 5;
int heghit = 5;

int print_title_sceern() {
    std::cout << "**********************************************\n";
    std::cout << "*                                            *\n";
    std::cout << "*                                            *\n";
    std::cout << "*                ������ ����                 *\n";
    std::cout << "*               (Snake  Bite)                *\n";
    std::cout << "*                                            *\n";
    std::cout << "*                                            *\n";

    std::cout << "*   1.���� ����                              *\n";
    std::cout << "*   2.���� ����                              *\n";
    std::cout << "*   3.���� ��ŷ ����                         *\n";
    std::cout << "*   4.���� ���� (esc)                        *\n";
    std::cout << "**********************************************\n";
    return 0;
}
int print_introductiom_screep() {
    std::cout << "**********************************************\n";
    std::cout << "    ���� ���� ȭ���Դϴ�.                    *\n";
    std::cout << "    ������ ������ Ŭ����?                    *\n";
    std::cout << "    �ô�� �ָ� �ָ� �����Ѵ�?.              *\n";
    std::cout << "**********************************************\n";
    std::cout << "    Ÿ��Ʋ ȭ�� ��?(Y/N)                     *\n";
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
    while (1) { // ���� ������ ���ϴ�.
        if (_kbhit()) {
            key_input = _getch();
            if (key_input == 27) { // ESC Ű�� �Է¹޾��� ���
                break; // ���� ������ ���������ϴ�.
            }
        }
    }
    return 0;
}
int main() {
    int game_state = 0;
    int game_run = 1;
    print_title_sceern(); // ó���� Ÿ��Ʋ ȭ�� ���

    while (game_run) {
        char key_input = '0';
        switch (game_state) {
        case 0:
            key_input = _getch();
            if (key_input == '2') {
                game_state = 2;
            }
            else if (key_input == '1') {
                system("cls"); // ȭ���� �����
                print_game_start(); // ���� ȭ�� ���
                game_state = 1;
            }
            else if (key_input == '4' || key_input == 27) {
                game_run = 0;
            }
            break;
        case 1:
            // ���� ���� ���� ��� ���⿡ �ڵ带 �߰��� �� �ֽ��ϴ�.
            // ESC Ű�� ������ ���� ���� �� Ÿ��Ʋ ȭ������ ���ư��ϴ�.
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