#include "BinaryTree.h"

void mirror(struct node* node) {
 if (node==NULL) {
 return;
 }
 struct node* temp;
 // do the subtrees
 // swap the pointers in this node
 temp = node->left;
 node->left = node->right;
 node->right = temp;

 mirror(node->left);
 mirror(node->right);
}

int main()
{
	node* root = BuildTree();
	printf("\noriginal \n");
	printTree(root);
	printf("\nmirror \n");
	mirror(root);
	printTree(root);
}
