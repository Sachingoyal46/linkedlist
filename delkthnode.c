#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};
//********************************************************

struct node *getnode()
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;
}
//************************************************************
struct node *insbeg(struct node **list,int x)
{
    struct node *temp;
    temp=getnode();
   temp->info=x;
   temp->next=(*list)->next;
   (*list)->next=temp;
}

//*****************************************************************
 struct node*deletekth(struct node *start,int k)
{   struct node *p,*q;
    p=start;
    int i=1;
    while(i<=k)
    {
        i=i+1;
        if(p!=NULL)
        {
            p=p->next;
        }
        else
        {
            printf("void deletion\n");
            exit(1);
        }
    }
        q=start;
        if(p!=NULL)
        {
            while(p->next!=NULL)
            {
                q=q->next;
                p=p->next;
            }
            delaft(q);
        }
        else
          {
            delbeg(start);
          }  
    


}

//******************************************************************
struct node * delaft(struct node *start)
{
struct node *p,*q;
int x;
    if(p!=NULL && p->next!=NULL)
    {
        q=p->next;
        p->next=q->next;
        x=q->info;
        free(q);
        return x;
    }
}

//*******************************************************************
// s

//*****************************************************************

struct node *insend(struct node **list,int x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=(*list)->next;
    (*list)->next=p;
    *list=p;
}

//**************************************************************

// struct node *delend(struct node **list)
// {
//     struct node *p,*q;
//     int x;
//     p=*list;
//     while(p->next!=*list)
//     {
//         p=p->next;
//     }
//     p->next=(*list)->next;
//    q=*list;
//    *list=p;
//    x=q->info;
//    free(q);
// //    return x;
// }

//(*************************************************************************)
 struct node * delbeg(struct node **list)
 {
    struct node *p;
    int x;
    p=(*list)->next;
    (*list)->next=p->next;
    x=p->info;
    free(p);
    // return x;
 }
//*********************************************************     

 struct node *traverse(struct node **start) {
  struct node *t;
  t =(*start)->next;
  while (t!=  *start) {
    printf("%d\n", t->info);
    t = t->next;
  }
   printf("%d\n", t->info);
  
 }

 //**********************************************************************8
 

 int main()
{
    struct node *start;
    start=NULL;
    insbeg(&start,100);
     insbeg(&start,200);
      insbeg(&start,300);
       insbeg(&start,400);
        insbeg(&start,500);
        traverse(&start);

        deletekth(&start,3);

        traverse(&start);
}



