//Operations on single linked list 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
  int data;
  struct student *next;
}ST;

void add_begin(ST **ptr)//To add node at the beginning
{
  ST *temp;
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
  temp->next=*ptr;
  *ptr=temp;
}

void add_end(ST **ptr)//To add node at the end
{
  ST *temp;
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
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

void sort_insert(ST **ptr)//To sort linked list while inserting the nodes
{
  ST *temp;
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
  if(*ptr == 0 || temp->data < (*ptr)->data)
  {
    temp->next=*ptr;
    *ptr=temp;
  }
  else
  {
    ST *last;
    last=*ptr;
    while(last->next != 0 && temp->data > last->next->data)
      last=last->next;
    temp->next=last->next;
    last->next=temp;
  }
}

int count(ST *ptr)//To count no of nodes
{
  int cnt=0;
  while(ptr != 0)
  {
    cnt++;
    ptr=ptr->next;
  }
  return cnt;
}

void add_middle(ST **ptr)//To add node in the middle
{
  int i,c=count(*ptr);
  ST *temp,*p;
  p=*ptr;
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
  for(i=1;i<c/2;i++)
    p=p->next;

  temp->next=p->next;
  p->next=temp;
}

void print(ST *ptr)//To print the nodes 
{
  while(ptr!=0)
  {
    printf("%d\n",ptr->data);
    ptr=ptr->next;
  }
}

void rev_print(ST *ptr)//To print nodes in reverse order
{
  int c=count(ptr);
  ST *temp=ptr;
  int i,j;
  for(i=1;i<=c;i++)
  {
    ptr=temp;
    for(j=0;j<c-i;j++)
      ptr=ptr->next;
    printf("%d\n",ptr->data);
  }
}

void rev_data(ST *ptr)//To reverse data of linked list
{
  int i,j,c = count(ptr),temp;
  ST *p1,*p2;

  p1=ptr;
  for(i=0;i<c/2;i++)
  {
    p2=ptr;
    for(j=0;j<c-1-i;j++)
      p2=p2->next;
    
    temp=p1->data;
    p1->data=p2->data;
    p2->data=temp;
    
    p1=p1->next;
  }
}

void rev_links(ST **ptr)//To reverse linkes of a linked list
{
  ST *q=0,*r;
  while(*ptr!=0)
  {
    r=q;
    q=*ptr;
    *ptr= (*ptr)->next;
    q->next=r;
  }
  *ptr=q;
}

void delete(ST **ptr,int n)//To delete a node
{
  ST *temp=*ptr;
  ST *prv;

  while(temp != 0)
  {
    if(temp->data == n)
    {
      if(*ptr==temp)
        *ptr=temp->next;
      else
        prv->next=temp->next;

      free(temp);
      temp=NULL;
      return;
    }
    else
    {
      prv=temp;
      temp=temp->next;
    }
  }
  printf("The data doesn't exist to delete\n");
}

void delete_all(ST **ptr)//To delete all nodes
{
  ST *temp;
  while(*ptr != 0)
  {
    temp=*ptr;
    *ptr=temp->next;
    free(temp);
  }
}

int main()
{
  ST *hptr=0;
  char ch;

  while(1)
  {
    printf("\n b.Add_begin\n e.Add_end\n m.Add_middle\n s.Sort while inserting\n p.Print\n c.Count nodes\n");
    printf(" r.Reverse print\n d.Reverse data\n l.Reverse links\n n.Delete a node\n a.Delete all nodes\n x:exit\n");
  
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
      case 'r': rev_print(hptr);
	        break;
      case 'd': rev_data(hptr);
	        break;
      case 'l': rev_links(&hptr);
                break;
      case 'n': ;
	        int data;
	       	printf("Enter the data delete:\n");
                scanf("%d",&data);
	        delete(&hptr,data);
                break;
      case 'a': delete_all(&hptr);
                printf("All Nodes deleted\n");
                break;
      case 'x': return 0;
      default:  printf("Invalid choice\n");
    }
  }
}
