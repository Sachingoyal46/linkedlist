//no of counting nodes
#include <stdio.h>
#include <stdlib.h>
struct node {
  int info;
  struct node *next;
};

//********************************************************

getnode() {
  struct node *p;
  p = (struct node *)malloc(sizeof(struct node));
  return p;
}
//********************************************************
void InsEnd(struct node **list,int x) {
  struct node *q, *p;
  q =*list;
  while (q->next != NULL) {
    q = q->next;
  }
  p = getnode();
  p->info = x;
  p->next = NULL;
  q->next = p; // this is for link the insert node to the previous node
}
//***************************************************************

insaft(struct node **list, int y, int x) {
  struct node *temp, *p;
  temp = *list;
  while (temp != NULL) {
    if (temp->info == y)
      break;
    else
      temp = temp->next;
  }
  p = getnode();
  p->info = x;
  p->next = temp->next;
  temp->next = p;
}
*******************************************************
insbeg(struct node **list,int x) {
  struct node *temp;
  temp = getnode();
  temp->info = x;
  temp->next = *list;
  *list = temp;
}
****************************************************************
 delbeg(struct node **list) {
  struct node *temp;
  int x;
  temp = *list;
  (*list) = (*list)->next;
  x = temp->info;
  free(temp);
  return x;
}
**********************************************************************
  delend(struct node **list) {
  struct node *p, *q;
  int x;
  p = *list;
  q = NULL;
  while (p->next != NULL) {
    q = p;
    p = p->next;
  }
  q->next = NULL;
  x = p->info;
  free(p);
  return x;
}
//****************************************************************
  int count(struct node *list)
{
  int c=0;
  struct node *t;
  t=list;
  while(t!=NULL)
    {
      c++;
      t=t->next;
    }
  return c;
}


//*******************************************************************
concatination(struct node *list1,struct node *list2)
{
  struct node *p;
  p=list1;
  if(list1!=NULL)
  {
    while(p->next!=NULL)
      {
        p=p->next;
        
      }
    p->next=list2;
    return list1;
  }
  else
    return list2;
}

//*****************************************************************8

void traverse(start) {
  struct node *t;
  t = start;
  while (t != NULL) {
    printf("%d\n", t->info);
    t = t->next;
  }
}
//*********************************************************************

void main() {
  struct node *start,*start1,*start2;
  start = NULL;
  start1=NULL;
  start2=NULL;
  int x;
  insbeg(&start,100);
  insbeg(&start,200);
  insbeg(&start,300);
  insbeg(&start,400);
  insbeg(&start,500);
  traverse(start);
 printf("\n");
  insbeg(&start1,600);
  insbeg(&start1,700);
  insbeg(&start1,800);
  insbeg(&start1,900);
  insbeg(&start1,1000);
  traverse(start1);

  printf("\n\n concatination of the link list ");
  start2=concatination(start,start1);
  traverse(start2);
 
  
}
