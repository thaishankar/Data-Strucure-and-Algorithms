#include<stdio.h>

/* Searches the element x in mat[][]. If the element is found, 
	then prints its position and returns true, otherwise prints 
	"not found" and returns false */
int search(int mat[][4], int m, int n, int x)
{
int i = 0, j = n-1; //set indexes for top right element
while ( i < m && j >= 0 )
{
	if ( mat[i][j] == x )
	{
		printf("\n Found at %d, %d", i, j);
		return 1;
	}
	if ( mat[i][j] > x )
		j--;
	else // if mat[i][j] < x
		i++;
}

printf("\n Element not found");
return 0; // if ( i==n || j== -1 )
}

// driver program to test above function
int main()
{
int mat[4][4] = { {1, 3, 5, 7},
					{10, 11, 16, 20},
					{23, 30, 34, 50},
				};
search(mat, 3, 4, 30);
getchar();
return 0;
}

