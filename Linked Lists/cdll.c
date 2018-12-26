//Operations on Circular double linked list 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
  struct student *prv;
  int data;
  struct student *next;
}ST;

void add_begin(ST **ptr)//To add node at the beginning
{
  ST *temp;
  static ST *last;
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
 
  if(*ptr == 0)
  {
    temp->prv=temp;
    temp->next=temp;;
    last=temp;
  }
  else
  {
    temp->prv=last;
    temp->next=*ptr;
    (*ptr)->prv=temp;
    last->next=temp;
  }
  *ptr=temp;
}

void add_end(ST **ptr)//To add node at the end
{
  ST *temp=*ptr;
  static ST *last;
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
  if(*ptr==0)
  {
    temp->prv=temp;
    temp->next=*ptr=temp;
  }
  else
  {
    temp->prv=last;
    temp->next=*ptr;

    (*ptr)->prv=temp;
    last->next=temp;
  }
  last=temp;
}

void sort_insert(ST **ptr)//To sort linked list while inserting nodes
{
  ST *temp;
  ST *last=*ptr;
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
  if(*ptr == 0 || temp->data < (*ptr)->data)
  {
    if(*ptr == 0)
    {
      temp->prv=temp;
      temp->next=temp;
    }
    else
    {
      while(last->next != *ptr)
        last=last->next;
     
      temp->prv=last;
      temp->next=*ptr;

      (*ptr)->prv=temp;
      last->next=temp;
    }
    *ptr=temp;
  }
  else
  {
    while((last->next != (*ptr)) && (temp->data > last->next->data))
      last=last->next;
    
    temp->prv=last;
    temp->next=last->next;
    
    if(last->next == *ptr)
      (*ptr)->prv=temp;

    else
      last->next->prv=temp;    
    
    last->next=temp;
  }
}

int count(ST *ptr)//To count no of nodes
{
  int cnt=0;
  ST *temp=ptr;
  do
  {
    cnt++;
    ptr=ptr->next;
  }while(ptr != temp);
  return cnt;
}

void print(ST *ptr)//To print the nodes
{
  ST *temp=ptr;
  do
  {
    printf("%d\n",ptr->data);
    ptr=ptr->next;
  }while(ptr != temp);
}

void add_middle(ST **ptr)
{
  int i,c=count(*ptr);
  ST *temp,*p;
  p=*ptr;
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
  for(i=1;i<c/2;i++)
    p=p->next;
  
  temp->prv=p;
  temp->next=p->next;

  p->next=temp;
  temp->next->prv=temp;
}

int main()
{
  ST *hptr=0;
  char ch;

  while(1)
  {
    printf("\n b.Add_begin\n e.Add_end\n m.Add_middle\n s.Sort while inserting\n p.Print\n c.Count nodes\n x:exit\n");

    printf("Enter your choice: ");
    scanf(" %c",&ch);
    switch(ch)
    {
      case 'b': add_begin(&hptr);
                break;
      case 'e': add_end(&hptr);
                break;
      case 'm': add_middle(&hptr);
                break;
      case 's': sort_insert(&hptr);
                break;
      case 'p': print(hptr);
                break;
      case 'c': printf("Node count: %d\n",count(hptr));
                break;
      case 'x': return 0;
      default:  printf("Invalid choice\n");
                break;
    }
  }
}
