/*
* int isOver(int array[6][7], int column)
* requires: The column in which has last inserted.
* effects: Returns if the user's last move allows him to win by returning an integer >0; else it returns 0.
* It calls 5 functions, such that each function checks vertically or horizontally and two functions to check the 2 diagonals.
*
*/

#include <stdio.h>
void print_Array(int [6][7]);
int isOver(int[6][7],int,int);
int findRow(int[6][7],int column,int input);
int checkVertically(int[6][7], int row, int column,int size);
int checkHorizontally(int[6][7], int row, int column,int size);
int checkDiagonally_1(int[6][7], int row, int column,int size);

void print_Array(int array[6][7])
{
	int i = 0;
	int j = 0;
	int rows = 6;
	int columns = 7;

	for (i; i < rows; i++)
	{
		for (j; j < columns; j++)
		{
			printf("%2d", array[i][j]);
		}
		j = 0;
		printf("\n");
	}
}


int findRow(int array[6][7],int column,int input)
{
	int row = 0;
	int i = 0;
	int insertion = array[0][column];
	if (insertion == input)
		row = 0;
	else
	{
		insertion = -1;
		while (insertion != input)
		{
			insertion = array[++i][column];
		}
		row = i;
	}
	return row;
}

int checkVertically(int array[6][7], int row, int column, int input)
{
	int i = 0;
	int j = i;
	int streak=0;
	
	while (5 - i >= 3)
	{
		for (j; j < 4+i; j++)
		{
			if (array[j][column] == input)
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

int checkHorizontally(int array[6][7], int row, int column,int input)
{
	int i = 0;
	int j = i;
	int streak = 0;

	while (6 - i >= 3)
	{
		for (j; j < 4 + i; j++)
		{
			if (array[row][j] == input)
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
			if (diagonal[j+i] == input)
				streak++;
		}
		if (streak == 4)
			return 1;
		j = 0;
		streak = 0;
	}
	return 0;
}

int checkDiagonally_2(int array[6][7], int row, int column,int input)
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
			if (diagonal[j + i] == input)
				streak++;
		}
		if (streak == 4)
			return 1;
		j = 0;
		streak = 0;
	}
	return 0;
}
int isOver(int array[6][7], int column,int input)
{
	int columns = 7;
	int rows = 6;
	int row = findRow(array,column,input);

	int vertical = checkVertically(array,row,column,input);
	int horizontal = checkHorizontally(array,row,column,input);
	int diagonal1 = checkDiagonally_1(array,row,column,input);
	int diagonal2 = checkDiagonally_2(array,row,column,input);

	return vertical + horizontal + diagonal1 + diagonal2;
	
}