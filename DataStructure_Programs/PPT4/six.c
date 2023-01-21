/*
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and print its area.

Input:
1
5 5
0 0 1 0 1
0 1 1 1 1
1 1 1 1 1
1 1 1 1 1
0 0 1 1 1

Output:
12

Explanation:
The inner matrix from index (1,1) to index (3,4) with area 12(3*4) gives the appropriate solution
*/
#include <stdio.h>
#include <conio.h>

// `M × N` matrix
#define M 4
#define N 5

// Utility function to replace all non-zero values in a matrix by 1
void resetMatrix(int mat[][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] != 0) {
                mat[i][j] = 1;
            }
        }
    }
}

// Utility function to find the maximum of two numbers
int max(int x, int y) {
    return (x > y) ? x : y;
}

// Function to calculate the area of the largest rectangle of 1's where swapping of
// columns is allowed
int findMaxRectArea(int mat[][N])
{
    // update the matrix to store the counts of consecutive 1's present in each column
    for (int j = 0; j < N; j++)
    {
        // process each column from bottom to top
        for (int i = M - 2; i >= 0; i--)
        {
            if (mat[i][j] == 1) {
                mat[i][j] = mat[i+1][j] + 1;
            }
        }
    }

    // keep track of the largest rectangle of 1's found so far
    int maxArea = 0;

    // traverse each row in the modified matrix to find the maximum area
    for (int i = 0; i < M; i++)
    {
        // create a count array for each row `i`
        int count[M + 1] = { 0 };

        // process row `i`
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] > 0)
            {
                // increment value in the count array using the current element
                // as an index
                count[mat[i][j]] += 1;

                // the area can be calculated by multiplying the current
                // element `mat[i][j]` with the corresponding value
                // in the count array `count[mat[i][j]]`

                maxArea = max(maxArea, mat[i][j] * count[mat[i][j]]);
            }
        }
    }

    // reset matrix before returning
    resetMatrix(mat);

    return maxArea;
}

int main(void)
{
    int mat[M][N] =
    {
       {0, 0, 1, 0, 1},
	   {0, 1, 1, 1, 1},
	   {1, 1, 1, 1, 1},
	   {1, 1, 1, 1, 1},
	   {0, 0, 1, 1, 1}
    };

    printf("The area of the largest rectangle of 1's is %d", findMaxRectArea(mat));

    return 0;
}
