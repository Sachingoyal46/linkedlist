#include<iostream>
#include<bits./stdc++.h>
using namespace std;
//*****************************************************************

struct node {
    int coef;
    int expo;
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

 void insert_beg(struct node **start,int c,int e)
{
    struct node *p;
    p=getnode();
    p->coef=c;
    p->expo=e;
    p->next=*start;
    *start=p;
}
//***********************************************************************

 void ins_end(struct node **start,int c,int e)
{
    struct node *p,*q;
    p=*start;
    if(*start==NULL)
    insert_beg(start,c,e);
    else
    {

    while(p->next!=NULL)
    {
        p=p->next;
    }
        q=getnode();
       q->coef=c;
       q->expo=e;
        q->next=NULL;
        p->next=q;
    }
}
//*************************************************************************
int  del_beg(struct node **start,int c,int e)
 {
    struct node *p;
    int x,y;
    if(*start!=NULL)
    {
        p=*start;
        *start=p->next;
        x=p->coef;
        y=p->expo;
        free(p);
        return x;
        return y;
    }
    else
    cout<<"void Deletion"<<endl;
 }


//*************************************************************************************
int Traversal(struct node *start)
{
    struct node*p;
    p=start;
    while(p!=NULL)
    {
        cout<<p->coef<<" "<< p->expo<<endl;
        p=p->next;
    }
}
//********************************************************************************

struct node *addition(struct node *poly1,struct node *poly2)
{
    struct node *p,*q,*poly3;
    p=poly1;
    q=poly2;
    poly3=NULL;
    while(p!=NULL &&q!=NULL)
    {
        if(p->expo==q->expo)
        {
            ins_end(&poly3,p->coef+q->coef,p->expo);
            p=p->next;
            q=q->next;

        }
        else
        {
            if(p->expo>q->expo)
            {
                ins_end(&poly3,p->coef,p->expo);
                p=p->next;
            }
            else
            {
                ins_end(&poly3,q->coef,q->expo);
                q=q->next;
            }
        }
    }
    while(p!=NULL)
    {
        ins_end(&poly3,p->coef,p->expo);
        p=p->next;
    }
    while(q!=NULL)
    {
        ins_end(&poly3,q->coef,q->expo);
        q=q->next;
    }
    return poly3;
    
}





int main()
{
    struct node *poly1,*poly2,*poly3;
    poly1=NULL;
    poly2=NULL;
    poly3=NULL;
    ins_end(&poly1,4,7);
    ins_end(&poly1,-2,5);
    ins_end(&poly1,1,4);
    ins_end(&poly1,5,2);
    ins_end(&poly1,2,0);
    Traversal(poly1);
    cout<<endl;
    ins_end(&poly2,8,6);
    ins_end(&poly2,4,5);
    ins_end(&poly2,-3,3);
    ins_end(&poly2,2,2);
    ins_end(&poly2,7,1);
    ins_end(&poly2,-7,0);
    Traversal(poly2);
    cout<<endl;

    poly3=addition(poly1,poly2);
    Traversal(poly3);




    

    

}




