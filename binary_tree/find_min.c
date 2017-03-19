#include "BinaryTree.h"

int FindMin( struct node *bt )
{
    if( !bt)
        return 0;  // Only if the tree contains nothing at all
    if( bt->left )
        return FindMin(bt->left);
    return bt->data;
}

int main()
{
	node* root = BuildTree();
	printTree(root);
	printf("\n");
	int min = FindMin(root);
	printf("Min = %d\n", min);
}

