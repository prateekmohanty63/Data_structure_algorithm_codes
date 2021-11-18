#include<stdio.h>

struct Queue {
    int front, rear, size;
    int  capacity;
    int* array;
};

struct Queue* createQueue(int capacity)
{
    struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity=capacity;
    queue->front=queue->size=0;

    queue->rear=capacity-1;
    queue->array=(int*)malloc(queue->capacity*sizeof(int));

    return queue;
};

int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d Added to the queue\n",item);


}

int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    printf("%d dequded from the queue\n",item);
    queue->size = queue->size - 1;


    return item;
}

void display(struct Queue *queue)
{
    for(int i=0;i<queue->size;i++)
        printf("%d  ",queue->array[i]);
    printf("\n");
}

int main()
{
          struct Queue* q1=createQueue(5);
          struct Queue* q2=createQueue(5);
          struct Queue* q3=createQueue(5);



          printf(" 1.ENQUEUE\n 2.DEQUEUE\n 3.EXIT\n");



          int flag=0;

          while(flag!=1)
          {
               int opt;
          scanf("%d",&opt);
          int n;
          if(opt==1){

          printf("Enter the number of elements:");
          scanf("%d",&n);
          for(int i=0;i<n;i++)
          {
              int pri,num;
              printf("\nEnter the priority and the number: ");
              scanf("%d%d",&pri,&num);

              if(pri==1)
                enqueue(q1,num);
              else if(pri==2)
                enqueue(q2,num);
              else{
                enqueue(q3,num);
              }

          }
          display(q1);
          display(q2);
          display(q3);

          }


        else if(opt==2)
        {
            if(q1->size!=0)
            {
                dequeue(q1);
            }
            else if(q1->size==0 && q2->size!=0)
                dequeue(q2);

            else if(q1->size==0 && q2->size==0 && q3->size!=0)
                dequeue(q3);
            else
                printf("No more element in any queue");
        }

          display(q1);
          display(q2);
          display(q3);

          if(opt==3)
            flag=1;
          }


}
