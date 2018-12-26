//Program for implementation of queue using Linked lists
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int rear=0,front=0;

typedef struct student
{
  int data;
  struct student *next;
}ST;

void enqueue(ST **ptr)//Create linked list using add_end method
{
  if(rear == MAX)
  {
    printf("Queue is overflow\n");
    return;
  }

  ST *temp;
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
  if(*ptr == 0)
  {
    temp->next=*ptr;
    *ptr=temp;
  }
  else
  {
    ST *last;
    last=*ptr;
    while(last->next != 0)
      last=last->next;
    temp->next=last->next;
    last->next=temp;
  }
  printf("%d is enqueued\n",temp->data);
  rear++;
}

void dequeue(ST **ptr)//Delete first node always
{
  if(front == MAX)
  {
    printf("Queue is underflow\n");
    return;
  }

  ST *temp=*ptr;
  *ptr=temp->next;
  printf("%d is dequeued\n",temp->data);
  free(temp);
  temp=NULL;
  front++;
}

void display(ST *ptr)//Print the nodes data
{
  while(ptr!=0)
  {
    printf("%d\n",ptr->data);
    ptr=ptr->next;
  }
  if(ptr==0)
    printf("Queue is empty\n");
}

void main()
{
  int op;
  ST *hptr=0;
  while(1)
  {
    printf(" 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
    printf("Enter your option:");
    scanf("%d",&op);
    switch(op)
    {
      case 1: enqueue(&hptr);
              break;
      case 2: dequeue(&hptr);
              break;
      case 3: display(hptr);
              break;
      case 4: printf("Queue operation is over\n");
              return;
      default: printf("Invalid option\n");
    }

  }
}

