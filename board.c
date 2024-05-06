#include "tictactoe.h"

void initBoard(Board *board)
{
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        board->board[i] = i + 1 + '0';
    }
}

void drawBoard(Board *board)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c", board->board[i * SIZE + j]);
            if (j < SIZE - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1)
        {
            for (int j = 0; j < SIZE; j++)
            {
                printf("-");
                if (j < SIZE - 1)
                {
                    printf("+");
                }
            }
            printf("\n");
        }
    }
}