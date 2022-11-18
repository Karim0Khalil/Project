#include "connect4_KCGH_CODES.h"


int main()
{
    int **board;
    board = (int **)malloc(sizeof(int *) * 6);
    for (int i = 0; i < 6; i++)
    {
        board[i] = (int *)malloc(sizeof(int) * 7);
    }
    char arr[100];
    Connect4_KCGH_CODES(board, arr);
    free(board);
    return 0;
}