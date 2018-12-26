//Program for implementation of circular queue using arrays
#include<stdio.h>
#define MAX 5
int CQ[MAX],rear=0,front=0,flag=0;

void enqueue()
{
  if(flag && rear == front)
  {
    printf("Queue is overflow\n");
    return;
  }
  int ele;
  printf("Enter the element\n");
  scanf("%d",&ele);
  CQ[rear++]=ele;
  printf("%d is enqueued\n",ele);

  if(rear == MAX)
  {
    flag=!flag;
    rear=0;
  }
}

void dequeue()
{
  if((!flag) && (front == rear))
  {
    printf("Queue is underflow\n");
    return;
  }
  printf("%d is dequeued\n",CQ[front]);
  CQ[front++] = 0;

  if(front == MAX)
  {
    flag=!flag;
    front=0;
  }
}

void display()
{
  for(int i=0;i<MAX;i++)
    printf("%d\n",CQ[i]);
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

