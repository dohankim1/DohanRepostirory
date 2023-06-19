#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>


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
    std::cout << "******************************************************\n";
    std::cout << "*   게임 설명 화면입니다.                            *\n";
    std::cout << "*   지렁이가 별을 먹으면 점수가 오릅니다.            *\n";
    std::cout << "*   지렁이가 별을 먹을때 100~400점이 오릅니다.       *\n";
    std::cout << "*   지렁이가 하트를 먹을때 랜덤으로 점수가 오릅니다. *\n";
    std::cout << "*   300,500,700점이 이 랜덤하게 오릅니다.            *\n";
    std::cout << "*   혹은 점수가 0점이 될 수도 있죠.                  *\n";
    std::cout << "******************************************************\n";
    std::cout << "    타이틀 화면으로 돌아가겠습니까?(Y/N)             *\n";
    return 0;
}

