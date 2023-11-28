#include <stdio.h>
#include <stdbool.h>
#define N 4
int board[N][N];

void printBoard() {
	int i,j;
    for ( i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int row, int col) {
	int i,j;
    for ( i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
    for ( i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for ( i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}
bool solveNQueens(int col) {
	int i;
    if (col >= N) {
        return true;  
    }
    for ( i = 0; i < N; i++) 
	{
        if (isSafe(i, col)) 
		{
            board[i][col] = 1;
            if (solveNQueens(col + 1)) 
			{
                return true;
            }
			board[i][col] = 0;
        }
    }

    return false;  
}

int main() {
	int i,j;
    for ( i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQueens(0)) 
	{
        printf("Solution exists:\n");
        printBoard();
    } 
	else 
        printf("Solution does not exist.\n");
    
}
