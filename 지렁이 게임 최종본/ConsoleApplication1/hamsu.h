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
    std::cout << "*                지렁이 게임                 *\n";
    std::cout << "*               (Snake  Bite)                *\n";
    std::cout << "*                                            *\n";
    std::cout << "*                                            *\n";
    std::cout << "*   1.게임 시작                              *\n";
    std::cout << "*   2.게임 설명                              *\n";
    std::cout << "*   3.게임 종료 (esc)                        *\n";
    std::cout << "**********************************************\n";
    return 0;
}

int print_introduction_screen() {
    std::cout << "************************************************\n";
    std::cout << "    게임 설명 화면입니다.                      *\n";
    std::cout << "    지렁이가 별을 먹으면 점수가 오릅니다.      *\n";
    std::cout << "    지렁이가 별을 먹을때 100~400점이 오릅니다. *\n";
    std::cout << "************************************************\n";
    std::cout << "    타이틀 화면으로 돌아가겠습니까?(Y/N)       *\n";
    return 0;
}

