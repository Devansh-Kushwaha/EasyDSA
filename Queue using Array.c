#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    int front, capacity,rear;
    int *ar;} *Q;

int isfull(struct node *Q){
    if (Q->front+1%Q->capacity==Q->front){
        return 1;
    }
    else{
        return 0;};
}
void insert(struct node *Q){
    int v;
   // if (isfull(Q)){}
         //   printf("Overflow");}
   // else{

     printf("Enter the value of element: ");
     scanf("%d",&v);
     Q->rear=(Q->rear+1)%Q->capacity;
     Q->ar[Q->rear]=v;

     if(Q->front==-1){
        Q->front=Q->rear;
     }}

void main(){
    Q->capacity=5;
    Q->front=-1;
    Q->rear=-1;
    insert(Q);
    insert(Q);
    insert(Q);
    insert(Q);
}
