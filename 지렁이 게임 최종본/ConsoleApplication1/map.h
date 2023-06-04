#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#define WIDTH 30
#define HEIGHT 20
extern int gameloop1;
bool gameOverFlag = false;
int snakeX[100], snakeY[100]; // 지렁이의 몸체 좌표
int snakeLength = 1; // 지렁이의 초기 길이
int direction = 0; // 지렁이의 이동 방향

int map[HEIGHT][WIDTH]; 
bool starExists = false;
int starX, starY;
int score = 0;
void setup()// 맵초기화
{
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;

 
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1)
                map[y][x] = 1; 
            else
                map[y][x] = 0; 
        }
    }
}
void generateStar() //별 생성
{
    if (starExists) {
        return;  
    }

    
    do {
       
        starX = rand() % (WIDTH - 2) + 1;  
        starY = rand() % (HEIGHT - 2) + 1;
    } while (map[starY][starX] != 0);  

    map[starY][starX] = 3; 
    starExists = true;  
}
void draw()
{
    system("cls"); 

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (y == 0 || y == HEIGHT - 1)
            {
                gotoxy(x, y);
                printf("■■"); // 상단과 하단 벽 출력
            }
            else
            {
                if (x == 0 || x == WIDTH - 1)
                {
                    gotoxy(x, y);
                    printf("■"); // 왼쪽과 오른쪽 벽 출력
                }
                else
                {
                    int isSnakeBody = 0;
                    for (int i = 0; i < snakeLength; i++)
                    {
                        if (snakeX[i] == x && snakeY[i] == y)
                        {
                            if (i == 0)
                            {
                                gotoxy(x, y);
                                printf("●"); // 머리 출력
                            }
                            else
                            {
                                gotoxy(x, y);
                                printf("■"); // 몸체 출력
                            }
                            isSnakeBody = 1;
                            break;
                        }
                    }

                    if (!isSnakeBody)
                    {
                        if (map[y][x] == 1)
                        {
                            gotoxy(x, y);
                            printf("□"); // 맵의 벽 출력
                        }
                        else if (map[y][x] == 3)
                        {
                            gotoxy(x, y);
                            printf("★"); // 별 출력
                        }
                        else
                        {
                            gotoxy(x, y);
                            printf(" "); // 빈 공간 출력
                        }
                    }
                }
            }
        }
    }

    generateStar(); // 별 생성
    gotoxy(50, 25);
    printf("%d",score);
}
void input()// 이동해라 지렁지렁
{
    if (_kbhit()) // 키 입력 확인
    {
        switch (_getch())
        {
        case 'w':
            direction = 0; // 위쪽으로 이동
            break;
        case 's':
            direction = 1; // 아래쪽으로 이동
            break;
        case 'a':
            direction = 2; // 왼쪽으로 이동
            break;
        case 'd':
            direction = 3; // 오른쪽으로 이동
            break;
        }
    }
}

void logic()
{
    // 맵에 있는 지렁이 몸체 제거
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (map[y][x] == 2)
                map[y][x] = 0;
        }
    }

    // 지렁이의 몸체 이동
    for (int i = snakeLength - 1; i > 0; i--)
    {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    // 지렁이의 머리 이동
    switch (direction)
    {
    case 0:
        snakeY[0]--; 
        break;
    case 1:
        snakeY[0]++; 
        break;
    case 2:
        snakeX[0]--; 
        break;
    case 3:
        snakeX[0]++; 
        break;
    }

    // 맵에 지렁이 몸체 표시
    for (int i = 0; i < snakeLength; i++)
    {
        map[snakeY[i]][snakeX[i]] = 2;
    }
}
void initialize() // 초기화
{
    snakeLength = 1;
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;
}
void gameOver()//게임 오버 함수 종료 할것인가 다시 시작할것인가 정함.
{
    system("cls"); 
    gotoxy(25, 15);
    printf("Game Over\n");

    gotoxy(25, 18);
    printf("당신의 점수 는 :%d ", score);
    if (score <= 500) {
        printf("좀 더 노력합시다.");
    }
    else if (score <= 1000) {
        printf("제법이군요");
    }
    else if (score <= 2000) {
        printf("잘하시는군요!");
    }
    else if (score <= 5000) {
        printf("굉장하세요!");
    }
    else if (score < 7600) {
        printf("완전 짱!!");
    }
    else if (score <= 7700) {
        printf("행운의 77");
    }
    else {
        printf("지렁이 게임 고여버렸다. ㄷㄷ ");
    }
    gotoxy(25, 21);
    printf("R을 누르면 재시작 Esc를 누르면 종료됩니다..\n");

    _flushall(); 

    int key = _getch();
    while (key != 'r' && key != 'R' && key != 27) {
        while (_kbhit()) {
            _getch(); // 
        }
        key = _getch();
    }

    if (key == 'r' || key == 'R')
    {
        score = 0;
        initialize(); 
        gameloop1 = 1; 
        gameOverFlag = false; 
    }
    else if (key == 27) 
    {
        gameloop1 = 0; 
        exit(0);
    }
}
void increaseSnakeLength()//길어져라 지렁지렁
{
  
    snakeLength++;
}
void checkCollision()// 벽,몸통,별과의 충돌 처리
{
    // 벽과 충돌 체크
    if (snakeX[0] == 0 || snakeX[0] == WIDTH - 1 || snakeY[0] == 0 || snakeY[0] == HEIGHT - 1)
    {
        gameOverFlag = true; 
    }

   
    for (int i = 1; i < snakeLength; i++)
    {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
        {
            gameOverFlag = true; 
        }
    }

    if (snakeX[0] == starX && snakeY[0] == starY)
    {
        int randomNumber = rand() % 4 + 1;
        score = score + randomNumber * 100;
        increaseSnakeLength();
        
        starExists = false; 
    }
}
