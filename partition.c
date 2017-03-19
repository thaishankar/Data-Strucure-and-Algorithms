// A recursive C program for partition problem
#include <stdio.h>      /* printf */
#include <stdlib.h> 

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int findPartiion (int arr[], int n)
{
	int i;
	int sum = 0, left_sum = 0;

	for(i = 0; i < n; i++)
		sum += arr[i];

	for(i = 0; i < n; i++) {
		left_sum = left_sum + arr[i];
		sum -= arr[i];
		if (left_sum == sum)
			return 1;
	}	
	return 0;
	
	
}

int main()
{
int i;
int arr[] = {3, 1, 5, 9, 12};
int n = sizeof(arr)/sizeof(arr[0]);

qsort(arr, n, sizeof(int), compare);

if (findPartiion(arr, n) == 1)
	printf("Can be divided into two subsets "
			"of equal sum");
else
	printf("Can not be divided into two subsets"
			" of equal sum");
return 0;
}

