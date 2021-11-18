#include<stdio.h>
#include<stdlib.h>


struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[],int n)
{
     struct Node *t,*last;
     int i;

     first=(struct Node *)malloc(sizeof(struct Node));
     first->data=A[0];
     first->prev=first->next=NULL;
     last=first;

     for(int i=1;i<n;i++)
     {
         t=(struct Node *)malloc(sizeof(struct Node));
         t->data=A[i];
         t->next=last->next;
         t->prev=last;
         last->next=t;
         last=t;
     }
}

void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int length(struct Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

void insert(struct Node *p,int pos,int value)
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=value;

    if(pos<1 || pos>length(first)+1)
        return ;
    if(pos==1){
        first->prev=t;
        t->next=first;
        t->prev=NULL;
        first=t;
    }
    else{
            t->next=first;
        for(int i=0;i<pos-2;i++)
        {
            p=p->next;
        }
       t->next=p->next;
       p->next=t;

    }
}


int Delete(struct Node *p,int pos)
{
    struct Node *q,*r;
    q=first;
    r=first;
    int x=-1;

    if(pos==1){
        first=q->next;
        x=q->data;
        free(q);
    }

    else{
        for(int i=0;i<pos-2;i++)
        {
           p=p->next;
           q=q->next;
        }
        q=q->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[]={1,2,2,4,5};

    create(A,5);
    printf("\nLength of doubly linked list is: %d\n",length(first));

    Display(first);
    insert(first,1,5);
    Display(first);
    printf("%d\n",Delete(first,6));
    Display(first);
}
