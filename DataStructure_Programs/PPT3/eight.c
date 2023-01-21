/*
Program for Checking if a Linked List is Sorted or not:
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}   *first = NULL;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf ("%d ", p->data);
        p = p->next;
    }
}

int IsSorted(struct Node *p)
{
    int x = -65536;

    while (p != NULL)
    {
        if (p->data < x)
         return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main()
{
    int A[] = { 4, 5, 7, 11, 12 };
    Create(A, 5);
    Display (first);
    if(IsSorted(first))
        printf ("\nLinked List is Sorted");
    else
        printf ("\nLinked List is not Sorted");
    return 0;
}
