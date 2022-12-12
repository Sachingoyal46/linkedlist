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
enqueue(struct node **front, struct node **rear, int x) {
  if (*rear == NULL) {
    insbeg(&(*rear), x);
    *front = *rear;

  } else {
    insaft(&(*rear), x);
    (*rear) = (*rear)->next;
  }
}
//**************************************************************

int dequeue(struct node **front, struct node **rear) {
  int x;
  if (*front == NULL) {
    printf("deletion is not possible\n");
    exit(1);
  } else {
    x = delbeg(&(*front));
    if (*front == NULL) {
      *rear = NULL;
    }
  }
  return x;
}
//************************************************************

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
  struct node *front, *rear;
  front = NULL;
  rear = NULL;
  int x,y,z;
  enqueue(&front, &rear, 100);
  enqueue(&front, &rear, 200);
  enqueue(&front, &rear, 300);
  enqueue(&front, &rear, 400);
  enqueue(&front, &rear, 500);
  enqueue(&front, &rear, 600);
  enqueue(&front, &rear, 700);
  enqueue(&front, &rear, 800);
  traverse(front);
  printf("\n");

  x = dequeue(&front, &rear);
  y = dequeue(&front, &rear);
  z= dequeue(&front, &rear);
  printf("\ndeleted elements is %d", x);
  printf("\ndeleted elements is %d", y);
  printf("\ndeleted elements is %d", z);
}
