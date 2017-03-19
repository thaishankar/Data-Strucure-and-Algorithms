#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct node
{
   int data;
   struct node* left;
   struct node* right;
}node;

struct node* newnode(int data);
void printTree(struct node* node);
node* BuildTree();
node* BuildTree2();
