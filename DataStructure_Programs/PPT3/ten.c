/*
 C program to Remove Nth Node From End of List
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// since we are
void insert_at_begenning ( struct Node **head_pointer, int data)
{
    // allocate memory for new node
    struct Node *temp_node = (struct Node*) malloc(sizeof(struct Node));

    // assign the data to new node
    temp_node->data = data;

    // initialize the new node to point to NULL
    temp_node->next = NULL;

    // if this is the first pointer, then this is the head pointer
    if (*head_pointer == NULL)
    {
        *head_pointer = temp_node;
    }
    else
    {
        // point the next of the present pointer to the head pointer
        temp_node->next = *head_pointer;

        //then move the reference of head pointer to the current pointer
        *head_pointer = temp_node;
    }
}

void display_list(struct Node **head_pointer)
{
    // take a reference to head pointer for navigation
    struct Node *temp = *head_pointer;

    while(temp != NULL)
    {
        if(temp->next != NULL)
            printf("%d -> ", temp->data);
        else
            printf("%d", temp->data);

        //navigate to next pointer
        temp = temp->next;
    }
    printf("\n");
}
struct Node * delete_node_from_end(struct Node *head, int num)
{

    // initialize both slow_pointer and fast_pointer pointing to head pointer
    struct Node *slow_pointer = head, *fast_pointer = head;

    // move fast pointer num steps ahead
    for (int i = 0; i < num; i++)
        fast_pointer = fast_pointer->next;

    // while fast_pointer is not null, increment both pointers one step at a time
    while (fast_pointer->next)
    {
        fast_pointer = fast_pointer->next;
        slow_pointer = slow_pointer->next;
    }

    // once we get the node to be deleted, get that node,
    //      store it in a local variable. This is because, it can be deleted later
    struct Node *node_to_be_deleted = slow_pointer->next;

    // link the slow pointer point to the next element
    slow_pointer->next = slow_pointer->next->next;

    // free the memory allocated for that pointer
    free(node_to_be_deleted);

    return head;
}


int main()
{
    struct Node *head = NULL;

    insert_at_begenning(&head,8);
    insert_at_begenning(&head,7);
    insert_at_begenning(&head,6);
    insert_at_begenning(&head,5);
    insert_at_begenning(&head,4);
    insert_at_begenning(&head,3);
    insert_at_begenning(&head,2);
    insert_at_begenning(&head,1);

    printf("The present linked list is\n");
    display_list(&head);

    head = delete_node_from_end(head, 2);
    printf("The linked list after deleting 2nd element from end is  is\n");
    display_list(&head);

    return 0;
}
