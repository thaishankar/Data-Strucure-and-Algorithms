// A Stack based C program to find next greater element
// for all array elements.
#include<iostream>
#include<bits/stdc++.h>

void printNGE(int arr[], int n)
{
	std::stack<int> s;
 	int i = 0;
	int elem;

	while(i<n) {
		while(!s.empty() && s.top() < arr[i]) {
			elem = s.top();
			s.pop();
			printf("%d -- %d\n", elem, arr[i]);
		}
		s.push(arr[i]);
		i++;
	}	

	while(!s.empty()) { 
		elem = s.top();
                s.pop();
                printf("%d -- %d\n", elem, -1);
	}
	
}

/* Driver program to test above functions */
int main()
{
	int arr[]= {11, 13, 21, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	printNGE(arr, n);
	getchar();
	return 0;
}

