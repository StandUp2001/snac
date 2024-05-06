#include <stdio.h>
#include "tictactoe.h"
#include "board.c"


int main() {
    printf("Tic Tac Toe\n");

    Board board;
    initBoard(&board);

    while (playing)
    {
        printf("Board:\n");
        drawBoard(&board);
        askPlayer(&board);
        checkWin(&board);
        nextPlayer();
    }

    drawBoard(&board);

    printf("Game Over\n");
    
}

void askPlayer(Board *board)
{
    int choice;
    while (1)
    {
        printf("Player %s, enter a number: ", players[currentPlayer]);
        scanf("%d", &choice);
        while (getchar() != '\n');
        if (choice > 0 && choice <= SIZE * SIZE && board->board[choice - 1] != 'X' && board->board[choice - 1] != 'O')
        {
            placeMarker(board, choice);
            return;
        }
        printf("Invalid choice\n");

    }
}

void placeMarker(Board *board, int choice)
{
    board->board[choice - 1] = players[currentPlayer][0];
}


void checkWin(Board *board)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board->board[i * SIZE] == board->board[i * SIZE + 1] && board->board[i * SIZE + 1] == board->board[i * SIZE + 2])
        {
            playing = 0;
            printf("Player %s wins\n", players[currentPlayer]);
            return;
        }
        if (board->board[i] == board->board[i + SIZE] && board->board[i + SIZE] == board->board[i + 2 * SIZE])
        {
            playing = 0;
            printf("Player %s wins\n", players[currentPlayer]);
            return;
        }
    }
    if (board->board[0] == board->board[4] && board->board[4] == board->board[8])
    {
        playing = 0;
        printf("Player %s wins\n", players[currentPlayer]);
        return;
    }
    if (board->board[2] == board->board[4] && board->board[4] == board->board[6])
    {
        playing = 0;
        printf("Player %s wins\n", players[currentPlayer]);
        return;
    }
    int draw = 1;
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        if (board->board[i] != 'X' && board->board[i] != 'O')
        {
            draw = 0;
            break;
        }
    }
    if (draw)
    {
        playing = 0;
        printf("Draw\n");
    }
}

void nextPlayer()
{
    currentPlayer = (currentPlayer + 1) % PLAYERS;
}
