#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#define WIDTH 30
#define HEIGHT 20
<<<<<<< HEAD

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
=======
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
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
<<<<<<< HEAD
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
=======
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
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
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
<<<<<<< HEAD
                for (int i = 0; i < snake.snakeLength; i++)
                {
                    if (snake.snakeX[i] == x && snake.snakeY[i] == y)
=======
                for (int i = 0; i < snakeLength; i++)
                {
                    if (snakeX[i] == x && snakeY[i] == y)
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
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
<<<<<<< HEAD
                    if (coord.map[y][x] == 3)
                    {
                        printf("��"); // �� ���
                    }
                    else if (coord.map[y][x] == 4)
                    {
                        printf("��"); // ��Ʈ ���
                    }
=======
                    if (map[y][x] == 3)
                    {
                        printf("��"); // �� ���
                    }
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
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
<<<<<<< HEAD
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
=======
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
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
{
    if (_kbhit()) // Ű �Է� Ȯ��
    {
        switch (_getch())
        {
        case 'w':
<<<<<<< HEAD
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
=======
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
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
            break;
        }
    }
}

<<<<<<< HEAD
void logic(struct Coordinat& coord, struct startsnake& snake)//������ ��ü �Ӹ� �� �̵��� �������ִ� �Լ�
=======
void logic()
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
{
    // �ʿ� �ִ� ������ ��ü ����
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
<<<<<<< HEAD
            if (coord.map[y][x] == 2)
                coord.map[y][x] = 0;
=======
            if (map[y][x] == 2)
                map[y][x] = 0;
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
        }
    }

    // �������� ��ü �̵�
<<<<<<< HEAD
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
=======
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
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
        break;
    }

    // �ʿ� ������ ��ü ǥ��
<<<<<<< HEAD
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
=======
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
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
{
    system("cls"); 
    gotoxy(25, 15);
    printf("Game Over\n");

    gotoxy(25, 18);
<<<<<<< HEAD
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
=======
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
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
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
<<<<<<< HEAD
        coord.score = 0;
        initialize(snake);
       
        gameloop1 = 1; 
        coord.gameOverFlag = false; 
=======
        score = 0;
        initialize(); 
        gameloop1 = 1; 
        gameOverFlag = false; 
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
    }
    else if (key == 27) 
    {
        gameloop1 = 0; 
        exit(0);
    }
}
<<<<<<< HEAD
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
        
=======
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
>>>>>>> 03eb67e6854e3454602aa453f4dd9f7fab8fd127
    }
}
