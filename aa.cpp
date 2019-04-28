#include<iostream>
using namespace std;
void PrintSpiral(int **a, int rowsStart, int rowsEnd, int colsStart, int colsEnd)
{
	if(rowsStart > rowsEnd && colsStart>colsEnd)
		return;

	// Print top row
	for(int i = colsStart ; i<=colsEnd; i++)
		cout<<a[rowsStart][i]<<" ";

	// If row start == row end then all the element got print in the previous loop
	// no need to print any column so putting the breaking condition for columns
	if(rowsStart == rowsEnd)
		colsStart = colsEnd+1;

	// Top row is done so remove the top row
	rowsStart++;

	// Print right rows
	for(int i = rowsStart ; i<=rowsEnd; i++)
		cout<<a[i][colsEnd]<<" ";

	// If col start == col end then all the element got print in the previous loop
	// no need to print any rows so putting the breaking condition for rows
	if(colsStart == colsEnd)
		rowsStart = rowsEnd+1;

	// Right most column is done so removing it
	colsEnd--;

	// Print Bottom row
	for(int i = colsEnd ; i>=colsStart; i--)
		cout<<a[rowsEnd][i]<<" ";

	// If row start == row end then all the element got print in the previous loop
	// no need to print any column so putting the breaking condition for columns
	if(rowsStart == rowsEnd)
		colsStart = colsEnd+1;

	// Bottom row is done so removing it
	rowsEnd--;
	// Print Left Row
	for(int i = rowsEnd ; i>=rowsStart; i--)
		cout<<a[i][colsStart]<<" ";

	// If col start == col end then all the element got print in the previous loop
	// no need to print any rows so putting the breaking condition for rows
	if(colsStart == colsEnd)
		rowsStart = rowsEnd+1;

	// left most column is done so removing it
	colsStart++;
	PrintSpiral(a, rowsStart, rowsEnd, colsStart, colsEnd);
}
int main()
{


    int **p=new int*[5];
    for(int i=0;i<5;i++)
    {
        p[i]=new int;
    }
    for(int i=0;i<=5;i++)
        for(int j=0;j<5;j++)
    {
        p[i][j]=i*j;
    }

    PrintSpiral(p,5,5,5,5);
}
