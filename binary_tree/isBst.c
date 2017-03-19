#include "BinaryTree.h"

int minValue(struct node* node) {
  struct node* current = node;
 
  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  return(current->data);
}

int maxValue(struct node* root)
{
    // Base case
    if (root == NULL)
      return -1;
 
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = maxValue(root->left);
    int rres = maxValue(root->right);
    if (lres > res)
      res = lres;
    if (rres > res)
      res = rres;
    return res;
}

int isBST(struct node* node) {
 if (node==NULL) return(1);
 // false if the min of the left is > than us
 if (node->left!=NULL && minValue(node->left) > node->data)
 return(0);
 // false if the max of the right is <= than us
 if (node->right!=NULL && maxValue(node->right) <= node->data)
 return(0);
 // false if, recursively, the left or right is not a BST
 if (!isBST(node->left) || !isBST(node->right))
 return(0);
 // passing all that, it's a BST
 return(1);
}

int main()
{
	node* root = BuildTree();
	printTree(root);
	printf("\n");
	if(isBST(root))
		printf("BST\n");
	else
		printf("Not BST\n");
}
