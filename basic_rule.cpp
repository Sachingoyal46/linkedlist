#include<iostream>
#include<bits./stdc++.h>
using namespace std;
//*****************************************************************

struct node {
    int info;
    struct node *next;
};
//********************************************************************

struct node *start;

//********************************************************************

struct node * getnode()
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;
}
//**********************************************************************

 void insert_beg(int x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=start;
    start=p;
}
//***********************************************************************

 void ins_end(int x)
{
    struct node *p,*q;
    p=start;
    if(start==NULL)
    insert_beg(x);
    else
    {

    while(p->next!=NULL)
    {
        p=p->next;
    }
        q=getnode();
        q->info=x;
        q->next=NULL;
        p->next=q;
    }
}
//******************************************************************************

void ins_after(int y,int x)
{
    struct node *q,*p;
    q=start;
    while(q!=NULL)
    {
        if(q->info==y)
        break;
      else
          q=q->next;
    }
    p=getnode();
    p->info=x;
    p->next=q->next;
    q->next=p;
}
//*************************************************************************
int  del_beg()
 {
    struct node *p;
    int x;
    if(start!=NULL)
    {
        p=start;
        start=p->next;
        x=p->info;
        free(p);
        return x;
    }
    else
    cout<<"void Deletion"<<endl;
 }

 //**************************************************************
 int del_aft(int x)
 {  
    struct node *p,*q;
    p=start;
    while(p!=NULL && p->next!=NULL)
    {   
        if(p->info==x)
        {
        q=p->next;
        p->next=q->next;
        int y=q->info;
        free(q);
        return x;
        }

        else
        {
        cout<<"void deletion"<<endl;
        }
    }
 }
 //*****************************************************************
 int del_end()
 {
    struct node *q,*p;
    p=start;
    q=NULL;
    int x;
    if(start==NULL)
    {
        cout<<"void deletion"<<endl;
    }
    else
    {
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        if(q!=NULL)
        {
            q->next=NULL;
            x=p->info;
            free(p);
            return x;
        }
        else
        start=NULL;
    }
 }
 //**************************************************************

 int del_specific(int x)
 {
    struct node *p,*q;
    p=start;
    q=NULL;
    while(p!=NULL)
    {
        if(p->info==x)
        {
            p=p->next;
            if(q==NULL)
            {
                del_beg();
            }
            else
            {
                del_aft(x);
            }
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
 }
//*************************************************************************************
int Traversal()
{
    struct node*p;
    p=start;
    while(p!=NULL)
    {
        cout<<p->info<<endl;
        p=p->next;
    }
}
//********************************************************************************

int main()
{
    start=NULL;
    ins_end(100);
     ins_end(200);
      ins_end(400);
       ins_end(500);
        ins_end(600);
        Traversal();

   
}




