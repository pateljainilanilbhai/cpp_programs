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
    int data;
    struct node * left;
    struct node * right;
};
int data;
struct node *start;


void insert(node ** tree, int val) {
 node *temp = NULL;
 if(!(*tree)) {
   temp = new node();
  temp->left = temp->right = NULL;
  temp->data = val;
  *tree = temp;
  return;
}

 if(val < (*tree)->data) {
     insert(&(*tree)->left, val);
  } else if(val > (*tree)->data) {
    insert(&(*tree)->right, val);
  }
}



void displayinorder(node * root)
{
    if(root==NULL)
    {
        return;
    }
    displayinorder(root->left);
    cout<<root->data<<" ";
    displayinorder(root->right);

}
int main()
{

    int choice;
    while(true){
        cout<<"\nenter 1 for insert";
        cout<<"\nenter 2 for display";
        cin>>choice;
        if(choice==1)
        {

            cout<<"enter data:";
            cin>>data;
            insert(&start,data);

        }
        if(choice==2)
        {
            displayinorder(start);
        }

        }
}
