/*C program to merge two sorted linked list
*/

#include <stdio.h>
#include <stdlib.h>

/* A structure of linked list node */
struct node {
  int data;
  struct node *next;
} *LLOne, *LLTwo, *mergedLL;

void initialize(){
    LLOne = LLTwo = mergedLL = NULL;
}
/*
Given a Inserts a node in front of a singly linked list.
*/
void insert(struct node **head, int num) {
    /* Create a new Linked List node */
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    /* Next pointer of new node will point to head node of linked list  */
    newNode->next = *head;
    /* make new node as new head of linked list */
    *head = newNode;
    printf("Inserted Element : %d\n", num);
}

struct node* mergeLinkedList(struct node* LLOne, struct node* LLTwo){
    struct node *resultHead, *resultTail, *temp;
    resultHead = resultTail = NULL;
    while(1){
        /* */
        if(LLOne == NULL){
            resultTail->next = LLTwo;
            break;
        }

        if(LLTwo == NULL) {
            resultTail->next = LLOne;
            break;
        }

        /* Check whether current node of
        which Linked list is smaller*/
        if(LLOne->data <= LLTwo->data){
            temp = LLOne;
            LLOne = LLOne->next;
        } else {
            temp = LLTwo;
            LLTwo = LLTwo->next;
        }
        /*Add smaller node to result linked list  */
        if(resultHead == NULL){
            resultHead = resultTail = temp;
        } else {
            resultTail->next = temp;
            resultTail = temp;
        }
        resultTail->next = NULL;
    }

    return resultHead;
}

/*
Prints a linked list from head node till tail node
*/
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}

int main() {
    initialize();
    /* Creating First linked List*/
    insert(&LLOne, 9);
    insert(&LLOne, 6);
    insert(&LLOne, 3);
    insert(&LLOne, 1);
    printLinkedList(LLOne);
    printf("\n");
    /* Creating Second linked List*/
    insert(&LLTwo, 10);
    insert(&LLTwo, 6);
    insert(&LLTwo, 5);
    insert(&LLTwo, 2);
    printLinkedList(LLTwo);
    /* Merge Linked List */
    mergedLL = mergeLinkedList(LLOne, LLTwo);
    printf("\nMerged Linked List\n");
    printLinkedList(mergedLL);

    return 0;
}
