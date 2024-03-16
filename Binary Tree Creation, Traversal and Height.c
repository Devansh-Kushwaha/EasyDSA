#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    struct node *preptr;
    int val;
    struct node *nxtptr;
    struct node *parent;
}*start;
int t=0,h=0;
int arr[50];
int *ar=arr;
void create(){
    struct node *tmp,*now;
    int a,v,b;
    printf("Enter the Root Node Value: ");
    scanf("%d",&a);
    start=malloc(sizeof(struct node));
    start->val=a;
    start->preptr=NULL;
    start->nxtptr=NULL;
        now=start;
    int p=0;
    while (p==0){
    printf("\n Choose \n 1)Insert Left Child \n 2)Insert Right Child \n 3)Go to Left Child \n 4)Go to Right Child \n 5)Go to parent \n 6)Go to root \n 7)End process \n");
    scanf("%d",&b);
    switch (b){
        case 1:
            t=t+1;
            if (t>h){
                h++;
            }
            tmp=malloc(sizeof(struct node));
            now->preptr=tmp;
            printf("Enter the value to be inserted here: ");
            scanf("%d",&v);
            tmp->val=v;
            tmp->nxtptr=NULL;
            tmp->preptr=NULL;
            tmp->parent=now;
            now=tmp;
            break;
        case 2:
            t=t+1;
            if (t>h){
                h++;
            }
            tmp=malloc(sizeof(struct node));
            now->nxtptr=tmp;
            printf("Enter the value to be inserted here: ");
            scanf("%d",&v);
            tmp->val=v;
            tmp->nxtptr=NULL;
            tmp->preptr=NULL;
            tmp->parent=now;
            now=tmp;
            break;
        case 3:
            t++;
            now=now->preptr;
            printf("You are now at %d",now->val);
            break;
        case 4:
            t++;
            now=now->nxtptr;
            printf("You are now at %d",now->val);
            break;
        case 5:
            t--;
            now=now->parent;
            printf("You are now at %d",now->val);
            break;
        case 6:
            t=0;
            now=start;
            printf("You are now at %d",now->val);
            break;
        case 7:
            p=1;}
        }}

void preorder(struct node *start){
    if (start == NULL) return;
    printf("%d ",start->val);
    preorder(start->preptr);
    preorder(start->nxtptr);
}
void inorder(struct node *start){
    if (start == NULL) return;
    inorder(start->preptr);
    printf("%d ",start->val);
    inorder(start->nxtptr);
}
void postorder(struct node *start){
    if (start == NULL) return;
    postorder(start->preptr);
    postorder(start->nxtptr);
    printf("%d ",start->val);
}
void leaf(struct node *start){

    if (start == NULL) return;
    if (start->nxtptr==NULL && start->preptr==NULL ){
        printf("%d ",start->val);}
    leaf(start->preptr);
    leaf(start->nxtptr);
}
    int tr=0,tre=0;
    int he=0,rhe=0;

void path(struct node *start){
    if (start == NULL){
        tr--;
        return;}
    tr++;
    if (tr>he){
        he=tr;}
    path(start->preptr);
    path(start->nxtptr);
}

void rpath(struct node *start){
   if (start == NULL){
        tre--;
        return;}
    tre++;
    if (tre>rhe){
        rhe=tre;
    }
    rpath(start->nxtptr);
    rpath(start->preptr);
}
void main(){
    printf("BINARY TREE CREATION \n");
    create();
    printf(" \n PRE-ORDER TRAVERSAL- ");
    preorder(start);
    printf(" \n IN-ORDER TRAVERSAL- ");
    inorder(start);
    printf(" \n POST-ORDER TRAVERSAL- ");
    postorder(start);
    printf(" \n Height of the tree is- %d \n",h+1);
    printf("Leaf in the trees are- ");
    leaf(start);
    path(start);
    rpath(start);
    printf("\n Longest Path of the tree is- %d",he+rhe);
}
