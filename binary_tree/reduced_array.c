#include <iostream>
using namespace std;

typedef struct node {
	int val;
	int pos;
	struct node *left;
	struct node *right;
} node_t;

node_t* insert_tree(node_t *root, int val, int pos) {
	if (root == NULL) {
		node_t *newnode = (node_t *)malloc(sizeof(node_t));
		newnode->val = val;
		newnode->pos = pos;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
	else {
		if(val < root->val)
			root->left = insert_tree(root->left, val, pos);
		else
			root->right = insert_tree(root->right, val, pos);	
	}
	return root;
}

void inorder_traverse(node_t *root, int *arr) {
	static int val = 0;

	if (root == NULL)
		return;

	inorder_traverse(root->left, arr);
	arr[root->pos] = val;
	val++;	
	printf("Writing val = %d\n", val);
	inorder_traverse(root->right, arr);
}

 
void convert(int *arr, int n)
{
    int val = 0;
    node_t *root = NULL;
    for (int i = 0; i < n; i++)
       root = insert_tree(root, arr[i], i);

    inorder_traverse(root, arr);  
}
 
void printArr(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
 
// Driver program to test above method
int main()
{

    int arr[] = {10, 20, 15, 12, 11, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
 
 
    cout << "Given Array is \n";
    printArr(arr, n);
 
    convert(arr , n);
 
    cout << "\n\nConverted Array is \n";
    printArr(arr, n);
 
    return 0;
}

