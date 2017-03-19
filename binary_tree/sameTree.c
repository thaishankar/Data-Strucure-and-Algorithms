#include "BinaryTree.h"

int sameTree(node* root1, node* root2) {
 if ((root1==NULL) && (root2==NULL)) {
 	return 1;
 }
	
 return (root1->data == root2->data &&
	 sameTree(root1->left, root2->left) &&
	 sameTree(root1->right, root2->right));
}

int main()
{
	node* root1 = BuildTree();
	node* root2 = BuildTree2();

	if(sameTree(root1, root2))
		printf("Trees are same");
	else
		printf("Trees are different");

	printTree(root1);
	printTree(root2);
}
