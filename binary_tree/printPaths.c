#include "BinaryTree.h"
#define MAX_PATH_LEN 20


void print_route(int path[], int pathlen) {
	int i = 0;
	printf("\n");
	for(i = 0; i < pathlen; i++)
		printf("%d ", path[i]);
	printf("\n");
}

void printPaths(struct node *root, int pathlen, int path[]) {
	
	if (root == NULL) {
		print_route(path, pathlen);
		return;
	}

	path[pathlen] = root->data;
	pathlen++;
	/*
	if(root->left == NULL && root->right == NULL) {
		print_route(path, pathlen);
	}
	*/
 	//	else {
		printPaths(root->left, pathlen, path);
		printPaths(root->right, pathlen, path);
	// }
}

int main()
{
	int p[MAX_PATH_LEN];
	node* root = BuildTree();
	printTree(root);
	printPaths(root, 0, p);
	printTree(root);
}
