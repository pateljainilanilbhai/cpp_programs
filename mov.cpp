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
    string info;
    struct node * ptr;
    struct node * pre;
}*start;
node * last;
void insertlast()
{
    struct node* nn =new node();
        cout<<"enter data:";
        cin>>nn->info;
         nn->ptr=NULL;
         nn->pre=NULL;
    if(start==NULL)
    {
        start=nn;
        last=nn;
    }
    else{
            nn->pre=last;
            last->ptr=nn;
            last=nn;
    }
}


void insertbegin()
{
    struct node* nn =new node();
        cout<<"enter data:";
        cin>>nn->info;
         nn->ptr=NULL;
          nn->pre=NULL;
    if(start==NULL)
    {
        start=nn;
    }
     else{
        nn->ptr=start;
        start->pre=nn;
        start=nn;
    }
}

void insertmiddle(int i)
{
     struct node* nn =new node();
        cout<<"enter data:";
        cin>>nn->info;
        nn->ptr=NULL;
          nn->pre=NULL;

    struct node* temp;
        temp=start;
        for(int j=0;j<i-2;j++)
        {
            temp=temp->ptr;
        }
        nn->ptr=temp->ptr;
        nn->pre=temp;
        temp->ptr->pre=nn;
        temp->ptr=nn;
}




void deletebegin()
{
    if(start==NULL)
    {
        cout<<"list is empty";
    }
    else{
        node* temp=start;
        start=start->ptr;
        free(temp);
    }
}




void deletelast()
{
    if(start==NULL)
    {
        cout<<"list is empty\n";
    }
    else{
            node * temp = last;
    last->pre->ptr=NULL;
    last=last->pre;
    free(temp);

    }
}

void deletemiddle(int i)
{

    struct node* temp;
        temp=start;
        for(int j=0;j<i-2;j++)
        {
            temp=temp->ptr;
        }
        struct node* temp2=temp->ptr;
        temp->ptr->ptr->pre=temp;
        temp->ptr=temp->ptr->ptr;
        free(temp2);
}



int searchl(string s)
{
     struct node* temp;
        temp=start;
    if(start==NULL)
    {
        cout<<"list is empty\n";
    }
    int flag=0;
    int count=0;
    while(temp!=NULL)
    {
        if(temp->info==s)
        {
            flag=1;
            deletemiddle(count+1);
            return count;
        }
        temp=temp->ptr;
        count++;
    }
    if (flag==1)
    {
        cout<<"found the movie";
    }
    else
    {
        cout<<"movie not found";

    }



}

void search(string s)
{
     struct node* temp;
        temp=start;
    if(start==NULL)
    {
        cout<<"list is empty\n";
    }
    int flag=0;
    while(temp!=NULL)
    {
        if(temp->info==s)
        {
            flag=1;
             cout<<temp->pre->info<<"  "<<temp->info<<"  "<<temp->ptr->info;
        }
        temp=temp->ptr;
    }
    if (flag==1)
    {
        cout<<"found the movie";

    }
    else
    {
        cout<<"movie not found";
    }



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
            cout<<temp->info<<" -> ";
            temp=temp->ptr;
        }

    }
}
int main()
{
    int choice;
    cout<<"movie list";
    while(true)
    {

        cout<<"\nenter 1 for insert";
        cout<<"\nenter 2 for display full list";
        cout<<"\nenter 3 for search";
        cout<<"\nenter 4 for delect movie";
        cout<<"\nenter 7 for delete at middle\n";

        cin>>choice;
        if(choice==1)
        {
            insertlast();
        }
        if(choice==2)
        {
            display();
        }
        if(choice==3)
        {
            string ss;
            cout<<"enter movie to search";
            cin>>ss;
            search(ss);

        }
        if(choice==4)
        {
           string ss;
            cout<<"enter movie to delete";
            cin>>ss;
           cout<<searchl(ss);

        }


    }

}


