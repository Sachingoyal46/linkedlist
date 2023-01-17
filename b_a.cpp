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

struct node *B_A(struct node *l1,struct node *l2)
{   
    struct node *p,*q,*l3;
    p=l1;
    q=l2;
    l3=NULL;

    while(p!=NULL && q!=NULL)
    {
        if(p->info>q->info)
        {
            ins_end(&l3,q->info);
            q=q->next;
        }
        else if(p->info<q->info)
        {
            // ins_end(&l3,p->info);
            p=p->next;
        }
        else
        {
            // ins_end(&l3,p->info);
            p=p->next;
            q=q->next;
        }
    }
        // while(p!=NULL)
        // {
        //     ins_end(&l3,p->info);
        //     p=p->next;
        // }
        while(q!=NULL)
        {
            ins_end(&l3,q->info);
            q=q->next;
        }
        return l3;

}


int main()
{
    struct node *start1,*start2,*start3;
    start1=NULL;
    start2=NULL;
    start3=NULL;
    ins_end(&start1,10);
    ins_end(&start1,20);
    ins_end(&start1,40);
    ins_end(&start1,50);
    ins_end(&start1,60);
    Traversal(start1);
    cout<<endl;
     ins_end(&start2,5);
    ins_end(&start2,20);
    ins_end(&start2,50);
    ins_end(&start2,35);
    ins_end(&start2,60);
    Traversal(start2);
    cout<<endl;

    start3=B_A(start1,start2);
    Traversal(start3);


    

}




