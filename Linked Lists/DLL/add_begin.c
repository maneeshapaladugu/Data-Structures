//Program to create double linked list using add-begin method
#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
  struct student *prv;
  int roll;
  char name[50];
  float marks;
  struct student *next;
}ST;

void add_begin(ST **ptr)
{
  ST *temp;
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the roll,name and marks\n");
  scanf("%d %s %f",&temp->roll,temp->name,&temp->marks);

  temp->prv=0;
  temp->next=*ptr;
  if(*ptr != 0)
    (*ptr)->prv=temp;
  *ptr=temp;
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

int main()
{
  ST *hptr=0;
  char ch;
  do
  {
    add_begin(&hptr);
    printf("Do you want to continue(y/n)\n");
    scanf(" %c",&ch);
  }while(ch=='y'||ch=='Y');
  int c = print_save(hptr);
  printf("No of nodes count: %d\n",c);
}
