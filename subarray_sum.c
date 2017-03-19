#include<stdio.h>

int subArraySum(int a[], int n, int sum)
{
	int front = 0, back = 0, sub_sum = 0;
	
	while(front < n) {
		while(sub_sum < sum && front < n) {
			sub_sum += a[front];
			front++;
		}
		while(sub_sum > sum && back < front)
		{
			sub_sum -= a[back];
			back++;
		}
		if(sum == sub_sum) {
			printf ("Sum found between indexes %d and %d", front, back);
			return 1;
		}
	}

	// If we reach here, then no subarray
	printf("No subarray found");
	return 0;
}

// Driver program to test above function
int main()
{
	int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 23;
	subArraySum(arr, n, sum);
	return 0;
}

