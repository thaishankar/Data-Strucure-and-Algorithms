#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* A utility function to check whether trees with roots as root1 and
   root2 are identical or not */
bool areIdentical(struct node * root1, struct node *root2)
{
    /* base cases */
    if (root1 == NULL && root2 == NULL)
        return true;
 
    if (root1 == NULL || root2 == NULL)
        return false;
 
    /* Check if the data of both roots is same and data of left and right
       subtrees are also same */
    return (root1->data == root2->data   &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right) );
}

struct node* lookup(struct node *root, int data)
{
	if (root == NULL) return false;
	if (root->data == data) return root;
	if (root->data < data) return lookup(root->right, data);
	else if (root->data > data) return lookup(root->left, data);

}
 
 
/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(struct node *T, struct node *S)
{
    struct node* rooted_node = NULL;
    /* base cases */
    if (S == NULL)
        return true;
 
    if (T == NULL)
        return false;
 
    /* Check the tree with root as current node */
    rooted_node = lookup(T, S->data); 

    if (rooted_node == NULL)
	return false;
 
    /* If the tree with root as current node doesn't match then
       try left and right subtrees one by one */
    return areIdentical(rooted_node, S);
}
 
 
/* Helper function that allocates a new node with the given data
   and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return(node);
}
 
/* Driver program to test above function */
int main()
{
    // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if (isSubtree(T, S))
        printf("Tree 2 is subtree of Tree 1");
    else
        printf("Tree 2 is not a subtree of Tree 1");
 
    getchar();
    return 0;
}

