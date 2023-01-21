/*
 Write a C program to find the position of a target value within a array using Ternary search.
*/

#include <stdio.h>

int ternarySearch(int l, int array_size, int key, int array_nums[])

{
	while (array_size >= l) {

		// Find the mid1 and mid2
		int mid1 = l + (array_size - l) / 3;
		int mid2 = array_size - (array_size - l) / 3;

		// Check if key is present at any mid
		if (array_nums[mid1] == key) {
			return mid1;
		}
		if (array_nums[mid2] == key) {
			return mid2;
		}

		// Since key is not present at mid,
		// check in which region it is present
		// then repeat the Search operation
		// in that region

		if (key < array_nums[mid1]) {

			// The key lies in between l and mid1
			array_size = mid1 - 1;
		}
		else if (key > array_nums[mid2]) {

			// The key lies in between mid2 and array_size
			l = mid2 + 1;
		}
		else {

			// The key lies in between mid1 and mid2
			l = mid1 + 1;
			array_size = mid2 - 1;
		}
	}

	// Key not found
	return -1;
}
int main()
{
    int n;
    int l = 0;
	int array_nums[] = {1,2,3,4,5,6,7,8,9,10};
	size_t array_size = sizeof(array_nums) / sizeof(int);
    printf("Original Array %d: ",array_size);
    for (int i = 0; i < array_size; i++) printf("%d ", array_nums[i]);
    printf("\nInput a number to search: ");
    scanf("%d", &n);
    int result_position = ternarySearch(l, array_size, n, array_nums);
    printf("\nElement found at position: %d", result_position);
    return 0;
}
