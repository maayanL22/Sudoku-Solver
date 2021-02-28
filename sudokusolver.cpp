#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define empty 0
#define N 9
bool isGridSafe(int grid[N][N], int row, int col, int num);
bool isEmptyLocation(int grid[N][N], int &row, int &col);
/* assign values to all the zero (not assigned) values for Sudoku solution
 */

//check if there is an empty position
bool isEmptyLocation(int grid[N][N], int &row, int &col)
{
	for(row = 0; row < N; row++)
	{ 
		for(col = 0; col < N; col++)
		{ 
			if(grid[row][col] == empty)
			{ 
				return true;
			}
		}
	}
	return false;
}

//checking if number num is already placed in the current row
bool isRowLegal(int grid[N][N], int &row, int num)
{
	for (int col = 0; col < N; col++)
	{
		if(grid[row][col] == num)
		{ 
			return false;
		}
	}
	return true;
}


//checking if number num is already placed in the current column
bool isColLegal(int grid[N][N], int &col, int num)
{
	for (int row = 0; row < N; row++)
	{
		if (grid[row][col] == num)
		{
			return false;
		}
	}
	return true;
}


//checking if number num is already placed in the current box (which is decided by the row and col params)
bool isBoxLegal(int grid[N][N], int row, int col, int num)
{
	int boxrow1 = row - row % 3;
	int boxcol1 = col - col % 3;

	for(int r = boxrow1; r < boxrow1 + 3; r++)
	{ 
		for(int c = boxcol1; c < boxcol1 + 3; c++)
		{ 
			if(grid[r][c] == num)
			{ 
				return false;
			}
		}
	}
	return true;
}

//Checks if num can be assigned to a given prow,pcol location. 
bool isGridSafe(int grid[N][N], int row, int col, int number)
{
	return isRowLegal(grid, row, number) && isColLegal(grid, col, number) &&
		isBoxLegal(grid, row, col, number);
}

/* print result  */
void printResult(int finalgrid[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			cout << finalgrid[row][col] << "  ";
		cout << endl;
	}
}

bool SolveSudoku(int grid[N][N])
{
	int row, col;
	if (!isEmptyLocation(grid, row, col))
		return true;
	for (int num = 1; num <= 9; num++)
	{
		if (isGridSafe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (SolveSudoku(grid))
				return true;
			grid[row][col] = empty;
		}
	}
	return false;
}

/* Main */
int main()
{
	cout << "Hello" << endl;
	int grid[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 3, 0, 8, 5},
					  {0, 0, 1, 0, 2, 0, 0, 0, 0},
					  {0, 0, 0, 5, 0, 7, 0, 0, 0},
					  {0, 0, 4, 0, 0, 0, 1, 0, 0},
					  {0, 9, 0, 0, 0, 0, 0, 0, 0},
					  {5, 0, 0, 0, 0, 0, 0, 7, 3},
					  {0, 0, 2, 0, 1, 0, 0, 0, 0},
					  {0, 0, 0, 0, 4, 0, 0, 0, 9} };
	if (SolveSudoku(grid) == true)
		printResult(grid);
	else
		cout << "No solution found" << endl;
	return 0;
}