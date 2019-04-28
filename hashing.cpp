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
using namespace std;
int hashTable[21]={};
    int hashTableSize = 21;
    int hashFunc(int x)
    {
        return((x%18)+2);
    }
void insert(int s)
    {
        //Compute the index using the hash function
        int index = hashFunc(s);
        //Search for an unused slot and if the index will exceed the hashTableSize then roll back
        while(hashTable[index] != 0)
            index = (index + 1) % hashTableSize;
        hashTable[index] = s;
    }
    void search(int s)
    {
        //Compute the index using the hash function
        int index = hashFunc(s);
         //Search for an unused slot and if the index will exceed the hashTableSize then roll back
        while(hashTable[index] != s and hashTable[index] != 0)
            index = (index + 1) % hashTableSize;
        //Check if the element is present in the hash table
        if(hashTable[index] == s)
            cout << s << " is found!" << endl;
        else
            cout << s << " is not found!" << endl;
    }
    int main()
    {
       int choice;
    while(true)
    {

        cout<<"\nenter 1 for insert in hash table";
        cout<<"\nenter 2 for search\n";

        int data;
        cin>>choice;
        if(choice==1)
        {
            cout<<"enter data:";
            cin>>data;
            insert(data);
        }
        if(choice==2)
        {
             cout<<"enter data to be searched:";
            cin>>data;
            search(data);
        }

    }
    return 0;
    }
