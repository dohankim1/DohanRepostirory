#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#define WIDTH 30
#define HEIGHT 20
extern int gameloop1;
bool gameOverFlag = false;
int snakeX[100], snakeY[100]; // �������� ��ü ��ǥ
int snakeLength = 1; // �������� �ʱ� ����
int direction = 0; // �������� �̵� ����

int map[HEIGHT][WIDTH]; 
bool starExists = false;
int starX, starY;
int score = 0;
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
void generateStar() //�� ����
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
void setup()
{
    hideCursor();
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1)
                map[y][x] = 1; // ���� �����ڸ��� �� ����
            else
                map[y][x] = 0; // ������ ������ �� ����
        }
    }
    generateStar();
}

void draw()
{
    gameOverFlag = false;
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
                for (int i = 0; i < snakeLength; i++)
                {
                    if (snakeX[i] == x && snakeY[i] == y)
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
                    if (map[y][x] == 3)
                    {
                        printf("��"); // �� ���
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
    gotoxy(0, HEIGHT);
    printf("���� ���� : %d", score);
    if (!starExists)
    {
        generateStar(); // ���� ���� ��� �� ����
    }
    // Ŀ�� ��ġ�� �̵����� �ʵ��� �ϱ� ���� ����
    hideCursor();
}
void input()// �̵��ض� ��������
{
    if (_kbhit()) // Ű �Է� Ȯ��
    {
        switch (_getch())
        {
        case 'w':
            direction = 0; // �������� �̵�
            break;
        case 's':
            direction = 1; // �Ʒ������� �̵�
            break;
        case 'a':
            direction = 2; // �������� �̵�
            break;
        case 'd':
            direction = 3; // ���������� �̵�
            break;
        }
    }
}

void logic()
{
    // �ʿ� �ִ� ������ ��ü ����
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (map[y][x] == 2)
                map[y][x] = 0;
        }
    }

    // �������� ��ü �̵�
    for (int i = snakeLength - 1; i > 0; i--)
    {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    // �������� �Ӹ� �̵�
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

    // �ʿ� ������ ��ü ǥ��
    for (int i = 0; i < snakeLength; i++)
    {
        map[snakeY[i]][snakeX[i]] = 2;
    }
}
void initialize() // �ʱ�ȭ
{
    snakeLength = 1;
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;
}
void gameOver()//���� ���� �Լ� ���� �Ұ��ΰ� �ٽ� �����Ұ��ΰ� ����.
{
    system("cls"); 
    gotoxy(25, 15);
    printf("Game Over\n");

    gotoxy(25, 18);
    printf("����� ���� �� :%d ", score);
    if (score <= 500) {
        printf("�� �� ����սô�.");
    }
    else if (score <= 1000) {
        printf("�����̱���");
    }
    else if (score <= 2000) {
        printf("���Ͻô±���!");
    }
    else if (score <= 5000) {
        printf("�����ϼ���!");
    }
    else if (score < 7600) {
        printf("���� ¯!!");
    }
    else if (score <= 7700) {
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
void increaseSnakeLength()//������� ��������
{
  
    snakeLength++;
}
void checkCollision()// ��,����,������ �浹 ó��
{
    // ���� �浹 üũ
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
