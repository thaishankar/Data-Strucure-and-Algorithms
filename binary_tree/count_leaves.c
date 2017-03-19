#include "BinaryTree.h"
#define MAX_PATH_LEN 20


int count_leaves(struct node *root) {
	
	if (root == NULL) {
		return 0; 
	}

	if(root->left == NULL && root->right == NULL) {
		return 1;
	}

	return (count_leaves(root->left) + count_leaves(root->right));
}

int main()
{
	int count = 0;
	node* root = BuildTree();
	count = count_leaves(root);
	printf("Leaves = %d\n", count);
	printTree(root);
}
