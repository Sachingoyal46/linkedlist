#include<iostream>
#include<bits./stdc++.h>
using namespace std;
//*****************************************************************

struct node {
    int info;
    struct node *next;
};
//********************************************************************

struct node * getnode()
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;
}
//**********************************************************************

 void insert_beg(struct node **start,int x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
}
//***********************************************************************

 void ins_end(struct node **start,int x)
{
    struct node *p,*q;
    p=*start;
    if(*start==NULL)
    insert_beg(start,x);
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

// void ins_after(int y,int x)
// {
//     struct node *q,*p;
//     q=start;
//     while(q!=NULL)
//     {
//         if(q->info==y)
//         break;
//       else
//           q=q->next;
//     }
//     p=getnode();
//     p->info=x;
//     p->next=q->next;
//     q->next=p;
// }
//*************************************************************************
int  del_beg(struct node **start)
 {
    struct node *p;
    int x;
    if(*start!=NULL)
    {
        p=*start;
        *start=p->next;
        x=p->info;
        free(p);
        return x;
    }
    else
    cout<<"void Deletion"<<endl;
 }

 //**************************************************************
 int del_aft(struct node **start,int x)
 {  
    struct node *p,*q;
    p=*start;
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
 int del_end(struct node **start)
 {
    struct node *q,*p;
    p=*start;
    q=NULL;
    int x;
    if(*start==NULL)
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
        *start=NULL;
    }
 }
 //**************************************************************

//  int del_specific(struct node **start,int x)
//  {
//     struct node *p,*q;
//     p=*start;
//     q=NULL;
//     while(p!=NULL)
//     {
//         if(p->info==x)
//         {
//             p=p->next;
//             if(q==NULL)
//             {
//                 del_beg();
//             }
//             else
//             {
//                 del_aft(x);
//             }
//         }
//         else
//         {
//             q=p;
//             p=p->next;
//         }
//     }
//  }
//*************************************************************************************
int Traversal(struct node *start)
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

    void order_insertion(int key)
    {
        struct node *p,*q;
        q=NULL;
        p=start;
        while(p!=NULL && key>=p->info)
        {
            q=p;
            p=p->next;
        }
        if(q!=NULL)
        {
            ins_after(q,key);

        }
    }

int main()
{

   
}




