#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *preptr;
    int val;
    struct node *nxtptr;
};
struct queue{
    int rear;
    int capacity;
    int front;
    struct node *frontptr;
    struct node *rearptr;
}*q;
void createq(struct queue *q){
    int c,i;
    printf("Enter the capacity of the queue- ");
    scanf("%d",&c);
    q->capacity=c;
    q->rear=-1;
    q->front=-1;
    q->frontptr=malloc(sizeof(struct node));
    q->rearptr=malloc(sizeof(struct node));
}
int isfullq(struct queue *q){

    if(q->rear-q->front+1==q->capacity){

        return (1);
    }
    else{
        return (0);
    }}
int isemptyq(struct queue *q){
    if(q->front==q->rear && q->rear==-1){
        return (1);
    }
    else{
        return (0);
    }}
void enqueue(){
    int e,w;
    w=isfullq(q);
    struct node *temp,*now;
    if (w==0){
    temp=malloc(sizeof(struct node));
    if (q->front==q->rear && q->rear==-1){
        q->front=0;
        q->frontptr=temp;
    }
    printf("Enter the element to be added into the queue- ");
    scanf("%d",&e);
    q->rear=(q->rear+1)%q->capacity;
    (q->rearptr)->nxtptr=temp;
    temp->preptr=q->rearptr;
    temp->val=e;
    temp->nxtptr=NULL;
    q->rearptr=temp;
    }
    else{
        printf("\n The queue is full \n");
    }}
int  dequeue(){
    int w=isemptyq(q);
    if(w==0){
    int e;
    e=q->frontptr->val;
    printf("Dequeued value is %d",e);
    q->front=(q->front+1)%q->capacity;
    q->frontptr=q->frontptr->nxtptr;
    if (q->front>q->rear){
    q->front=-1;
    q->rear=-1;
    return(e);
    }}
    else{
        printf("\n The queue is empty \n");
    }}
void traverseq(struct queue *q){
    int i;
    struct node *show;
    show=q->frontptr;
    if(!(q->rear==-1)){
    for(i=q->front;i<=q->rear;i++){
    printf("%d ",show->val);
    show=show->nxtptr;}}
}
void main(){
    int p,a,b,c=0,d=0;
    q=malloc(sizeof(struct queue));
    createq(q);
while(d==0)
        {
            printf("\n What operation do you wish to perform- \n 1)Enqueue \n 2)Dequeue \n 3)Traversal \n 4)End Program \n");
            scanf("%d",&c);
                switch(c){

                    case 1:
                        enqueue();
                        printf("Now, the queue is- ");
                        traverseq(q);
                        break;
                    case 2:
                        dequeue();
                        printf("\n Now, the queue is- ");
                        traverseq(q);
                        break;
                    case 3:
                        printf("The stack is- ");
                        traverseq(q);
                        break;

                    case 4:
                        d=1;}}}
