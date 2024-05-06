#ifndef TICTACTOE_H
#define TICTACTOE_H

#define PLAYERS 2
#define SIZE 3

extern const char *players[PLAYERS] = {"X", "O"};
extern int currentPlayer = 0;
extern int playing = 1;

typedef struct Board {
    char board[SIZE * SIZE];
} Board;

void initBoard(Board *board);
void drawBoard(Board *board);
void askPlayer(Board *board);
void checkWin(Board *board);
void nextPlayer();
void placeMarker(Board *board, int choice);

#endif
