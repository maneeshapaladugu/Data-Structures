//Program to print single linked list in reverse using recursion
#include<stdio.h>
#include<stdlib.h>
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

int print_save(ST *ptr)
{
  int cnt=0;
  FILE *fp=fopen("file.txt","w");
  while(ptr!=0)
  {
    //To print on screen
    printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
    //To save in a text file
    fprintf(fp,"%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
    ptr=ptr->next;
    //To count no of nodes 
    cnt++;
  }
  return cnt;
}

void rev_print(ST *ptr)
{
  if(ptr!=0)
  {
    rev_print(ptr->next);
    printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
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
  int c = print_save(hptr);
  printf("No of nodes count: %d\n",c);

  rev_print(hptr);
}
