// A C program to sort an array in wave form using a bubble sort function

#include<stdio.h>
// This function sorts arr[0..n-1] in wave form, i.e.,
// arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5]..
void sortInWave(int arr[], int n)
{
	// Sort the input array
	Sort(arr,n);
// Swap adjacent elements
	for (int i=0; i<n-1; i += 2)
		swap(&arr[i], &arr[i+1]);
}
void Sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int arr[] = {10, 90, 49, 2, 1, 5, 23};
	int n = sizeof(arr)/sizeof(arr[0]);
	sortInWave(arr, n);
	for (int i=0; i<n; i++)
	printf("%d \t",arr[i]);
	return 0;
}
