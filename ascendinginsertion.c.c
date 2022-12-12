//ascending insertion in a linked list
#include <stdio.h>
#include <stdlib.h>
struct node {
  int info;
  struct node *next;
};

//********************************************************

 struct node *getnode() {
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

insaft(struct node **temp,int x) {
  struct node  *p;
  
 
  p = getnode();
  p->info = x;
  p->next = (*temp)->next;
  (*temp)->next = p;
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
//  delbeg(struct node **list) {
//   struct node *temp;
//   int x;
//   temp = *list;
//   (*list) = (*list)->next;
//   x = temp->info;
//   free(temp);
//   return x;
// }
**********************************************************************
//   delend(struct node **list) {
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

 traverse(start) {
  struct node *t;
  t = start;
  while (t != NULL) {
    printf("%d\n", t->info);
    t = t->next;
  }
}
//*********************************************************************
ascendinginsertion(struct node **start ,int x)
{
  struct node *p,*q;
  p=*start;
  q=NULL;
  while(p!=NULL && x>=p->info)
    {
      q=p;
      p=p->next;
    }
  if(q==NULL)
  {
    insbeg(&(*start),x);
  }
  else
    insaft(&q, x);
}
//***********************************************************************
void main() {
  struct node *start,*t;
  start = NULL;
  ascendinginsertion(&start,100);
  ascendinginsertion(&start,20);
  ascendinginsertion(&start,2000);
  ascendinginsertion(&start,150);
  ascendinginsertion(&start,40);
  ascendinginsertion(&start,400);
  traverse(start);
  
 
  // insbeg(&start,100);
  // insbeg(&start,200);
  // insbeg(&start,300);
  // insbeg(&start,400);
  // insbeg(&start,500);
  // traverse(start);
  // printf("\n");
  // InsEnd(&start,2000);
  //  t=start;
  // while(t->info!=200)
  //   t=t->next;
  // insaft(&t, 20);
  // insaft(&start,2000, 2);
  // traverse(start);
  // delbeg(&start);

  // printf("\n");
  // traverse(start);
  // printf("\n");
  // delend(&start);
  // traverse(start);
  return 0;
}
