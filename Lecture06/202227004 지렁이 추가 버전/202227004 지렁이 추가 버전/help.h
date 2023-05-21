#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>

#define KEY_ESC 27
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_ENTER 13
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#define ANSI_COLOR_LIGHTGRAY "\x1b[37m"
#define ANSI_COLOR_DARKGRAY "\x1b[90m"
int weight = 20;
int height = 20;
char LastKey;
void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void KeyEvent(char KeyInput) {
    if (KeyInput == KEY_ESC) {
        LastKey = 0; // ������ Ű�� �ʱ�ȭ
        system("cls");
        gotoxy(3, 10);
        std::cout << ANSI_COLOR_RESET"������ �����Ͻðڽ��ϱ�?(��/�ƴϿ�)" << std::endl;
    }
    else if (LastKey != KEY_ESC) { // ESC�� �������� �ʾ��� ������ ����
        switch (KeyInput) {
        case KEY_LEFT:
            LastKey = KEY_LEFT;
            system("cls");
            gotoxy(10, 10);
            std::cout << "������ �����Ͻðڽ��ϱ�?";
            gotoxy(40, 10);
            std::cout << ANSI_COLOR_YELLOW << "��" << ANSI_COLOR_RESET;
            gotoxy(42, 10);
            std::cout << "//";
            gotoxy(42, 10);
            std::cout << ANSI_COLOR_DARKGRAY << "�ƴϿ�" << ANSI_COLOR_RESET;
            break;
        case KEY_RIGHT:
            system("cls");
            gotoxy(10, 10);
            std::cout << "������ �����Ͻðڽ��ϱ�?";
            gotoxy(40, 10);
            std::cout << ANSI_COLOR_DARKGRAY << "��" << ANSI_COLOR_RESET;
            gotoxy(42, 10);
            std::cout << ANSI_COLOR_YELLOW << "�ƴϿ�" << ANSI_COLOR_RESET;
            break;
        case KEY_ENTER:
            if (LastKey == KEY_LEFT) {
                gotoxy(3, 24);
                system("cls");
                std::cout << ANSI_COLOR_RESET"������ �����մϴ�." << std::endl;
                print_title_screen();
            }
            else if (LastKey == KEY_RIGHT) {
                system("cls");
                print_game_start();
            }
            // ������ Ű�� �ʱ�ȭ
            LastKey = 0;
            break;
        default:
            break;
        }
    }
}