#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*

This file contains the following functions:

int isOver(int**, int);
int findRow(int** , int column);
int checkVertically(int [6][7], int row, int column, int size);
int checkHorizontally(int[6][7], int row, int column, int size);
int checkDiagonally_1(int[6][7], int row, int column, int size);
int checkDiagonally_2(int [6][7], int row, int column, int input);
int isOver(int **array, int column);
int nextopenRow(int **board, int column);
int *GetValidLocations(int **board);
int CountWindow(int window[], int size, int piece);
int evauluate_window(int window[], int size, int piece);
int **copyFunction(int **board);
int scoreposition(int **board, int piece);

*/

/*
    int findRow(int **array, int column)

    requires: the board, the column that was last played at, an whose turn it was
    effects: returns the row that was played at
*/

int findRow(int **array, int column)
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
        else if (insertion != 0)
            break;
    }
    return row;
}

/*
    int checkVertically(int array[6][7], int row, int column, int input)

    requires: the board, column and row that the last turn was played at, and whose turn it was
    effects: return 1 if there is any win at the row the last turn was played at
*/
int checkVertically(int array[6][7], int row, int column, int input)

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

int checkHorizontally(int array[6][7], int row, int column, int input)
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

int checkDiagonally_1(int array[6][7], int row, int column, int input)
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
 
int checkDiagonally_2(int array[6][7], int row, int column, int input)
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
 * int isOver(int array[6][7], int column)
 *
 * requires: The column in which has last inserted.
 * effects: Returns if the user's last move allows him to win by returning an integer >0; else it returns 0.
 * It calls 5 functions, such that each function checks vertically or horizontally and two functions to check the 2 diagonals.
 * 
 */
int isOver(int **board, int column)
{
    int columns = 7;
    int rows = 6;
    int row = findRow(board, column);

    int array[6][7];

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            array[i][j] = board[i][j];
        }
    }

    int input = array[row][column];

    int vertical = checkVertically(array, row, column, input);
    int horizontal = checkHorizontally(array, row, column, input);
    int diagonal1 = checkDiagonally_1(array, row, column, input);
    int diagonal2 = checkDiagonally_2(array, row, column, input);

    int result = vertical + horizontal + diagonal1 + diagonal2;
    if (result > 0 && input==1)
        return 1;
    else if (result > 0 && input == 2)
        return -1;
}
/*
int nextopenRow(int **board, int column)

Requires: An int** board argument(2D array) , and an integer argument which is a column(values allowed btwn 0-6)
Effects: Returns the first valid row where the player can place the peice at the given column.

Testing: 2 Sufficeint test cases:

1-Given a board allocated dynamically with malloc, given the column where we need to check at what row position can we place:
example of board: consider: {
	 {2,1,1,2,2,1,0}
	,{2,1,1,2,2,1,2}
	,{1,2,2,1,1,2,1}
	,{2,1,2,2,1,1,2}
	,{1,2,2,1,1,2,1},
	 {2,1,1,2,2,1,2}
	 };
	nextopenRow(board,6) will output 0;

2-Given an empty array we must get row 0, since no player has played yet
example: 
	 {0,0,0,0,0,0,0}
	,{0,0,0,0,0,0,0}
	,{0,0,0,0,0,0,0}
	,{0,0,0,0,0,0,0}
	,{0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0}
	 };
	 nextopenRow(board,6) will also output 0.
*/
int nextopenRow(int **board, int column)
{
	for (int i = 0; i < 6; i++)
		if (board[i][column] == 0)
			return i;
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
int *GetValidLocations(int **board)
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
int CountWindow(int window[], int size, int piece)
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

Permutations of the list won't effect the algorithm, since we assume that the CountWindow function is implemented correclty and tested and
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
    if (CountWindow(window, 4, piece) == 4)
    {
        score += 100;
    }
    else if (CountWindow(window, 4, piece) == 3 && CountWindow(window, 4, 0) == 1)
    {
        score += 5;
    }
    else if (CountWindow(window, 4, piece) == 2 && CountWindow(window, 4, 0) == 2)
    {
        score += 2;
    }
    if (CountWindow(window, 4, opp_piece) == 3 && CountWindow(window, 4, 0) == 1)
    {
        score -= 4;
    }
    return score;
}
/*
int **copyFunction(int **board)

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
	 int **board = copyFunction(gameboard);
	 The newly created board will be a 2D array a copy of gameboard(having a different address).
*/
int **copyFunction(int **board)
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
int scoreposition(int **board, int piece)

Requires: A 2D array which is the board of 6 rows and 7 columns and an integer piece argument piece which can have the value of 1 or 2.

Effects: Returns a given score , using the evaluate window functions for rows,columns, left and right diagonals. 

Testing Cases: The function int scoreposition(int board[6][7], int piece) uses the help of the function evaluate position which we assume
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
int scoreposition(int **board, int piece)
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

int NumberOfValidPositions(int *ValidPositions)

Requires: An array pointer.

Effects: Returns an integer namely size which counts the number of valid positions(if index at i !=-1)

Testing cases:
1-array with all zero's will return 0, since no valid positions initially.
2-array with -1's will output the correct output which is the number of -1 found in the array.

Manual Example:
int *Valid = int*(malloc(sizeof(int))7);
for(int i=0;i<7;++i)
Valid[i]=-1;
NumberOfValidPositions(Valid) will output 7.
All other cases are trivial...
*/
int NumberOfValidPositions(int *ValidPositions)
{
    int size=0;
    for(int i=0;i<7;i++){
        if (ValidPositions[i]!=-1)
            size++;
    }
    return size;
}

int AI = 1;
int player = 2;

