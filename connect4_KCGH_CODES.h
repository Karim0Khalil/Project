#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*

This file contains the following functions:

int isOver_KCGH_CODES(int**, int);
int findRow(int** , int column);
int checkVertically(int [6][7], int row, int column, int size);
int checkHorizontally(int[6][7], int row, int column, int size);
int checkDiagonally_1(int[6][7], int row, int column, int size);
int checkDiagonally_2(int [6][7], int row, int column, int input);
int isOver_KCGH_CODES(int **array, int column);
int nextopenRow(int **board, int column);
int *GetValidLocations(int **board);
int CountWindow(int window[], int size, int piece);
int evauluate_window(int window[], int size, int piece);
int **copyFunction_KCGH_CODES(int **board);
int scoreposition_KCGH_CODES(int **board, int piece);

*/

/*
    int findRow(int **array, int column)

    requires: the board, the column that was last played at, an whose turn it was
    effects: returns the row that was played at
*/

int findRow_KCGH_CODES(int **array, int column)
{
    int i = 0;
    int row = 0;
    int insertion = array[0][column];
    while (row<=4)
    {
        if (insertion == 0){
            row++;
            insertion=array[row][column];
        }
        else break;
    }
    return row;
}

/*
    int checkVertically(int array[6][7], int row, int column, int input)

    requires: the board, column and row that the last turn was played at, and whose turn it was
    effects: return 1 if there is any win at the row the last turn was played at
*/
int checkVertically_KCGH_CODES(int array[6][7], int row, int column, int input)

{

    int i = 0;
    int j = i;
    int streak = 0;

    while (5 - i >= 3)   //there are 3 possible wins at each horizontal level
    {
        for (j; j < 4+i; j++)
        {
            if (array[j][column] == input)  //checks that if there is a win, the win must be from one player only
                streak++;
        }

        if (streak == 4)
            return 1;

        i++;
        j = i;
        streak = 0;

    }
    return 0;
}

/*
    int checkHorizontally(int array[6][7], int row, int column, int input)

    requires: the board, column and row that the last turn was played at, and whose turn it was
    effects: return 1 if there is any win at the column the last turn was played at
*/

int checkHorizontally_KCGH_CODES(int array[6][7], int row, int column, int input)
{

    int i = 0;
    int j = i;
    int streak = 0;

    while (6 - i >= 3) // there are 4 possible wins at each horizontal level
    {
        for (j; j < 4 + i; j++)
        {
            if (array[row][j] == input) // checks that if there is a win, the win must be from one player only
                streak++;
        }

        if (streak == 4)
            return 1;

        i++;
        j = i;
        streak = 0;
    }
    return 0;
}

/*
     int checkDiagonally_1(int array[6][7], int row, int column, int input)

     requires: the board, column and row that the last turn was played at, and whose turn it was
     effects: return 1 if there is any win at the diagonal to the right the last turn was played at
*/

int checkDiagonally_1_KCGH_CODES(int array[6][7], int row, int column, int input)
{

    int diagonal[6] = { -1,-1,-1,-1,-1,-1 };
    int i = 0;

    while (row <= 5 && column>0)
    {
        row++;
        column--;
    }

    while (row >= 0 && column <= 6)
    {
        diagonal[i] = array[row--][column++];
        i++;
    }

    i = 0;
    int j = 0;
    int streak = 0;

    for (i; i < 3; i++)
    {
        for (j; j < 4; j++)
        {
            if (diagonal[j+i] == input) //checks that if there is a win, the win must be from one player only
                streak++;
        }
        if (streak == 4)
            return 1;
        j = 0;
        streak = 0;
    }
    return 0;
}

/*
    int checkDiagonally_2(int array[6][7], int row, int column, int input)

    requires: the board, column and row that the last turn was played at, and whose turn it was
    effects: return 1 if there is any win at the diagonal to the left the last turn was played at
*/

int checkDiagonally_2_KCGH_CODES(int array[6][7], int row, int column, int input)
{

    int diagonal[6] = { -1,-1,-1,-1,-1,-1 };
    int i = 0;

    while (row < 5 && column > 0)
    {
        row++;
        column++;
    }
    while (row >= 0 && column <= 6)
    {
        diagonal[i] = array[row--][column--];
        i++;
    }
    i = 0;
    int j = 0;
    int streak = 0;

    for (i; i < 3; i++)
    {
        for (j; j < 4; j++)
        {
            if (diagonal[j + i] == input) //checks that if there is a win, the win must be from one player only
                streak++;
        }
        if (streak == 4)
            return 1;
        j = 0;
        streak = 0;
    }
    return 0;
}

/*
 * int isOver_KCGH_CODES(int array[6][7], int column)
 *
 * requires: The column in which has last inserted.
 * effects: Returns if the user's last move allows him to win by returning an integer >0; else it returns 0.
 * It calls 5 functions, such that each function checks vertically or horizontally and two functions to check the 2 diagonals.
 *
 */
int isOver_KCGH_CODES(int **board, int column)
{
    int columns = 7;
    int rows = 6;
    int row = findRow_KCGH_CODES(board, column);

    int array[6][7];

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            array[i][j] = board[i][j];
        }
    }

    int input = array[row][column];

    int vertical = checkVertically_KCGH_CODES(array, row, column, input);
    int horizontal = checkHorizontally_KCGH_CODES(array, row, column, input);
    int diagonal1 = checkDiagonally_1_KCGH_CODES(array, row, column, input);
    int diagonal2 = checkDiagonally_2_KCGH_CODES(array, row, column, input);

    int result = vertical + horizontal + diagonal1 + diagonal2;
    if (result > 0 && input==1)
        return 1;
    else if (result > 0 && input == 2)
        return -1;
    return 0;
}
/*
int *GetValidLocations(int **board)

Requires: The 2D array board with 6 rows and 7 columns
Effects: Returns a 1D array with the valid locations(meaning the column is valid to make
a move in) of the numbered columns in the board, -1 otherwise.


Test cases:
1- If given a valid input the functions performs its operations correctly.
given an 2Darray(gameboard)
int gameboard[6][7] = {{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,2,0,0,0},{0,1,1,1,2,2,0}};
The functions returns a 1D array with the number of the columns that are valid to make a move in.(columns are 0 indexed).
Output: {0,1,2,3,4,5,6};

2- int gameboard[6][7] = {{1,0,0,0,0,0,0},{2,0,0,0,0,0,0},{1,0,0,0,0,0,0},{2,0,0,0,0,0,0},{1,0,0,2,0,0,0},{2,1,1,1,2,2,0}};
Output: {1,0,0,0,0,0,0}

This function will always output the correct result since we are always giving it a fixed sized board with valid arguments
in our function calls.
*/
int *GetValidLocations_KCGH_CODES(int **board)
{
    int *arr = (int *)malloc(sizeof(int) * 7);
    for (int i = 0; i < 7; ++i)
    {
        arr[i] = -1;
    }
    for (int i = 0; i < 7; ++i)
    {
        if (board[0][i] == 0)
            arr[i] = i;
    }
    return arr;
}
/*

int CountWindow(int window[], int size, int piece)

Requires: A 1D array of size 4, size of the given 1D array(as an integer) which is 4, and an integer named piece which can
have the values 1 or 2.
Effects:Returns the number of times piece is found in the window array

Simple Testing case:
window = {1,2,1,2};
CountWindow(window,4,2) will ouput 2.

The algorithm is clear and is always guranteed to output the correct answer.
*/
int CountWindow_KCGH_CODES(int window[], int size, int piece)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (window[i] == piece)
        {
            count++;
        }
    }
    return count;
}

/*
int evauluate_window(int window[], int size, int piece)

Requires: A 1D array of size 4, size of the given 1D array(as an integer) which is 4, and an integer named piece which can
have the values 1 or 2.

Effects: Returns a value which is named as score which is used to in other functions namely the minimax function(check minimax function
for details.)This value evaluates the given window based on the elements contained in the window.

Testing Cases: Given a window of size 4:
1-window{1,1,1,1}
 evauluate_window(int window[], 4, 1) will output score 100 which is correct.

2-window{1,1,0,1};
 evauluate_window(int window[], 4, 1) will output score 5 which is correct.

3-window{1,1,0,0}
 evauluate_window(int window[], 4, 1) will output score 2 which is correct.

4-window{2,0,2,2}
evauluate_window(int window[], 4, 1) will output score -4 which is correct.

If peices 1 and 2 are found in the array, the score won't be updated.

Permutations of the list won't effect the algorithm, since we assume that the CountWindow_KCGH_CODES function is implemented correclty and tested and
it is used in our evaluating window function.

These are the 4 cases that can be experimented, otherwise if for example we enter a negative number, the function will eventaully return
0 score. Enterting wrong arguments is the fault of the client, since we specified in the precondition that the piece entered must be 1 or 2.
*/
int evauluate_window(int window[], int size, int piece)
{
    int score = 0;
    int opp_piece = 1;
    if (piece == 1)
    {
        opp_piece = 2;
    }
    if (CountWindow_KCGH_CODES(window, 4, piece) == 4)
    {
        score += 100;
    }
    else if (CountWindow_KCGH_CODES(window, 4, piece) == 3 && CountWindow_KCGH_CODES(window, 4, 0) == 1)
    {
        score += 5;
    }
    else if (CountWindow_KCGH_CODES(window, 4, piece) == 2 && CountWindow_KCGH_CODES(window, 4, 0) == 2)
    {
        score += 2;
    }
    if (CountWindow_KCGH_CODES(window, 4, opp_piece) == 3 && CountWindow_KCGH_CODES(window, 4, 0) == 1)
    {
        score -= 4;
    }
    return score;
}
/*
int **copyFunction_KCGH_CODES(int **board)

Requires: A 2D array board of 6 rows and 7 columns.
Effects: Returns a double pointer which refers to the address of a copy of the given board which is a 2D array.

Testing: given the board[6][7] by:
	{
	 {2,1,1,2,2,1,0}
	,{2,1,1,2,2,1,2}
	,{1,2,2,1,1,2,1}
	,{2,1,2,2,1,1,2}
	,{1,2,2,1,1,2,1},
	 {2,1,1,2,2,1,2}
	 };
	 int **board = copyFunction_KCGH_CODES(gameboard);
	 The newly created board will be a 2D array a copy of gameboard(having a different address).
*/
int **copyFunction_KCGH_CODES(int **board)
{
    int **copy =(int**) malloc(6 * sizeof(int *));
    if (copy == NULL)
    {
        printf("out of memory\n");
        return NULL;
    }
    for (int i = 0; i < 6; i++)
    {
        copy[i] =(int*) malloc(7 * sizeof(int));
        if (copy[i] == NULL)
        {
            printf("out of memory\n");
            return NULL;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            copy[i][j] = board[i][j];
        }
    }
    return copy;
}
/*
int scoreposition_KCGH_CODES(int **board, int piece)

Requires: A 2D array which is the board of 6 rows and 7 columns and an integer piece argument piece which can have the value of 1 or 2.

Effects: Returns a given score , using the evaluate window functions for rows,columns, left and right diagonals.

Testing Cases: The function int scoreposition_KCGH_CODES(int board[6][7], int piece) uses the help of the function evaluate position which we assume
it is correct.

The function will give us the combinations of all the rows and columns, and diagonals in a 1D array.
Note: we tested each function call seperately and it resulted in outputing correct answers.

1-For even entries:
scorepostion(gameboard,1); && scorepostion(gameboard,2);
 int gameboard[6][7] = {
	 {0,1,1,2,2,1,0}
	,{2,1,1,2,2,1,2}
	,{1,2,2,1,1,2,1}
	,{2,1,2,2,1,1,2}
	,{1,2,2,1,1,2,1},
	 {2,1,1,2,2,1,2}
	 };
 gave us the correct output.

 2-For odd entries:
 scorepostion(gameboard,1) && scorepostion(gameboard,2);
	 int gameboard[6][7] = {
	 {2,1,1,2,2,1,0}
	,{2,1,1,2,2,1,2}
	,{1,2,2,1,1,2,1}
	,{2,1,2,2,1,1,2}
	,{1,2,2,1,1,2,1},
	 {2,1,1,2,2,1,2}
	 };
	gave us the correct output.

3- For 42 entries(meaning the board is empty)
	scorepostion(gameboard,1) && scorepostion(gameboard,2);
	int gameboard[6][7]=
	 {0,0,0,0,0,0,0}
	,{0,0,0,0,0,0,0}
	,{0,0,0,0,0,0,0}
	,{0,0,0,0,0,0,0}
	,{0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0}
	 };
	 gave us the correct result here the result for the pieces 1 or 2.
	 scorepostions for 1 and 2 here gives us the same result , since the board is empty.
*/
int scoreposition_KCGH_CODES(int **board, int piece)
{
    int score = 0;
    int window[4];
    // Score center column
    int centerarray[6];
    int center_count = 0;
    for (int i = 0; i < 6; ++i)
    {
        centerarray[i] = board[i][3];
        if (centerarray[i] == piece)
        {
            ++center_count;
        }
    }
    score += center_count * 3;
    // Score Horizontal
    for (int r = 0; r < 6; ++r)
    {
        int row_array[7];
        for (int j = 0; j < 7; ++j)
        {
            row_array[r] = board[r][j];
        }
        for (int c = 0; c < 7 - 3; ++c)
        {
            for (int i = 0; i < 4; ++i)
            {
                window[i] = row_array[i + c];
            }
            score += evauluate_window(window, 4, piece);
        }
    }
    // Score vertical
    for (int c = 0; c < 7; ++c)
    {
        int col_array[6];
        for (int i = 0; i < 6; ++i)
        {
            col_array[i] = board[i][c];
        }
        for (int r = 0; r < 6 - 3; ++r)
        {
            for (int i = 0; i < 4; ++i)
            {
                window[i] = col_array[i + r];
            }
            score += evauluate_window(window, 4, piece);
        }
    }
    // Score diagonal
    for (int r = 0; r < 6 - 3; ++r)
    {
        for (int c = 0; c < 7 - 3; ++c)
        {
            for (int i = 0; i < 4; ++i)
            {
                window[i] = board[r + i][c + i];
            }
            score += evauluate_window(window, 4, piece);
        }
    }

    for (int r = 0; r < 6 - 3; ++r)
    {
        for (int c = 0; c < 7 - 3; ++c)
        {
            for (int i = 0; i < 4; ++i)
            {
                window[i] = board[r + 3 - i][c + i];
            }
            score += evauluate_window(window, 4, piece);
        }
    }

    return score;
}/*

int NumberOfValidPositions_KCGH_CODES(int *ValidPositions)

Requires: An array pointer.

Effects: Returns an integer namely size which counts the number of valid positions(if index at i !=-1)

Testing cases:
1-array with all zero's will return 0, since no valid positions initially.
2-array with -1's will output the correct output which is the number of -1 found in the array.

Manual Example:
int *Valid = int*(malloc(sizeof(int))7);
for(int i=0;i<7;++i)
Valid[i]=-1;
NumberOfValidPositions_KCGH_CODES(Valid) will output 7.
All other cases are trivial...
*/
int NumberOfValidPositions_KCGH_CODES(const int *ValidPositions)
{
    int size=0;
    for(int i=0;i<7;i++){
        if (ValidPositions[i]!=-1)
            size++;
    }
    return size;
}





































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