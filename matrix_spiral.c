/* This code is adopted from the solution given 
   @ http://effprog.blogspot.com/2011/01/spiral-printing-of-two-dimensional.html */
 
#include <stdio.h>
#define R 3
#define C 6
 
void spiralPrint(int m, int n, int a[R][C])
{
   int rowStart = 0, rowEnd = R - 1;
   int colStart = 0, colEnd = C - 1;
   while(rowStart <= rowEnd && colStart <= colEnd) {
	int i;

	for (i = colStart; i <= colEnd; i++) {
		printf("%d ", a[rowStart][i]);
	}
	rowStart++;

	for (i = rowStart; i <= rowEnd; i++) {
		printf("%d ", a[i][colEnd]);
	}
	colEnd--;

	if(rowStart <= rowEnd) {
		for (i = colEnd; i >= colStart; i--) {
			printf("%d ", a[rowEnd][i]);
		}
	}
	rowEnd--;

	if(colStart <= colEnd) {
		for (i = rowEnd; i >= rowStart; i--) {
			printf("%d ", a[i][colStart]);
		}
	}

	colStart++;
   }

}
 
/* Driver program to test above functions */
int main()
{
    int a[R][C] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
 
    spiralPrint(R, C, a);
    return 0;
}
 
