#include "BinaryTree.h"
#define MAX_PATH_LEN 20

int isLeaf(struct node *root) {
	return !root->left && !root->right; 
}

void delete_leaves(struct node *root) {
	
	if (root == NULL) {
		return; 
	}

	delete_leaves(root->left);
	delete_leaves(root->right);
	
        printf(" Delete = %d\n", root->data); 
        free(root);

	
/*
	printf(" Delete = %d\n", root->left->data); 
		free(root->left);
		root->left = NULL;
	}

	if(root->right != NULL && isLeaf(root->right)) {
		printf(" Delete = %d\n", root->right->data);
		free(root->right);
		root->right = NULL;
	}
*/

}

int main()
{
	node* root = BuildTree();
	delete_leaves(root);
	printTree(root);
}
