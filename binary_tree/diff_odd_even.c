// A recursive program to find difference between sum of nodes at
// odd level and sum at even level
#include <stdio.h>
#include <stdlib.h>

// Binary Tree node
typedef struct node
{ 
	int data;
	struct node* left, *right;
} node_t;
void find_sum(node_t *root, int level, int *odd_sum , int *even_sum);

// A utility function to allocate a new tree node with given data
struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

int getLevelDiff(struct node *root)
{
if (root == NULL)
		return 0;
int even_sum = 0;
int odd_sum = 0;
find_sum(root, 1, &odd_sum , &even_sum);
return odd_sum - even_sum;
}

void find_sum(node_t *root, int level, int *odd_sum , int *even_sum) {
	if (root == NULL)
		return; 
	if (level % 2 == 0)
		even_sum += root->data;
	else
		odd_sum += root->data;

	find_sum(root->left, level+1, odd_sum, even_sum);
	find_sum(root->right, level+1, odd_sum, even_sum);
}

// Driver program to test above functions
int main()
{
	struct node *root = newNode(5);
	root->left = newNode(2);
	root->right = newNode(6);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	root->left->right->left = newNode(3);
	root->right->right = newNode(8);
	root->right->right->right = newNode(9);
	root->right->right->left = newNode(7);
	printf("%d is the required difference\n", getLevelDiff(root));
	getchar();
	return 0;
}

