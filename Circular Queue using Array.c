#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct array{
    int front, capacity,rear;
    int *ar;
    int s} *Q;

struct array *createQueue (int capacity){
    struct array *Q;
    Q=malloc(sizeof(struct array));
    Q->capacity=capacity;
    Q->front=-1;
    Q->rear=-1;
    Q->s=0;
    Q->ar=malloc(sizeof(int)*capacity);
    return (Q);}

int isEmpty (struct array *Q){
    if(Q->s==0){
    return 1;}
    else {return 0;}
}
int isFull (struct array *Q){
    if(Q->s==5){
        return 1;}
    else{
        return 0;}
}

void enQueue(struct array *Q, int data)
{if(isFull(Q)){
        printf("Overflow");}
    else{
        Q->rear=(Q->rear+1)%Q->capacity;
        Q->ar[Q->rear]=data;
        Q->s++;}
        if(Q->front==-1){
            Q->front=Q->rear;}
}

int deQueue(struct array *Q)
{int data=-1;
    if (isEmpty(Q)){
     printf("Queue is empty");
        return 1;}
    else
    {data=Q->ar[Q->front];
        Q->s--;
        if (Q->front==Q->rear )
        {Q->front=Q->rear=-1;}
        else
        {Q->front=(Q->front+1)%Q->capacity;}}
    return data;
}

void deleteQueue(struct array *Q)
{if(Q)
    {if(Q->ar)
        {free(Q->ar);}
        free(Q);}
}

void traverses(struct array *Q)
{   int i;
    for (i=Q->front;i<Q->s+Q->front;i++){
        printf("%d ",Q->ar[(i%Q->capacity)]);}
}

void main(){
    int x,d=0,c;
        printf("Enter the capacity of the queue: ");
        scanf("%d", &c);
        Q=createQueue(c);
    while(d==0){
        {printf("\n What operation do you wish to perform- \n 1)Enqueue \n 2)Dequeue \n 3)Traversal \n 4)Change Capacity \n 5)End Program \n");
            scanf("%d",&c);
                switch(c){
                    case 1:
                        printf("Enter the element to be enqueued- ");
                        scanf("%d", &c);
                        enQueue(Q,c);
                        printf("Now, the queue is- ");
                        traverses(Q);
                        break;
                    case 2:
                        deQueue(Q);
                        printf("Now, the queue is- ");
                        traverses(Q);
                        break;
                    case 3:
                        printf("The queue is- ");
                        traverses(Q);
                        break;
                    case 4:
                        printf("Enter the new capacity ");
                        scanf("%d", &c);
                        Q->capacity=c;
                        break;
                    case 5:
                        d=1;}
}}}
