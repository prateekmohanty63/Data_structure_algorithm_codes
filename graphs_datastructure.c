#include<stdlib.h>
#include<stdio.h>
#define maxNode 9

char arr[]={'A','B','C','D','F','H','N','P','X'};
struct queue {
    int front, rear, size;
    unsigned max;
    int* array;
};

struct queue* create(unsigned max)
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->max = max;
    q->front = q->size = 0;
    q->rear = max - 1;
    q->array = (int*)malloc(q->max * sizeof(int));
    return q;
}

int isFull(struct queue* q)
{   if(q->size==q->max){
        return 1;
    }
    else
        return 0;
}
int isEmpty(struct queue* q)
{
    if(q->size==0){
        return 1;
    }
    else
        return 0;
}

void enqueue(struct queue* q, int item)
{
    if (isFull(q))
        return;
    q->rear = (q->rear + 1)
                  %q->max;
    q->array[q->rear] = item;
    q->size = q->size + 1;
}

int dequeue(struct queue* q)
{
    if (isEmpty(q))
        return -1;
    int item = q->array[q->front];
    q->front = (q->front + 1)
                   % q->max;
    q->size = q->size - 1;
    return item;
}

typedef struct Node
{
    int vertexNum;
    struct Node *next;
}Node;

typedef struct List
{
    Node *head;
}List;

List* adjlist[maxNode]={0};

void addNode(int s,int d)
{
    Node *dest,*tmp,*src;

    if(adjlist[s]->head==NULL)
    {
        src=(Node *)malloc(sizeof(Node));
        src->vertexNum=s;
        src->next=NULL;
        adjlist[s]->head=src;
    }

    dest=(Node *)malloc(sizeof(Node));
    dest->vertexNum=d;
    dest->next=NULL;
    tmp=adjlist[s]->head;

    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=dest;
}

void printList()
{

    int i;
    for(i=1;i<maxNode;++i)
    {
        Node *p=adjlist[i]->head;
        printf("Adjacency List for vertex %d\n",i);

        while(p)
        {
            printf("%d",p->vertexNum);
            p=p->next;
        }
        printf("\n");
    }
}

// DEPTH FOR SEARCH 

int checkedge(int s,int d)
{
    Node *p=adjlist[s]->head;

    while(p)
    {
        if(p->vertexNum==d)
        {
            return 1;
        }
        p=p->next;
    }
    return 0;
}

void DFS(int i,int *p)
{
    printf("%c->",arr[i]);
    p[i]=1;

    for(int j=0;j<maxNode;j++){
        if(checkedge(i,j) && !p[j])
        {
            DFS(j,p);
        }
    }
}

int main()
{
    for(int i=0;i<maxNode;i++)
    {
        adjlist[i]=(List*)malloc(sizeof(List));
        adjlist[i]->head=NULL;
    }
     printf("A is 0 and B is 1 and C is 2 and D is 3 and F is 4 and H is 5 and N is 6 and P is 7 and X is 8\n");

     addNode(0,1);
    addNode(0,3);
    addNode(0,2);
    addNode(1,6);
    addNode(1,7);
    addNode(1,5);
    addNode(2,4);
    addNode(2,6);
    addNode(3,5);
    addNode(4,6);
    addNode(5,7);
    addNode(5,8);
    addNode(6,7);
    addNode(7,8);

    int *visited=(int*)calloc(maxNode,sizeof(int));
    struct queue *q=create(maxNode);
    printf("The code for BFS of code c is: \n");
    enqueue(q,2);
    visited[2]=1;

    while(!isEmpty(q))
    {
        int node=dequeue(q);
        for(int j=0;j<maxNode;j++){
            if(checkedge(node,j) && !visited[j])
            {
                printf("%c->",arr[j]);
                visited[j]=1;
                enqueue(q,j);
            }
        }
    }
    printf("\n");
     printf("The code for BFS of source B is: \n");
     free(q);
     struct queue* z1=create(maxNode);
     visited=(int*)calloc(maxNode,sizeof(int));
     enqueue(z1,1);
     visited[1]=1;

     while(!isEmpty(z1)){
         int node1=dequeue(z1);
         for(int j=0;j<maxNode;j++){
             if(checkedge(node1,j) && !visited[j])
             {
                 printf("%c->",arr[j]);
                 visited[j]=1;
                 enqueue(z1,j);
             }
         }
     }
     printf("\n");

     

   int *visited2=(int*)calloc(maxNode,sizeof(int));
   printf("The DFS of node B is: \n");
   DFS(1,visited2);
   printf("\n");
  int *visited3=(int*)calloc(maxNode,sizeof(int));
   printf("The DFS of node C is: \n");
   DFS(2,visited3);

}