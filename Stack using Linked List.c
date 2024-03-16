#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *ptr;
}*start;
int capacity=5;
int top = 0;

void create(int n){  //creation//
    top=capacity;
    struct node *now,*tmp;
    int v,i;
    printf("Enter the value of 1 element: ");
    scanf("%d",&v);
    start=malloc(sizeof(struct node));
    start->val=v;
    start->ptr=NULL;
    tmp=start;
    for(i=2;i<=n;i++){

        printf("Enter the value of %d element: ",i);
        scanf("%d",&v);
        now=malloc(sizeof(struct node));
        tmp->ptr=now;
        now->val=v;
        now->ptr=NULL;
        tmp=now;
}}

void pop(){
    printf("%d",start->val);
    start=start->ptr;


  }

int isfull(){
    return(top==capacity);

}
void insert(){
    struct node *now;
    top++;
    now=malloc(sizeof(struct node));

    now->val=90;
    now->ptr=start;
    start=now;
}
void main(){
    int a;
    create(5);
    pop();
    top--;
    pop();
    top--;
    insert();
    pop();
    top--;
    a=isfull();
    printf("\n %d",a);
}
