#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void Display_recur_rev(struct Node *p)
{
    /// FIRST CALLING TAKES PLACE THEN PRINTING TAKES PLACE
    /// HENCE ARRAY IS PRINTED IN REVERSE ORDER;
    if(p!=NULL)
    {
        Display_recur(p->next);
        printf("%d ",p->data);
    }
    printf("\n");
}

void Display_recur(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        Display_recur(p->next);
    }
    printf("\n");
}


/// Length of linked list
int length(struct Node *p)
{
    int count=0;
    while(p!=0)
    {
        count++;
        p=p->next;
    }
    return count;
}

int recr_length(struct Node *p)
{
    int count=0;
    if(p!=0)
    {
        count=recr_length(p->next);
        return count+1;
    }
    return count;
}

int sum(struct Node *p)
{
    int count=0;

    while(p!=0)
    {
        count+=p->data;
        p=p->next;
    }
    return count;
}

int count=0;
int recur_sum(struct Node *p)
{

    if(p!=0)
    {
        count+=p->data;
        recur_sum(p->next);
        /*count=recur_sum(p->next)+p->data;*/
    }
    return count;
}

int max(struct Node *p)
{
    int min=-1;
    while(p!=0)
    {
        if(p->data>min)
            min=p->data;
        p=p->next;
    }
    return min;
}

int max_ter(struct Node *p)
{
    int x=0;
    if(p==0)
    return -1;
    x=max(p->next);
    return x>p->data?x:p->data;
}


///Searching in linked list
/// We cannot directly access any index in linked list
/// Hence binary search is not posssible

int search(struct Node *p,int a)
{
    int r=length(first);


     for(int i=0;i<r;i++)
     {

        if(p->data==a)
        {
            return i;
        }

         p=p->next;
    }
    return -1;
}

struct Node * search_imv(struct Node *p,int key)
{
    struct Node *q=NULL;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
        }
        q=p;
        p=p->next;
    }
    return q;
}

/// Inserting into a linked list

void insert(struct Node *p,int pos,int value)
{
    struct Node *t;
     if(pos<0 || pos>length(p))
        return ;

     t=(struct Node *)malloc(sizeof(struct Node));
     t->data=value;

     if(pos==1)
     {
         t->next=first;
         first=t;
     }

     else if(pos>1)
     {
         t->next=first;
         for(int i=0;i<pos-1;i++)
         {
             p=p->next;
         }
         t->next=p->next;
         p->next=t;
     }
}


/// deleting

/// deleting the first element in linked list

int Delete(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1;

    if(index<1 || index>5)
        return -1;

    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }

}

int check_sort(struct Node *p)
{
    int min=-32786;

    while(p!=NULL)
    {
        if(p->data<min)
            return -1;

            min=p->data;
            p=p->next;
    }
    return 1;

}

void remove_duplicate(struct Node *p)
{
    struct Node *q=p->next;

    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void rev_ele(struct Node *p)
{
    int a=length(first);
    struct Node *q;
    q=p;
    int *arr=(int *)malloc(sizeof(int)*a);
    int i=0;

    while(p!=NULL)
    {
        arr[i]=p->data;
        p=p->next;
        i++;
    }

    i--;
    while(q!=NULL)
    {
        q->data=arr[i];
        i--;
        q=q->next;
    }


}



int main()
{
    /*int A[]={3,5,7,10,15};
    create(A,5);

    Display(first);

    struct Node *q;*/

    /*Display_recur_rev(first);
    Display_recur(first);*/
  /* printf("%d\n",length(first));
    printf("%d\n",recr_length(first));
    printf("%d\n",sum(first));
    printf("%d\n",recur_sum(first));
    printf("%d\n",max(first));
    printf("%d\n",max_ter(first));
   /* printf("%d\n",search(first,10));*/
   /* q=search_imv(first,10);
    printf("%d\n ",q->data);
    printf("%d\n ",q->next);*/
    /*printf("%d\n ",first->next);*/

    /*Delete(first,9);*/
    /*Display(first);*/

   /* int B[]={1,2,3,3,5};
    create(B,5);

    int C[]={1,1,2,3,4};
    create(C,5);
    check_duplicate(first);
    Display(first);
    printf("%d",check_sort(first));*/

    int C[]={1,1,1,2,2,3,4,5};
    create(C,8);
    insert(first,2,2);
    Display(first);
    Display(first);
    Delete(first,2);
    printf("%d\n",search(first,1));

    insert(first,5,10);
    Display(first);


    return 0;
}
