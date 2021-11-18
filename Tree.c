#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Node *root=NULL;
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full");
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct Node * dequeue(struct Queue *q)
{
    struct Node* x=NULL;

    if(q->front==q->rear)
        printf("Queue is Empty\n");

    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}


int IsEmpty(struct Queue q)
{

    if(q.front==q.rear)
        return 1;
    return -1;
}

void createtree()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Enter root value: ");
    scanf("%d",&x);
    root=(struct Node*)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!IsEmpty(q))
    {

        p=dequeue(&q);
        printf("Enter left child: ");
        scanf("%d",&x);

        if(x!=-1)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
         printf("Enter right child: ");
        scanf("%d",&x);

        if(x!=-1)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
void preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

struct Stack1 {
    int top;
    unsigned capacity;
    int* array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack1* createStack(unsigned capacity)
{
    struct Stack1* stack = (struct Stack1*)malloc(sizeof(struct Stack1));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}


void pushs(struct Stack1* stack, int item)
{
    if (isFulls(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
int pops(struct Stack1* stack)
{
    if (isEmptys(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

int isFulls(struct Stack1* stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmptys(struct Stack1* stack)
{
    return stack->top == -1;
}


/// Iterative methods of tree traversal

void IPreorder(struct Node *p)
{
    struct Stack* stk1=createStack(100);

    while(p || !isEmptys(stk1))
    {
        if(p)
        {
            printf("%d ",p->data);
            pushs(stk1,p);
            p=p->lchild;
        }
        else{
            p=pops(stk1);
            p=p->rchild;
        }
    }
}

void IInorder(struct Node *p)
{
    struct Stack* stk1=createStack(100);

    while(p || !isEmptys(stk1))
    {
        if(p)
        {
            pushs(stk1,p);
            p=p->lchild;
        }
        else{
            p=pops(stk1);
             printf("%d ",p->data);
            p=p->rchild;
        }
    }
}



int search(struct Node *p,int key)
{

    if(p->data==key)
        return 1;
    else if(key<p->data)
    {
        search(p->lchild,key);
    }
    else if(key>p->data)
        search(p->rchild,key);
    return -1;

}




int main()
{
    createtree();

    preorder(root);
    printf("\n");
    postorder(root);
    printf("\nPre Order: ");
    IPreorder(root);


    if(search(root,10)==1)
        printf("\nElement found");
    else
        printf("\nElement not found");

}
