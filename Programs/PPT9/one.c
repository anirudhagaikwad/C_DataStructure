// C program to sort an array with 0, 1 and 2 in a single pass

#include <stdio.h>

/* Function to swap *a and *b */
void swap(int* a, int* b);

// Sort the input array, the array is assumed to
// have values in {0, 1, 2}
void sort012(int a[], int arr_size)
{
	int lo = 0;
	int hi = arr_size - 1;
	int mid = 0;
	// Iterate till all the elements
	// are sorted
	while (mid <= hi) {
		switch (a[mid]) {
			// If the element is 0
		case 0:
			swap(&a[lo++], &a[mid++]);
			break;
			// If the element is 1
		case 1:
			mid++;
			break;
			// If the element is 2
		case 2:
			swap(&a[mid], &a[hi--]);
			break;
		}
	}
}

/* UTILITY FUNCTIONS */
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* Utility function to print array arr[] */
void printArray(int arr[], int arr_size)
{
	int i;
	for (i = 0; i < arr_size; i++)
		printf("%d ", arr[i]);
}


int main()
{
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	int i;

	sort012(arr, arr_size);

	printArray(arr, arr_size);

	getchar();
	return 0;
}
