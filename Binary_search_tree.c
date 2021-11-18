#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *root=NULL;

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void Preorder(struct Node *p)
{
 if(p)
 {
 printf("%d ",p->data);
 Preorder(p->lchild);
 Preorder(p->rchild);
 }
}

void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}


struct Node * insert(struct Node *p,int key)
{
    struct Node *t;

    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }

    if(key<p->data)
        p->lchild=insert(p->lchild,key);
    else if(key>p->data)
        p->rchild=insert(p->rchild,key);
    return p;
}

struct Node * RInsert(struct Node *p,int key)
{
    struct Node *t=NULL;
    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
        p->lchild=RInsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=RInsert(p->rchild,key);
    return p;
}

int Height(struct Node *p)
{
    int x,y;
    int count=0;
    if(p==NULL)
        return 0;
        x=Height(p->lchild);
        y=Height(p->rchild);
        return x>y?x+1:y+1;

}

struct Node *InPre(struct Node *p)
{
    while(p && p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
}

struct Node *Insucc(struct Node *p)
{
    while(p && p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
}
struct Node *Delete(struct Node *p,int key)
{
    struct Node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
        p->rchild=Delete(p->rchild,key);
    else{
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else{
            q=Insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

void search(struct Node *p,int key)
{
    while(p){
    if(p->data==key){
        printf("\n%d found in the tree",key);
        break;}
    else if(key>p->data)
        p=p->rchild;
    else if(key<p->data)
        p=p->lchild;
    }

    if(p==NULL)
    printf("\nElement not found");
}



int main()
{
     printf("\nEnter the root element: ");
     int n;
     scanf("%d",&n);

     root=insert(root,n);

     int k=0;

     while(k!=-1)
     {
         printf("\nEnter the value to be inserted in binary tree: ");
         scanf("%d",&k);
         if(k==-1)
            break;
         insert(root,k);
     }
     Preorder(root);
     printf("\n");
     Postorder(root);
     printf("\n");
     Inorder(root);
     search(root,20);
     Delete(root,12);
     printf("\n");
     Inorder(root);
}
