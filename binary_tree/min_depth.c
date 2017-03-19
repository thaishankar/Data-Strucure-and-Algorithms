// C++ program to find minimum depth of a given Binary Tree
#include<iostream>
using namespace std;
 
// A BT Node
typedef struct Node
{
    int data;
    struct Node* left, *right;
} Node;

void min_depth(Node *root, int level, int *min);
 
int minDepth(Node *root)
{
	if(root == NULL)
		return 0;
	
	int min = INT_MAX;
	min_depth(root, 1, &min);
	return min;
	
 
}

void min_depth(Node *root, int level, int *min) {
	if (root == NULL)
		return;

	if (root->left == NULL && root->right == NULL && (level < *min))
		*min = level;

	min_depth(root->left, level + 1, min);
	min_depth(root->right, level + 1, min);
}
 
// Utility function to create new Node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data  = data;
    temp->left  = temp->right = NULL;
    return (temp);
}
 
// Driver program
int main()
{
    // Let us construct the Tree shown in the above figure
    Node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    cout << minDepth(root);
    return 0;
}
