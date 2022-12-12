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
//*****************************************************
traverse(start) {
  struct node *t;
  t = start;
  while (t != NULL) {
    printf("%d\n", t->info);
    t = t->next;
  }
}
//***************************************************
struct node *split(struct node **start)
{
    struct node*t,*r,*start2;
    t=*start;
    r=(*start)->next;
    while(r!=NULL && r->next!=NULL)
    {
        t=t->next;
        r=r->next;
        r=r->next;
    }
    start2=t->next;
    t->next=NULL;
    return start2;
}
insbeg(struct node **list,int x) {
  struct node *temp;
  temp = getnode();
  temp->info = x;
  temp->next = *list;
  *list = temp;
}
//**************************************************
 insend(struct node **list,int x) {
  struct node *q, *p;
  q =*list;
  if(*list==NULL)
  {
        insbeg(&(*list),x);
  }
  else
  {
  while (q->next != NULL) {
    q = q->next;
  }
  p = getnode();
  p->info = x;
  p->next = NULL;
  q->next = p; // this is for link the insert node to the previous node
}
 }

 pairswap(struct node **start)
 {
    struct node*p,*q ,*x;
    p=*start;
    q=p->next;
    while(q!=NULL)
    {
        x=p->info;
        p->info=q->info;
        q->info=x;
        p=p->next;
        p=p->next;
        q=q->next;
        if(q!=NULL)
        {
            q=q->next;
        }
    }
 }

int main()
{
    struct node *start,*q;
    start=NULL;
    insend(&start,100);
     insend(&start,200);
      insend(&start,300);
       insend(&start,400);
        insend(&start,600);
         insend(&start,500);
         traverse(start);
         printf("\n");
        //  q=split(&start);
        //  traverse(q);
        //  traverse(start);
         pairswap(&start);
         traverse(start);





    
}