
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "helpfile.h"


void Start() {
    
    print_title_screen();
}

void Update() {
   
    char key_input = '0';
    key_input = _getch();
    while (key_input != '1' && key_input != '2' && key_input != '3' && key_input != '4' && key_input != 27) {
        key_input = _getch();
    }
    if (key_input == '1')
    {
        system("cls");
        print_game_start();
    }
    else if (key_input == '2') { 
        system("cls");
        print_introduction_screen(); }
    else if (key_input == '3')
    { 
        system("cls");
        print_introduction_screen(); }
    else if (key_input == '4') {
        printf("게임을 종료합니다."); exit(0);
    }
    else if (key_input == 27) {
        printf("게임을 종료합니다."); exit(0);
    }
}

int main() {
    
    Start();

   
    while (true) {
        
        Update();

        
       
    }

    return 0;
}