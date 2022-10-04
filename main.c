#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
void initializeBoard(int board[6][7]){
    int i;
    int j;
    for (i=0;i<6;i++){
        for (j=0;j<7;j++){
            board[i][j]=0;
        }
    }
}
void initializeInputArray(char arr[100]){
for(int i=0;i<100;i++){
    arr[i]=0;
}
}
//updates the entries after each play.
void updateBoard(int column,int board[6][7],char player){
    int i;
    for (i=5;i>=0;i--){
        if (board[i][column-1]==0&&player=='R'){
            board[i][column-1]=1;
            break;
        }
        else if (board[i][column-1]==0&&player=='Y'){
            board[i][column-1]=2;
            break;
        }
    }
}
bool valid_And_Legal(char input[100], int board[6][7]){
    //get the ascii value of the whole input to make sure it is valid.
    int result=0;
   for(int i=0;i<100;i++){
    if (input[i]!=' '||input[i]!='\n')
    result+=input[i];
   }
   //we subtract 10 because when we hit ENTER after writing an input,
   //fgets adds it to the input array as a line feed "\n" which has
   //an ascii code 10.
   result=result-10;
   if (result<49||result>55){
       printf("Please enter a number between 1 and 7\n");
    return false;
    }
    // At this point the input is val
    int column=input[0]-'0';
   // if (column<1||column>7){
    //    printf("Invalid input, Please enter a Number between 1 and 7!\n");
    //    return false;
   // }
    //Check if a move is legal.
     if (board[0][column-1]!=0){
            printf("Column is full, try with another one!\n");
            return false;
    }

    return true;
}
void printBoard(int board[6][7]){
    int i;
    int j;
    for (i=0;i<15;i++){
        printf("- ");
    }
    printf("\n");
    for(i=0;i<6;i++){
        for (j=0;j<7;j++){
            printf("| %d ",board[i][j]);
        }
        printf("|\n");
    }
    for (i=0;i<15;i++){
        printf("- ");
    }
    printf("\n");
}

void Connect4(int board[6][7],char input[100]){
    initializeBoard(board);
    initializeInputArray(input);
    int column;
    int k=0;//for the number of tries.
    //Randomly choose who starts here.
    while (k<42){
    fgets(input,100,stdin);
    while (valid_And_Legal(input,board)==0){
        initializeInputArray(input);
        fgets(input,100,stdin);
    }
    column=input[0]-'0';
    printf("%d",column);
    updateBoard(column,board,'R');
    printBoard(board);
   k++;
    }

}
int main()
{
    int board[6][7];
    char arr[100];
    Connect4(board,arr);
}
