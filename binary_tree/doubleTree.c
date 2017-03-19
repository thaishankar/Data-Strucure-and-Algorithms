#include "BinaryTree.h"

void doubleTree(struct node* node) {
 struct node* oldLeft;
 if (node==NULL) return;
 // do the subtrees
 // duplicate this node to its left
 doubleTree(node->left);
 doubleTree(node->right);

 struct node* mynode = newnode(node->data);
 mynode->left = node->left;
 node->left = mynode;

}

int main()
{
	node* root = BuildTree();
	doubleTree(root);
	printTree(root);
}
