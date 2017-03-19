// C++ program to find minimum time required to make all
// oranges rotten
#include<bits/stdc++.h>
#define R 3
#define C 5
using namespace std;
 
// function to check whether a cell is valid / invalid
bool isvalid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < R && j < C);
}
 
// Function to check whether there is still a fresh
// orange remaining
bool checkall(int arr[][C])
{
    for (int i=0; i<R; i++)
       for (int j=0; j<C; j++)
          if (arr[i][j] == 1)
             return true;
    return false;
}

// A function to check if a given cell (row, col) can be included in DFS
int isSafe(int M[][C], int row, int col, int visited[][C])
{
    // row number is in range, column number is in range and value is 1 
    // and not yet visited
    return (row >= 0) && (row < R) &&     
           (col >= 0) && (col < C) &&      
           (M[row][col] && !visited[row][col]); 
}
 
// A utility function to do DFS for a 2D boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void DFS(int M[][C], int row, int col, int visited[][C], int *time)
{
    // These arrays are used to get row and column numbers of 8 neighbours 
    // of a given cell
    static int rowNbr[] = {0, -1, 0, 1};
    static int colNbr[] = {-1, 0, 1, 0};
 
    // Mark this cell as visited
    visited[row][col] = true;
    *time++;

    if (M[row][col] == 1)
	M[row][col] = 2;
 
    // Recur for all connected neighbours
    for (int k = 0; k < 4; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited) )
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
}
 
// This function finds if it is possible to rot all oranges or not.
// If possible, then it returns minimum time required to rot all,
// otherwise returns -1
int rotOranges(int arr[][C])
{
 
    int visited[R][C] = {0};
    int i, j;
    int time = 0, max_time = 0;
    // Store all the cells having rotten orange in first time frame
    for (i=0; i<R; i++)
    {
       for (j=0; j<C; j++)
       {
            if (arr[i][j] == 2)  && (!visited[i][j]))
            {
		time = 0;
		DFS(arr, i, j, visited, &time);
		if (time > max_time)
			max_time = time;
		
            }
        }
    }

    for (i=0; i<R; i++)
    {
	for (j=0; j<C; j++)
	{
		if (arr[i][j] == 1)
			return max_time;
	}
    }
    return -1;
}
 
// Drive program
int main()
{
    int arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
    int ans = rotOranges(arr);
    if (ans == -1)
        cout << "All oranges cannot rot\n";
    else
         cout << "Time required for all oranges to rot => " << ans << endl;
    return 0;
}

