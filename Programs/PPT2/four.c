/* C program to print
subarray with sum as given sum
*/
#include <stdio.h>

/* Returns true if the there is a subarray
of arr[] with a sum equal to 'sum'
otherwise returns false. Also, prints
the result */
void subArraySum(int arr[], int n, int sum)
{
	// Pick a starting point
	for (int i = 0; i < n; i++) {
		int currentSum = arr[i];

		if (currentSum == sum) {
			printf("Sum found at indexe %d ", i);
			return;
		}
		else {
			// Try all subarrays starting with 'i'
			for (int j = i + 1; j < n; j++) {
				currentSum += arr[j];

				if (currentSum == sum) {
					printf("Sum found between indexes %d "
						"and %d",
						i, j);
					return;
				}
			}
		}
	}
	printf("No subarray found");
	return;
}

// Driver program to test above function
int main()
{
	int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 23;
	subArraySum(arr, n, sum);
	return 0;
}
