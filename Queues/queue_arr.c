//Program for implementation of queue using arrays
#include<stdio.h>
#define MAX 5
int Q[MAX],rear=0,front=0;

void enqueue()
{
  if(rear == MAX)
  {
    printf("Queue is overflow\n");
    return;
  }
  int ele;
  printf("Enter the element\n");
  scanf("%d",&ele);
  Q[rear++]=ele;
  printf("%d is enqueued\n",ele);
}

void dequeue()
{
  if(front == MAX)
  {
    printf("Queue is underflow\n");
    return;
  }
  printf("%d is dequeued\n",Q[front]);
  Q[front++]=0;
}

void display()
{
  for(int i=0;i<MAX;i++)
    printf("%d\n",Q[i]);
}

void main()
{
  int op;
  while(1)
  {
    printf(" 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
    printf("Enter your option:");
    scanf("%d",&op);
    switch(op)
    {
      case 1: enqueue();
              break;
      case 2: dequeue();
              break;
      case 3: display();
              break;
      case 4: printf("Queue operation is over\n");
              return;
      default: printf("Invalid option\n");
    }

  }
}

