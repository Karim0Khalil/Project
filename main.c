#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <Windows.h>



struct Player
{
    char Name[40];
    char Color;
    double time_taken;

};


/*Requires: A declared 6x7 2D array.
Effects: initializes the entries to "0".
*/
void initializeBoard(int board[6][7]){
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
void updateBoard(int column,int board[6][7],char player){
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
bool valid_And_Legal(char input[100], int board[6][7]){
    //Because this is a char array, we need to convert from ascii to int.
    int column=input[0]-'0';
    if ((strlen(input)>2)||(column<1||column>7)==1){

        printf("Invalid input, Please enter a Number between 1 and 7!\n");
    
       return false;
    }
    //Check if a move is legal.
    if (board[0][column-1]!=0){
            printf("Column is full, try with another one!\n");
            return false;
    }
    return true;
}


/*
Requires: The game board(a 6x7 2D array)
Effects: prints the entries of the board.
*/
void printBoard(int board[6][7]){
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
*/
int CoinToss(){
    srand(time(NULL));   
    int r = 1+(rand()%3);//Line 93 and 94 were taken from https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c
    return r;
}


/*
Requires: The game board along with an input array.
Effects: combines the functionalities made to run the game.
*/
void Connect4(int board[6][7],char input[100]){

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

    //Creating pointers to the Players, first we'll assign them randomly.
    struct Player *Redptr;
    Redptr=&Player_1;
    struct Player *YellowPtr;
    YellowPtr=&Player_2;


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

    if (who_starts==1){
        Player_1.Color='R';
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
    Redptr->time_taken += (double)(end_t - start_t) / CLOCKS_PER_SEC;//This increments Red's timer.
    updateBoard(column,board,'R');
    printBoard(board);


    //Check if the game is over here.


    k++;


    printf("%s , Enter a number between 1 and 7: ",YellowPtr->Name);

    start_t=clock();
    fgets(input,100,stdin);
    while (valid_And_Legal(input,board)==0){

        fgets(input,100,stdin);
    
    }

    column=input[0]-'0'; //"input" is a char array, so we convert to int.
    end_t=clock();
    YellowPtr->time_taken += (double)(end_t - start_t) / CLOCKS_PER_SEC;//This increments Yellow's timer.
    updateBoard(column,board,'Y');
    printBoard(board);


    //Check if the game is Over here.


    k++;


    }

}



int main()
{
    int board[6][7];
    char arr[100];
    Connect4(board, arr);
}
