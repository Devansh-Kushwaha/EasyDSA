#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *preptr;
    int val;
    struct node *nxtptr;
}*start,*end;

void create(int n){  //creation//
    struct node *now,*tmp,*pre;
    int v,i;
    printf("Enter the value of 1 element: ");
    scanf("%d",&v);
    start=malloc(sizeof(struct node));
    start->preptr=NULL;
    start->val=v;
    start->nxtptr=NULL;
    tmp=start;
    for(i=2;i<=n;i++){
        printf("Enter the value of %d element: ",i);
        scanf("%d",&v);
        now=malloc(sizeof(struct node));
        now->preptr=tmp;
        tmp->nxtptr=now;
        now->val=v;
        now->nxtptr=NULL;
        tmp=now;
        if (i==n){
            end=now;}}
}

void display(){ //display//
    struct node *show;
    show=start;
    printf("Now the linked list is: ");
    while (show!=NULL){
    printf("%d ",show->val);
    show=show->nxtptr;}
    printf("\n");}
void revdisplay(){ //reverse display//
    struct node *show;
    show=end;
    printf("Reversed linked list is: ");
while (show!=NULL){
    printf("%d ",show->val);
    show=show->preptr;}
}

void traverse(n){ //traversal//
   struct node *show;
    show=start;
    int x=0;
    printf("Now the linked list is: \n ");
    while (show!=NULL){
    printf("Index number %d- %d \n ",x,show->val);
    show=show->nxtptr;
    x++;}
    printf("\n");}

void insert(int n){ //insertion//
    int ch,i,v,j,ne;
    struct node *tmp,*tr;
    printf("Where do you want to insert a node \n 1)In the beginning 2)In the ending 3)After a node \n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("Enter the value: ");
            scanf("%d",&v);
            tmp=malloc(sizeof(struct node));
            tmp->val=v;
            tmp->nxtptr=start;
            start=tmp;
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d",&v);
            tr=start;
            for (i=1;i<=n;i++){
                if (i==n){
                    tmp=malloc(sizeof(struct node));
                    tr->nxtptr=tmp;
                    tmp->val=v;
                    tmp->nxtptr=NULL;}
            tr=tr->nxtptr;}
            break;
        case 3:
            printf("After what value do you wish to add: ");
            scanf("%d",&j);
            printf("Enter the value: ");
            scanf("%d",&v);
            tr=start;
            for (i=1;i<=n;i++){
                if (tr->val==j){
                    tmp=malloc(sizeof(struct node));
                    ne=tr->nxtptr;
                    tr->nxtptr=tmp;
                    tmp->val=v;
                    tmp->nxtptr=ne;
                    break;}
            tr=tr->nxtptr;}}}

void delet(int n){ //deletion//
    int ch,i,v,j,ne;
    struct node *tmp,*tr,*px;
    printf("Which node do you wish to delete \n 1)Beginning node \n 2)Ending node \n 3)A Particular Value \n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            px=start;
            start=start->nxtptr;
            free(px);
        break;
        case 2:
            tr=start;
            for (i=1;i<=n;i++){
                if (i==n-1){
                    px=tr->nxtptr;
                    tr->nxtptr=NULL;
                    free(px);
                    break;}
            tr=tr->nxtptr;}
            break;
        case 3:
            printf("What value do you wish to delete: ");
            scanf("%d",&j);
            tr=start;
            for (i=1;i<=n;i++){
                if (tr->nxtptr->val==j){
                    px=tr->nxtptr;
                    tr->nxtptr=px->nxtptr;
                    free(px);
                    break;}
                tr=tr->nxtptr;}
           break;
           }}

void main(){
    int l,c;
    printf("Enter the number of elements to be added in the doubly linked list: ");
    scanf("%d",&l);
    create(l);
    display();
    revdisplay();
    printf("\n");
    int p=0;
    while(p==0){
    printf("What operation do you wish to perform: \n 1)Insertion \n 2)Deletion \n 3)Traversal \n 4)End Program \n");
    scanf("%d",&c);
    switch(c){
        case 1:
            insert(l);
            display();
            l++;
            break;
        case 2:
            delet(l);
            display();
            l--;
            break;
        case 3:
            traverse(l);
            break;
        case 4:
            p=1;}
}}
