//no of counting nodes
#include <stdio.h>
#include <stdlib.h>
struct node {
  int info;
  struct node *next;
};

//********************************************************

struct node*getnode() {
  struct node *p;
  p = (struct node *)malloc(sizeof(struct node));
  return p;
}
//********************************************************
// void InsEnd(struct node **list,int x) {
//   struct node *q, *p;
//   q =*list;
//   while (q->next != NULL) {
//     q = q->next;
//   }
//   p = getnode();
//   p->info = x;
//   p->next = NULL;
//   q->next = p; // this is for link the insert node to the previous node
// }
//***************************************************************

// struct node*insaft(struct node **list, int y, int x) {
//   struct node *temp, *p;
//   temp = *list;
//   while (temp != NULL) {
//     if (temp->info == y)
//       break;
//     else
//       temp = temp->next;
//   }
//   p = getnode();
//   p->info = x;
//   p->next = temp->next;
//   temp->next = p;
// }
//*******************************************************

struct node*insbeg(struct node **list,int x) {
  struct node *temp;
  temp = getnode();
  temp->info = x;
  temp->next = *list;
  *list = temp;
}


//****************************************************************
// int delbeg(struct node **list) {
//   struct node *temp;
//   int x;
//   temp = *list;
//   (*list) = (*list)->next;
//   x = temp->info;
//   free(temp);
//   return x;
// }
//**********************************************************************
// int delend(struct node **list) {
//   struct node *p, *q;
//   int x;
//   p = *list;
//   q = NULL;
//   while (p->next != NULL) {
//     q = p;
//     p = p->next;
//   }
//   q->next = NULL;
//   x = p->info;
//   free(p);
//   return x;
// }
//****************************************************************
//   int count(struct node *list)
// {
//   int c=0;
//   struct node *t;
//   t=list;
//   while(t!=NULL)
//     {
//       c++;
//       t=t->next;
//     }
//   return c;
// }


//*******************************************************************

void traverse(start) {
  struct node *t;
  t = start;
  while (t != NULL) {
    printf("%d\n", t->info);
    t = t->next;
  }
}
//*********************************************************************
struct node * reverse(struct node *start)
{
  struct node *c,*p,*n;
  c=start;
  p=NULL;
  n=c->next;
  while(c!=NULL)
    {
      c->next=p;
      p=c;
      c=n;
      if(n!=NULL)
      {
        n=n->next;
      }
    }
  start=p;
  return start;
  
}

void main() {
  struct node *start;
  start = NULL;
  int x;
  insbeg(&start,100);
  insbeg(&start,200);
  insbeg(&start,300);
  insbeg(&start,400);
  insbeg(&start,500);
  traverse(start);
  printf("\n");
  // start=NULL;
  reverse(start);
  
  traverse(start);
  
}
