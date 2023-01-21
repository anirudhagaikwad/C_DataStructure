/* C program for brute force method to calculate stock span values

The stock span problem is a financial problem where we have a series of N daily price quotes for a stock and we need to
calculate the span of the stock’s price for all N days. The span Si of the stock’s price on a given day i is defined as the
maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less
than its price on the given day.

----Traverse the input price array. For every element being visited, traverse elements on the left of it and increment the
span value of it while elements on the left side are smaller

*/
#include <stdio.h>

// Fills array S[] with span values
void calculateSpan(int price[], int n, int S[])
{
	// Span value of first day is always 1
	S[0] = 1;

	// Calculate span value of remaining days by linearly
	// checking previous days
	for (int i = 1; i < n; i++) {
		S[i] = 1; // Initialize span value

		// Traverse left while the next element on left is
		// smaller than price[i]
		for (int j = i - 1;
			(j >= 0) && (price[i] >= price[j]); j--)
			S[i]++;
	}
}

// A utility function to print elements of array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int price[] = { 10, 4, 5, 90, 120, 80 };
	int n = sizeof(price) / sizeof(price[0]);
	int S[n];

	// Fill the span values in array S[]
	calculateSpan(price, n, S);

	// print the calculated span values
	printArray(S, n);

	return 0;
}
