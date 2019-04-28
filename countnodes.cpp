#include<iostream>
#include<queue>
using namespace std;
struct node
{
    node* left;
    int data;
    node* right;
};
node* root;
int count;
void insert(node** root,int data)
{
    if(*root==NULL)
    {
        *root=new node();
        (*root)->data=data;
        (*root)->left=NULL;
        (*root)->right=NULL;

    }
    else if(data<=(*root)->data)
    {
        insert(&(*root)->left,data);

    }
    else
    {
        insert(&(*root)->right,data);

    }
}

void lror(node* root)
{
    if(root==NULL)
    {
        return;
    }
        lror(root->left);
        if(root->left==NULL&&root->right==NULL)
            count++;
        lror(root->right);

}

int main()
{
    int data;
    int choice;
    while(true){
    cout<<"\n1 insert data in binary tree\n";
    cout<<"2 count\n";

    cin>>choice;
    if(choice==1)
    {
        cout<<"enter data to be inserted\n";
        cin>>data;
        insert(&root,data);
    }
    else if(choice==2)
    {
        lror(root);
        cout<<"count of leaf nodes="<<count;
        count=0;
    }
    }

}
