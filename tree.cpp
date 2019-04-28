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
        cout<<"inserted \n";
    }
    else if(data<=(*root)->data)
    {
        insert(&(*root)->left,data);
        cout<<"left ";
    }
    else
    {
        insert(&(*root)->right,data);
        cout<<"right ";
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

node* Find(node*root, int data) {
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(root->right,data);
	else return Find(root->left,data);
}
struct node* Getsuccessor(struct node* root,int data) {
	// Search the Node - O(h)
	struct node* current = Find(root,data);
	if(current == NULL) return NULL;
	if(current->right != NULL) {  //Case 1: Node has right subtree
		return FindMin(current->right); // O(h)
	}
	else {   //Case 2: No right subtree  - O(h)
		struct node* successor = NULL;
		struct node* ancestor = root;
		while(ancestor != current) {
			if(current->data < ancestor->data) {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
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
    for(int i=0;i<500;i++)
    insert(&root,i);


    lror(root);

}
