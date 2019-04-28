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

    cout<<root->data<<" ";

        lror(root->right);

}
void rolr(node* root)
{
    if(root==NULL)
    {
        return;
    }
        cout<<root->data<<" ";
        lror(root->left);
        lror(root->right);

}
void lrro(node* root)
{
    if(root==NULL)
    {
        return;
    }

        lror(root->left);
        lror(root->right);
        cout<<root->data<<" ";

}

bool search(node* root,int data)
{
    if(root==NULL)
        return false;
    else if(root->data==data)
    {
        return true;
    }
    else if(root->data<data)
    {
        return search(root->right,data);
    }
    else {return search(root->left,data); }
}



node* FindMin(node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

// Function to search a delete a value from tree.
struct node* Delete(struct node *root, int data) {
	if(root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child
		else if(root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			struct node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}


void LevelOrder(node *root) {
	if(root == NULL) return;
	queue<node*> Q;
	Q.push(root);
	//while there is at least one discovered node
	while(!Q.empty()) {
		node* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}
int main()
{
    int data;
    int choice;
    while(true){
    cout<<"\n1 insert data in binary tree\n";
    cout<<"2 inorder display\n";
    cout<<"3 preprder display\n";
    cout<<"4 postorder display\n";
    cout<<"5 search element\n";
    cout<<"6 delete element\n";
    cout<<"7 level order display\n";
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
    }
    else if(choice==3)
    {
        rolr(root);
    }
    else if(choice==4)
    {
        lrro(root);
    }
    else if(choice==5)
    {
        cout<<"enter data to be searched\n";
        cin>>data;
        if(search(root,data))
        {
            cout<<"data is found\n";
        }
        else
        {
            cout<<"data is not found\n";
        }
    }
    else if(choice==6)
    {
        cout<<"enter data to be deleted\n";
        cin>>data;
        root=Delete(root,data);
    }
    else if(choice==7)
    {
        LevelOrder(root);
    }}
}
