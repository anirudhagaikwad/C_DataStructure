/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of
S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn\’t matter.
For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}.
So output should be 4.
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
So the output should be 5.


Input: N=8
        Coins : 1, 5, 10
Output: 2

Explanation:
1 way:
      1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 8 cents.
2 way:
      1 + 1 + 1 + 5 = 8 cents.
*/


#include<stdio.h>

int count( int S[], int m, int n )
{
	int i, j, x, y;

	// We need n+1 rows as the table is constructed
	// in bottom up manner using the base case 0
	// value case (n = 0)
	int table[n+1][m];

	// Fill the entries for 0 value case (n = 0)
	for (i=0; i<m; i++)
		table[0][i] = 1;

	// Fill rest of the table entries in bottom
	// up manner
	for (i = 1; i < n+1; i++)
	{
		for (j = 0; j < m; j++)
		{
			// Count of solutions including S[j]
			x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

			// Count of solutions excluding S[j]
			y = (j >= 1)? table[i][j-1]: 0;

			// total count
			table[i][j] = x + y;
		}
	}
	return table[n][m-1];
}

int main()
{
	int arr[] = {1, 2, 3};
	int m = sizeof(arr)/sizeof(arr[0]);
	int n = 4;
	printf(" %d ", count(arr, m, n));
	return 0;
}
