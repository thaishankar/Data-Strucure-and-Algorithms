/* An efficient program to print subarray with sum as given sum */
#include<stdio.h>

/* Returns true if the there is a subarray of arr[] with sum equal to 'sum'
otherwise returns false. Also, prints the result */
int subArraySum(int arr[], int n, int sum)
{
	/* Initialize curr_sum as value of first element
	and starting point as 0 */
	int curr_sum = 0, start = 0, end = 0, i;

	/* Add elements one by one to curr_sum and if the curr_sum exceeds the
	sum, then remove starting element */
	for (i = 1; i <= n; i++)
	{
		// If curr_sum exceeds the sum, then remove the starting elements
		if (curr_sum < sum && end < n)
		{
			curr_sum = curr_sum + arr[end];
			end++;
		}

		// If curr_sum becomes equal to sum, then return true
		if (curr_sum == sum)
		{
			printf ("Sum found between indexes %d and %d", start, end);
			return 1;
		}

		// Add this element to curr_sum
		if (curr_sum > sum && start < end) {
		    curr_sum = curr_sum - arr[start];
		    start++;
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

