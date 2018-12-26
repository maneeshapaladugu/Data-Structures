//Operations on double linked list 
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
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the data: ");
  scanf("%d",&temp->data);

  temp->prv=0;
  temp->next=*ptr;
  if(*ptr != 0)
    (*ptr)->prv=temp;
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

void sort_insert(ST **ptr)//To sort the linked list while inserting the node
{
  ST *temp;
  temp=(ST*)malloc(sizeof(ST));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
  if(*ptr == 0 || temp->data < (*ptr)->data)
  {
    temp->prv=0;
    temp->next=*ptr;

    if(*ptr != 0)
      (*ptr)->prv=temp;
    
    *ptr=temp;
  }
  else
  {
    ST *last;
    last=*ptr;
    while(last->next != 0 && temp->data > last->next->data)
      last=last->next;
    
    temp->prv=last;
    temp->next=last->next;
    
    if(last->next != 0)
      last->next->prv=temp;

    last->next=temp;
  }
}

void print(ST *ptr)//To print the nodes
{
  while(ptr!=0)
  {
    printf("%d\n",ptr->data);
    ptr=ptr->next;
  }
}

int count(ST *ptr)//To count the no of nodes
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

  temp->prv=p;
  temp->next=p->next;

  p->next=temp;
  temp->next->prv=temp;
}

void rev_print(ST *ptr)//To print the nodes in reverse order
{
  while(ptr->next != 0)
   ptr=ptr->next;

  while(ptr != 0)
  {
    printf("%d\n",ptr->data);
    ptr=ptr->prv;
  }
}

void rev_data(ST *ptr)//To reverse the data of linked list
{
  int i,c = count(ptr);
  int size=sizeof(ST)-8;
  ST *p1,*p2,*temp;
  temp = (ST*)malloc(sizeof(ST));

  p1=p2=ptr;
  while(p2->next != 0)
    p2 = p2->next;

  for(i=0;i<c/2;i++)
  {
    memcpy(temp,p1,size);
    memcpy(p1,p2,size);
    memcpy(p2,temp,size);

    p1=p1->next;
    p2=p2->prv;
  }
}

void rev_links(ST **ptr)//To reverse links of a linked list
{
  ST *temp;
  while(*ptr != 0)
  {
    temp=(*ptr)->prv;
    (*ptr)->prv=(*ptr)->next;
    (*ptr)->next=temp;

    *ptr=(*ptr)->prv;
  }
  *ptr=temp->prv;
}

void delete(ST **ptr,int n)//To delete a node
{
  ST *temp=*ptr;
  while(temp != 0)
  {
    if(temp->data == n)
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
  char ch,c;
  while(1)
  {
    printf("\n b.Add_begin\n e.Add_end\n m.Add_middle\n s.Sort while inserting\n p.Print\n c.Count nodes\n");
    printf(" r.Reverse print\n d.Reverse data\n l.Reverse links\n n.Delete a node\n a.Delete all nodes\n x.Exit\n");

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
      default: printf("Invalid choice\n");
    }
  }
}
