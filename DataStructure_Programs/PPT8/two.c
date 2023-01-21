/*
We have to create a C Program which inputs a sorted array and tells whether the key
searched is present in array or not using Binary Search Algorithm recursively. We have to take array and the key as an input from the user.
*/


#include <stdio.h>

void binary_search(int [], int, int, int);
void bubble_sort(int [], int);

int main()
{
    int key, size, i;
    int list[25];

    printf("Enter size of a list: ");
    scanf("%d", &size);
    printf("Enter elements\n");
    for(i = 0; i < size; i++)
    {
        scanf("%d",&list[i]);
    }
    bubble_sort(list, size);
    printf("\n");
    printf("Enter key to search\n");
    scanf("%d", &key);
    binary_search(list, 0, size, key);

}

void bubble_sort(int list[], int size)
{
    int temp, i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (list[i] > list[j])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void binary_search(int list[], int lo, int hi, int key)
{
    int mid;

    if (lo > hi)
    {
        printf("Key not found\n");
        return;
    }
    mid = (lo + hi) / 2;
    if (list[mid] == key)
    {
        printf("Key found\n");
    }
    else if (list[mid] > key)
    {
        binary_search(list, lo, mid - 1, key); //if key is less than mid search in lower half
    }
    else if (list[mid] < key)
    {
        binary_search(list, mid + 1, hi, key);//if key is greater than mid search in upper half
    }
}
