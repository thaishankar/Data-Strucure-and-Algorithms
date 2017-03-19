#include <stdlib.h> 
#include <assert.h> 
#include <stdio.h>

extern int find( int *, int ); 
	
int find (int * arr, int n) {

	return binary_search(arr, 0, n-1);
	
}

int binary_search(int *a, int left, int right) {
	if (left >= right - 1) { //Deal with the edge condition
		if ((left > 0) && (a[left] > a[left - 1] + 1))
			return (a[left] - 1);
		else
			return (a[left] + 1);
	}

	int mid = left + (right - left) / 2;
	if (mid - left <= a[mid] - a[left])
		return binary_search(a, left, mid);
	else
		return binary_search(a, mid, right);
}

int main( int argc, char *argv[] ) { 
int o[4][5] = { { 4,6,7,8,9 }, 
{ 4,5,7,8,9 }, 
{ 4,5,6,8,9 }, 
{ 4,5,6,7,9 } }; 

int e[5][6] = { { 4,6,7,8,9,10 }, 
{ 4,5,7,8,9,10 }, 
{ 4,5,6,8,9,10 }, 
{ 4,5,6,7,9,10 }, 
{ 4,5,6,7,8,10 } }; 
int i; 
for( i=0; i < 4; i++ ) 
assert( find( o[ i ], 5 ) == i + 5 ); 
for( i=0; i < 5; i++ ) 
assert( find( e[ i ], 6 ) == i + 5 ); 

printf ("I'm a winner\n"); 
return 0; 
} 

