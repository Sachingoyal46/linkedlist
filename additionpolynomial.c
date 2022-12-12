#include <stdio.h>
#include <stdlib.h>
struct node {
  int coef;
  int expo;
  struct node *next;
};

//********************************************************

struct node *getnode(struct node **list) {
  struct node *p;
  p = (struct node *)malloc(sizeof(struct node));
  return p;
}


//********************************************************
struct node insbeg(struct node **list, int c, int e) {
  struct node *Q;
  Q = getnode(list);
  Q->coef = c;
  Q->expo = e;
  Q->next = *list;
  *list = Q;
  
}
//*******************************************************

struct node insend(struct node **list, int c, int e) {
  struct node *q, *p;
  q = *list;
  if (q == NULL) {
    insbeg(&(*list), c, e);
  } else {
    while (q->next != NULL)
      q = q->next;

    p = getnode(list);
    p->coef = c;
    p->expo = e;
    p->next = NULL;
    q->next = p;
  }
  // return 0;
}
//*******************************************************************

void traverse(struct node *list) {
  struct node *t;
  t = list;
  while (t != NULL) {
    printf("%d x^ %d + \n", t->coef, t->expo);
    t = t->next;
  }
}
//*********************************************************************

struct node *PolynomialAddition(struct node *p1, struct node *p2) {
  struct node *p3;
  struct node *p, *q;
  p3 = NULL;
  p = p1;
  q = p2;

  while (p != NULL && q != NULL) {
    if (p->expo == q->expo) {
      insend(&p3, (p->coef + q->coef), p->expo);
      
        p = p->next;
        q = q->next;
      
    } else {
      if (p->expo > q->expo) {
        insend(&p3, p->coef, p->expo);
        p = p->next;
      } else {
        insend(&p3, q->coef, q->expo);
        q = q->next;
      }
    }
    }
    while (p != NULL) {
      insend(&p3, p->coef, p->expo);
      p = p->next;
    }
    while (q != NULL) {
      insend(&p3, q->coef, q->expo);
      q = q->next;
    }
  
  return p3;
}
//**********************************************************************

void main() {
  struct node *l1,*l2,*l3;
  l1 = NULL;
  l2=NULL;
  l3=NULL;

 

  insend(&l1, 3, 8);
  insend(&l1, 5, 7);
  insend(&l1, -2, 6);
  insend(&l1, 8, 4);

  printf("first polynomial is\n");
  traverse(l1);

  insend(&l2, 4, 7);
  insend(&l2, 5, 6);
  insend(&l2, -1, 3);
  insend(&l2, 7, 2);
  insend(&l2, -3, 0);
  printf("\n");

  printf("second polynomial is\n");
  traverse(l2);

  l3 = PolynomialAddition(l1, l2);
  printf("\n");
  printf("the result of the polynomial is\n");
  traverse(l3);
}