#include <stdio.h>
#include <limits.h>

// Returns minimum number of jumps to reach arr[h] from arr[l]
int minJumps(int arr[], int n, int curr)
{
// Base case: when source and destination are same
if (curr == n-1)
	return 0;

// When nothing is reachable from the given source
if (curr >= n)
	return INT_MAX;

// Traverse through all the points reachable from arr[l]. Recursively
// get the minimum number of jumps needed to reach arr[h] from these
// reachable points.
int min = INT_MAX;
for (int i = 1; i <= n && i <= arr[curr]; i++)
{
	int jumps = minJumps(arr, n, curr+i);
	if(jumps != INT_MAX && jumps + 1 < min)
		min = jumps + 1;
}

return min;
}

// Driver program to test above function
int main()
{
int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
int n = sizeof(arr)/sizeof(arr[0]);
printf("Minimum number of jumps to reach end is %d ", minJumps(arr, n, 0));
return 0;
}

