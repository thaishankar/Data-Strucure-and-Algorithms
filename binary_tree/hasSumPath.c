#include "binaryTree.h"

int hasPathSum(struct node* node, int sum) {
 // return true if we run out of tree and sum==0
 if (node == NULL) {
	 return(sum == 0);
 }
 else {
 // otherwise check both subtrees
 	sum = sum - node->data;
 	return(hasPathSum(node->left, sum) ||
 	hasPathSum(node->right, sum));
 }
}

struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

int main()
{
 
  int sum = 15;
 
  /* Constructed binary tree is
            5 
          /   \
        2      6
      /  \    /
    1     3  4
  */
  struct node *root = newnode(5);
  root->left        = newnode(2);
  root->right       = newnode(6);
  root->left->left  = newnode(1);
  root->left->right = newnode(3);
  root->right->left = newnode(4);
 
  if(hasPathSum(root, sum))
    printf("There is a root-to-leaf path with sum %d\n", sum);
  else
    printf("There is no root-to-leaf path with sum %d\n", sum);
 
  return 0;
}
