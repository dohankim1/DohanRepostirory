#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#define WIDTH 30
#define HEIGHT 20
extern int gameloop1; // 없으면 안돌아감..
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
struct Coordinat
{
    int heartX, heartY; // 하트 좌표
    int starX, starY;   // 별 좌표
    int map[HEIGHT][WIDTH]; // 맵 넓이
    bool heartExists = false;
    bool starExists = false;
    bool gameOverFlag = false;
    int score;
};

struct startsnake
{
    int snakeX[100], snakeY[100]; // 지렁이의 몸체 좌표
    int snakeLength = 1; // 지렁이의 초기 길이
    int direction; // 지렁이의 이동 방향
};






void hideCursor() {//커서 숨기는 용도
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
void setup(struct Coordinat& coord, struct startsnake& snake)//게임 시작 설정 지렁이 가운데 소환
{
    hideCursor();
    snake.snakeX[0] = WIDTH / 2;
    snake.snakeY[0] = HEIGHT / 2;

}

void generteHeart(struct Coordinat& coord) {//하트를 생성하는 용도
    if (coord.heartExists) {
        return;
    }
    do {
        coord.heartX = rand() % (WIDTH - 2) + 1;
        coord.heartY = rand() % (HEIGHT - 2) + 1;
    } while (coord.map[coord.heartY][coord.heartX] != 0);
    coord.map[coord.heartY][coord.heartX] = 4;
    coord.heartExists = true;
}

void generateStar(struct Coordinat& coord) {//별을 생성하는 용도
    if (coord.starExists) {
        return;
    }
    do {
        coord.starX = rand() % (WIDTH - 2) + 1;
        coord.starY = rand() % (HEIGHT - 2) + 1;
    } while (coord.map[coord.starY][coord.starX] != 0);
    coord.map[coord.starY][coord.starX] = 3;
    coord.starExists = true;
}


void draw(struct Coordinat& coord, struct startsnake& snake)//화면 출력하는 곳
{
    coord.gameOverFlag = false;
    hideCursor();

    // 맵의 전체를 지우기 위해 커서를 맨 왼쪽 위로 이동
    gotoxy(0, 0);
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1)
            {
                printf("■"); // 맵의 가장자리에 벽 출력
            }
            else
            {
                int isSnakeBody = 0;

                // 머리와 몸통 체크
                for (int i = 0; i < snake.snakeLength; i++)
                {
                    if (snake.snakeX[i] == x && snake.snakeY[i] == y)
                    {
                        if (i == 0)
                        {
                            printf("●"); // 머리 출력
                        }
                        else
                        {
                            printf("⊙"); // 몸체 출력
                        }
                        isSnakeBody = 1;
                        break;
                    }
                }

                if (!isSnakeBody)
                {
                    if (coord.map[y][x] == 3)
                    {
                        printf("★"); // 별 출력
                    }
                    else if (coord.map[y][x] == 4)
                    {
                        printf("♥"); // 하트 출력
                    }
                    else
                    {
                        printf("ㅤ"); // 빈 공간 출력
                    }
                }
            }
        }

        printf("\n");
    }

    // 점수 출력
    int thousands = coord.score / 1000;

    // 백의 자리 숫자 계산
    int hundreds = (coord.score % 1000) / 100;

    // 일의 자리와 십의 자리 숫자 계산
    int units = (coord.score % 100) / 10;
    int tens = coord.score % 10;
    gotoxy(0, HEIGHT);
    printf("현재 점수 : %d%d%d%d", thousands, hundreds, units, tens);
    if (!coord.starExists)
    {
        generateStar(coord); // 별이 없을 경우 별 생성
    }
    if (!coord.heartExists)
    {
        generteHeart(coord); // 하트가 없을 경우 하트 생성
    }

    // 커서 위치를 이동하지 않도록 하기 위해 숨김
    hideCursor();
}
void input(struct startsnake& snake)// 지렁이의 이동방향 담당
{
    if (_kbhit()) // 키 입력 확인
    {
        switch (_getch())
        {
        case 'w':
            snake.direction = 0; // 위쪽으로 이동
            break;
        case 's':
            snake.direction = 1; // 아래쪽으로 이동
            break;
        case 'a':
            snake.direction = 2; // 왼쪽으로 이동
            break;
        case 'd':
            snake.direction = 3; // 오른쪽으로 이동
            break;
        }
    }
}

void logic(struct Coordinat& coord, struct startsnake& snake)//지렁이 몸체 머리 를 이동및 갱신해주는 함수
{
    // 맵에 있는 지렁이 몸체 제거
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (coord.map[y][x] == 2)
                coord.map[y][x] = 0;
        }
    }

    // 지렁이의 몸체 이동
    for (int i = snake.snakeLength - 1; i > 0; i--)
    {
        snake.snakeX[i] = snake.snakeX[i - 1];
        snake.snakeY[i] = snake.snakeY[i - 1];
    }

    // 지렁이의 머리 이동
    switch (snake.direction)
    {
    case 0:
        snake.snakeY[0]--;
        break;
    case 1:
        snake.snakeY[0]++;
        break;
    case 2:
        snake.snakeX[0]--;
        break;
    case 3:
        snake.snakeX[0]++;
        break;
    }

    // 맵에 지렁이 몸체 표시
    for (int i = 0; i < snake.snakeLength; i++)
    {
        coord.map[snake.snakeY[i]][snake.snakeX[i]] = 2;
    }
}

void initialize(struct startsnake& snake) // 초기화
{
    snake.snakeLength = 1;
    snake.snakeX[0] = WIDTH / 2;
    snake.snakeY[0] = HEIGHT / 2;
}

void gameOver(struct Coordinat& coord, struct startsnake& snake)//게임 오버 함수 종료 할것인가 다시 시작할것인가 정함.
{
    system("cls");
    gotoxy(25, 15);
    printf("Game Over\n");

    gotoxy(25, 18);
    printf("당신의 점수 는 :%d ", coord.score);
    if (coord.score <= 500) {
        printf("좀 더 노력합시다.");
    }
    else if (coord.score == 0) {
        printf("혹시 하트를 먹다다 0점이 되셨나요? 그렇다면 축하드립다!! 꽝이예요! 그게 아니면... 쓰흡..");
    }
    else if (coord.score <= 1000) {
        printf("제법이군요");
    }
    else if (coord.score <= 2000) {
        printf("잘하시는군요!");
    }
    else if (coord.score <= 5000) {
        printf("굉장하세요!");
    }
    else if (coord.score < 7600) {
        printf("완전 짱!!");
    }
    else if (coord.score <= 7700) {
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
        system("cls");
        coord.score = 0;
        initialize(snake);

        gameloop1 = 1;
        coord.gameOverFlag = false;
    }
    else if (key == 27)
    {
        gameloop1 = 0;
        exit(0);
    }
}
void increaseSnakeLength(struct startsnake& snake)//길어져라 지렁지렁
{

    snake.snakeLength++;
}
void checkCollision(struct Coordinat& coord, struct startsnake& snake)// 벽,몸통,별과의 충돌 처리
{
    // 벽과 충돌 체크
    if (snake.snakeX[0] == 0 || snake.snakeX[0] == WIDTH - 1 || snake.snakeY[0] == 0 || snake.snakeY[0] == HEIGHT - 1)
    {
        coord.gameOverFlag = true;
    }


    for (int i = 1; i < snake.snakeLength; i++)
    {
        if (snake.snakeX[0] == snake.snakeX[i] && snake.snakeY[0] == snake.snakeY[i])
        {
            coord.gameOverFlag = true;
        }
    }

    if (snake.snakeX[0] == coord.starX && snake.snakeY[0] == coord.starY)
    {
        int randomNumber = rand() % 4 + 1;
        coord.score = coord.score + randomNumber * 100;
        increaseSnakeLength(snake);

        coord.starExists = false;
    }
    if (snake.snakeX[0] == coord.heartX && snake.snakeY[0] == coord.heartY) {
        int random = rand() % 4 + 1;
        if (random == 1) {
            snake.snakeLength = 1;
            coord.score = 0;
        }
        if (random == 2) {
            coord.score = coord.score + 300;
            snake.snakeLength++;
        }
        if (random == 3) {
            coord.score = coord.score + 500;
            snake.snakeLength++;
        }
        if (random == 4) {
            coord.score = coord.score + 700;
            snake.snakeLength++;
        }
        coord.heartExists = false;
        generteHeart(coord);

    }
}