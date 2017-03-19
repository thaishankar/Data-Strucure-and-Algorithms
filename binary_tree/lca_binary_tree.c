// A O(n) solution to find LCA of two given values n1 and n2
#include <iostream>
#include <vector>
using namespace std;
 
// A Bianry Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};
 
// Utility function creates a new binary tree node with given key
Node * newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

bool findpath(Node *root, int n, vector<int> &path) {
	if(root == NULL)
		return false;

	path.push_back(root->key);

	if(root->key == n)
		return true;
	
	if(findpath(root->left, n, path) || findpath(root->right, n, path)) {
		return true;
	}
	path.pop_back();
	return false;
}
 
int findLCA(Node *root, int n1, int n2)
{
	vector<int> v1, v2;
	
	if(!findpath(root, n1, v1) || (!findpath(root, n2, v2)))
		return -1;
	
	int i;
	for(i=0; i < v1.size() && i < v2.size(); i++) {
		if(v1[i] != v2[i])
			break;	
	}
	return v1[i-1];
}
 
// Driver program to test above functions
int main()
{
    // Let us create the Binary Tree shown in above diagram.
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
}
