/*
C Program to implement Linear Search Algorithm to find the minimum element in an array.
*/

#include <stdio.h>
int min_linearsearch(int numbers[], int n)
{
    int min = numbers[0]; //set min as 1st element of array
    int i;
    for (i = 1; i <= n; i++)
    {
        if (min > numbers[i]) //if min is greater than any number in array set that number as min
            min = numbers[i];
    }
    return min;
}
int main() {
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    int numbers[n];
    int i;
    int min ;
    printf("Enter %d numbers : ", n);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }
    min = min_linearsearch(numbers,n);
    printf("\nMinimum number in the array is : %d\n", min);
    return 0;
    }
