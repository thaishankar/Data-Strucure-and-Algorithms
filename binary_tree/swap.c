#include "binaryTree.h"

struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

void printTree(struct node* node) {
 if (node == NULL) return;
 printTree(node->left);
 printf("%d ", node->data);
 printTree(node->right);
}

node* BuildTree()
{
 
  /* Constructed binary tree is
            4 
          /   \
        2      6
      /  \    /
    1     3  5 
  */
  struct node *root = newnode(4);
  root->left        = newnode(2);
  root->right       = newnode(6);
  root->left->left  = newnode(1);
  root->left->right = newnode(3);
  root->right->left = newnode(5);
   
	return root;
}

node* BuildTree2()
{
 
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
   
        return root;
}
