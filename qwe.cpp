//
// Created by jainil on 7/19/2017.
//

#include <cstdlib>
#include<vector>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<conio.h>
#include<cmath>
#include<cstring>
#include<iomanip>
#include <complex>
#include<dos.h>
#include<algorithm>
#include<ctime>
#define UNASSIGNED 0
using namespace std;
const double PI = 3.14159265358979323846;
const int NN=9;
//Print values
void print_ar(int ar[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}

//Shell sort function
void shell_sort(int ar[], int size)
{
    int j;

    //Narrow the array by 2 everytime
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; ++i)
        {
            int temp = ar[i];
            for (j = i; j >= gap && temp < ar[j - gap]; j -= gap)
            {
                ar[j] = ar[j - gap];
            }
            ar[j] = temp;
        }
    }
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver program to test above functions

class linearsort
{
    int arr[10000], n;

public:
    void getdataelements();

    void showdataelements();

    void sortelements();
};

void linearsort::getdataelements()
{
    cout << "How many elements you want : ";
    cin >> n;

    cout << "enter elements :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void linearsort::showdataelements()
{
    cout << "\nDisplay sorted elements\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }

}

void linearsort::sortelements()
{
    int temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void merge(int *, int, int, int);

void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
    return;
}

void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}


int Partition(int a[], int beg, int end)
{
    int p = beg, pivot = a[beg], loc;

    for (loc = beg + 1; loc <= end; loc++)
    {
        if (pivot > a[loc])
        {
            a[p] = a[loc];
            a[loc] = a[p + 1];
            a[p + 1] = pivot;

            p = p + 1;
        }
    }
    return p;
}


void QuickSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int p = Partition(a, beg, end);
        QuickSort(a, beg, p - 1);
        QuickSort(a, p + 1, end);
    }
}

void bubble_sort(vector<int> &a)
{
    for (int i = a.size(); i > 0; i--)
    {
        for (int j = 0, k = 1; k < i; j++, k++)
        {
            if (a[j] > a[k])
            {
                int swap = a[j];
                a[j] = a[k];
                a[k] = swap;
            }
        }
    }
}

struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;
class double_llist
{
    public:
        void create_list(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_dlist();
        void count();
        void reverse();
        double_llist()
        {
            start = NULL;
        }
};
void double_llist::create_list(int value)
{
    struct node *s, *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}

void double_llist::add_begin(int value)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element Inserted"<<endl;
}

void double_llist::add_after(int value, int pos)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->info = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Element Inserted"<<endl;
}

void double_llist::delete_element(int value)
{
    struct node *tmp, *q;
     /*first element deletion*/
    if (start->info == value)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {
        /*Element deleted in between*/
        if (q->next->info == value)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element Deleted"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
     /*last element deleted*/
    if (q->next->info == value)
    {
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Element Deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
}

void double_llist::display_dlist()
{
    struct node *q;
    if (start == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = start;
    cout<<"The Doubly Link List is :"<<endl;
    while (q != NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}

void double_llist::count()
{
    struct node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout<<"Number of elements are: "<<cnt<<endl;
}

void double_llist::reverse()
{
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    cout<<"List Reversed"<<endl;
}

class single_llist
{
    public:
        node* create_node(int);
        void insert_begin();
        void insert_pos();
        void insert_last();
        void delete_pos();
        void sort();
        void search();
        void update();
        void reverse();
        void display();
        single_llist()
        {
            start = NULL;
        }
};
node *single_llist::create_node(int value)

{
struct node *temp, *s;
temp = new(struct node);
if (temp == NULL)
{
cout<<"Memory not allocated "<<endl;
return 0;
}
else
{
temp->info = value;
temp->next = NULL;
return temp;
}
}

void single_llist::insert_begin()
{
int value;
cout<<"Enter the value to be inserted: ";
cin>>value;
struct node *temp, *p;
temp = create_node(value);
if (start == NULL)
{
start = temp;
start->next = NULL;
}
else
{
p = start;
start = temp;
start->next = p;
}
cout<<"Element Inserted at beginning"<<endl;
}

void single_llist::insert_last()
{
int value;
cout<<"Enter the value to be inserted: ";
cin>>value;
struct node *temp, *s;
temp = create_node(value);
s = start;
while (s->next != NULL)

{
s = s->next;
}
temp->next = NULL;
s->next = temp;
cout<<"Element Inserted at last"<<endl;
}

void single_llist::insert_pos()
{
int value, pos, counter = 0;
cout<<"Enter the value to be inserted: ";
cin>>value;
struct node *temp, *s, *ptr;
temp = create_node(value);
cout<<"Enter the postion at which node to be inserted: ";
cin>>pos;
int i;
s = start;
while (s != NULL)
{
s = s->next;
counter++;
}
if (pos == 1)
{
if (start == NULL)
{
start = temp;
start->next = NULL;
}
else
{
ptr = start;
start = temp;
start->next = ptr;
}
}
else if (pos > 1 && pos <= counter)
{
s = start;
for (i = 1; i < pos; i++)
{
ptr = s;
s = s->next;
}

ptr->next = temp;
temp->next = s;
}
else
{
cout<<"Positon out of range"<<endl;
}
}

void single_llist::sort()
{
struct node *ptr, *s;
int value;
if (start == NULL)
{
cout<<"The List is empty"<<endl;
return;
}
ptr = start;
while (ptr != NULL)
{
for (s = ptr->next;s !=NULL;s = s->next)
{
if (ptr->info > s->info)
{
value = ptr->info;
ptr->info = s->info;
s->info = value;
}
}
ptr = ptr->next;
}
}

void single_llist::delete_pos()
{
int pos, i, counter = 0;
if (start == NULL)
{
cout<<"List is empty"<<endl;
return;
}
cout<<"Enter the position of value to be deleted: ";
cin>>pos;
struct node *s, *ptr;
s = start;
if (pos == 1)
{
start = s->next;
}
else
{
while (s != NULL)
{
s = s->next;

counter++;
}
if (pos > 0 && pos <= counter)
{
s = start;
for (i = 1;i < pos;i++)
{
ptr = s;
s = s->next;
}
ptr->next = s->next;
}
else
{
cout<<"Position out of range"<<endl;
}
free(s);
cout<<"Element Deleted"<<endl;
}
}

void single_llist::update()
{
int value, pos, i;
if (start == NULL)
{
cout<<"List is empty"<<endl;
return;
}
cout<<"Enter the node postion to be updated: ";
cin>>pos;
cout<<"Enter the new value: ";
cin>>value;
struct node *s, *ptr;
s = start;
if (pos == 1)
{
start->info = value;
}
else
{
for (i = 0;i < pos - 1;i++)
{
if (s == NULL)
{
cout<<"There are less than "<<pos<<" elements";
return;
}
s = s->next;
}
s->info = value;
}
cout<<"Node Updated"<<endl;

}

void single_llist::search()
{
int value, pos = 0;
bool flag = false;
if (start == NULL)
{
cout<<"List is empty"<<endl;
return;
}
cout<<"Enter the value to be searched: ";
cin>>value;
struct node *s;
s = start;
while (s != NULL)
{
pos++;
if (s->info == value)
{
flag = true;
cout<<"Element "<<value<<" is found at position "<<pos<<endl;
}
s = s->next;
}
if (!flag)
cout<<"Element "<<value<<" not found in the list"<<endl;
}

void single_llist::reverse()
{
struct node *ptr1, *ptr2, *ptr3;
if (start == NULL)
{
cout<<"List is empty"<<endl;
return;
}
if (start->next == NULL)
{
return;
}
ptr1 = start;
ptr2 = ptr1->next;
ptr3 = ptr2->next;
ptr1->next = NULL;
ptr2->next = ptr1;
while (ptr3 != NULL)
{
ptr1 = ptr2;
ptr2 = ptr3;
ptr3 = ptr3->next;
ptr2->next = ptr1;
}
start = ptr2;
}

void single_llist::display()
{
    struct node *temp;
    if (start == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = start;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void convetTo(int value)
{
    const char * const ones[20] = {"zero", "one", "two", "three","four","five","six","seven",
     "eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
     "eighteen","nineteen"};

 const char * const tens[10] = {"", "ten", "twenty", "thirty","forty","fifty","sixty","seventy",
     "eighty","ninety"};

    if(value<0)
     {
  cout<<"minus ";
         convetTo(-value);
 }

 else if(value>=1000)
  {
         convetTo(value/1000);
         cout<<" thousand";

         if(value % 1000)
         {
              if(value % 1000 < 100)
              {
                  cout << " and";
              }
              cout << " " ;
              convetTo(value % 1000);
         }
     }

 else if(value >= 100)
     {
         convetTo(value / 100);
         cout<<" hundred";

         if(value % 100)
         {
              cout << " and ";
              convetTo (value % 100);
         }
     }

else if(value >= 20)
{
cout << tens[value / 10];
if(value % 10)
{
cout << " ";
convetTo(value % 10);
}
}

else
{
cout<<ones[value];
}
}
void drawTriangle(char border, char filler, int length)
{
    int start = 2;
    int base = 4;
    int i;
    for (i = start; i <= length; i++)
    {
        for (int sp = 0; sp <= length - i; sp++)
        {
            cout << " ";
        }
        if (i > start)
        {
            cout << border << " ";
        }
        if (i > start)
        {
            for (int b = base; b <= i; b++)
            {
                cout << filler << " ";
            }
        }
        cout << border << " ";
        cout << endl;
    }

    for (int j = base; j < length + base; j++)
    {
        cout << border << " ";
    }
    cout << endl;
}


class Calendar
{
 private:
  int month;
  int year;
  int firstday;

 public:
  Calendar(int =03, int =2016);
  void setFirstDay();
  void print();
};

Calendar :: Calendar (int _month, int _year)
{
 month = _month;
 year = _year;
}

void Calendar :: setFirstDay()
{
    //This part determines which day will be the first day of that year (0 for Sunday, 1 for Monday, etc.)
 int day=1;
 int y = year - (14-month)/12;
 int m = month +12 * ((14-month) / 12) -2;
 firstday= (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;
}

void Calendar :: print()
{
 int NumberOfDaysInMonth;
 int FirstDayOfMonth = 0;
 int DayOfWeekCounter = 0;
 int DateCounter = 1;

 switch (month)
 {
   case 1:
  cout<<setw(21)<<"January "<<year;
  NumberOfDaysInMonth = 31;
   break;

   case 2:
  cout<<setw(21)<<"February "<<year;
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    NumberOfDaysInMonth = 29;
  else
    NumberOfDaysInMonth = 28;
    break;



case 3:
cout<<setw(21)<<"March "<<year;
NumberOfDaysInMonth = 31;
break;

case 4:
cout<<setw(21)<<"April "<<year;
NumberOfDaysInMonth = 30;
break;

case 5:
cout<<setw(21)<<"May "<<year;
NumberOfDaysInMonth = 31;
break;

case 6:
cout<<setw(21)<<"June "<<year;
NumberOfDaysInMonth = 30;
break;

case 7:
cout<<setw(21)<<"July "<<year;
NumberOfDaysInMonth = 31;
break;

case 8:
cout<<setw(21)<<"August "<<year;
NumberOfDaysInMonth = 31;
break;

case 9:
cout<<setw(21)<<"September "<<year;
NumberOfDaysInMonth = 30;
break;

case 10:
cout<<setw(21)<<"October "<<year;
NumberOfDaysInMonth = 31;
break;

case 11:
cout<<setw(21)<<"November "<<year;
NumberOfDaysInMonth = 30;
break;

case 12:
cout<<setw(21)<<"December "<<year;
NumberOfDaysInMonth = 31;
break;

}

//Display the days at the top of each month

cout<<"\nSun   Mon   Tue   Wed  Thu   Fri   Sat";
cout<<"\n\n"<<setw(2);

 //Determine where the first day begins

 for (FirstDayOfMonth; FirstDayOfMonth < firstday; ++FirstDayOfMonth)
 {

  cout<<setw(14);
 }

 int tempfirstday=firstday;
 DateCounter = 1;
 DayOfWeekCounter = tempfirstday;

 //This loop represents the date display and will continue to run until
 //the number of days in that month have been reached

 for (DateCounter; DateCounter <= NumberOfDaysInMonth; ++DateCounter)
 {
  cout<<DateCounter<<setw(6);
  ++DayOfWeekCounter;
  if (DayOfWeekCounter > 6)
  {
   cout<<"\n\n"<<setw(2);
   DayOfWeekCounter = 0;
  }
 }
 cout << " \n" ;

 tempfirstday = DayOfWeekCounter + 1;
}

int hcf(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            return hcf(a - b, b);
        }
        else
        {
            return hcf(a, b - a);
        }
    }
    return a;
}
int lcm(int a, int b)
{static int common = 1;
if (common % a == 0 && common % b == 0)
    {
        return common;
    }
    common++;
    lcm(a, b);
    return common;
}
bool FindUnassignedLocation(int grid[NN][NN], int &row, int &col);
bool isSafe(int grid[NN][NN], int row, int col, int num);
/* assign values to all unassigned locations for Sudoku solution
�*/
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
�  the given number. */
bool UsedInRow(int grid[NN][NN], int row, int num)
{
    for (int col = 0; col < NN; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
/* Returns whether any assigned entry in the specified column matches
�  the given number. */
bool UsedInCol(int grid[NN][NN], int col, int num)
{
    for (int row = 0; row < NN; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}/* Returns whether any assigned entry within the specified 3x3 box matches
�  the given number. */
bool UsedInBox(int grid[NN][NN], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}/* Returns whether it will be legal to assign num to the given row,col location.
�*/
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
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                    && square[4] != '4' && square[5] != '5' && square[6] != '6'
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}
void board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}
bool solveQuadratic(double &a, double &b, double &c, double &root)
{
	if(a == 0.0 || abs(a/b) < 1.0e-6)
	{
		if(abs(b) < 1.0e-4)
			return false;
		else
		{
			root = -c/b;
			return true;
		}
	}

	double discriminant = b * b - 4.0 * a * c;
	if(discriminant >= 0.0)
	{
		discriminant = sqrt(discriminant);
		root = (b + discriminant) * -0.5 / a;
		return true;
	}

	return false;
}
bool solveCubic(double &a, double &b, double &c, double &d, double &root)
{
	if(a == 0.0 || abs(a/b) < 1.0e-6)
		return solveQuadratic(b, c, d, root);

	double B = b, C = c/a, D = d/a;

	double Q = (B*B - C*3.0)/9.0, QQQ = Q*Q*Q;
	double R = (2.0*B*B*B - 9.0*B*C + 27.0*D)/54.0, RR = R*R;

	// 3 real roots
	if(RR<QQQ)
	{
        /* This sqrt and division is safe, since RR >= 0, so QQQ > RR,    */
        /* so QQQ > 0.  The acos is also safe, since RR/QQQ < 1, and      */
        /* thus R/sqrt(QQQ) < 1.                                     */
        double theta = acos(R/sqrt(QQQ));
        /* This sqrt is safe, since QQQ >= 0, and thus Q >= 0             */
		double r1, r2, r3;
        r1 = r2 = r3 = -2.0*sqrt(Q);
        r1 *= cos(theta/3.0);
        r2 *= cos((theta+2*PI)/3.0);
        r3 *= cos((theta-2*PI)/3.0);

        r1 -= B/3.0;
        r2 -= B/3.0;
        r3 -= B/3.0;

		root = 1000000.0;

		if(r1 >= 0.0) root = r1;
		if(r2 >= 0.0 && r2 < root) root = r2;
		if(r3 >= 0.0 && r3 < root) root = r3;

        return true;
	}
	// 1 real root
	else
	{
        double A2 = -pow(fabs(R)+sqrt(RR-QQQ),1.0/3.0);
        if (A2!=0.0) {
			if (R<0.0) A2 = -A2;
			root = A2 + Q/A2;
		}
        root -= B/3.0;
        return true;
	}
}

bool solveQuartic(double &a, double &b, double &c, double &d, double &e, double &root)
{
	// When a or (a and b) are magnitudes of order smaller than C,D,E
	// just ignore them entirely.
	if(a == 0.0 || abs(a/b) < 1.0e-6 || abs(a/c) < 1.0e-6)
		return solveCubic(b, c, d, e, root);

	// Uses Ferrari's Method
	double aa = a*a, aaa=aa*a, bb=b*b, bbb=bb*b;
	double alpha = -3.0*bb/(8.0*aa)   + c/a, alpha2 = alpha * alpha;
	double beta  =    bbb/(8.0*aaa) + b*c/(-2.0*aa) + d/a;
	double gamma = -3.0*bbb*b/(256.0*aaa*a) + c*bb/(16.0*aaa) + b*d/(-4.0*aa) + e/a;

	if(beta == 0.0)
	{
		root = b/(-4.0*a) + sqrt(0.5 * (-alpha + sqrt(alpha2 + 4.0*gamma)));
		return true;
	}
	else
	{
		std::complex<double> P = -alpha2/12.0 - gamma;
		std::complex<double> Q = -alpha2*alpha/108.0 + alpha*gamma/3.0 - beta*beta/8.0;
		std::complex<double> R = Q*0.5 + sqrt(Q*Q*0.25 + P*P*P/27.0);
		std::complex<double> U = pow(R, 1.0/3.0);
		std::complex<double> y = -5.0*alpha/6.0 - U;
		if(U != 0.0) y += P/(3.0*U);
		std::complex<double> W = sqrt(alpha + y + y);

		std::complex<double> aRoot;
		bool foundRealRoot = false;

		double firstPart = b/(-4.0*a);
		std::complex<double> secondPart = -3.0*alpha - 2.0*y;
		std::complex<double> thirdPart = 2.0*beta/W;

		aRoot = firstPart + 0.5 * (-W - sqrt(secondPart + thirdPart));
		if(abs(aRoot.imag()) < 1.0e-10 && aRoot.real() >= 0.0)
		{
			root = aRoot.real();
			foundRealRoot = true;
		}

		aRoot = firstPart + 0.5 * (-W + sqrt(secondPart + thirdPart));
		if(abs(aRoot.imag()) < 1.0e-10 && aRoot.real() >= 0.0 &&
			 (!foundRealRoot || aRoot.real() < root))
		{
			root = aRoot.real();
			foundRealRoot = true;
		}

		aRoot = firstPart + 0.5 * (W - sqrt(secondPart - thirdPart));
		if(abs(aRoot.imag()) < 1.0e-10 && aRoot.real() >= 0.0 &&
			 (!foundRealRoot || aRoot.real() < root))
		{
			root = aRoot.real();
			foundRealRoot = true;
		}

		aRoot = firstPart + 0.5 * (W + sqrt(secondPart - thirdPart));
		if(abs(aRoot.imag()) < 1.0e-10 && aRoot.real() >= 0.0 &&
			 (!foundRealRoot || aRoot.real() < root))
		{
			root = aRoot.real();
			foundRealRoot = true;
		}

		return foundRealRoot;
	}
}

long int fact(int n)
{
    long int s=1;
    for(int i=1;i<=n;i++)
    {
        s=s*i;
    }
    return s;
}

void con(int x,int y)
{
    int  a, i, t, j;

int sum=0;
 // x as the number in base-10 and x, as the destination base
a = x;
while (x >= y)
{
    t = 1;
    for (i = 0; x > y; i++)
    {
        x /= y;

    }
    cout<<x;
    for (j = 0; j < i; j++)
    {
        t *= y;
    }
    a = a - (t*x);
    x = a;
    cout<<x;
}
}
int Nz;
int lef = -1, righ = 1, dow = Nz, u = -Nz;
int next(int dir)
{
    if(dir==lef)
    {return u;}
    else if(dir==u)
    {return righ;}
   else if(dir==righ)
    {return dow;}
    else if(dir==dow)
    {return lef;}
}

void fill(int grid[])
{
  int pos = 0, dir = u;
  for (int i = 1; i <= Nz*Nz; i++)
  {
    grid[pos] = i;
    if (pos == 0 || pos == Nz - 1 || pos == Nz*(Nz - 1) || pos == Nz*Nz - 1 || grid[pos + dir] != 0)
    {
      dir = next(dir);
    }
    pos += dir;
  }
}
class date
{
    int dd,mm,yyyy;
    public:
    void getdata()
    {
    cout<<"enter date in dd mm yyyy format:";
    cin>>dd>>mm>>yyyy;
    }
    void putdata()
    {
        cout<<dd<<":"<<mm<<":"<<yyyy<<endl;
    }
    friend void swapdates(date &a,date &b)
    {
        date t;
        t=a;
        a=b;
        b=t;
    }
};
void swap(char &a,char &b)
{
    char t;
    t=a;
    a=b;
    b=t;
}

void swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
}
void swap(float &a,float &b)
{
    float t;
    t=a;
    a=b;
    b=t;
}
void swap(double &a,double &b)
{
    double t;
    t=a;
    a=b;
    b=t;
}

class dist
{
    float inches;
    float feet;
    public:
    void getdata()
    {
        cout<<"enter feet"<<endl;
        cin>>feet;
        cout<<"enter inches"<<endl;
        cin>>inches;
    }
    void putdata()
    {
        cout<<feet<<"'"<<inches<<"''";
    }
    void scale(dist &a,float b)
    {
        a.feet*=b;
        a.inches*=b;
    }

};
class MyString
{
public:
char *value;
int len;

MyString()
{
len=0;
value=0;
}
~MyString()
{
}
MyString(char *s)
{
len=strlen(s);
value=new char[len+1];
strcpy(value,s);
}
MyString(MyString & s)
{
len=s.len;
value=new char[len+1];
strcpy(value,s.value);
}
friend MyString operator+(MyString obj1,MyString obj2);
friend int operator==(MyString obj1,MyString obj2);
friend int operator!=(MyString obj1,MyString obj2);
friend int operator<(MyString obj1,MyString obj2);
friend int operator<=(MyString obj1,MyString obj2);
friend int operator>(MyString obj1,MyString obj2);
friend int operator>=(MyString obj1,MyString obj2);
friend istream & operator >>(istream & ccin,MyString & obj);
friend ostream & operator <<(ostream & ccout,MyString & obj);
};
//end of class defination.



ostream & operator <<(ostream & ccout,MyString & obj)
{
ccout<<"\n Entered String is:"<<obj.value<<"\n";
return ccout;
}





istream & operator >>(istream & ccin,MyString & obj)
{
char* val;
cout<<"enter string:";
cin>>val;
obj.len=strlen(val);
obj.value=new char[obj.len+1];
strcpy(obj.value,val);
return ccin;
}


MyString operator+(MyString obj1,MyString obj2)
{
MyString obj3;
obj3.len=obj1.len+obj2.len;
obj3.value=new char[obj3.len+1];
strcpy(obj3.value,obj1.value);
strcat(obj3.value,obj2.value);
return obj3;
}




int operator==(MyString obj1,MyString obj2)
{
int rel=0;
if(strcmp(obj1.value,obj2.value)==0)
{
rel=1;
}
return rel;
}



int operator<(MyString obj1,MyString obj2)
{
int rel=0;
int result=0;
rel=strcmp(obj1.value,obj2.value);
if(rel<0)
{
result=1;
}
return result;
}



int operator<=(MyString obj1,MyString obj2)
{
int rel=0;
int result=0;
rel=strcmp(obj1.value,obj2.value);
if(rel<=0)
{
result=1;
}
return result;
}




int operator>(MyString obj1,MyString obj2)
{
int rel=0;
int result=0;
rel=strcmp(obj1.value,obj2.value);
if(rel>0)
{
result=1;
}
return result;
}



int operator!=(MyString obj1,MyString obj2)
{
int rel=0;
if(strcmp(obj1.value,obj2.value)!=0)
{
rel=1;
}
return rel;
}



int operator>=(MyString obj1,MyString obj2)
{
int rel=0;
int result=0;
rel=strcmp(obj1.value,obj2.value);
if(rel>0 || rel==0)
{
result=1;
}
return result;
}


class term
{
    public:
    int coef;
    int exp;
    term operator+(term t2)
    {
        term t3;
        t3.coef=coef+t2.coef;
        return t3;
    }
    term operator-(term t2)
    {
        term t3;
        t3.coef=coef-t2.coef;
        return t3;
    }
    term operator*(term t2)
    {
        term t3;
        t3.coef=coef*t2.coef;
        t3.exp=exp+t2.exp;
        return t3;
    }
};
class polynomial
{
public:
int d;
term *t;
polynomial()
{}
    polynomial(int s)
    {
       d=s;
        t=new term[d+1];
        for(int i=d;i>=0;i--)
        {
            t[i].exp=i;
            t[i].coef=0;
        }
    }
    void getdata()
    {
        cout<<"enter coefficients "<<endl;
         for(int i=d;i>=0;i--)
        {
            int a;
            cin>>a;
            t[i].coef=a;
        }
    }
    void putdata()
    {
        for(int i=d;i>=0;i--)
        {
            cout<<t[i].coef<<"x^"<<t[i].exp;
            if(i>0)
            {
                cout<<" + ";
            }
        }
    }
    polynomial operator +(polynomial p2)
    {
    int q;
    if(d>p2.d)
    {
        q=d;
    }
    else
    {
        q=p2.d;
    }
    polynomial p3(q);
    if(d>p2.d)
    {
        for(int i=q;i>=q-p2.d;i--)
        {
            p3.t[i].coef=t[i].coef;
        }
    for(int i=q-p2.d-1;i>=0;i--)
    {
        p3.t[i].coef=t[i].coef+p2.t[i].coef;
    }
    }
    else
    {
       for(int i=q;i>=p2.d-q;i--)
        {
                    p3.t[i].coef=p2.t[i].coef;
        }
        for(int i=p2.d-q+2;i>=0;i--)
        {
            p3.t[i].coef=t[i].coef+p2.t[i].coef;
        }
    }
    return p3;
}
polynomial operator -(polynomial p2)
    {
    int q;
    if(d>p2.d)
    {
        q=d;
    }
    else
    {
        q=p2.d;
    }
    polynomial p3(q);
    if(d>p2.d)
    {
        for(int i=q;i>=q-p2.d;i--)
        {
                    p3.t[i].coef=t[i].coef;
        }
    for(int i=q-p2.d-1;i>=0;i--)
    {
        p3.t[i].coef=t[i].coef-p2.t[i].coef;
    }
    }
    else
    {
       for(int i=q;i>=p2.d-q;i--)
        {
                    p3.t[i].coef=p2.t[i].coef;
        }
        for(int i=p2.d-q+2;i>=0;i--)
        {
            p3.t[i].coef=t[i].coef-p2.t[i].coef;
        }
    }
    return p3;

}
 void operator +=(polynomial p2)
{
    int q;
    if(d>p2.d)
    {
        q=d;
    }
    else
    {
        q=p2.d;
    }
    polynomial p3(q);
    if(d>p2.d)
    {
        for(int i=q;i>=q-p2.d;i--)
        {
                    p3.t[i].coef=t[i].coef;
        }
    for(int i=q-p2.d;i>=0;i--)
    {
        p3.t[i].coef=t[i].coef+p2.t[i].coef;
    }
    }
    else
    {
       for(int i=q;i>=p2.d-q;i--)
        {
                    p3.t[i].coef=p2.t[i].coef;
        }
        for(int i=p2.d-q+1;i>=0;i--)
        {
            p3.t[i].coef=t[i].coef+p2.t[i].coef;
        }
    }

    d=p3.d;
    t=p3.t;
}
void operator -=(polynomial p2)
    {
    int q;
    if(d>p2.d)
    {
        q=d;
    }
    else
    {
        q=p2.d;
    }
    polynomial p3(q);
    if(d>p2.d)
    {
        for(int i=q;i>=q-p2.d;i--)
        {
                    p3.t[i].coef=t[i].coef;
        }
    for(int i=q-p2.d;i>=0;i--)
    {
        p3.t[i].coef=t[i].coef-p2.t[i].coef;
    }
    }
    else
    {
       for(int i=q;i>=p2.d-q;i--)
        {
                    p3.t[i].coef=p2.t[i].coef;
        }
        for(int i=p2.d-q+1;i>=0;i--)
        {
            p3.t[i].coef=t[i].coef-p2.t[i].coef;
        }
    }
    d=p3.d;
    t=p3.t;
}
polynomial operator *(polynomial p2)
{
    int x;
    x=d+p2.d;
    polynomial p3(x);
    for(int i=d;i>=0;i--)
    {
        for(int j=p2.d;j>=0;j--)
        {
            p3.t[i+j]=p3.t[i+j]+(t[i]*p2.t[j]);
        }
    }
    return p3;
}
void operator *=(polynomial p2)
{
    int x;
    x=d+p2.d;
    polynomial p3(x);
    for(int i=d;i>=0;i--)
    {
        for(int j=p2.d;j>=0;j--)
        {
            p3.t[i+j]=p3.t[i+j]+(t[i]*p2.t[j]);
        }
    }
    d=p3.d;
    t=p3.t;
}
};
class array
{
    public:
    double *d;
    int len;
    void getdata()
    {
        cout<<"enter no of terms\n";
        cin>>len;
        d=new double[len];
        cout<<"enter "<<len<<" numbers\n";
        for(int i=0;i<len;i++)
        {
            cin>>d[i];
        }
    }
    void putdata()
    {
        for(int i=0;i<len;i++)
        {
            cout<<d[i]<<" ";
        }
    }
    friend ostream & operator <<(ostream & ccout,array & obj);
    friend istream & operator >>(istream & ccin,array & obj);
    friend int operator ==(array a,array b);
    friend int operator !=(array a,array b);
    void operator =(array a)
    {
        d=a.d;
        len=a.len;
    }
};


int operator ==(array a,array b)
{
    int flag =1;
    if(a.len==b.len)
    {
        for(int i=0;(i<a.len)&&(flag==1);i++)
        {
            if((a.d[i])!=(b.d[i]))
            {
                flag=0;
            }

        }
        if(flag==1)
        {
            return 1;
        }
        else if(flag==0)
        {
            return 0;
        }
    }
    else
        {return 0;}
}
int operator !=(array a,array b)
{
    int flag =1;
    if(a.len==b.len)
    {
        for(int i=0;(i<a.len)&&(flag==1);i++)
        {
            if((a.d[i])!=(b.d[i]))
            {
                flag=0;
            }

        }
        if(flag==1)
        {
            return 0;
        }
        else if(flag==0)
        {
            return 1;
        }
    }
    else
        {return 1;}
}
ostream & operator <<(ostream & ccout,array & obj)
{
ccout<<"\n Entered Array is:\n";
for(int i=0;i<obj.len;i++)
        {
           ccout<<obj.d[i]<<" ";
        }

return ccout;
}
istream & operator >>(istream & ccin,array & obj)
{
        cout<<"enter no of terms\n";
        cin>>obj.len;
        obj.d=new double[obj.len];
        cout<<"enter "<<obj.len<<" numbers\n";
        for(int i=0;i<obj.len;i++)
        {
            cin>>obj.d[i];
        }
        return ccin;
}
int main()
{
    start:
    int choice;
    array a;
    array b;
    cout<<"___________________________________________$$s\n    _________________________$____$$s___________s$$s\n_________________________s$$$$s$$$$$$s________$$$___s$\n_______________s$$$$$$$$s___s$$$$ss$$$$s________$$$__$$\n________________________s$$$s__$$$$$s_$$$s___s$__s$$s_$$\n__________s$$$$$$$$$$$$$$$$$$$$sss$$$$s_$$$s__$$$__s$$s$\n_____s$$$$$$$$$s_____s$$$$$$$$$$$$$$h$$$__$$$s__$$___$$$\n___s$$$$$s_____________________ss$$$$$$$$s_s$$$s$$$__s$$$\n__________________________s$$$s____s$$$$$$$$s$$$$$$$__$$$\n_________s$$$$$$$$$$$$$$$s$$$$$$$$$$s$$$$$$$$$ss$$$$s_$$$\n_____________________s$$$$$$$$$$s$$$s____s$$$$$$__$$$__$$\n________________s$$$$$$$$$$$$$$$$$$$$$$s_____s$$$s_$$__$$\n________s$$$$$$$$$$$$$$$$$$$$$$$s$s__s$$$$$$s___$$s_$s$$$\n_____s$$$$$s$$$$$$$$$$$$$$s____$$s$$$$$$$$$$$$$s____$$$$s\n___s$$$$__s$$$$$$$$$s_____s$$$$$s$$$$$$$$$$$$$$$$$s__$$$\n___s$___$$$$$$______s$$$$$$$s_s$$$$$$$$$$$$$$$$$$$$$____$$$\n______s$$$s___s$$$$$$$$$$$___$$$$$$$$$$$$$$$$$$$$$$$$s$$$$$$$s\n\_____$$$__s$$$$$$$$$$$$$$__$$$$$$$$$$$$$$$$$$$$s$s$_$$$$$$$$$$$\n____$$$_$$$$$$i$$$$$s_$$__$$$$$$$$$$$$$$$$$$$ss$$$s$$$$$$$$s$$s\n___$$__$$$__s$$$$ss__$$_$$$$$$$$$$$$$$$$$$$$s$$$$$_$$$$e$$s$\n__$$_s$$___$$$$s_$$_$$s$$$$$$$$$$$$$$$$$$$$s$$$$$s_$$$$$$s$\n_s$s$$$___$$$$_s$$__$$__$$$$$$$$$$$$$$$$$$_$$$$$$$_s_$$$\n_$$s$s__s$$$__$$____s$$__$$$$$$$$$$$$$$$$$_$$$$$$$$__$$$\n$$_$___$$$$_s$$__$$__$$$s__s$$$$$$$$$$$$$$_$$$$$$$$$$$$s\n$$____$$$s_$$$__$$$_$_s$$$$s___s$s$$$$$$$$_$$$$$$$$s$$$\n$____$$$__$$sss$$$$__$_s$$$$$$$$$$s$s$$$$$___s$$$$s$$$s\n____$$$_s$$$_$s$$$$s_s$__$$$$$$___s$$s_$$$s___s$$$_$$$\n____$$_s$$$_$$_s$$$$$_s$$___$$$$$________$_____$$$s$$s\n___s$$_$$$__$$__$$$$$$$$$$s____s$$$$$_________s$$$$$$\n___$$$s$$$__$$___$$ss$$$$$$$$s____s$$$$$s______$$$$$$\n___$s$$$$$_s$$__s_$$$_s$$$$$$$$$$s___s$$$$$$$s___sss\n___$$$$$$$_$$$__$s_$$$$s__s$$$$$$$$$s___$$$$$$$s\n__s$$$$$$$_$$$s_s$__$$$$$$s__s$$$$$$$$$s__$__$$$$s\n__$_$$$$s$_s$$$__$$__$$$$$$$$s__$$s$$$$$$$_____$$$$\n____s$$$_$$_$$$___$$__$s$$$$$$$$_s__s$$$s$$$____$$$$\n_____$$$__$_$$$$___$$_ss_$$$$$$$$$____$$$$_s$____$$$s\n_____$$$s_$_s$$$s__$$$____s$$$$$$$$$___s$$$______$$$$\n_____s$$$_ss_$$$$___$$s____$$$$$$$$$$___$$$$_____s$$$\n______$k$__$__$$$$__s$$____$$$$$$$h$$____$$$$_____$$s\n______$$$______$$$s__$$$___$$_$$$$$$$$___s$$$$____$$\n_______$$s______$$$__s$$$___$_s$$$$$s____s$$$$____$s\n_______$$$_______$$$_s$$_$__$__$$$$$s____s$$$$___$$\n________$$_______s$$__$$_______$$$$$s____$$$$$___$s\n________$$________s$$_$$______s$$$$$_____$$_$$___$\n___________________$$_$$s_____$$$$$_____$$s_$s\n____________________$$s$$_____$$$$_____s$$__$\n____________________s$_$$____$$$s_____s$$\n_____________________$_$$___$$$______s$$\n_______________________$$__s$$______$$$\n________________________$__$$______$$$\n________________________$_$$s____$$$s\n__________________________$$___s$$s\n__________________________$$__$$s\n\n";
    cout<<"MADE BY JAINIL in INDIA in 2017 FIRST PROJECT"<<endl;
    cout<<"\n1. create a file"<<endl;
    cout<<"2. display content of file"<<endl;
    cout<<"3. write content in a file"<<endl;
    cout<<"4. update the content of file"<<endl;
    cout<<"5. copy file content"<<endl;
    cout<<"6. delete file permanently from storage"<<endl;
    cout<<"7. to count number of cbaracters in file"<<endl;
    cout<<"8. to write array of double in binary file"<<endl;
    cout<<"9. to read array of double from binary file"<<endl;
    cout<<"10. for changing colour of screen"<<endl;
    cout<<"11. shut down all programs running now"<<endl;
    cout<<"12. Restart the computer"<<endl;
    cout<<"13. Shutdown the computer"<<endl;
    cout<<"14. == operator for array comparision"<<endl;
    cout<<"15. != operator for array comparision"<<endl;
    cout<<"16. for subscript operator"<<endl;
    cout<<"17. = operator to copy array"<<endl;
    cout<<"18. for  polynomial addition:"<<endl;
    cout<<"19. for  polynomial subtraction:"<<endl;
    cout<<"20. for  polynomial += operation:"<<endl;
    cout<<"21. for  polynomial -= operation:"<<endl;
    cout<<"22. for  polynomial multiplication:"<<endl;
    cout<<"23. for  polynomial *= operation"<<endl;
    cout<<"24. for string + operation"<<endl;
    cout<<"25. for string == operation"<<endl;
    cout<<"26. for string <= operation"<<endl;
    cout<<"27. for string >= operation"<<endl;
    cout<<"28. for string > operation"<<endl;
    cout<<"29. for string > operation"<<endl;
    cout<<"30. for string << operation"<<endl;
    cout<<"31. for string >> operation"<<endl;
    cout<<"32. for distance scaling"<<endl;
    cout<<"33. for name sorting"<<endl;
    cout<<"34. for swap functon "<<endl;
    cout<<"35. for date swapping"<<endl;
    cout<<"36. for printing chakrayuh"<<endl;
    cout<<"37. for base converting function"<<endl;
    cout<<"38. for factorial function"<<endl;
    cout<<"39. for combination function"<<endl;
    cout<<"40. for permutation function"<<endl;
    cout<<"41. for 21 matchstick game"<<endl;
    cout<<"42. for face printing"<<endl;
    cout<<"43. for prime numbers till n"<<endl;
    cout<<"44. for roots of eq ax^2+bx+c"<<endl;
    cout<<"45. for solution of three linear equation"<<endl;
    cout<<"46. for Celsius and Fahrenheit conversion"<<endl;
    cout<<"47. for solving determinant 4*4"<<endl;
    cout<<"48. for transpose of matrix"<<endl;
    cout<<"49. for matrix addition"<<endl;
    cout<<"50. for matrix subtraction"<<endl;
    cout<<"51. for matrix multiplication"<<endl;
    cout<<"52. for diamond printing design"<<endl;
    cout<<"53. for currency note calculator"<<endl;
    cout<<"54. for equation with degree 2"<<endl;
    cout<<"55. for equation with degree 3 cardon"<<endl;
    cout<<"56. for date changing"<<endl;
    cout<<"57. for time changing"<<endl;
    cout<<"for secret menu enter a whole number <50 not listed above"<<endl;
    cout<<"100.to end the program"<<endl;
secretcode:
    cout<<"ENTER YOUR CHOICE:";
   cin>>choice;

   switch (choice)
   {
   case 1:
    {
        char c[500];
        cout<<"enter name of file to be created:";
        cin>>c;
        ofstream file(c);
        cout<<"file "<<c<<" is created now\n";
        file.close();
        break;
    }
    case 2:
    {
        char c[500];
        cout<<"enter name of file to be readed and displayed:";
        cin>>c;
        ifstream dest2(c);
        char ch;
        int i=0;
        while(!dest2.eof())
    {

        dest2.seekg(i,ios::beg);
        dest2.get(ch);
        cout<<ch;
        i++;
    }
    dest2.close();

        break;
    }
    case 3:
        {
            char c[500];
        cout<<"enter name of file to be writted from beginning :";
        cin>>c;
        ofstream sour(c);
    cout<<"\n"<<"enter data in file "<<c<<"\n";

    char ch='a';
    while(ch!=EOF)
    {
        ch=getchar();
        sour.put(ch);
    }
    sour.close();
    break;
        }
    case 4:
        {
            char c[500];
        cout<<"enter name of file to be readed and updated :";
        cin>>c;
        ifstream dest2(c);
        char ch;
        int i=0;
        while(!dest2.eof())
    {

        dest2.seekg(i,ios::beg);
        dest2.get(ch);
        cout<<ch;
        i++;

    }
    fstream sour(c);
    sour.seekg(0,ios::end);
     ch='a';
    while(ch!=EOF)
    {
        ch=getchar();
        sour.put(ch);
    }
    sour.close();

    break;
        }

    case 5:
        {
        char c1[500];
        cout<<"enter source file name :";
        cin>>c1;
        char c2[500];
        cout<<"enter destination file name :";
        cin>>c2;
        ifstream sour1(c1);
        ofstream dest1(c2);
        char ch;
        int i=0;
        while(sour1)
        {
            sour1.seekg(i,ios::beg);
            sour1.get(ch);
            dest1<<ch;
            i++;
        }
        sour1.close();
        dest1.close();
        cout<<"data copied from "<<c1<<" to "<<c2;
        break;

        }
    case 6:
        {
           char c1[500];
        cout<<"enter file to be deleted or enter path of file to be deleted: ";
        cin>>c1;
        remove(c1);
        //use of remove command in cstdio is done here to delete a file.
        break;

        }
    case 7:
        {
            char c1[500];
            cout<<"enter file so that characters are count: ";
            cin>>c1;
            ifstream dest2(c1);

        char ch;
        int i=0;
        while(!dest2.eof())
    {

        dest2.seekg(i,ios::beg);
        dest2.get(ch);
        i++;

    }
             int n=dest2.tellg();
            cout<<"the number of characters in file are:"<<i-1<<endl;
            break;

        }
    case 8:
        {
            char c1[500];
            cout<<"enter binary file name to write it: "<<endl;
            cin>>c1;
            int qq;
            cout<<"enter no of terms you like to write in double binary file:"<<endl;
            cin>>qq;
                float g[qq];
    for(int i=0;i<qq;i++)
    {
        cout<<"enter "<<i+1<<" "<<" item :";
        cin>>g[i];
    }
    ofstream f(c1);
    f.write((char *)&g,sizeof(g));
    f.close();
    break;
        }
    case 9:
        {char c1[500];
            cout<<"enter binary file name to read it: "<<endl;
            cin>>c1;
            int qq;
            cout<<"enter no of terms you like to read from double binary file:"<<endl;
            cin>>qq;
    ifstream a(c1);
    float s[qq];
    a.read((char *)&s,sizeof(s));
    a.close();
    for(int i=0;i<qq;i++)
    {
       cout<<s[i]<<" ";

        }
        break;
        }
    case 10:
        {
         string s1;
         string s2;
         string s3;
    cout<<"    0 = Black       8 = Gray\n    1 = Blue        9 = Light Blue\n    2 = Green       A = Light Green\n    3 = Aqua        B = Light Aqua\n    4 = Red         C = Light Red\n    5 = Purple      D = Light Purple\n    6 = Yellow      E = Light Yellow\n    7 = White       F = Bright White\n";
        cout<<"enter background colour";
        cin>>s1;
        cout<<"enter text colour";
        cin>>s2;
        s3="color "+s1+s2;
        char charArray[1024];
    strncpy(charArray, s3.c_str(), sizeof(charArray));
    charArray[sizeof(charArray) - 1] = 0;
    system(charArray);



        break;
        }
    case 11:
        { cout<<"________$$$$\n_______$$__$\n_______$___$$\n_______$___$$\n_______$$___$$\n________$____$$\n________$$____$$$\n_________$$_____$$\n_________$$______$$\n__________$_______$$\n____$$$$$$$________$$\n__$$$_______________$$$$$$\n_$$____$$$$____________$$$\n_$___$$$__$$$____________$$\n_$$________$$$____________$\n__$$____$$$$$$____________$\n__$$$$$$$____$$___________$\n__$$_______$$$$___________$\n___$$$$$$$$$__$$_________$$\n____$________$$$$_____$$$$\n____$$____$$$$$$____$$$$$$\n_____$$$$$$____$$__$$\n_______$_____$$$_$$$\n________$$$$$$$$$$\n";    cout<<"������������������� ��������������������������������������`\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n����������������������������������`�����������������������`\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n�����������������������������������������������������������\n";

            system("shutdown -f"); break;}
    case 12:
        { system("shutdown -r");     break; }
    case 13:
    { system("shutdown -s");     break;}

case 14:
            {
                cin>>a;
                cin>>b;
                if(a!=b)
                {
                    cout<<"a is not equal to b"<<endl;
                }
                else
                {
                    cout<<"a is equal to b"<<endl;
                }
                break;
            }
        case 15:
            {
                 cin>>a;
                cin>>b;
                if(a==b)
                {
                    cout<<"a is equal to b"<<endl;
                }
                else
                {
                    cout<<"a is not equal to b"<<endl;
                }
                break;
            }
        case 16:
            {
                break;
            }
        case 17:
            {
                cin>>a;
                b=a;
                cout<<"a is\n";
                cout<<a;
                cout<<"b is\n";
                cout<<b;
            }
case 18:
    {int d;
    cout<<"for p1 enter degree:";
    cin>>d;
    polynomial p1(d);
    p1.getdata();
    cout<<"for p2 enter degree:";
    cin>>d;
    polynomial p2(d);
    p2.getdata();
     int q;
    if(d>p2.d)
    {
        q=d;

    }
    else
    {
        q=p2.d;
    }
    polynomial p3(q);

    p3=p1+p2;
    cout<<"addition of ";
    p1.putdata();
    cout<<" and ";
    p2.putdata();
    cout<<" is \n";
    p3.putdata();
    break;
    }
    case 19:
            {
                int d;
    cout<<"for p1 enter degree:";
    cin>>d;
    polynomial p1(d);
    p1.getdata();
    cout<<"for p2 enter degree:";
    cin>>d;
    polynomial p2(d);
    p2.getdata();
    int q;
    if(d>p2.d)
    {
        q=d;
    }
    else
    {
        q=p2.d;
    }
    polynomial p3(q);
    p3=p1-p2;
    cout<<"subtraction of ";
    p1.putdata();
    cout<<" and ";
    p2.putdata();
    cout<<" is \n";
    p3.putdata();
    break;
            }
        case 20:
            {int d;
    cout<<"for p1 enter degree:";
    cin>>d;
    polynomial p1(d);
    p1.getdata();
    cout<<"for p2 enter degree:";
    cin>>d;
    polynomial p2(d);
    p2.getdata();
    p1+=p2;
    cout<<"after p1+=p2\n p1 is ";
    p1.putdata();
    cout<<" and p2 is ";
    p2.putdata();
break;
            }
        case 21:
            {
                 int d;
    cout<<"for p1 enter degree:";
    cin>>d;
    polynomial p1(d);
    p1.getdata();
    cout<<"for p2 enter degree:";
    cin>>d;
    polynomial p2(d);
    p2.getdata();
    p1-=p2;
    cout<<"after p1-=p2\n p1 is ";
    p1.putdata();
    cout<<" and p2 is ";
    p2.putdata();
break;
            }
        case 22:
            {
                 int d;
    cout<<"for p1 enter degree:";
    cin>>d;
    polynomial p1(d);
    p1.getdata();
    cout<<"for p2 enter degree:";
    cin>>d;
    polynomial p2(d);
    p2.getdata();
      int x;
    x=d+p2.d;
    polynomial p3(x);
    p3=p1*p2;
    cout<<"mulptiplicaltion of  ";
    p1.putdata();
    cout<<" and ";
    p2.putdata();
    cout<<" is \n";
    p3.putdata();
break;
            }
               case 23:
            {
                 int d;
    cout<<"for p1 enter degree:";
    cin>>d;
    polynomial p1(d);
    p1.getdata();
    cout<<"for p2 enter degree:";
    cin>>d;
    polynomial p2(d);
    p2.getdata();
    p1*=p2;
    cout<<"after p1*=p2\n p1 is ";
    p1.putdata();
    cout<<" and p2 is";
    p2.putdata();
break;
            }



            case 24:
    {
       MyString str1;
       MyString str2;
       cout<<"for string 1\n";
       cin>>str1;
       cout<<"for string 2\n";
       cin>>str2;
       MyString str3;
       str3=str1+str2;
       cout<<"\n\n\nafter str1+str2 result is \n";
       cout<<str3;
       break;

    }
   case 25:
     {
       MyString str1;
       MyString str2;
       cout<<"for string 1\n";
        cin>>str1;
       cout<<"for string 2\n";
       cin>>str2;
       cout<<"after str1==str2\n";
       if(str1==str2)
        {
            cout<<"\n Condition is TRUE\n string are same\n";
        }
        else
        {
        cout<<"\n Condition is FALSE \n string are not same\n";
        }
        break;

     }
   case 26:
    {

       MyString str1;
       MyString str2;
       cout<<"for string 1\n";
        cin>>str1;
       cout<<"for string 2\n";
      cin>>str2;
       cout<<"after str1<=str2\n";
       if(str1<=str2)
        {
            cout<<"\n Condition is TRUE\n str1<=str2\n";
        }
        else
        {
        cout<<"\n Condition is FALSE \n str1>str2\n";
        }
        break;
    }
   case 27:
    {
         MyString str1;
       MyString str2;
       cout<<"for string 1\n";
     cin>>str1;
       cout<<"for string 2\n";
     cin>>str2;
       cout<<"after str1>=str2\n";
       if(str1>=str2)
        {
            cout<<"\n Condition is TRUE\n str1>=str2\n";
        }
        else
        {
        cout<<"\n Condition is FALSE \n str1<str2\n";
        }
        break;
    }
   case 28:
    {
           MyString str1;
       MyString str2;
       cout<<"for string 1\n";
        cin>>str1;
       cout<<"for string 2\n";
      cin>>str2;
       cout<<"after str1<str2\n";
       if(str1<str2)
        {
            cout<<"\n Condition is TRUE\n str1<str2\n";
        }
        else
        {
        cout<<"\n Condition is FALSE \n str1>=str2\n";
        }
        break;
    }
   case 29:
    {
         MyString str1;
       MyString str2;
       cout<<"for string 1\n";
      cin>>str1;
       cout<<"for string 2\n";
      cin>>str2;
       cout<<"after str1>str2\n";
       if(str1>str2)
        {
            cout<<"\n Condition is TRUE\n str1>str2\n";
        }
        else
        {
        cout<<"\n Condition is FALSE \n str1<=str2\n";
        }
        break;
    }
   case 30:
    {
          MyString str1;
       cout<<"for string 1\n";
       cin>>str1;
       cout<<str1;
       break;
    }
    case 31:
    {
          MyString str1;
       cout<<"for string 1\n";
       cin>>str1;
       cout<<str1;
       break;
    }
    case 32:
        {
             dist d1;
        float f;
        d1.getdata();
        cout<<"enter scale value::";
        cin>>f;
        d1.scale(d1,f);
        d1.putdata();
        break;
        }
    case 33:
        {
              int no;
    char temp[50];
    cout<<"enter number of names you want to arrange:"<<endl;
    cin>>no;
    char name[no][50];
    for(int i=0;i<no;i++)
    {
        cout<<"enter "<<i<<" th name:";
        cin>>name[i];
        cout<<endl;
    }
    for(int i=0;i<no;i++)
        for(int j=0;j<no;j++)
    {
        if(strcmp(name[i],name[j])<0)
        {
            strcpy(temp,name[i]);
            strcpy(name[i],name[j]);
            strcpy(name[j],temp);
        }
    }
    cout<<"sorted list is"<<endl;
    for(int i=0;i<no;i++)
        cout<<name[i]<<endl;
        break;
        }

    case 34:
        {
             int a,b;
    cout<<"enter two integer"<<endl;
    cin>>a>>b;
    swap(a,b);
    cout<<"swapped integer are"<<a<<" "<<b<<endl;

    float e,f;
    cout<<"enter two floating  value"<<endl;
    cin>>e>>f;
    swap(e,f);
    cout<<"swapped float are"<<e<<" "<<f<<endl;

    double p,q;
    cout<<"enter two double value"<<endl;
    cin>>p>>q;
    swap(p,q);
    cout<<"swapped integer are"<<p<<" "<<q<<endl;

    char x,y;
    cout<<"enter two characters"<<endl;
    cin>>x>>y;
    swap(x,y);
    cout<<"swapped integer are"<<x<<" "<<y<<endl;
break;
        }

    case 35:
        {
        date a,b;
    a.getdata();
    b.getdata();
    swapdates(a,b);
    cout<<"after swapping"<<endl;
    a.putdata();
    b.putdata();
        break;
        }

    case 36:
        {
            cout<<"enter number to print spiral:";
cin>>Nz;
    u=-Nz; dow=Nz;
    int a[Nz*Nz];
    for(int i=0;i<Nz*Nz;i++)
    {a[i]=0;}
    fill(a);
    for(int i=0;i<=(Nz*Nz)-1;i++)
    {
        if(i%Nz==0&&i!=0)
        {
            cout<<"\n";
        }
        cout<<setw(3)<<a[i]<<" " ;
    }
    break;
        }
    case 37:
        {
                int num;
    int base;
    cout<<"enter a number in decimal";
    cin>>num;
    cout<<"enter base";
    cin>>base;
    con(num,base);
    break;
        }
    case 38:
        {
            int num;
            long int a;
            cout<<"enter a number to find its factorial";
            cin>>num;
            a=fact(num);
            cout<<a;
            break;
        }
    case 39:
        {
            int n,i;long int ans;
            cout<<"enter n"<<endl;
            cin>>n;
            cout<<"enter r"<<endl;
            cin>>i;
            ans=(fact(n)/((fact(n-i))*fact(i)));
            cout<<"nr = "<<ans;
            break;
        }
        case 40:
        {
            int n,i;long int ans;
            cout<<"enter n"<<endl;
            cin>>n;
            cout<<"enter r"<<endl;
            cin>>i;
            ans=(fact(n)/((fact(n-i))));
             cout<<"nPr = "<<ans;
             break;
        }
        case 41:
            {
                int matchstick = 21;
    int user,computer;

    while (matchstick>=1)
    {

        if (matchstick==1)
        {
            printf("\nMatch stick status:%d",matchstick);
            printf("\nYou loose!!!!!!:(:(");               break;
        }

        printf("\nMatch stick status:%d",matchstick);
        printf("\nEnter the choice (1,2,3,4)):");        scanf("%d",&user);

        printf("\nYou picked %d",user);
        if (user>=5 || user <=0)
        {
            printf("\nInvalid value");            continue;
        }

        computer = 5 - user;

        printf("\nComputer picked%d",computer);
        matchstick = matchstick - computer - user;

    }
    break;
            }
        case 42:
            {
                	printf("         ()         \n");
	printf("        (  )        \n");
	printf("       (    )       \n");
	printf("      (      )      \n");
	printf("     (        )     \n");
	printf("    ************    \n");
	printf("     | 0   0  |     \n");
	printf("     |   ||   |     \n");
	printf("     |   ||   |     \n");
	printf("     |   --   |     \n");
	printf("     ( )---(  )     \n");
	printf("      (      )      \n");
	printf("        (  )        \n");
	printf("         --         \n");
	break;
            }

        case 43:
            {
                int n;
                cout<<"enter last number"<<endl;
                cin>>n;
                	int a[n];    int i;   int j;
	for(i=0;i<n;i++)
	a[i]=i+1;

	for(i=1;i<n;i++)
	{if(a[i]!=0)
	for(j=2;j<(i);j++)
	{
	if((a[i]%j)==0)
	{a[i]=0;}
	}
	}
	for(i=1;i<n;i++)
	{
	if(a[i]!=0)
	{
	printf("%d  ",a[i]);
	}
	}

	break;
            }
        case 44:
            {
                double a,b,c,x1,x2,D,rp,ip;

printf("enter the value of a:");
scanf("%lf",&a);
printf("enter the value of b:");
scanf("%lf",&b);
printf("enter the value of c:");
scanf("%lf",&c);
D=pow(b,2)-4*a*c;
if (D>0)
{
printf("ROOTS ARE REAL AND DISTINCT");
x1=(-b+sqrt(D))/2*a;
x2=(-b-sqrt(D))/2*a;
printf("\n%lf+%lfi",x1);
printf("\n%lf+%lfi",x2);
}
else if(D==0)
{
printf("ROOTS ARE EQUAL");
x1=x2=-b/2*a;
printf("%lf",x1);
}
else
{
printf("ROOTS ARE COMPLEX AND DISTINCT");
rp=-b/2*a;
ip=sqrt(-D)/2*a;
printf("\n%lf+%lfi",rp,ip);
printf("\n%lf-%lfi",rp,ip);
}

break;
            }
        case 45:
            {
                float a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;
	float aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk;
	printf("this is program to find perfect answer of three variable equation \n");
	printf("the equation will look like:");
	printf("\n ax+by+cz=d  \n ex+fy+gz=h   \n ix+jy+kz=l");
	printf("\n enter the value of a:");
	scanf("%f",&a);
	printf("\n enter the value of b:");
	scanf("%f",&b);
	printf("\n enter the value of c:");
	scanf("%f",&c);
	printf("\n enter the value of d:");
	scanf("%f",&d);
	printf("\n enter the value of e:");
	scanf("%f",&e);
	printf("\n enter the value of f:");
	scanf("%f",&f);
	printf("\n enter the value of g:");
	scanf("%f",&g);
	printf("\n enter the value of h:");
	scanf("%f",&h);
	printf("\n enter the value of i:");
	scanf("%f",&i);
	printf("\n enter the value of j:");
	scanf("%f",&j);
	printf("\n enter the value of k:");
	scanf("%f",&k);
	printf("\n enter the value of l:");
	scanf("%f",&l);
	dd=(a*((f*l)-(h*j)))-(b*((e*l)-(h*i)))+(d*((e*j)-(i*f)));
	aa=(a*((k*f)-(g*j)))-(b*((e*k)-(g*i)))+(c*((e*j)-(i*f)));
	bb=(d*((f*k)-(g*j)))-(b*((h*k)-(l*g)))+(c*((h*j)-(l*f)));
	cc=(a*((h*k)-(l*g)))-(d*((e*k)-(i*g)))+(c*((e*l)-(i*h)));
	ee=bb/aa;
	ff=cc/aa;
	gg=dd/aa;
	printf("your equation is \n %f x + %f y + %f z = %f  \n %f x + %f y + %f z = %f  \n %f x + %f y + %f z = %f \n",a,b,c,d,e,f,g,h,i,j,k,l);
	printf("delta= %f \n  delta1= %f \n  delta2= %f \n  delta3=%f \n",aa,bb,cc,dd);
	printf("the valueb of x is %f \n the value of y is %f \n the value of z is %f",ee,ff,gg);
	printf("\n please give only valid equation which have only one solution if you give more than one solution equation then it will generate error of infinite solutions");


	break;
            }
        case 46:
            {
                int a; float c,f;

printf("enter 1 to change celsius to farenheit: \n");
printf("enter 2 to change farenheit to celsius: \n");
scanf("%d",&a);
if (a==1)
{printf("enter the value of celsius: \n");
scanf("%f",&c);
f=((9.0/5.0)*c)+32;
printf("farenheit is %f \n",f);
}

if (a==2)
{printf("enter the value of farenheit: \n") ;
scanf("%f",&f);
c=(f-32)*(5.0/9.0);
printf("celsius is %f \n",c);
 }

break;
            }
        case 47:
            {
                int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;  int det;

	printf("this is program to solve 4 x 4 determinant \n");
	printf("your determinant will look like:\n");
	printf(" | a b c d| \n | e f g h| \n | i j k l| \n | m n o p| \n");
	printf("please enter the value of a:::::::");
	scanf("%d",&a);
	printf("please enter the value of b:::::::");
	scanf("%d",&b);
	printf("please enter the value of c:::::::");
	scanf("%d",&c);
	printf("please enter the value of d:::::::");
	scanf("%d",&d);
	printf("please enter the value of e:::::::");
	scanf("%d",&e);
	printf("please enter the value of f:::::::");
	scanf("%d",&f);
	printf("please enter the value of g:::::::");
	scanf("%d",&g);
	printf("please enter the value of h:::::::");
	scanf("%d",&h);
	printf("please enter the value of i:::::::");
	scanf("%d",&i);
	printf("please enter the value of j:::::::");
	scanf("%d",&j);
	printf("please enter the value of k:::::::");
	scanf("%d",&k);
	printf("please enter the value of l:::::::");
	scanf("%d",&l);
	printf("please enter the value of m:::::::");
	scanf("%d",&m);
	printf("please enter the value of n:::::::");
	scanf("%d",&n);
	printf("please enter the value of o:::::::");
	scanf("%d",&o);
	printf("please enter the value of p:::::::");
	scanf("%d",&p);
	printf(" | %d %d %d %d | \n | %d %d %d %d | \n | %d %d %d %d | \n | %d %d %d %d | \n",a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p);
	det=(a*((f*((k*p)-(o*l)))-(g*((j*p)-(n*l)))+(h*((j*o)-(n*k)))))-(b*((e*((k*p)-(o*l)))-(g*((i*p)-(l*m)))+(h*((i*o)-(m*k)))))+(c*((e*((j*p)-(n*l)))-(f*((i*p)-(m*l)))+(h*((i*n)-(j*m)))))-(d*((e*((j*o)-(k*n)))-(f*((i*o)-(k*m)))+(g*((i*n)-(j*m)))));
	printf("%d",det);
break;
            }
        case 48:
            {
                int n,m;
                cout<<"Enter rows:";
                cin>>n;
                cout<<"Enter columns:";
                cin>>m;
                int a[n][m]; int i; int j;
                int b[m][n];

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{	printf("enter value of a[%d] [%d] \n",i,j);
			scanf("%d",&a[i][j]);
        }
			}
			for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    b[j][i]=a[i][j];
                }
            }
            if(n>m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{printf("%d \t ",b[i][j]);}
		printf("\n");
		}

		break;
            }
        case 49:
            {
                int m; int n; int i; int j;

    printf("enter value of m \n");

    scanf("%d",&m);

    printf("enter value of n \n");
    scanf("%d",&n);
    int a[m][n];
    int b[m][n];
    int c[m][n];
    if (m>=n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        printf("give value of a[%d][%d]",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
    }
    if (m<n)
        {
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
    {
        printf("give value of a[%d][%d]",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
    }



        if (m>=n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        printf("give value of b[%d][%d]",i+1,j+1);
        scanf("%d",&b[i][j]);
    }
    }
    if (m<n)
        {
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
    {
        printf("give value of b[%d][%d]",i+1,j+1);
        scanf("%d",&b[i][j]);
    }
    }




                if (m>=n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        c[i][j]=a[i][j]+b[i][j];
    }
    }
    if (m<n)
        {
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
    {
    c[i][j]=a[i][j]+b[i][j];
    }
    }

        printf("***********************************************\n");
        printf("the addition is \n \n \n \n");


    if(m>=n)
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
        {

            printf("%d    ",c[i][j]);
            if(j==n-1)
            {
                printf("\n");
            }
        }
        if(m<n)
        for(j=0;j<m;j++)
            for(i=0;i<n;i++)
        {

            printf("%d    ",c[i][j]);

            if(i==n-1)
            {
                printf("\n");
            }
        }
break;
            }
        case 50:
            {
                int m; int n; int i; int j;

    printf("enter value of m \n");

    scanf("%d",&m);

    printf("enter value of n \n");
    scanf("%d",&n);
    int a[m][n];
    int b[m][n];
    int c[m][n];
    if (m>=n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        printf("give value of a[%d][%d]",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
    }
    if (m<n)
        {
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
    {
        printf("give value of a[%d][%d]",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
    }



        if (m>=n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        printf("give value of b[%d][%d]",i+1,j+1);
        scanf("%d",&b[i][j]);
    }
    }
    if (m<n)
        {
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
    {
        printf("give value of b[%d][%d]",i+1,j+1);
        scanf("%d",&b[i][j]);
    }
    }

                if (m>=n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        c[i][j]=a[i][j]-b[i][j];
    }
    }
    if (m<n)
        {
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
    {
    c[i][j]=a[i][j]-b[i][j];
    }
    }

        printf("\n ***********************************************\n");
        printf("the subtraction is \n \n \n \n");


    if(m>=n)
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
        {

            printf("%d    ",c[i][j]);
            if(j==n-1)
            {
                printf("\n");
            }
        }
        if(m<n)
        for(j=0;j<m;j++)
            for(i=0;i<n;i++)
        {

            printf("%d    ",c[i][j]);

            if(i==n-1)
            {
                printf("\n");
            }
        }

break;
            }
        case 51:
            {
                gh:
    int m1,m2,n1,n2;
    cout<<"enter m for a"<<endl;
    cin>>m1;
    cout<<"enter n for a"<<endl;
    cin>>n1;
    cout<<"enter m for b"<<endl;
    cin>>m2;
    cout<<"enter m for b"<<endl;
    cin>>n2;
    if(n1!=m2)
    {
        cout<<"enter again"<<endl;
        goto gh;
    }

    int a[m1][n1];
    int i,j,k;
    int b[m2][n2];
    int c[m1][n2];
     for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {c[i][j]=0;}
    }

    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
           printf("enter value of a[%d][%d] \n",i,j);
           scanf("%d",&a[i][j]);
        }
    }
    printf("\n \n \n \n \n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
           printf("enter value of b[%d][%d] \n",i,j);
           scanf("%d",&b[i][j]);
        }
    }
    for (i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            for(k=0;k<n1;k++)
            {
                c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
            }
        }
    }
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            printf("    %d    ",c[i][j]);
        }
        printf("\n");
    }
    break;
            }
        case 52:
            {
                int nn,cc,kk, space = 1;      int iii,jjj,aaa;
                printf("Enter number of rows\n");
    scanf("%d", &nn);
    space = nn - 1;
    for (kk = 1; kk <= nn; kk++)
    {
	for (cc = 1; cc <= space; cc++)
	    printf(" ");
	space--;
	for (cc = 1; cc <= 2*kk-1; cc++)
	    printf("*");

	printf("\n");
    }
    space = 1;
    for (kk = 1; kk <= nn - 1; kk++)
    {
	for (cc = 1; cc <= space; cc++)
	    printf(" ");
space++;
	for (cc = 1 ; cc <= 2*(nn-kk)-1; cc++)
	    printf("*");

	printf("\n");
    }
    break;
            }
        case 53:
            {
                int a,hundrednotes,fiftynotes,tennotes,onenotes;
printf("please enter amount in hundreds only till 999 only \n");
scanf("%d",&a);
hundrednotes=a/100;
printf("the number of hundred notes is %d \n",hundrednotes);
a=a%100;
fiftynotes=a/50;
printf("the number of fifty notes is %d \n",fiftynotes);
a=a%50;
tennotes=a/10;
printf("the number of ten notes is %d \n",tennotes);
a=a%10;
onenotes=a;
printf("the one rupee coins to be given is %d \n",a);

break;
            }
        case 54:
            {
                double a,b,c,x1,x2,D,rp,ip;
printf("enter the value of a:");
scanf("%lf",&a);
printf("enter the value of b:");
scanf("%lf",&b);
printf("enter the value of c:");
scanf("%lf",&c);
D=pow(b,2)-4*a*c;
if (D>0)
{
printf("ROOTS ARE REAL AND DISTINCT");
x1=(-b+sqrt(D))/2*a;
x2=(-b-sqrt(D))/2*a;
printf("\n%lf+%lfi",x1);
printf("\n%lf+%lfi",x2);
}
else if(D==0)
{
printf("ROOTS ARE EQUAL");
x1=x2=-b/2*a;
printf("%lf",x1);
}
else
{
printf("ROOTS ARE COMPLEX AND DISTINCT");
rp=-b/2*a;
ip=sqrt(-D)/2*a;
printf("\n%lf+%lfi",rp,ip);
printf("\n%lf-%lfi",rp,ip);
}

break;
            }
        case 55:
            {
                double a,b,c,d,ro;
                cout<<"enter a:";
                cin>>a;
                cout<<"enter b:";
                cin>>b;
                cout<<"enter c:";
                cin>>c;
                 cout<<"enter d:";
                cin>>d;
                solveCubic(a,b,c,d,ro);
                cout<<"one root is:"<<ro;
                break;
            }
                        case 56:
                {
                    system("date");break;
                }
            case 57:
                {
                    system("time");break;
                }


            case 58:
            {
                double a,b,c,d,e,ro;
                cout<<"enter a:";
                cin>>a;
                cout<<"enter b:";
                cin>>b;
                cout<<"enter c:";
                cin>>c;
                 cout<<"enter d:";
                cin>>d;
                cout<<"enter e:";
                cin>>e;
                if(solveQuartic(a,b,c,d,e,ro))
                cout<<ro;
                else{cout<<"no result found";}
                break;
            }
            case 59:
                {
                    int player = 1,i,choice;

	char mark;
	do
	{
		board();
		player=(player%2)?1:2;
		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;
		mark=(player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')

			square[1] = mark;
		else if (choice == 2 && square[2] == '2')

			square[2] = mark;
		else if (choice == 3 && square[3] == '3')

			square[3] = mark;
		else if (choice == 4 && square[4] == '4')

			square[4] = mark;
		else if (choice == 5 && square[5] == '5')

			square[5] = mark;
		else if (choice == 6 && square[6] == '6')

			square[6] = mark;
		else if (choice == 7 && square[7] == '7')

			square[7] = mark;
		else if (choice == 8 && square[8] == '8')

			square[8] = mark;
		else if (choice == 9 && square[9] == '9')

			square[9] = mark;
		else
		{
			cout<<"Invalid move ";
			player--;
			cin.ignore();
			cin.get();
		}
		i=checkwin();
		player++;
	}while(i==-1);
	board();
	if(i==1)

		cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";

	cin.ignore();
	cin.get();
	break;
                }

            case 60:
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
            case 61:
                {
                    int rows;
printf("\n enter the number of rows:");
        scanf("%d", &rows);
    int array[rows][rows], i, j,  num = 25, k;
    for (i = 0; i < rows; i++)
    {
        for (k = num - 2 * i; k >= 0; k--)
            printf(" ");
	    for (j = 0; j <= i; j++)
	    {
                if (j == 0 || i == j)
		{
                    array[i][j] = 1;
                }
                else
                {
                    array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
		}
		printf("%4d", array[i][j]);
            }
            printf("\n");
    }
    break;
                }
            case 62:
                {
                    int a, b, result;
    int prime[100];
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    result = lcm(a, b);
    printf("The LCM of %d and %d is %d\n", a, b, result);
                }
            case 63:
                {int a, b, result;
                 printf("Enter the two numbers to find their HCF: ");
                     scanf("%d%d", &a, &b);
                         result = hcf(a, b);
                             printf("The HCF of %d and %d is %d.\n", a, b, result);
                             break;
                }
            case 64:
                {
                    int num;

    cout<<"Enter number to find multiplication table : ";
    cin>>num;

    for(int a=1;a<=10;a++)
        cout<<num<<" * "<<a<<" = "<<num*a<<endl;
        break;

                }
            case 65:
                {
                    //declare variable
   int year;

   //take user input for year
   cout<<"Enter year : ";
   cin>>year;

   if(year%4==0 || year%400==0 || year%100==0)
   cout<<"This is a leap year"<<endl;

   else
   cout<<"This is not a leap year"<<endl;
   break;
                }
            case 66:
                {
                    // current date/time based on your system
   time_t nowuptime = time(0);

   // convert current time  to string format
   char* date = ctime(&nowuptime);


   //print the value
   cout << "The localhost date and time is : " <<"\n";
   cout<<date << endl;
   break;


                }
            case 67:
                {
                     int year,month;
                cout<<"enter year in yyyy"<<endl;
                cin>>year;
                cout<<"enter month 1 for jan 2 for feb ... 12 for dec"<<endl;
                cin>>month;
                Calendar c(month,year);
                c.setFirstDay();
                c.print();
                break;
                }
            case 68:
                {
                    int i=1, u=1, sum=0;
   while(i<=50000)
 {                                  // start of first loop.

   while(u<=50000)
   {                               //start of second loop.
     if(u<i)
     {
      if(i%u==0 )
      sum=sum+u;
     }                          //End of if statement

     u++;
   }                           //End of second loop

   if(sum==i)
   {
    cout<<i<<" is a perfect number."<<"\n";
   }

   i++;
   u=1;  sum=0;
 }                             //End of First loop

   break;

                }
            case 69:
                {
                    //variable declaration
 int Number,j,m,d,c,l,x,ix,v,iv,i;

 //take user input
 cout << " Enter an Integer Number : ";
 cin >> Number;

 if (Number <= 0)
 {
  cout << " Invalid number." << endl;
  cout << " Press enter to continue..." << endl;
  cin.ignore();
  cin.get();
  return 0;
 }

 m = Number / 1000;
 Number = Number % 1000;

 d = Number / 500;
 Number = Number % 500;

 c = Number / 100;
 Number = Number % 100;

 l = Number / 50;
 Number = Number % 50;

 x = Number / 10;
 Number = Number % 10;

 ix = Number / 9;
 Number = Number % 9;

 v = Number / 5;
 Number = Number % 5;

 iv = Number / 4;
 Number = Number % 4;

 i = Number;

 cout << " Roman Numeral = ";
 for (j = 1; j <= m; j++)
  cout << "M";

 for (j = 1; j <= d; j++)
  cout << "D";
for (j = 1; j <= c; j++)
  cout << "C";

 for (j = 1; j <= l; j++)
  cout << "L";

 for (j = 1; j <= x; j++)
  cout << "X";

 for (j = 1; j <= ix; j++)
  cout << "IX";

 for (j = 1; j <= v; j++)
  cout << "V";

 for (j = 1; j <= iv; j++)
  cout << "IV";

 for (j = 1; j <= i; j++)
  cout << "I";

 cout << endl;

 cout << " Press enter to continue..." << endl;
 cin.ignore();
 cin.get();
break;

                }
            case 70:
                {
                    int num;
     cout<<"Enter a number : ";
    cin>>num;
 cout<<endl;
    convetTo(num);
    break;
                }
            case 71:
                {
                    int length ;
                    cout<<"enter length of triangle to print:"<<endl;
                    cin>>length;
    drawTriangle('*', ' ', length);
                break;
                }
            case 72:
                {
                    int i, j, k, n;
    float a[10][10] = {0}, d;

    cout << "Enter the order of matrix : ";
    cin >> n;
    cout << "Enter the elements : " << endl;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= 2 * n; j++)
            if (j == (i + n))
                a[i][j] = 1;

    for (i = n; i > 1; i--)
    {
        if (a[i - 1][1] < a[i][1])
            for (j = 1; j <= n * 2; j++)
            {
                d = a[i][j];
                a[i][j] = a[i - 1][j];
                a[i - 1][j] = d;
            }
    }
    cout << "Augmented : " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n * 2; j++)
            cout << a[i][j] << "    ";
        cout << endl;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n * 2; j++)
            if (j != i)
            {
                d = a[j][i] / a[i][i];
                for (k = 1; k <= n * 2; k++)
                    a[j][k] -= a[i][k] * d;
            }
    }

    for (i = 1; i <= n; i++)
    {
 d = a[i][i];
        for (j = 1; j <= n * 2; j++)
            a[i][j] = a[i][j] / d;
    }


    cout << "Inverse Matrix : " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = n + 1; j <= n * 2; j++)
            cout << a[i][j] << "    ";
        cout << endl;
    }

    break;
                }
            case 73:
                {
                        int  i, j, size,flag=1;

    cout << "Enter size of matrix : ";
    cin >> size;
    int arr[size][size];


    cout << "Enter values in matrix : \n";
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                cout << "\n\nMatrix is not symmetric";
                flag=0;


            }
        }
    }
    if(flag==1)
    cout << "\n\nMatrix is symmetric";

                }
            case 74:
                {
                        int  i, j, size,flag=1;;

    cout << "Enter order of square matrix : ";
    cin >> size;
    int arr[size][size];

    cout << "\nEnter matrix values : \n";
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {

            cin >> arr[i][j];
        }
    }
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {
            if (arr[i][j] != -arr[j][i])
            {
                cout << "\nMatrix is not skew matrix ";
                flag=0;
            }
        }
    }
    if(flag==1)
    cout << "\nMatrix is skew matrix";
break;

                }
            case 75:
                {
                    int choice, nodes, element, position, i;
    single_llist sl;
    start = NULL;
    while (1)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"4.Sort Link List"<<endl;
        cout<<"5.Delete a Particular Node"<<endl;
        cout<<"6.Update Node Value"<<endl;
        cout<<"7.Search Element"<<endl;
        cout<<"8.Display Linked List"<<endl;
        cout<<"9.Reverse Linked List "<<endl;
        cout<<"10.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
case 1:
cout<<"Inserting Node at Beginning: "<<endl;
sl.insert_begin();
cout<<endl;
break;
case 2:
cout<<"Inserting Node at Last: "<<endl;
sl.insert_last();
cout<<endl;
break;
case 3:
cout<<"Inserting Node at a given position:"<<endl;
sl.insert_pos();
cout<<endl;
break;
case 4:
cout<<"Sort Link List: "<<endl;
sl.sort();
cout<<endl;
break;
case 5:
cout<<"Delete a particular node: "<<endl;
sl.delete_pos();
break;
case 6:
cout<<"Update Node Value:"<<endl;
sl.update();
cout<<endl;
break;
case 7:
cout<<"Search element in Link List: "<<endl;
sl.search();
cout<<endl;
break;
case 8:
cout<<"Display elements of link list"<<endl;
sl.display();
cout<<endl;
break;
case 9:
cout<<"Reverse elements of Link List"<<endl;
sl.reverse();
cout<<endl;
break;
case 10:
cout<<"Exiting..."<<endl;
exit(1);
break;
default:
cout<<"Wrong choice"<<endl;
}
}
break;
                }
case 76:
    {
        int choice, element, position;
    double_llist dl;

    cout<<endl<<"Operations on Doubly linked list"<<endl;
    cout<<"1.Create Node"<<endl;
    cout<<"2.Add at begining"<<endl;
    cout<<"3.Add after position"<<endl;
    cout<<"4.Delete"<<endl;
    cout<<"5.Display"<<endl;
    cout<<"6.Count"<<endl;
    cout<<"7.Reverse"<<endl;
    cout<<"8.Quit"<<endl;
    while (1)
    {
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            dl.create_list(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            dl.add_begin(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert Element after postion: ";
            cin>>position;
            dl.add_after(element, position);
            cout<<endl;
            break;
        case 4:
            if (start == NULL)
            {
                cout<<"List empty,nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            dl.delete_element(element);
            cout<<endl;
            break;
        case 5:
            dl.display_dlist();
            cout<<endl;
            break;
        case 6:
            dl.count();
            break;
        case 7:
            if (start == NULL)
            {
                cout<<"List empty,nothing to reverse"<<endl;
                break;
            }
            dl.reverse();
            cout<<endl;
            break;
        case 8:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    break;

    }
        case 77:
            {
                int alen, val;
    vector<int> a;

    cout << "Enter the number of elements : ";
    cin >> alen;
    for (int i = 0; i < alen; i++)
    {
        cin >> val;
        a.push_back(val);
    }

    bubble_sort(a);

    cout << "List of sorted elements: " << endl;
    for (int i = 0; i < alen; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    break;
            }
        case 78:
            {
                int  i, n, p, k, min, loc, temp;

    cout << "\n------------ SELECTION SORT ------------ \n\n";
    cout << "Enter No. of Elements=";
    cin >> n;
    int a[n+1];

    cout << "\nEnter Elements=\n";
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (p = 1; p <= n - 1; p++)
    {
        min = a[p];
        loc = p;

        for (k = p + 1; k <= n; k++)
        {
            if (min > a[k])
            {
                min = a[k];
                loc = k;
            }
        }
        temp = a[p];
        a[p] = a[loc];
        a[loc] = temp;
    }

    cout << "\nAfter Sorting : \n";

    for (i = 1; i <= n; i++)
    {
        cout << a[i] << endl;
    }

    break;
            }
        case 79:
            {
                int  i, n, p, ptr, temp;

    cout << "\n------------ INSERTION SORT ------------ \n\n";
    cout << "Enter No. of Elements : ";
    cin >> n;
    int a[n+1];

    cout << "\nEnter Elements : \n";
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    a[0] = 0;

    for (p = 2; p <= n; p++)
    {
        temp = a[p];
        ptr = p - 1;

        while (temp < a[ptr])
        {
            a[ptr + 1] = a[ptr];
            ptr--;
        }

        a[ptr + 1] = temp;
    }
    cout << "\nAfter Sorting : \n";
    for (i = 1; i <= n; i++)
    {
        cout << a[i] << endl;
    }
    break;
            }
        case 80:
            {
                int i, n, beg, end;
    cout << "\n------- QUICK SORT -------\n\n";
    cout << "Enter the No. of Elements : ";
    cin >> n;;
    int a[n];
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    beg = 1;
    end = n;
    QuickSort(a, beg, end);
    cout << "\nAfter Sorting : \n";
    for (i = 1; i <= n; i++)
    {
        cout << a[i] << endl;
    }
    break;
            }
        case 81:
            {
                int n;
                cout<<"enter number of element to sort:"<<endl;
                cin>>n;
    int a[n], i;
    cout << "Enter "<<n<<" elements to sort : \n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergesort(a, 0, n-1);
    cout << "sorted array : \n";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    break;
            }
        case 82:
            {
                cout << "\nLinear Sort Method\n\n";
    linearsort obj;
    obj.getdataelements();
    obj.sortelements();
    obj.showdataelements();
    break;
            }
        case 83:
            {
                int n;
                cout<<"enter number of element to sort:"<<endl;
                cin>>n;
                int i;
    int a[n];
    cout << "Enter "<<n<<" elements to sort : \n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    radixsort(a, n);
    print(a, n);
    break;
            }
        case 84:
            {
                int n;
                cout<<"enter number of element to sort:"<<endl;
                cin>>n;
                int i;
    int a[n];
    cout << "Enter "<<n<<" elements to sort : \n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Intial Array : ";
    print_ar(a, n);

    shell_sort(a, n);

    cout << "Sorted Array : ";
    print_ar(a, n);
    break;
            }
        case 85:
            {
                cout<<"______________________111____________________\n_____________________1��11___________________\n____________________�����1�________1�________\n_____________________1�1��1________1���______\n_____��1_____________1�1��___________���1____\n____��1______________1����____________1��1___\n___��1_______________111��_____________1��___\n__1��________________1�1��______________1��__\n__���________________1�1��_______________��1_\n__���________________1�11�1______________���_\n__���________1_______1�11�1____��________���_\n__1���_______1��______�11�1___��________1���_\n___����_______���1____11_��__��_________����_\n___1�����1___1����____111�1__��1_______�����_\n____���������������___�11��__���1___1���11�1_\n_____1�������������___1�1��__����������1_��__\n______1�����������1___��1��__1���_11____1�1__\n_________�����__1�____��1��___1�1_______1____\n_____________1��1_____��11�____�����_________\n____________1�1__���1_�����11����__��1_______\n__________1��11�1___111������11___��111______\n__________�������__�11�1__11_11__1����1______\n_________��11��1_�����11__1_����1_���1�1_____\n_________�1_1��_1��1_11_��_��11��111�1_�1____\n_________�1_�_1���____���11��__���__��1�1____\n_________�1�1__1��___����1����111____���1____\n_________���_________����1��1���1____1�1_____\n_________1��_________1����_111����___��______\n____1�____1�_________1����_1�_1����_1�__1____\n____1�_______________�1_11__�1__����____��___\n____1�______________���11�___�___���1___1��__\n____��_____________�������1�1�1__����____��1_\n___1��____________��__����_��1___����____1��_\n___��1__________1��___1���_��____���11�11���1\n__1��__________1��_____���_1�___1�����������1\n_1���__________��______�1�1_�__1������������1\n_���1_________��1______�1�1_�_1����____1����1\n_���_________1��_______���1_����1_______����_\n1���_________���_______1��1����_________����_\n1���1____��__1��1______1�����1__________���1_\n�����___��1___���______����1�__________���1__\n1����1_1��____����___�����1_�_________1���___\n_�����11�1____1���11���11��_�________1���____\n_���������_____1��1���__1��_�1______1���_____\n__��������1______1���1__���_�1_____1��1______\n__1��������1___1����1�1_1��_�_____1��________\n___1���������������11��11��_1_____��_________\n_____��������������1_����1�_11___��__________\n________1111111����1__1����1�1__1�___________\n______________1����1____1�����1__1___________\n______________�����1____11�������____________\n______________������____�11_������1__________\n______________1������___11�_�1_1����_________\n_______________������1___1__�1__1����________\n________________������1__1__��____����_______\n_________________�������_11_��_____����______\n__________________���������_��_____1���1_____\n___________________1�������11�______���1_____\n_____________________1�����11���1___����1____\n_______________________1��1_1�����__1���1____\n_________________________111�������_1���1____\n_________________________�11��_1����1����____\n_________________________�11��___��������____\n_________________________�1���____������1____\n_________________________11���____1�����1____\n__________________________����_____�����_____\n__________________________����_____1���1_____\n__________________________����_____����______\n__________________________����____1���1______\n__________________________1��1____���1_______\n___________________________��1___���1________\n___________________________��___���1_________\n____________________________1_1���___________\n_____________________________����____________\n____________________________���1_____________\n___________________________���1______________\n__________________________1��1_______________\n__________________________��1________________\n_________________________1��_________________\n__________________________��_________________\n__________________________1�1________________\n___________________________11________________\n";

                cout<<"____________________________________________________\n____________________________�_______________________\n___________________________���______________________\n___________________________����_____________________\n________________________���������___________________\n_______________________�����������__________________\n___________________________���______________________\n____________________________��______________________\n___________________�������____������________________\n_______________��������������_______��______________\n_____________��____�������������_____�______________\n___________��_________������������___�______________\n__________��____________�����������_��______________\n_________���_____________������������_______________\n_________���_______________���������________________\n________�����_______________������__________________\n________������_______________����__________������___\n_____��_��������______________��_________���������__\n_____��_����������____________�_________�___������__\n_____��__�������������_______��________�\'____����___\n_____��__���������������������________�_____________\n_____���__����������������������_____��_____________\n_____����____�������������������������______________\n_____�����____��������������������������____________\n_____�������____����������������������������________\n______���������____���������������������������______\n_______����������_______������������������������____\n________��������������_______��������������������___\n_________������������������______�����������������__\n__________����������������������______�������������_\n___________�������������������������_____�����������\n_____________���������������������������____��������\n________________��������������������������___�������\n____________________�����������������������___������\n_____________________�___�������������������___�����\n____________________�________����������������__�����\n___________________�________��____�����������__�����\n________����______�_________�________��������__�����\n_______������___��_________�___________������__����_\n_______���������__________�_____________����__����__\n________�����____________�______________���___���___\n________________________�_______________��___���____\n___________�����������������___________��___���_____\n_______�������������������������___________��_______\n____�������������������������������_______�_________\n__������______�����������������������___��__________\n_���______________��_�������������������____________\n��_______________�______��������������______________\n�______________��_________����������________________\n�____________��___________�_������__________________\n��_________��_____________�___���___________________\n_����������_______________�____�____________________\n__________________________�_________________________\n__________________________��________________________\n_________________________����_______________________\n_________________________����_______________________\n____________________________________________________\n____________________________________________________\n____________________________________________________\n_�_________________________________________________�\n__�_______________________________________________�_\n___�_____________________________________________�__\n____���_______________________________________���___\n______����_________________________________����_____\n__�_____�_���___________________________���_�_____�_\n___��________��_______________________��________��__\n___�����________��_________________��________�����__\n____��������______��______________�______��������___\n______����������____�___________�____����������_____\n__________���������___�_______�___���������_________\n____�����������������_�_____�_�����������������____\n_________���������������_____���������������________\n___________��������������___��������������__________\n__________�___���__���_________���__���___�_________\n_____________�__�______�___�______�__�_____________\n________________�____���_____���____�_______________\n___________________����_______����__________________\n_________________�����_________�����________________\n_______________������___________������______________\n______________������_____________������_____________\n_____________�������_____________�������____________\n_____________�����_�_____________�_�����____________\n____________�_����__�______________����_�___________\n____________��__��_________________��__��___________\n_________________�_________________�________________\n___________�_____________________________�__________\n___________�_____________________________�__________\n____________________________________________________\n";
            break;
            }
        case 86:
            {
                string tmp ;
                cout<<"enter string:";
                cin>>tmp;

    cout<<"String : "<<tmp<<endl;

    cout<<"Converting string to char array : ";

    char charArray[1024];
    strncpy(charArray, tmp.c_str(), sizeof(charArray));
    charArray[sizeof(charArray) - 1] = 0;

    for(int i = 0;charArray[i]!=0;i++)
    {
        cout<<endl<<"charArray["<<i<<"] :\t"<<charArray[i];
    }

  break;

            }
        case 0:
            {
    cout<<"58. for equation with degree 4 ferrari"<<endl;
    cout<<"59. for tic tac toe game 2 players:"<<endl;
    cout<<"60. for sudoku solving"<<endl;
    cout<<"61. for pascal triangle"<<endl;
    cout<<"62. for lcm calculation by reccursive"<<endl;
    cout<<"63. for Hcf calculation by reccursive"<<endl;
    cout<<"64. for printing multiplication table"<<endl;
    cout<<"65. for finding leap year"<<endl;
    cout<<"66. for system date and time printing"<<endl;
    cout<<"67. for calendar printing"<<endl;
    cout<<"68. for perfect number"<<endl;
    cout<<"69. for integer to roman numbers"<<endl;
    cout<<"70. for converting number to alphabets"<<endl;
    cout<<"71. for drawing a triangle"<<endl;
    cout<<"72. for finding inverse using gauss jaudan method"<<endl;
    cout<<"73. for symmetric matrix checking"<<endl;
    cout<<"74. for skew symmetric matrix checking"<<endl;
    cout<<"75. for singly linked list"<<endl;
    cout<<"76. for doubly linked list"<<endl;
    cout<<"77. for bubble sort"<<endl;
    cout<<"78. for selection sort"<<endl;
    cout<<"79. for insertion sort"<<endl;
    cout<<"80. for quick sort"<<endl;
    cout<<"81. for merge sort"<<endl;
    cout<<"82. for linear sort"<<endl;
    cout<<"83. for radix sort"<<endl;
    cout<<"84. for shell sort"<<endl;
    cout<<"85. for printing dollarly butterfly:"<<endl;
    cout<<"86. for converting string to character array:"<<endl;
    goto secretcode;
            }
    }
    if(choice!=100)
    {
        goto start;
    }
}

