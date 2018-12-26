//Program to print double linked list in reverse order
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student 
{
  struct student *prv;
  int roll;
  char name[50];
  float marks;
  struct student *next;
}ST;

void add_end(ST **ptr)
{
  ST *temp;
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the roll,name and marks\n");
  scanf("%d %s %f",&temp->roll,temp->name,&temp->marks);
  if(*ptr == 0)
  {
    temp->prv=0;
    temp->next=*ptr;
    *ptr=temp;
  }
  else
  {
    ST *last;
    last=*ptr;
    while(last->next != 0)
      last=last->next;

    temp->prv=last;
    temp->next=last->next;
    last->next=temp;
  }
}

int print(ST *ptr)
{
  while(ptr!=0)
  {
    printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
    ptr=ptr->next;
  }
}

int count(ST *ptr)
{
  int cnt=0;
  while(ptr != 0)
  {
    cnt++;
    ptr=ptr->next;
  }
  return cnt;
}

void rev_print(ST *ptr)
{
  while(ptr->next != 0)
   ptr=ptr->next;

  while(ptr != 0)
  {
    printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
    ptr=ptr->prv;
  }
}

int main()
{
  ST *hptr=0;
  char ch;
  do
  {
    add_end(&hptr);
    printf("Do you want to continue(y/n)\n");
    scanf(" %c",&ch);
  }while(ch=='y'||ch=='Y');
  print(hptr);
  int c = count(hptr);
  printf("No of nodes count: %d\n",c);
  rev_print(hptr);
}
