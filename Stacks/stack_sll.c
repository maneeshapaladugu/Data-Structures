//Program for implementation of stack using Linked lists
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
//int stk[MAX];
int top=0;

typedef struct student
{
  int data;
  struct student *next;
}ST;

void push(ST **ptr)//Create linked list using add_end method
{
  if(top == MAX)
  {
    printf("Stack is overflow\n");
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
  printf("%d is inserted in to stack\n",temp->data);
  top++;
}

void pop(ST **ptr)//Delete last node always
{
  if(top == 0)
  {
    printf("Stack is underflow\n");
    return;
  } 

  ST *prv,*last=*ptr;
  while(last->next != 0)
  {
    prv=last;
    last=last->next;
  }
  prv->next=0;
  printf("%d is deleted from stack\n",last->data);
  free(last);
  last=NULL;
  top--;
}

void display(ST *ptr)//Print the nodes data
{
  if(top == 0)
  {
    printf("Stack is empty\n");
    return;
  }
  while(ptr!=0)
  {
    printf("%d\n",ptr->data);
    ptr=ptr->next;
  }
}

void main()
{
  int op;
  ST *hptr=0;
  while(1)
  {
    printf(" 1.Push\n 2.pop\n 3.Display\n 4.Exit\n");
    printf("Enter your option:");
    scanf("%d",&op);
    switch(op)
    {
      case 1: push(&hptr);
	      break;
      case 2: pop(&hptr);
              break;
      case 3: display(hptr);
              break;
      case 4: printf("Stack operation is over\n");
	      return;
      default: printf("Invalid option\n");
    }

  }
}  
