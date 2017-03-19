#include "BinaryTree.h"

int maxDepth(struct node* node) {
	if (node==NULL) {
 	return(0);
}
else {
// compute the depth of each subtree
	int lDepth = 1 + maxDepth(node->left);
	int rDepth = 1 + maxDepth(node->right);
// use the larger one
	 if (lDepth > rDepth) 
		return(lDepth);
 	 else 
		return(rDepth);
	}
}

int main()
{
	node* root = BuildTree();
	printTree(root);
	printf("\n");
	int depth = maxDepth(root);
	printf("Depth = %d\n", depth);
}

