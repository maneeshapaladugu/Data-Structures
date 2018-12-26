//Program to delete a node from double linked list 
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

void delete(ST **ptr,int n)
{
  ST *temp=*ptr;
  while(temp != 0)
  {
    if(temp->roll == n)
    {
      if(*ptr==temp)
      {
        *ptr=temp->next;
	if(*ptr != 0)
          (*ptr)->prv=0;
      }
      else
      {
	temp->prv->next=temp->next;
	if(temp->next != 0)
          temp->next->prv=temp->prv;
      }
      free(temp);
      temp=NULL;
      return ;
    }
    else
      temp=temp->next;
  }
  printf("The roll number doesn't exist to delete\n");
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

  int roll;
  printf("Enter the roll to delete\n");
  scanf("%d",&roll);
  delete(&hptr,roll);
  print(hptr);
}
