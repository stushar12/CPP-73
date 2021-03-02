#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted is lesser, insert in left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert in right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}

int balanced_BST(Node* root)
{
	if(root==NULL)
	return 0;

	int lh=balanced_BST(root->left);
	if(lh==-1)
	return -1;

	int rh=balanced_BST(root->right);
	if(rh==-1)
	return -1;

	if(abs(lh-rh)>1)
	return -1;
	else
	return max(lh,rh)+1;

}


int main() 
{
	Node* root = NULL;  // Creating an empty tree

	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,25);

	cout<<balanced_BST(root);

}
