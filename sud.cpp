#include<iostream>
using namespace std;
bool FindUnassignedLocation(int grid[NN][NN], int &row, int &col);
bool isSafe(int grid[NN][NN], int row, int col, int num);
/* assign values to all unassigned locations for Sudoku solution
 */
bool SolveSudoku(int grid[NN][NN])
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}
/* Searches the grid to find an entry that is still unassigned. */
bool FindUnassignedLocation(int grid[NN][NN], int &row, int &col)
{
    for (row = 0; row < NN; row++)
        for (col = 0; col < NN; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
/* Returns whether any assigned entry n the specified row matches
   the given number. */
bool UsedInRow(int grid[NN][NN], int row, int num)
{
    for (int col = 0; col < NN; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
/* Returns whether any assigned entry in the specified column matches
   the given number. */
bool UsedInCol(int grid[NN][NN], int col, int num)
{
    for (int row = 0; row < NN; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}/* Returns whether any assigned entry within the specified 3x3 box matches
   the given number. */
bool UsedInBox(int grid[NN][NN], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}/* Returns whether it will be legal to assign num to the given row,col location.
 */
bool isSafe(int grid[NN][NN], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 , col - col % 3, num);
}
/* print grid  */
void printGrid(int grid[NN][NN])
{
    for (int row = 0; row < NN; row++)
    {
        for (int col = 0; col < NN; col++)
            cout<<grid[row][col]<<"  ";
        cout<<endl;
        }
}
int main()
{
 int grid[NN][NN];
    cout<<"Solving 9*9 sudoku:"<<endl;
    cout<<"enter sudoku row wise:"<<endl;
    cout<<"enter 0 for unknown:"<<endl;
    for(int i=0;i<NN;i++)
    {
        for(int j=0;j<NN;j++)
        {
            cout<<"enter "<<i<<" "<<j<<" "<<"digit:";
            cin>>grid[i][j];
        }
    }

    if (SolveSudoku(grid) == true)
          printGrid(grid);
    else
        cout<<"No solution exists"<<endl;
        break;
}
