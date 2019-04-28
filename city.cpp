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
struct node
{
    string cityname;
    int x;
    int y;
    struct node * ptr;
}*start;

void insertlast()
{
    struct node* nn =new node();
        cout<<"enter city name:";
        cin>>nn->cityname;
        cout<<"enter x coordinate:";
        cin>>nn->x;
        cout<<"enter y coordinate:";
        cin>>nn->y;
         nn->ptr=NULL;
    if(start==NULL)
    {
        start=nn;
    }
    else{
        struct node* temp;
        temp=start;
        while(temp->ptr!=NULL)
        {
            temp=temp->ptr;
        }
        temp->ptr=nn;
    }
}


bool searchbycityname(string c)
{
    struct node* temp;
        temp=start;
        while(true)
        {
            string data;
            data=temp->cityname;
            if(data==c)
            {
                return true;
            }
            if(temp->ptr==NULL)
            {
                break;
            }
            temp=temp->ptr;

        }
        return false;
}


bool searchbyxycoordinate(int c,int d)
{
    struct node* temp;
        temp=start;
        while(true)
        {
            int datax;
            datax=temp->x;
            int datay;
            datay=temp->y;

            if(datax==c&&datay==d)
            {
                cout<<"city name is: "<<temp->cityname;
                return true;
            }
            if(temp->ptr==NULL)
            {
                break;
            }
            temp=temp->ptr;
        }
        return false;
    }

void deletevbycityname(string s)
{
    int i=0;bool flag=false;int foundindex;
     struct node* temp1;
        temp1=start;
        while(true)
        {
            i++;
            string data;
            data=temp1->cityname;
            if(data==s)
            {
                foundindex=i;
                flag=true;
                break;
            }
            if(temp1->ptr==NULL)
            {
                break;
            }
            temp1=temp1->ptr;
        }
        if(flag==false){cout<<"not found";
        return;}


    struct node* temp;
        temp=start;
        for(int k=0;k<i-2;k++)
        {
            temp=temp->ptr;
        }
        struct node* temp2=temp->ptr;
        temp->ptr=temp->ptr->ptr;
        free(temp2);

}



void deletevbycoordinate(int a,int b)
{
    int i=0;bool flag=false;int foundindex;
     struct node* temp1;
        temp1=start;
        while(true)
        {
            i++;
            int datax;int datay;
            datax=temp1->x;
            datay=temp1->y;

            if(datax==a&&datay==b)
            {
                foundindex=i;
                flag=true;
                break;

            }
            if(temp1->ptr==NULL)
            {
                break;
            }
            temp1=temp1->ptr;
        }
        if(flag==false){cout<<"not found";
        return;}


    struct node* temp;
        temp=start;
        for(int k=0;k<i-2;k++)
        {
            temp=temp->ptr;
        }
        struct node* temp2=temp->ptr;
        temp->ptr=temp->ptr->ptr;
        free(temp2);

}


void display()
{
     if(start==NULL)
    {
       cout<<"empty list\n";
    }
    else{
        struct node* temp;
        temp=start;
        while(temp!=NULL)
        {
            cout<<temp->cityname<<" "<<temp->x <<" "<<temp->y<<" -> ";
            temp=temp->ptr;
        }

    }
}
int main()
{
    int choice;
    while(true)
    {
        cout<<"\n1 enter data of city\n";
        cout<<"2 search by city name\n";
        cout<<"3 search by coordinate\n";
        cout<<"4 delete by city name\n";
        cout<<"5 delete by coordinate\n";
        cout<<"6 display list";
        cin>>choice;
        if(choice==1)
        {
            insertlast();
        }
        else if(choice==2)
        {
            string cityn;
            cout<<"enter city name\n";
            cin>>cityn;
            if(searchbycityname(cityn))
            {
                cout<<"found\n";
            }
            else
            {
                cout<<"not found\n";
            }
        }
        else if(choice==3)
        {
            int cityx;
            cout<<"enter city x coordinate\n";
            cin>>cityx;
            int cityy;
            cout<<"enter city y coordinate\n";
            cin>>cityy;
            if(searchbyxycoordinate(cityx,cityy))
            {
                cout<<"found\n";
            }
            else
            {
                cout<<"not found\n";
            }
        }
        else if(choice==4)
        {
            string cityn;
            cout<<"enter city name\n";
            cin>>cityn;
            deletevbycityname(cityn);
        }
        else if(choice==5)
        {
             int cityx;
            cout<<"enter city x coordinate\n";
            cin>>cityx;
            int cityy;
            cout<<"enter city y coordinate\n";
            cin>>cityy;
            deletevbycoordinate(cityx,cityy);
        }
        else if(choice==6)
        {
            display();
        }
    }
}

