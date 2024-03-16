#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int capacity;
    int array[100];
}*s;

struct queue{
    int rear;
    int capacity;
    int front;
    int array[100];
}*q;

void createq(struct queue *q){
    int c,i;
    printf("Enter the capacity of the queue- ");
    scanf("%d",&c);
    q->capacity=c;
    q->rear=-1;
    q->front=-1;
}

int isfullq(struct queue *q){
    if(q->rear-q->front+1==q->capacity){
        return (1);}
    else{
        return (0);}
}

int isemptyq(struct queue *q){
    if(q->front==q->rear && q->rear==-1){
        return (1);}
    else{
        return (0);}
}

void enqueue(){
    int e,w;
    w=isfullq(q);
    if (w==0){
    if (q->front==q->rear && q->rear==-1){
        q->front=0;}
    printf("Enter the element to be added into the queue- ");
    scanf("%d",&e);
    q->rear++;
    q->array[q->rear]=e;}
    else{
        printf("\n The queue is full \n");}
    }

int  dequeue(){
    int w=isemptyq(q);
    if(w==0){
    int e;
    e=q->array[q->front];
    q->front++;
    if (q->front>q->rear){
    q->front=-1;
    q->rear=-1;}
    return(e);}
    else{
        printf("\n The queue is empty \n");}
    }

void creates(struct stack *s){
    int c,i;
    printf("Enter the capacity of the stack- ");
    scanf("%d",&c);
    s->capacity=c;
    s->top=-1;
}

void traverseq(struct queue *q){
    int i;
    if(!(q->rear==-1)){
    for (i=q->front;i<=q->rear;i++){
        printf("%d ",q->array[i]);}}
}

int isfulls(struct stack *s){
    if(s->top==s->capacity){
        return (1);}
    else{
        return (0);}
}

int isemptys(struct stack *s){
    if(s->top==-1){
        return (1);}
    else{
        return (0);}
}

void push(){
    int q=isfulls(s);
    if (q==0){
    int e;
    printf("Enter an element to be added into the stack");
    scanf("%d",&e);
    s->top++;
    s->array[s->top]=e;}
    else{
        printf("\n The stack is full \n");}}

int pop(){
    int q=isemptys(s);
    if (q==0){
    int e;
    e=s->array[s->top];
    s->top--;
    return(e);}
    else{
        printf("\n The stack is empty \n");
    }}

void traverses(struct stack *s){
    int i;
    for (i=0;i<=s->top;i++){
        printf("%d ",s->array[i]);}
}

void main(){
    int p,a,b,c=0,d=0;
    s=malloc(sizeof(struct stack));
    q=malloc(sizeof(struct queue));
    creates(s);
    createq(q);
    printf("\n On what do you wish to perform operations- \n 1)Stack \n 2)Queue \n");
    scanf("%d",&b);
    switch(a){
        case 1:
            b=1;
        case 2:
            b=2;}
    d=0;
while(d==0){
        while(d==0 && b==1)
        {printf("\n What operation do you wish to perform- \n 1)Push \n 2)Pop \n 3)Traversal \n 4)Switch to Queue \n 5)End Program \n");
            scanf("%d",&c);
                switch(c){
                    case 1:
                        push();
                        printf("Now, the stack is- ");
                        traverses(s);
                        break;
                    case 2:
                        pop();
                        printf("Now, the stack is- ");
                        traverses(s);
                        break;
                    case 3:
                        printf("The stack is- ");
                        traverses(s);
                        break;
                    case 4:
                        b=2;
                        break;
                    case 5:
                        d=1;}}
        while(d==0 && b==2)
        {printf("\n What operation do you wish to perform- \n 1)Enqueue \n 2)Dequeue \n 3)Traversal \n 4)Switch to Stack \n 5)End Program \n");
            scanf("%d",&c);
                switch(c){
                    case 1:
                        enqueue();
                        printf("Now, the queue is- ");
                        traverseq(q);
                        break;
                    case 2:
                        dequeue();
                        printf("Now, the queue is- ");
                        traverseq(q);
                        break;
                    case 3:
                        printf("The stack is- ");
                        traverseq(q);
                        break;
                    case 4:
                        b=1;
                        break;
                    case 5:
                        d=1;}}}
}
