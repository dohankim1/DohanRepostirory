#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>


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
    std::cout << "******************************************************\n";
    std::cout << "*   ���� ���� ȭ���Դϴ�.                            *\n";
    std::cout << "*   �����̰� ���� ������ ������ �����ϴ�.            *\n";
    std::cout << "*   �����̰� ���� ������ 100~400���� �����ϴ�.       *\n";
    std::cout << "*   �����̰� ��Ʈ�� ������ �������� ������ �����ϴ�. *\n";
    std::cout << "*   300,500,700���� �� �����ϰ� �����ϴ�.            *\n";
    std::cout << "*   Ȥ�� ������ 0���� �� ���� ����.                  *\n";
    std::cout << "******************************************************\n";
    std::cout << "    Ÿ��Ʋ ȭ������ ���ư��ڽ��ϱ�?(Y/N)             *\n";
    return 0;
}

