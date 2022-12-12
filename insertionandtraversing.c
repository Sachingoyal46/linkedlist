//insertion and traversing
#include <stdio.h>
#include <stdlib.h>
struct node {
  int info;
  struct node *next;
};

struct node *start;
//********************************************************

getnode() {
  struct node *p;
  p = (struct node *)malloc(sizeof(struct node));
  return p;
}
//********************************************************
void InsEnd(int x) {
  struct node *q, *p;
  q = start;
  while (q->next != NULL) {
    q = q->next;
  }
  p = getnode();
  p->info = x;
  p->next = NULL;
  q->next = p; // this is for link the insert node to the previous node
}
//***************************************************************

insaft(int y, int x) {
  struct node *temp, *p;
  temp = start;
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
//*******************************************************
insbeg(int x) {
  struct node *temp;
  temp = getnode();
  temp->info = x;
  temp->next = start;
  start = temp;
}
//****************************************************************

int delbeg() {
  struct node *temp;
  int x;
  temp = start;
  start = start->next;
  x = temp->info;
  free(temp);
  return x;
}
//**********************************************************************
int delend() {
  struct node *p, *q;
  int x;
  p = start;
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

void traverse() {
  struct node *t;
  t = start;
  while (t != NULL) {
    printf("%d\n", t->info);
    t = t->next;
  }
}
//*********************************************************************

void main() {
  start = NULL;
  insbeg(100);
  insbeg(200);
  insbeg(300);
  insbeg(400);
  insbeg(500);
  traverse();
  printf("\n");
  InsEnd(2000);
  insaft(200, 20);
  insaft(2000, 2);
  traverse();
  delbeg();

  printf("\n");
  traverse();
  printf("\n");
  delend();
  traverse();
}
