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
//***************************************************
insaft(struct node **temp, int x) {
  struct node *p;

  p = getnode();
  p->info = x;
  p->next = (*temp)->next;
  (*temp)->next = p;
}
//*******************************************************
insbeg(struct node **list, int x) {
  struct node *temp;
  temp = getnode();
  temp->info = x;
  temp->next = *list;
  *list = temp;
}

//****************************************************************
delbeg(struct node **list) {
  struct node *temp;
  int x;
  temp = *list;
  (*list) = (*list)->next;
  x = temp->info;
  free(temp);
  return x;
}
//****************************************************************
// enqueue(struct node **front, struct node **rear, int x) {
//   if (*rear == NULL) {
//     insbeg(&(*rear), x);
//     *front = *rear;

//   } else {
//     insaft(&(*rear), x);
//     (*rear) = (*rear)->next;
//   }
// }
//**************************************************************

// int dequeue(struct node **front, struct node **rear) {
//   int x;
//   if (*front == NULL) {
//     printf("deletion is not possible\n");
//     exit(1);
//   } else {
//     x = delbeg(&(*front));
//     if (*front == NULL) {
//       *rear = NULL;
//     }
//   }
//   return x;
// }
//************************************************************
push(struct node **top,int x)
{
    insbeg(&(*top),x);
}
//*************************************************************
int pop(struct node **top)
{
    int x;
    x=delbeg(&(*top));
    return x;
}
//*********************************************************

traverse(struct node *list) {
  struct node *t;
  t = list;
  while (t != NULL) {
    printf("%d\n", t->info);
    t = t->next;
  }
}
//************************************************************

void main() {
    struct node *top;
    top=NULL;
    int x,y,z;
    push(&top,100);
    push(&top,200);
    push(&top,300);
    push(&top,400);
    push(&top,500);

    traverse(top);
    printf("\n");

    x=pop(&top);
     y=pop(&top);
      z=pop(&top);
    printf("deleted elements is %d\n",x);
    printf("deleted elements is %d\n",y);
    printf("deleted elements is %d\n",z);

}
