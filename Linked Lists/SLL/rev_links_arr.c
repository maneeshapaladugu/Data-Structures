//Program to reverse the links of single linked list using array of pointers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
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
}

void print(ST *ptr)
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

void rev_links(ST **ptr)
{
  int c=count(*ptr);
  ST **p=(ST**)malloc(c*sizeof(ST*));
  ST *temp=*ptr;
  int i=0;
  while(temp != 0)
  {
    p[i++]=temp;
    temp=temp->next;
  }
  *ptr=p[c-1];
  p[0]->next=0;
  for(i=1;i<c;i++)
    p[i]->next=p[i-1];
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
  int c= count(hptr);
  printf("No of nodes count: %d\n",c);
  rev_links(&hptr);
  print(hptr);
}
