#include<stdio.h>
#include<stdlib.h>


int ele[100];
int k=0;

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
    printf("Admitted patient %d\n", item);
  ele[k++]=queue->array[k];

}


int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;

    int r=k;

    for(int i=0;i<queue->size;i++){
        ele[i]=ele[i+1];
        k--;
    }

    return item;
}

/*void display(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("No patients currently admitted in the hospital\n");
        return ;
    }

    printf("Beds occupied-> ");
    for(int i=0;i<queue->size;i++)

}*/


int peek(struct Queue* queue)
{

    return queue->array[queue->front];
}

void admit_patients(struct Queue *queue)
{
     for(int i=0;i<5;i++)
    {
        int pati_no;
        printf("Please enter the patient number to be admitted: \n");
        scanf("%d",&pati_no);
        enqueue(queue,pati_no);
    }

}

void dispay_patients(struct Queue *queue)
{
    for(int i=0;i<queue->size;i++)
        printf("%d ",queue->array[i]);
    printf("\n");
}
int main()
{
     struct Queue* queue = createQueue(5);

   /* for(int i=0;i<5;i++)
    {
        int pati_no;
        printf("Please enter the patient number to be admitted: \n");
        scanf("%d",&pati_no);
        enqueue(queue,pati_no);
    }*/

    admit_patients(queue);

    printf("Beds occupied-> ");

    /*for(int i=0;i<queue->size;i++)
        printf("%d ",ele[i]);*/

        dispay_patients(queue);
    printf("\n");

    for(int i=0;i<3;i++)
    printf("%d patient discharged from the hospital\n\n",dequeue(queue));

    printf("beds occupied-> \n");

    for(int i=0;i<queue->size;i++)
        printf("%d ",ele[i]);
        printf("\n");

    for(int i=0;i<4;i++)
    {
        int pat_no;
        if(isFull(queue))
        {
            printf("Sorry, the beds are filled\n");
        }
        else{
            printf("Please enter the patient number:\n");
            scanf("%d",&pat_no);
            enqueue(queue,pat_no);
        }
    }

    printf("Beds occupied-> ");
    /*for(int i=0;i<queue->size;i++)
        printf("%d ",ele[i]);*/

        dispay_patients(queue);

    printf("\n");


   printf("The total number of occupied beds in the hospital is: ");
   printf("%d\n",queue->size);

   printf("The total number of beds unoccupied in the hospital is: ");
   printf("%d\n",queue->capacity-queue->size);

  /* for(int i=0;i<queue->size;i++)
    printf("%d ",dequeue(queue));*/


}
