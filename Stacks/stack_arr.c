//Program for implementation of stack using arrays
#include<stdio.h>
#define MAX 5
int stk[MAX],top=0;

void push()
{
  if(top == MAX)
  {
    printf("Stack is overflow\n");
    return;
  }
  int ele;
  printf("Enter the element\n");
  scanf("%d",&ele);
  stk[top++]=ele;
  printf("%d is inserted into stack\n",ele);
}

void pop()
{
  if(top == 0)
  {
    printf("Stack is underflow\n");
    return;
  }
  printf("%d is deleted from the stack\n",stk[top-1]);
  stk[--top]=0;
}

void display()
{
  if(top == 0)
  {
    printf("Stack is empty\n");
    return;
  }
  for(int i=0;i<top;i++)
    printf("%d\n",stk[i]);
}

void main()
{
  int op;
  while(1)
  {
    printf(" 1.Push\n 2.pop\n 3.Display\n 4.Exit\n");
    printf("Enter your option:");
    scanf("%d",&op);
    switch(op)
    {
      case 1: push();
	      break;
      case 2: pop();
              break;
      case 3: display();
              break;
      case 4: printf("Stack operation is over\n");
	      return;
      default: printf("Invalid option\n");
    }

  }
}  
