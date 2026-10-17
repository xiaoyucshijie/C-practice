#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

typedef struct {
    int x;
    int y;
} Point;

Point snake[100];
int snakeLen;
Point food;
int score;
int gameOver;
int direction; // 1:up 2:down 3:left 4:right

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawBorder()
{
    int i;
    for (i = 0; i < WIDTH; i++)
    {
        gotoxy(i, 0);
        printf("#");
        gotoxy(i, HEIGHT - 1);
        printf("#");
    }
    for (i = 0; i < HEIGHT; i++)
    {
        gotoxy(0, i);
        printf("#");
        gotoxy(WIDTH - 1, i);
        printf("#");
    }
}

void initGame()
{
    snakeLen = 3;
    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;
    snake[1].x = snake[0].x - 1;
    snake[1].y = snake[0].y;
    snake[2].x = snake[0].x - 2;
    snake[2].y = snake[0].y;
    direction = 4;
    score = 0;
    gameOver = 0;
    srand((unsigned int)time(NULL));
}

void spawnFood()
{
    int i, onSnake;
    while (1)
    {
        food.x = rand() % (WIDTH - 2) + 1;
        food.y = rand() % (HEIGHT - 2) + 1;
        onSnake = 0;
        for (i = 0; i < snakeLen; i++)
        {
            if (snake[i].x == food.x && snake[i].y == food.y)
            {
                onSnake = 1;
                break;
            }
        }
        if (!onSnake)
            break;
    }
}

void drawGame()
{
    int i;
    gotoxy(food.x, food.y);
    printf("*");
    for (i = 0; i < snakeLen; i++)
    {
        gotoxy(snake[i].x, snake[i].y);
        if (i == 0)
            printf("@");
        else
            printf("o");
    }
    gotoxy(0, HEIGHT);
    printf("Score: %d", score);
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 72:
            if (direction != 2) direction = 1;
            break;
        case 80:
            if (direction != 1) direction = 2;
            break;
        case 75:
            if (direction != 4) direction = 3;
            break;
        case 77:
            if (direction != 3) direction = 4;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

void logic()
{
    int i;
    for (i = snakeLen - 1; i > 0; i--)
    {
        snake[i] = snake[i - 1];
    }
    switch (direction)
    {
    case 1:
        snake[0].y--;
        break;
    case 2:
        snake[0].y++;
        break;
    case 3:
        snake[0].x--;
        break;
    case 4:
        snake[0].x++;
        break;
    }

    if (snake[0].x <= 0 || snake[0].x >= WIDTH - 1 ||
        snake[0].y <= 0 || snake[0].y >= HEIGHT - 1)
    {
        gameOver = 1;
        return;
    }

    for (i = 1; i < snakeLen; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            gameOver = 1;
            return;
        }
    }

    if (snake[0].x == food.x && snake[0].y == food.y)
    {
        score += 10;
        snakeLen++;
        spawnFood();
    }
}

void clearScreen()
{
    system("cls");
}

int main()
{
    initGame();
    spawnFood();
    clearScreen();
    drawBorder();

    while (!gameOver)
    {
        input();
        logic();
        if (!gameOver)
        {
            drawGame();
        }
        Sleep(100);
    }

    gotoxy(WIDTH / 2 - 4, HEIGHT / 2);
    printf("Game Over!");
    gotoxy(WIDTH / 2 - 6, HEIGHT / 2 + 1);
    printf("Final Score: %d", score);
    gotoxy(0, HEIGHT + 2);
    return 0;
}