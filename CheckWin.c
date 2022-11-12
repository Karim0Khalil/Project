#include <stdio.h>
#include <math.h>
void print_Array(int [6][7]);
int isOver(int[6][7],int,int);
int findRow(int[6][7],int column,int input);
int checkVertically(int[6][7], int row, int column,int size);
int checkHorizontally(int[6][7], int row, int column,int size);
int checkDiagonally_1(int[6][7], int row, int column,int size);

//requires: the board as a 2D array
//effects: prints the array as a form of a matrix
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


//requires: the board, the column that was last played at, an whose turn it was
//effects: returns the row that was played at
int findRow(int array[6][7],int column)
{
	int i=0;
	int row = 0;
	int insertion = array[row][column];
	while (i==0)
	{
		if(insertion == 0)
			row++;
		else if(insertion !=0)
			break;
	}
	return row;
}

//requires: the board, column and row that the last turn was played at, and whose turn it was
//effects: return 1 if there is any win at the row the last turn was played at
int checkVertically(int array[6][7], int row, int column, int input)
{
	int i = 0;
	int j = i;
	int streak=0;
	
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

//requires: the board, column and row that the last turn was played at, and whose turn it was
//effects: return 1 if there is any win at the column the last turn was played at
int checkHorizontally(int array[6][7], int row, int column,int input)
{
	int i = 0;
	int j = i;
	int streak = 0;

	while (6 - i >= 3)  //there are 4 possible wins at each horizontal level
	{
		for (j; j < 4 + i; j++)
		{
			if (array[row][j] == input) //checks that if there is a win, the win must be from one player only
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


//requires: the board, column and row that the last turn was played at, and whose turn it was
//effects: return 1 if there is any win at the diagonal to the right the last turn was played at
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


//requires: the board, column and row that the last turn was played at, and whose turn it was
//effects: return 1 if there is any win at the diagonal to the left the last turn was played at
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
* requires: The column in which has last inserted.
* effects: Returns if the user's last move allows him to win by returning an integer >0; else it returns 0.
* It calls 5 functions, such that each function checks vertically or horizontally and two functions to check the 2 diagonals.
*
*/
int isOver(int array[6][7], int column)
{
	int columns = 7;
	int rows = 6;
	int row = findRow(array,column);
	int input = array[row][column];

	int vertical = checkVertically(array,row,column,input);
	int horizontal = checkHorizontally(array,row,column,input);
	int diagonal1 = checkDiagonally_1(array,row,column,input);
	int diagonal2 = checkDiagonally_2(array,row,column,input);

	int result= vertical + horizontal + diagonal1 + diagonal2;
	if(result>0 && input==1)
		return 1;
	else if(result>0 && input==2)
		return -1;
}
int nextopenRow(int **board, int column)
{
	for (int i=0;i<6;i++)
	if(board[i][column] == 0)
		return i;
}
int * GetValidLocations(int board[6][7]){
	int * arr = (int*)malloc(sizeof(int)*7);
	for(int i=0;i<7;++i){
		arr[i]=-1;
	}
	for(int i=0;i<7;++i){
		if(board[0][i]==0)
			arr[i]=i;
			}
	return arr;
}

int is_terminal_node(int ** board,int column)
{
	return isOver(board,column);
}
int Length(int *array){
	return sizeOf(array)/sizeOf(array[0]);
}
int maximizingplayer=1;
int minimizingplayer=2;
int *minimax(int ** board,int depth, double alpha, double beta, int Player, int columnPlayed)
{
	int * validLocations = GetValidLocations(board);
	int * play = malloc(2*sizeof(int));
	if(columnPlayed!=-1)
	{
		int Who_won=isOver(board,columnPlayed);
		if (Who_won==1)
		{
		play[0]= NULL;
		play[1]=10000000;
		return play;
	  
		}
		else if (Who_won==-1){
		play[0]= NULL;
		play[1]=-10000000;
		return play;
		}
		else if(Length(validLocations)==0)
		{
			play[0]=NULL;
			play[1]=0;
		}
		// else {
		// 	play[0]=NULL;
		// 	play[1]=scoringpositions.
		// 	return play;
		// }
	} 
	else 
	{
		if (Player==maximizingplayer){
			long long int value=-999999999999;
			int column =0;
			for(int col=0;col<Length(validLocations);col++)
			{
				int row = nextopenRow(board,col);
				updateBoard(col,board,'R');
				int new_score= minimax(board,depth-1,alpha,beta,2,col);
				if(new_score>value)
				{
					value=new_score;
					column=col;
				}
				if(value>=alpha)
					alpha=value;
				if(alpha >= beta)
					break;
				play[0]=column;
				play[1]=value;

				return play;
			}

		}
		else {
			long long int value=999999999999;
			int column =0;
			for(int col=0;col<Length(validLocations);col++)
			{
				int row = nextopenRow(board,col);
				updateBoard(col,board,'R');
				int new_score= minimax(board,depth-1,alpha,beta,2,col);
				if(new_score>value)
				{
					value=new_score;
					column=col;
				}
				if(value<=beta)
					beta=value;
				if(beta <= alpha)
					break;
				play[0]=column;
				play[1]=value;

				return play;
			}

		}
	}

}
