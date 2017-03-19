// A C++ program to move all zeroes at the end of array
#include <iostream>
using namespace std;

// Function which pushes all zeros to end of an array.
void pushZerosToEnd(int arr[], int n)
{
	int count = 0; // Count of non-zero elements

    int i = 0, j = n-1;
    int tmp;
    
    while(i<j) {
        while(i<j && arr[i]!=0)
            i++;
        while(i<j && arr[j]==0)
            j--;
        tmp = arr[i];
        arr[i]= arr[j];
        arr[j] = tmp;
        i++, j--;
    }
}

// Driver program to test above function
int main()
{
	int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	pushZerosToEnd(arr, n);
	cout << "Array after pushing all zeros to end of array :\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}

