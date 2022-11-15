
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
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include "CheckWin.c"

struct Player
{
    char Name[40];
    char Color;
    double time_taken;
};

/*Requires: A declared 6x7 integer 2D array.
Effects: initializes the entries to "0".
*/
void initializeBoard(int **board){
    
   


    int i;
    int j;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            board[i][j] = 0;
        }
    }
}

/*Requires: A VALID input entered by the player, the game
board so far, and the player(Red or Yellow).
Effects: updates the game board with the value "1" if Red
plays, and "2" if Yellow plays.
*/
void updateBoard(int column, int **board, char player)
{
    int i;
    for (i = 5; i >= 0; i--)
    {
        if (board[i][column - 1] == 0 && player == 'R')
        {
            board[i][column - 1] = 1;
            break;
        }
        else if (board[i][column - 1] == 0 && player == 'Y')
        {
            board[i][column - 1] = 2;
            break;
        }
    }
}

/*Requires: The user input, whatever that may be.
Effects: returns true if the input is valid (an integer between 1 and 7)
and the column is not full, else it returns false.
*/
bool valid_And_Legal(char input[100], int **board)
{
    // Because this is a char array, we need to convert from ascii to int.
    int column = input[0] - '0';
    if ((strlen(input) > 2) || (column < 1 || column > 7) == 1)
    {

        printf("Invalid input, Please enter a Number between 1 and 7!\n");

        return false;
    }
    // Check if a move is legal.
    if (board[0][column-1] != 0)
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
void printBoard(int **board)
{
    int i;

    int j;
    for (i = 0; i < 15; i++)
    {
        printf("- ");
    }
    printf("\n");
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("| %d ", board[i][j]);
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
int CoinToss()
{
    srand(time(NULL));
    int r = 1 + (rand() % 3);
    return r;
}

int *minimax(int **board, int depth, double alpha, double beta, int Player, int columnPlayed, char P_Character)
{
    int *validLocations = GetValidLocations(board);
    int *play = (int *)malloc(2 * sizeof(int));
    if (columnPlayed != -1)
    {
        int Who_won = isOver(board, columnPlayed);
        if (Who_won == 1 && P_Character == 'R')
        {
            play[0] = -313;
            play[1] = 10000000;
            return play;
        }
        else if (Who_won == -1 && P_Character == 'Y')
        {
            play[0] = -313;
            play[1] = -10000000;
            return play;
        }
        else if (NumberOfValidPositions(validLocations) == 0)
        {
            play[0] = -313;
            play[1] = 0;
        }
        else
        {
            play[0] = -313;
            if (Player == 0 && P_Character == 'R')
                play[1] = scoreposition(board, 2);
            else if (Player == 1 && P_Character == 'Y')
                play[1] = scoreposition(board, 2);
            else
                play[1] = scoreposition(board, 1);
            return play;
        }
    }
    else
    {
        if (Player == 1)
        {
            long long int value = -999999999999;
            int column = 0;
            for (int col = 0; col < 7; col++)
            {
                if (validLocations[col] == -1)
                {
                    continue;
                }
                // int row = nextopenRow(board, validLocations[col]);
                int **copy_b = copyFunction(board);
                updateBoard(validLocations[col], copy_b, 'R');
                int *new_score = minimax(copy_b, depth - 1, alpha, beta, 0, validLocations[col], 'Y');
                if (new_score[1] > value)
                {
                    value = new_score[1];
                    column = validLocations[col];
                }
                if (value >= alpha)
                    alpha = value;
                if (alpha >= beta)
                    break;
                play[0] = column;
                play[1] = value;

                return play;
            }
        }
        else
        {
            long long int value = 999999999999;
            int column = 0;
            for (int col = 0; col < 7; col++)
            {
                if (validLocations[col] == -1)
                {
                    continue;
                }
                // int row = nextopenRow(board, validLocations[col]);
                int **copy_b = copyFunction(board);
                updateBoard(validLocations[col], copy_b, 'Y');
                int *new_score = minimax(copy_b, depth - 1, alpha, beta, 1, validLocations[col], 'R');
                if (new_score[1] > value)
                {
                    value = new_score[1];
                    column = validLocations[col];
                }
                if (value <= beta)
                    beta = value;
                if (beta <= alpha)
                    break;

                play[0] = column;
                play[1] = value;

                return play;
            }
        }
    }
}

/*
Requires: The game board along with an input array.
Effects: combines the functionalities made to run the game.
*/
void Connect4(int **board, char input[100])
{

    // initializeBoard(board);

    // int column;
    // int k = 0; // for the number of tries.

    // // Timer variables
    // clock_t start_t, end_t;

    // // Creating the Players.

    // struct Player Player_1;
    // Player_1.time_taken = 0;

    // struct Player Player_2;
    // Player_2.time_taken = 0;

    // // Creating pointers to the Players.
    // struct Player *Redptr;
    // struct Player *YellowPtr;

    // printf("Press 1 for 1 Player Mode, 2 for 2 Players: ");
    // int a;
    // scanf("%d", &a);
    // printf("Player 1, Enter your name please: ");
    // fgets(Player_1.Name, 40, stdin);

    // // fgets adds "\n" to the end of the name so it gets printed with it, to solve it
    // // we adapted this piece of code from https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input#:~:text=Replacing%20a%20%5Cn%20with%20a,of%20%22removing%22%20the%20newline.
    // Player_1.Name[strcspn(Player_1.Name, "\n")] = 0;

    // printf("\n");
    // if (a == 2)
    // {
    //     printf("BOTTT, Enter your name please: ");
    //     fgets(Player_2.Name, 40, stdin);
    //     Player_2.Name[strcspn(Player_2.Name, "\n")] = 0;
    // }
    // printf("We will toss a coin to see who's lucky to start!\n");

    // Sleep(2000); // let them wait, just for fun :)

    // int who_starts = CoinToss();

    // if (who_starts == 1)
    // {                         // Actually we are not tossing a coin to see who starts, we actually toss a coin to see who is the red player (Player with insert number 1)
    //     Player_1.Color = 'R'; // and the red player always starts.
    //     Player_2.Color = 'Y';
    //     Redptr = &Player_1;
    //     YellowPtr = &Player_2;
    //     if (a == 2)
    //         printf("%s was lucky enough to start!\n", Player_1.Name);
    //     else
    //     {
    //         printf("The Bot was lucky enough to start!\n");
    //         strcpy(Player_2.Name, "Bot");
    //     }
    // }
    // else
    // {
    //     Player_2.Color = 'R';
    //     Player_1.Color = 'Y';
    //     Redptr = &Player_2;
    //     YellowPtr = &Player_1;
    //     if (a == 2)
    //         printf("%s was lucky enough to start!\n", Player_2.Name);
    //     else
    //     {
    //         printf("The bot was lucky enough to start!\n");
    //         strcpy(Player_1.Name, "Bot");
    //     }
    // }

    // while (k < 42)
    // {
    //     printf("%s , Enter a number between 1 and 7: ", Redptr->Name);

    //     start_t = clock();
    //     if (a == 2)
    //     {
    //         fgets(input, 100, stdin);
    //         while (valid_And_Legal(input, board) == 0)
    //         {

    //             fgets(input, 100, stdin);
    //         }
    //         column = input[0] - '0'; //"input" is a char array, so we convert to int.
    //     }
    //     else
    //     {
    //         int *move = minimax(board, 4, -99999999, 99999999, 1, -1, Redptr->Color);
    //         int column = move[1] + 1;
    //     }
    //     end_t = clock();
    //     Redptr->time_taken += ((double)(end_t - start_t)) / CLOCKS_PER_SEC; // This increments Red's timer.
    //     updateBoard(column, board, 'R');
    //     printBoard(board);

    //     // Check if the game is over here.
    //     // k>5 because no one would have won before 7 tries (before incrementation).
    //     if (k > 5)
    //     {
    //         if (isOver(board, column - 1) > 0)
    //         {
    //             printf(" CONGRATULATIONS %s, you won!!!\n", Redptr->Name);
    //             break;
    //         }
    //     }

    //     k++;

    //     printf("%s , Enter a number between 1 and 7: ", YellowPtr->Name);

    //     start_t = clock();
    //     if (a == 2)
    //     {
    //         fgets(input, 100, stdin);
    //         while (valid_And_Legal(input, board) == 0)
    //         {

    //             fgets(input, 100, stdin);
    //         }
    //         column = input[0] - '0'; //"input" is a char array, so we convert to int.
    //     }
    //     else
    //     {
    //         int *move = minimax(board, 4, -99999999, 99999999, 1, -1, YellowPtr->Color);
    //         int column = move[1] + 1;
    //     }
    //     end_t = clock();
    //     YellowPtr->time_taken = YellowPtr->time_taken + ((double)(end_t - start_t)) / CLOCKS_PER_SEC; // This increments Yellow's timer.
    //     updateBoard(column, board, 'Y');
    //     printBoard(board);

    //     // Check if the game is Over here.
    //     if (k > 5)
    //     {
    //         if (isOver(board, column - 1) > 0)
    //         {
    //             printf(" CONGRATULATIONS %s, you won!!!\n", YellowPtr->Name);
    //             break;
    //         }
    //     }

    //     k++;
    // }

    // if (k == 42)
    // {
    //     if (Redptr->time_taken < YellowPtr->time_taken)
    //     {
    //         printf("Time taken by %s:%f\n", YellowPtr->Name, YellowPtr->time_taken);
    //         printf("Time taken by %s:%f\n", Redptr->Name, Redptr->time_taken);
    //         printf(" CONGRATULATIONS %s, you won!!!", Redptr->Name);
    //     }
    //     else
    //     {
    //         printf(" CONGRATULATIONS %s, you won!!!\n", YellowPtr->Name);
    //         printf("Time taken by %s:%f\n", YellowPtr->Name, YellowPtr->time_taken);
    //         printf("Time taken by %s:%f", Redptr->Name, Redptr->time_taken);
    //     }
    // }


    initializeBoard(board);

    int column;
    int k=0;//for the number of tries.

    //Timer variables
    clock_t start_t,end_t;

    //Creating the Players.

    struct Player Player_1;
    Player_1.time_taken=0;

    struct Player Player_2;
    Player_2.time_taken=0;

    //Creating pointers to the Players.
    struct Player *Redptr;
    struct Player *YellowPtr;

    printf("Player 1, Enter your name please: ");
    fgets(Player_1.Name,40,stdin);

    //fgets adds "\n" to the end of the name so it gets printed with it, to solve it
    //we adapted this piece of code from https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input#:~:text=Replacing%20a%20%5Cn%20with%20a,of%20%22removing%22%20the%20newline.
    Player_1.Name[strcspn(Player_1.Name, "\n")] = 0;

    printf("\n");

    printf("Player 2, Enter your name please: ");
    fgets(Player_2.Name,40,stdin);
    Player_2.Name[strcspn(Player_2.Name, "\n")] = 0;
    printf("We will toss a coin to see who's lucky to start!\n");

    Sleep(2000);//let them wait, just for fun :)

    int who_starts=CoinToss();

    if (who_starts==1){         //Actually we are not tossing a coin to see who starts, we actually toss a coin to see who is the red player (Player with insert number 1) 
        Player_1.Color='R';     //and the red player always starts.
        Player_2.Color='Y';
        Redptr=&Player_1;
        YellowPtr=&Player_2;
        printf("%s was lucky enough to start!\n",Player_1.Name);
    }
    else 
    {
        Player_2.Color='R';
        Player_1.Color='Y';
        Redptr=&Player_2;
        YellowPtr=&Player_1;
        printf("%s was lucky enough to start!\n",Player_2.Name);
    }

    while (k<42){

    printf("%s , Enter a number between 1 and 7: ",Redptr->Name);

    start_t=clock();
    fgets(input,100,stdin);
    while (valid_And_Legal(input,board)==0){

        fgets(input,100,stdin);
    
    }
    column=input[0]-'0'; //"input" is a char array, so we convert to int.
    end_t=clock();
    Redptr->time_taken += ((double)(end_t - start_t))/CLOCKS_PER_SEC;//This increments Red's timer.
    updateBoard(column,board,'R');
    printBoard(board);

    //Check if the game is over here.
    //k>5 because no one would have won before 7 tries (before incrementation).
     if(k>5){
        if(isOver(board,column-1)>0){
            printf(" CONGRATULATIONS %s, you won!!!\n", Redptr->Name);
            break;
        }
     }

    k++;

    printf("%s , Enter a number between 1 and 7: ",YellowPtr->Name);

    start_t=clock();
    fgets(input,100,stdin);
    while (valid_And_Legal(input,board)==0){

        fgets(input,100,stdin);
    
    }

    column=input[0]-'0'; //"input" is a char array, so we convert to int.
    end_t=clock();
    YellowPtr->time_taken = YellowPtr->time_taken + ((double)(end_t - start_t))/CLOCKS_PER_SEC;//This increments Yellow's timer.
    updateBoard(column,board,'Y');
    printBoard(board);

    //Check if the game is Over here.
     if(k>5){
        if(isOver(board,column-1)>0){
            printf(" CONGRATULATIONS %s, you won!!!\n", YellowPtr->Name);
            break;
        }
     }

    k++;

    }

    if(k==42){
        if(Redptr->time_taken < YellowPtr-> time_taken){
            printf("Time taken by %s:%f\n",YellowPtr->Name,YellowPtr->time_taken);
            printf("Time taken by %s:%f\n",Redptr->Name,Redptr->time_taken);
            printf(" CONGRATULATIONS %s, you won!!!", Redptr->Name);
        }
        else{
            printf(" CONGRATULATIONS %s, you won!!!\n", YellowPtr->Name);
            printf("Time taken by %s:%f\n",YellowPtr->Name,YellowPtr->time_taken);
            printf("Time taken by %s:%f",Redptr->Name,Redptr->time_taken);
        }
    }

}

int main()
{
    int **board;
    board = (int **)malloc(sizeof(int *)* 6);
   for (int i = 0; i < 6; i++)
   {
      board[i] = (int*)malloc(sizeof(int) * 7);
   }
    char arr[100];
    Connect4(board, arr);
}
