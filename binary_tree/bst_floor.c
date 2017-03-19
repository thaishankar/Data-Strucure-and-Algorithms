// Program to find floor of a given value in BST
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has key, left child and right child */
struct node
{
	int key;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node with the given key and
NULL left and right pointers.*/
struct node* newNode(int key)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

int Floor(struct node *root, int input)
{
	// Base case
	if( root == NULL )
		return -1;

	// We found equal key
	if( root->key == input )
		return root->key;

	if( input > root->key )
		return Floor(root->right, input);

	int floor_val = Floor(root->left, input);
	return (root->key >= floor_val) ? root->key : floor_val;
}

// Driver program to test above function
int main()
{
	struct node *root = newNode(8);

	root->left = newNode(4);
	root->right = newNode(12);

	root->left->left = newNode(2);
	root->left->right = newNode(6);

	root->right->left = newNode(10);
	root->right->right = newNode(14);

	for(int i = 0; i < 16; i++)
		printf("%d %d\n", i, Floor(root, i));

	return 0;
}

