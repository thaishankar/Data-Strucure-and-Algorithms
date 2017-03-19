// C++ program to print matrix in diagonal order
#include <iostream>
using namespace std;
const int MAX = 100;
#define R 3
#define C 3
 
bool isvalid(int i, int j)
{
    if (i < 0 || i >= R || j >= C || j < 0) return false;
    return true;
}

void printMatrixDiagonal(int mat[MAX][MAX], int n) {
    int i = 0, j = 0 ;
    int col = 0, limit;
    int rowStart, colStart;

    for( i = 0; i < C; i++) {
	rowStart = R - 1;
        colStart = i;
	while(isvalid(rowStart, colStart)) {
		cout << mat[rowStart][colStart] << " ";
		rowStart--;
		colStart--;
        }
    }
    for (i = R - 2; i >= 0; i--) {
	rowStart = i;
	colStart = C - 1;
	while(isvalid(rowStart, colStart)) {
		cout << mat[rowStart][colStart] << " ";
		rowStart--;
		colStart--;
	}
    }
}

int main()
{
    int mat[MAX][MAX] = {{1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
 
    int n = 3;
    printMatrixDiagonal(mat, n);
    return 0;
}
