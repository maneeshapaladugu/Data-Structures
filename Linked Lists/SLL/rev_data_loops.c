//Program to reverse the nodes data in single linked list using loops
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

void rev_data(ST *ptr)
{
  int i,j,c = count(ptr);
  int size=sizeof(ST)-4;
  ST *p1,*p2,*temp;
  temp = (ST*)malloc(sizeof(ST));
  
  p1=ptr;
  for(i=0;i<c/2;i++)
  {
    p2=ptr;
    for(j=0;j<c-1-i;j++)
      p2=p2->next;
    
    memcpy(temp,p1,size);
    memcpy(p1,p2,size);
    memcpy(p2,temp,size);
    p1=p1->next;
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
  int c= count(hptr);
  printf("No of nodes count: %d\n",c);
  rev_data(hptr);
  print(hptr);
}
