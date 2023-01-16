#include<iostream>
#include<bits./stdc++.h>
#include<malloc.h>
using namespace std;
//************************************************

struct node{
    int info;
    struct node *next;
};

//******************************************************
struct node *start;
//*****************************************************
struct node *getnode()
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;
}
//******************************************************
void Insbeg(int x)
{
    struct node *temp;
    temp=getnode();
    temp->info=x;
    temp->next=start;
    start=temp;
}
//*******************************************************

 void Traversal()
 {
    struct node *t;
    t=start;
    while(t!=NULL)
    {
        cout<<t->info<<endl;
        t=t->next;
    }
 }
//***********************************************************
 int main()
 {
    start=NULL;
    Insbeg(100);
    Insbeg(200);
    Insbeg(300);
    Insbeg(400);
    Insbeg(500);
    Insbeg(600);
    Insbeg(700);
    Traversal();
 }
 

