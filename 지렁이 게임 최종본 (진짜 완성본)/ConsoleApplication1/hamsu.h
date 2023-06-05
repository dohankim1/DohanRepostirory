#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>

int weight = 20;
int height = 20;
char LastKey;
void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printSquare(char c) {
    for (int i = 0; i < 2; i++) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}

int print_title_screen() {
    std::cout << "**********************************************\n";
    std::cout << "*                                            *\n";
    std::cout << "*                                            *\n";
    std::cout << "*                ������ ����                 *\n";
    std::cout << "*               (Snake  Bite)                *\n";
    std::cout << "*                                            *\n";
    std::cout << "*                                            *\n";
    std::cout << "*   1.���� ����                              *\n";
    std::cout << "*   2.���� ����                              *\n";
    std::cout << "*   3.���� ���� (esc)                        *\n";
    std::cout << "**********************************************\n";
    return 0;
}

int print_introduction_screen() {
    std::cout << "************************************************\n";
    std::cout << "    ���� ���� ȭ���Դϴ�.                      *\n";
    std::cout << "    �����̰� ���� ������ ������ �����ϴ�.      *\n";
    std::cout << "    �����̰� ���� ������ 100~400���� �����ϴ�. *\n";
    std::cout << "************************************************\n";
    std::cout << "    Ÿ��Ʋ ȭ������ ���ư��ڽ��ϱ�?(Y/N)       *\n";
    return 0;
}

