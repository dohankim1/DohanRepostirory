#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#define WIDTH 30
#define HEIGHT 20

extern int gameloop1; //mainhamsu�� gameloop1�� ������

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
struct Coordinat
{
    int heartX, heartY; // ��Ʈ ��ǥ
    int starX, starY;   // �� ��ǥ
    int map[HEIGHT][WIDTH]; // �� ����
    bool heartExists = false;
    bool starExists = false;
    bool gameOverFlag = false;
    int score;
};

struct startsnake
{
    int snakeX[100], snakeY[100]; // �������� ��ü ��ǥ
    int snakeLength = 1; // �������� �ʱ� ����
    int direction; // �������� �̵� ����
};






void hideCursor() {//Ŀ�� ����� �뵵
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
void setup(struct Coordinat& coord, struct startsnake& snake)//���� ���� ���� ������ ��� ��ȯ
{
    hideCursor();
    snake.snakeX[0] = WIDTH / 2;
    snake.snakeY[0] = HEIGHT / 2;

}

void generteHeart(struct Coordinat& coord) {//��Ʈ�� �����ϴ� �뵵
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

void generateStar(struct Coordinat& coord) {//���� �����ϴ� �뵵
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


void draw(struct Coordinat& coord, struct startsnake& snake)//ȭ�� ����ϴ� ��
{
    coord.gameOverFlag = false;
    hideCursor();

    // ���� ��ü�� ����� ���� Ŀ���� �� ���� ���� �̵�
    gotoxy(0, 0);
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1)
            {
                printf("��"); // ���� �����ڸ��� �� ���
            }
            else
            {
                int isSnakeBody = 0;

                // �Ӹ��� ���� üũ
                for (int i = 0; i < snake.snakeLength; i++)
                {
                    if (snake.snakeX[i] == x && snake.snakeY[i] == y)
                    {
                        if (i == 0)
                        {
                            printf("��"); // �Ӹ� ���
                        }
                        else
                        {
                            printf("��"); // ��ü ���
                        }
                        isSnakeBody = 1;
                        break;
                    }
                }

                if (!isSnakeBody)
                {
                    if (coord.map[y][x] == 3)
                    {
                        printf("��"); // �� ���
                    }
                    else if (coord.map[y][x] == 4)
                    {
                        printf("��"); // ��Ʈ ���
                    }
                    else
                    {
                        printf("��"); // �� ���� ���
                    }
                }
            }
        }

        printf("\n");
    }

    // ���� ���
    int thousands = coord.score / 1000;

    // ���� �ڸ� ���� ���
    int hundreds = (coord.score % 1000) / 100;

    // ���� �ڸ��� ���� �ڸ� ���� ���
    int units = (coord.score % 100) / 10;
    int tens = coord.score % 10;
    gotoxy(0, HEIGHT);
    printf("���� ���� : %d%d%d%d", thousands, hundreds, units, tens);
    if (!coord.starExists)
    {
        generateStar(coord); // ���� ���� ��� �� ����
    }
    if(!coord.heartExists)
    {
        generteHeart(coord); // ��Ʈ�� ���� ��� ��Ʈ ����
    }

    // Ŀ�� ��ġ�� �̵����� �ʵ��� �ϱ� ���� ����
    hideCursor();
}
void input(struct startsnake& snake)// �������� �̵����� ���
{
    if (_kbhit()) // Ű �Է� Ȯ��
    {
        switch (_getch())
        {
        case 'w':
            snake.direction = 0; // �������� �̵�
            break;
        case 's':
            snake.direction = 1; // �Ʒ������� �̵�
            break;
        case 'a':
            snake.direction = 2; // �������� �̵�
            break;
        case 'd':
            snake.direction = 3; // ���������� �̵�
            break;
        }
    }
}

void logic(struct Coordinat& coord, struct startsnake& snake)//������ ��ü �Ӹ� �� �̵��� �������ִ� �Լ�
{
    // �ʿ� �ִ� ������ ��ü ����
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (coord.map[y][x] == 2)
                coord.map[y][x] = 0;
        }
    }

    // �������� ��ü �̵�
    for (int i = snake.snakeLength - 1; i > 0; i--)
    {
        snake.snakeX[i] = snake.snakeX[i - 1];
        snake.snakeY[i] = snake.snakeY[i - 1];
    }

    // �������� �Ӹ� �̵�
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

    // �ʿ� ������ ��ü ǥ��
    for (int i = 0; i < snake.snakeLength; i++)
    {
        coord.map[snake.snakeY[i]][snake.snakeX[i]] = 2;
    }
}

void initialize(struct startsnake& snake) // �ʱ�ȭ
{
    snake.snakeLength = 1;
    snake.snakeX[0] = WIDTH / 2;
    snake.snakeY[0] = HEIGHT / 2;
}

void gameOver(struct Coordinat& coord, struct startsnake& snake)//���� ���� �Լ� ���� �Ұ��ΰ� �ٽ� �����Ұ��ΰ� ����.
{
    system("cls"); 
    gotoxy(25, 15);
    printf("Game Over\n");

    gotoxy(25, 18);
    printf("����� ���� �� :%d ", coord.score);
    if (coord.score <= 500) {
        printf("�� �� ����սô�.");
    }
    else if (coord.score == 0) {
        printf("Ȥ�� ��Ʈ�� �Դٴ� 0���� �Ǽ̳���? �׷��ٸ� ���ϵ帳��!! ���̿���! �װ� �ƴϸ�... ����..");
    }
    else if (coord.score <= 1000) {
        printf("�����̱���");
    }
    else if (coord.score <= 2000) {
        printf("���Ͻô±���!");
    }
    else if (coord.score <= 5000) {
        printf("�����ϼ���!");
    }
    else if (coord.score < 7600) {
        printf("���� ¯!!");
    }
    else if (coord.score <= 7700) {
        printf("����� 77");
    }
    else {
        printf("������ ���� �����ȴ�. ���� ");
    }
    gotoxy(25, 21);
    printf("R�� ������ ����� Esc�� ������ ����˴ϴ�..\n");

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
void increaseSnakeLength(struct startsnake& snake)//������� ��������
{
    snake.snakeLength++;
}
void checkCollision(struct Coordinat& coord, struct startsnake& snake)// ��,����,������ �浹 ó��
{
    // ���� �浹 üũ
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
        if(random == 4) {
            coord.score = coord.score + 700;
            snake.snakeLength++;
        }
        coord.heartExists = false;
        generteHeart(coord);
        
    }
}
