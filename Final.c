
// THIS IS WHERE THE GAME RUNS
/*
       Horizontal Case
- - - - - - - - - - - - - - -
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 2 | 0 | 0 | 2 | 0 | 0 | 0 |
| 2 | 1 | 1 | 1 | 1 | 0 | 0 |
- - - - - - - - - - - - - - -
Player 1 wins in row 6 from columns 1 to 4




        Vertical Case
- - - - - - - - - - - - - - -
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 2 | 2 | 2 | 0 | 0 |
- - - - - - - - - - - - - - -
Player 1 wins in column 2 from rows 1 to 4





  Diagonal To The Right Case
- - - - - - - - - - - - - - -
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 2 | 0 | 0 | 0 |
| 0 | 0 | 2 | 1 | 0 | 0 | 0 |
| 1 | 2 | 1 | 1 | 0 | 0 | 0 |
| 2 | 1 | 1 | 2 | 2 | 0 | 0 |
- - - - - - - - - - - - - - -
Player 2 wins in rows 3 to 6 and columns 1 to 4




  Diagonal To The Left Case
- - - - - - - - - - - - - - -
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 2 | 0 | 0 | 0 | 0 | 0 |
| 0 | 2 | 2 | 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 2 | 1 | 0 | 0 |
| 1 | 1 | 2 | 1 | 2 | 0 | 0 |
- - - - - - - - - - - - - - -
Player 2 wins in rows 3 to 6 and columns 1 to 4



         Tie Case
- - - - - - - - - - - - - - -
| 2 | 1 | 1 | 2 | 2 | 1 | 2 |
| 1 | 2 | 2 | 1 | 1 | 2 | 1 |
| 2 | 1 | 2 | 2 | 1 | 1 | 2 |
| 1 | 2 | 2 | 1 | 1 | 2 | 1 |
| 2 | 1 | 1 | 2 | 2 | 1 | 2 |
| 1 | 2 | 2 | 1 | 1 | 2 | 1 |
- - - - - - - - - - - - - - -
In this case the player who spent less time during his turns wins the game.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include "CheckWin.c"

long long int runn = 0;
int AIPIECE_KCGH_CODES;
int PlayerPiece_KCGH_CODES;


struct Player
{
    char Name[40];
    char Color;
    double time_taken;
};

/*Requires: A declared 6x7 integer 2D array.
Effects: initializes the entries to "0".
*/
void initializeBoard_KCGH_CODES(int **board)
{
    int i;
    int j;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            *(*(board + i) + j) = 0;
        }
    }
}

/*Requires: A VALID input entered by the player, the game
board so far, and the player(Red or Yellow).
Effects: updates the game board with the value "1" if Red
plays, and "2" if Yellow plays.
*/
void updateBoard_KCGH_CODES(int column, int **board, int player)
{
    int i;
    for (i = 5; i >= 0; i--)
    {
        if (*(*(board + i) + (column - 1)) == 0 && player == 1)
        {
            *(*(board + i) + (column - 1)) = 1;
            break;
        }
        else if (*(*(board + i) + (column - 1)) == 0 && player == 2)
        {
            *(*(board + i) + (column - 1)) = 2;
            break;
        }
    }
}

/*Requires: The user input, whatever that may be.
Effects: returns true if the input is valid (an integer between 1 and 7)
and the column is not full, else it returns false.
*/
bool valid_And_Legal_KCGH_CODES(char input[100], int **board)
{
    // Because this is a char array, we need to convert from ascii to int.
    int column = *input - '0';
    if ((strlen(input) > 2) || (column < 1 || column > 7) == 1)
    {

        printf("Invalid input, Please enter a Number between 1 and 7!\n");

        return false;
    }
    // Check if a move is legal.
    if (board[0][column - 1] != 0)
    {
        printf("Column is full, try with another one!\n");
        return false;
    }
    return true;
}

/*
Requires: The game board(a 6x7 integer 2D array)
Effects: prints the entries of the board.
*/
void printBoard_KCGH_CODES(int **board)
{
    int i;

    int j;
    for (i = 0; i < 11; i++)
    {
        printf(" __ ");
    }
    printf("\n");
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("|__%d__", board[i][j]);
        }
        printf("|\n");
    }
    for (i = 0; i < 15; i++)
    {
        printf("- ");
    }
    printf("\n");
    printf("\n");
}

/*Requires: Nothing.
Effects: A vlaue 1 or 2 indicating which of the two players is going to start.
Adapted from: https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c
*/
int CoinToss_KCGH_CODES()
{
    srand(time(NULL));
    int r = 1 + (rand() % 3);
    return r;
}

int isTerminal_KCGH_CODES(int **board, int column)
{
    int is_over = isOver_KCGH_CODES(board, column);
    if (is_over == 1)
        return 1;
    else if (is_over == -1)
        return -1;
    int *ValidPositions = GetValidLocations_KCGH_CODES(board);
    if (NumberOfValidPositions_KCGH_CODES(ValidPositions) == 0)
    {
        free(ValidPositions);
        return -2;
    }
    return 0;
}

int *Minimax_KCGH_CODES(int **board, int depth, int alpha, int beta, int Player, int columnPlayed)
{
    int *validLocations = GetValidLocations_KCGH_CODES(board);
    int *play = (int *)malloc(2 * sizeof(int));
    if (columnPlayed != -1)
    {
        if ((depth == 0 || isTerminal_KCGH_CODES(board, columnPlayed) != 0) == 1)
        {
            if (isTerminal_KCGH_CODES(board, columnPlayed) != 0)
            {
                int Who_won = isOver_KCGH_CODES(board, columnPlayed);
                if ((Who_won == 1 && AIPIECE_KCGH_CODES == 1) || (Who_won == -1 && AIPIECE_KCGH_CODES == 2) == 1)
                {
                    *play = columnPlayed;
                    *(play + 1) = 10000;
                    return play;
                }
                else if ((Who_won == 1 && AIPIECE_KCGH_CODES == 2) || (Who_won == -1 && AIPIECE_KCGH_CODES == 1) == 1)
                {
                    *(play) = columnPlayed;
                    *(play + 1) = -10000;
                    return play;
                }
                else if (NumberOfValidPositions_KCGH_CODES(validLocations) == 0)
                {
                    *play = columnPlayed;
                    *(play + 1) = 0;
                    return play;
                }
            }
            else
            {
                *play = columnPlayed;
                *(play + 1) = scoreposition_KCGH_CODES(board, AIPIECE_KCGH_CODES);
                return play;
            }
        }
    }
    if (Player == 1)
    {
        int value = -9999999;
        int column;
        int SAVE_COL;
        for (int col = 0; col < 7; col++)
        {
            if (*(validLocations + col) == -1)
            {
                continue;
            }
            int **copy_b = copyFunction_KCGH_CODES(board);

            SAVE_COL = *(validLocations + col);

            updateBoard_KCGH_CODES(SAVE_COL + 1, copy_b, AIPIECE_KCGH_CODES);

            if (depth - 1 < 0)
            {
                free(copy_b);
                break;
            }
            int *new_score = Minimax_KCGH_CODES(copy_b, depth - 1, alpha, beta, 0, SAVE_COL);
            free(copy_b);
            if (*(new_score + 1) > value)
            {
                value = new_score[1];
                column = SAVE_COL;
                *(play) = column;
                *(play + 1) = value;
            }
            free(new_score);
            if (value > alpha)
                alpha = value;
            if (alpha >= beta)
                break;
        }
        free(validLocations);
        return play;
    }
    else
    {
        int value = 9999999;
        int column;
        int SAVE_COL;
        for (int col = 0; col < 7; col++)
        {
            if (*(validLocations + col) == -1)
            {
                continue;
            }
            int **copy_b = copyFunction_KCGH_CODES(board);

            SAVE_COL = *(validLocations + col);

            updateBoard_KCGH_CODES(SAVE_COL + 1, copy_b, PlayerPiece_KCGH_CODES);
            if (depth - 1 < 0)
            {
                free(copy_b);
                break;
            }
            int *new_score = Minimax_KCGH_CODES(copy_b, depth - 1, alpha, beta, 1, SAVE_COL);
            free(copy_b);
            // copy_b=NULL;
            if (*(new_score + 1) < value)
            {
                value = *(new_score + 1);
                column = SAVE_COL;
                *(play) = column;
                *(play + 1) = value;
            }
            free(new_score);
            if (value < beta)
                beta = value;
            if (beta <= alpha)
                break;
        }
        free(validLocations);
        return play;
    }
}
/*Requires: a double integer pointer
 * Effects: returns an array containing the entry corresponding to our turn (1 or 2) along with the number of entries.
 * Testing Strategy: calling it on an empty array returns nothing.
 * produces the correct output when calling it on odd and even cases.
 */
int *Who_Started_KCGH_CODES(int **board)
{
    int *starter = (int *)malloc(2 * sizeof(int));
    int i;
    int j;
    int Num_entries = 0;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (board[i][j] != 0)
                Num_entries++;
        }
    }

    if (Num_entries % 2 == 0)
    {
        *starter = 1;
        *(starter + 1) = Num_entries;
        return starter;
    }
    *starter = 2;
    *(starter + 1) = Num_entries;
    return starter;
}
/*
 * Requires: The game board
 * Effects: returns the optimal column.
 * Testing strategy: sending an empty board: gives us the correct output
 * sending a board containing an even number of entries as well as odd also gives us the correct output.
 */

int make_move_KCGH_CODES(int **board)
{
    int *turn = Who_Started_KCGH_CODES(board);
    int entries = *(turn+1);
    AIPIECE_KCGH_CODES = *turn;
    int column;
    int depth=8;
    if (AIPIECE_KCGH_CODES == 1)
    {
        PlayerPiece_KCGH_CODES = 2;
    }
    else
    {
        PlayerPiece_KCGH_CODES = 1;
    }

    if (entries == 0)
    {
        column = 3;
    }
    else if (entries == 2 && board[4][3] == PlayerPiece_KCGH_CODES)
    {
        column = 3;
    }
    else if (entries == 1 && board[5][3] == 0)
    {
        column = 3;
    }
    else if (entries == 1 && board[5][3] == PlayerPiece_KCGH_CODES)
    {
        column = 3;
    }
    else if (entries == 3 && board[3][3] == PlayerPiece_KCGH_CODES)
    {
        column = 2;
    }
    else if (entries == 4 && board[2][3] == PlayerPiece_KCGH_CODES)
    {
        column = 2;
    }
    else{
        if(entries>=16 && entries<21){
            int *BOT = Minimax_KCGH_CODES(board, depth+1, -9999999, 9999999, 1, -1);
            column = *BOT;
        }
        else if(entries>=21 && entries<28){
            int *BOT = Minimax_KCGH_CODES(board, depth+2, -9999999, 9999999, 1, -1);
            column = *BOT;
        }
        else if(entries>=28 && entries<35){
            int *BOT = Minimax_KCGH_CODES(board, depth+3, -9999999, 9999999, 1, -1);
            column = *BOT;
        }
        else if(entries>=35 && entries<38){
            int *BOT = Minimax_KCGH_CODES(board, depth+4, -9999999, 9999999, 1, -1);
            column = *BOT;
        }
        else if(entries>=38){
            int *BOT = Minimax_KCGH_CODES(board, depth+5, -9999999, 9999999, 1, -1);
            column = *BOT;
        }
        else {
            int *BOT = Minimax_KCGH_CODES(board, depth, -9999999, 9999999, 1, -1);
            column = *BOT;
        }

    }
    return column;
}

/*
Requires: The game board along with an input array.
Effects: combines the functionalities made to run the game.
*/
void Connect4_KCGH_CODES(int **board, char input[100])
{
    int k=0;
    int a;
    printf("Enter 1 for Single Player, 2 for Two Players: ");

    scanf("%d", &a);
    fflush(stdin);

    initializeBoard_KCGH_CODES(board);

    int column;

    // Timer variables
    clock_t start_t, end_t;

    // Creating the Players.

    struct Player Player_1;
    Player_1.time_taken = 0;

    struct Player Player_2;
    Player_2.time_taken = 0;

    // Creating pointers to the Players.
    struct Player *Redptr;
    struct Player *YellowPtr;

    if (a == 2)
    {
        printf("Player 1, Enter your name please: ");
        fgets(Player_1.Name, 40, stdin);

        // fgets adds "\n" to the end of the name so it gets printed with it, to solve it
        // we adapted this piece of code from https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input#:~:text=Replacing%20a%20%5Cn%20with%20a,of%20%22removing%22%20the%20newline.
        Player_1.Name[strcspn(Player_1.Name, "\n")] = 0;

        printf("\n");

        printf("Player 2, Enter your name please: ");
        fgets(Player_2.Name, 40, stdin);
        Player_2.Name[strcspn(Player_2.Name, "\n")] = 0;
        printf("We will toss a coin to see who's lucky to start!\n");

        Sleep(1000); // let them wait, just for fun 🙂

        int who_starts = CoinToss_KCGH_CODES();

        if (who_starts == 1)
        {                         // Actually we are not tossing a coin to see who starts, we actually toss a coin to see who is the red player (Player with insert number 1)
            Player_1.Color = 'R'; // and the red player always starts.
            Player_2.Color = 'Y';
            Redptr = &Player_1;
            YellowPtr = &Player_2;
            printf("%s was lucky enough to start!\n", Player_1.Name);
        }
        else
        {
            Player_2.Color = 'R';
            Player_1.Color = 'Y';
            Redptr = &Player_2;
            YellowPtr = &Player_1;
            printf("%s was lucky enough to start!\n", Player_2.Name);
        }

        while (k < 42)
        {

            printf("%s , Enter a number between 1 and 7: ", Redptr->Name);

            start_t = clock();
            fgets(input, 100, stdin);
            while (valid_And_Legal_KCGH_CODES(input, board) == 0)
            {

                fgets(input, 100, stdin);
            }
            column = input[0] - '0'; //"input" is a char array, so we convert to int.
            end_t = clock();
            Redptr->time_taken += ((double)(end_t - start_t)) / CLOCKS_PER_SEC; // This increments Red's timer.
            updateBoard_KCGH_CODES(column, board, 1);
            printBoard_KCGH_CODES(board);

            // Check if the game is over here.
            // k>5 because no one would have won before 7 tries (before incrementation).
            if (k > 5)
            {
                if (isOver_KCGH_CODES(board, column - 1) > 0)
                {
                    printf(" CONGRATULATIONS %s, you won!!!\n", Redptr->Name);
                    break;
                }
            }

            k++;

            printf("%s , Enter a number between 1 and 7: ", YellowPtr->Name);

            start_t = clock();
            fgets(input, 100, stdin);
            while (valid_And_Legal_KCGH_CODES(input, board) == 0)
            {

                fgets(input, 100, stdin);
            }

            column = input[0] - '0'; //"input" is a char array, so we convert to int.
            end_t = clock();
            YellowPtr->time_taken = YellowPtr->time_taken + ((double)(end_t - start_t)) / CLOCKS_PER_SEC; // This increments Yellow's timer.
            updateBoard_KCGH_CODES(column, board, 2);
            printBoard_KCGH_CODES(board);

            // Check if the game is Over here.
            if (k > 5)
            {
                if (isOver_KCGH_CODES(board, column - 1) < 0)
                {
                    printf(" CONGRATULATIONS %s, you won!!!\n", YellowPtr->Name);
                    break;
                }
            }

            k++;
        }

        if (k == 42)
        {
            if (Redptr->time_taken < YellowPtr->time_taken)
            {
                printf("Time taken by %s:%f\n", YellowPtr->Name, YellowPtr->time_taken);
                printf("Time taken by %s:%f\n", Redptr->Name, Redptr->time_taken);
                printf(" CONGRATULATIONS %s, you won!!!", Redptr->Name);
            }
            else
            {
                printf(" CONGRATULATIONS %s, you won!!!\n", YellowPtr->Name);
                printf("Time taken by %s:%f\n", YellowPtr->Name, YellowPtr->time_taken);
                printf("Time taken by %s:%f", Redptr->Name, Redptr->time_taken);
            }
        }
    }

    else if (a == 1)
    {
        printf("Player 1, Enter your name please: ");
        fgets(Player_1.Name, 40, stdin);

        // fgets adds "\n" to the end of the name so it gets printed with it, to solve it
        // we adapted this piece of code from https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input#:~:text=Replacing%20a%20%5Cn%20with%20a,of%20%22removing%22%20the%20newline.
        Player_1.Name[strcspn(Player_1.Name, "\n")] = 0;

        printf("\n");

        printf("We will toss a coin to see who's lucky to start!\n");

        int who_starts = CoinToss_KCGH_CODES();

        Sleep(1500); // let them wait, just for fun 🙂

        if (who_starts == 1)
        {                         // Actually we are not tossing a coin to see who starts, we actually toss a coin to see who is the red player (Player with insert number 1)
            Player_1.Color = 'R'; // and the red player always starts.
            Redptr = &Player_1;
            YellowPtr = &Player_2;
            printf("%s was lucky enough to start!\n", Player_1.Name);
        }
        else
        {
            Player_2.Color = 'R'; // Bot is red and player is yellow
            Player_1.Color = 'Y';
            Redptr = &Player_2;
            printf("Bot was lucky enough to start!\n");
        }

        if (Player_2.Color == 'R')
        {
            AIPIECE_KCGH_CODES = 1;
            PlayerPiece_KCGH_CODES = 2;
        }
        else
        {
            AIPIECE_KCGH_CODES = 2;
            PlayerPiece_KCGH_CODES = 1;
        }

        while (k < 42)
        {

            start_t = clock();

            if (PlayerPiece_KCGH_CODES == 1)
            {
                printf("%s , Enter a number between 1 and 7: ", Redptr->Name);
                fgets(input, 100, stdin);
                while (valid_And_Legal_KCGH_CODES(input, board) == 0)
                {

                    fgets(input, 100, stdin);
                }
                column = input[0] - '0'; //"input" is a char array, so we convert to int.
                updateBoard_KCGH_CODES(column, board, 1);
                end_t = clock();
                Player_1.time_taken += ((double)(end_t - start_t)) / CLOCKS_PER_SEC; // This increments Red's timer.
            }

            else
            {

                    column = make_move_KCGH_CODES(board) + 1;
                    updateBoard_KCGH_CODES(column, board, 1);
                    end_t = clock();
                    Player_2.time_taken += ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
            }

            printBoard_KCGH_CODES(board);

            // Check if the game is over here.
            // k>5 because no one would have won before 7 tries (before incrementation).
            if (k > 5)
            {
                int Who_won = isOver_KCGH_CODES(board, column - 1);
                if ((Who_won == 1 && AIPIECE_KCGH_CODES == 1) || (Who_won == -1 && AIPIECE_KCGH_CODES == 2) == 1)
                {
                    printf("You Lost to Minimax looooooooooooooooooool\n");
                    break;
                }
                else if ((Who_won == 1 && AIPIECE_KCGH_CODES == 2) || (Who_won == -1 && AIPIECE_KCGH_CODES == 1) == 1)
                {
                    printf(" CONGRATULATIONS %s, you won!!!\n", Player_1.Name);
                    break;
                }
            }

            k++;

            if (PlayerPiece_KCGH_CODES == 2)
            {
                printf("%s , Enter a number between 1 and 7: ", Player_1.Name);
                start_t = clock();
                fgets(input, 100, stdin);
                while (valid_And_Legal_KCGH_CODES(input, board) == 0)
                {

                    fgets(input, 100, stdin);
                }

                column = input[0] - '0'; //"input" is a char array, so we convert to int.
                updateBoard_KCGH_CODES(column, board, 2);
                end_t = clock();
                Player_1.time_taken += ((double)(end_t - start_t)) / CLOCKS_PER_SEC; // This increments Yellow's timer.
            }

            else
            {
                    column = make_move_KCGH_CODES(board) + 1;
                    updateBoard_KCGH_CODES(column, board, 2);
                    end_t = clock();
                    Player_2.time_taken += ((double)(end_t - start_t)) / CLOCKS_PER_SEC; // This increments Yellow's timer.
            }

            printBoard_KCGH_CODES(board);

            // Check if the game is Over here.
            if (k > 5)
            {
                int Who_won = isOver_KCGH_CODES(board, column - 1);
                if ((Who_won == 1 && AIPIECE_KCGH_CODES == 1) || (Who_won == -1 && AIPIECE_KCGH_CODES == 2) == 1)
                {
                    printf("You Lost to Minimax looooooooool\n");
                    break;
                }
                else if ((Who_won == 1 && AIPIECE_KCGH_CODES == 2) || (Who_won == -1 && AIPIECE_KCGH_CODES == 1) == 1)
                {
                    printf(" CONGRATULATIONS %s, you won!!!\n", Player_1.Name);
                    break;
                }
            }
            k++;
        }

        if (k == 42)
        {
            if (Player_1.time_taken < Player_2.time_taken)
            {
                printf("Time taken by %s:%.3f\n",Player_1.Name, Player_1.time_taken);
                printf("Time taken by Bot:%.3f\n", Player_2.time_taken);
                printf(" CONGRATULATIONS %s, you won!!!", Player_1.Name);
            }
            else
            {
                printf("Minimax Won!\n");
                printf("Time taken by Minimax:%.3f\n", Player_2.time_taken);
                printf("Time taken by %s:%f",Player_1.Name, Player_1.time_taken);
            }
        }
    }
}

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