/*
C program to add and delete items from string queue.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define max 5
int insq(char queue[max][80], int *rear, char data[80])
{
      if(*rear == max -1)
            return(-1);
      else
      {
            *rear = *rear + 1;
            strcpy(queue[*rear], data); //add element in queue
            return(1);
      }
}
int delq(char queue[max][80], int *front, int *rear, char data[80])
{
      if(*front == *rear)
            return(-1);
      else
      {
            (*front)++; //delete element from queue
            strcpy(data, queue[*front]);
            return(1);
      }
}
int main()
{
      char queue[max][80], data[80];
      int front, rear, reply;
      int ch;
      front = rear = -1; //... Initialize a Queue
      printf("------------------------------\n");
      printf("\tMenu");
      printf("\n------------------------------");
      printf("\n 1. Insert String in a Queue");
      printf("\n 2. Delete String from a Queue");
      printf("\n 3. Exit");
      printf("\n------------------------------\n");
      while(1)
      {
            printf("Choose operation : ");
            scanf("%d", &ch);
            switch(ch)
            {
                  case 1 : // insert
                        printf("\nEnter string : ");
                        scanf("%s",data);
                        reply = insq(queue, &rear, data);
                        if(reply == -1 )
                              printf("\nQueue is Full \n");
                        else
                              printf("\n'%s' is inserted in queue.\n\n",data);
                        break;
                  case 2 : // delete
                        reply = delq(queue, &front, &rear, data);
                        if( reply == -1 )
                              printf("\nQueue is Empty \n");
                        else
                              printf("\nDeleted String from Queue is : %s\n", data);
                              printf("\n");
                        break;
                  case 3 : exit(0);
                  default: printf("Invalid operation \n");
            }
      }
      return 0;
}
