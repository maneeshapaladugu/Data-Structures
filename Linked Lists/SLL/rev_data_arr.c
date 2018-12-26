//Program to reverse the data of nodes of single linked list using array of pointers
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
  ST **p = (ST**)malloc(c*sizeof(ST*));
  ST *temp = (ST*)malloc(sizeof(ST));
  for(i=0;i<c;i++)
  {
    p[i]=ptr;
    ptr=ptr->next;
  }
  for(i=0,j=c-1;i<j;i++,j--)
  {
    memcpy(temp,p[i],size);
    memcpy(p[i],p[j],size);
    memcpy(p[j],temp,size);
  }
  for(i=0;i<c;i++)  
  printf("%d %s %f\n",p[i]->roll,p[i]->name,p[i]->marks);
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
}
