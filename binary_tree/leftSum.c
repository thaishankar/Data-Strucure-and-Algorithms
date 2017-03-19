#include "BinaryTree.h"

int leftSum(node *root, int flag) {

	if (root == NULL) 
		return 0;

	if (root->left == NULL && root->right == NULL) {
		if (flag) {
			printf ("left node = %d\n", root->data);
			return root->data;
		}
		else
			return 0;
	}

	return leftSum(root->left, 1) + leftSum(root->right, 0);
}

int main()
{
	node* root = BuildTree();
	printTree(root);
	printf("\n");
	int sum = leftSum(root, 0);
	printf("leftSum = %d\n", sum);
}

