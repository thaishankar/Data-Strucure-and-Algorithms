#include "BinaryTree.h"

//Max sum path root to leaf

int maxSumPath(node *root, int sum) {

	int lsum, rsum;
	if (root == NULL) return sum;

	sum = sum + root->data;
	lsum = maxSumPath(root->left, sum);
	rsum = maxSumPath(root->right, sum);
	if (lsum > rsum)
		return lsum;
	else	
		return rsum;
}

int main()
{
	node* root = BuildTree();
	printTree(root);
	printf("\n");
	int max = maxSumPath(root, 0);
	printf("Sum = %d\n", max);
	printTree(root);
}
