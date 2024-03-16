#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    struct node *lptr;
    int val;
    struct node *rptr;
    struct node *parent;
}*start;
void create(){
    int l,i,le,r;
    printf("Enter the number of elements in the binary tree- ");
    scanf("%d",&l);
    printf("Enter the value of the root of binary tree- ");
    scanf("%d",&r);
    start=malloc(sizeof(struct node));
    start->val=r;
    start->lptr=NULL;
    start->rptr=NULL;
    start->parent==NULL;
    int lis[l-1];
    printf("Enter the numbers to be stored in the initial tree (Press enter after each number)- \n");
    for (i=1;i<l;i++){
        scanf("%d",&le);
        insert(le);}
}
void insert(int n){
    struct node *temp,*now;
    int x=1;
    now=start;
    temp=malloc(sizeof(struct node));
    temp->val=n;
    temp->lptr=NULL;
    temp->rptr=NULL;
    while(x!=2){
        if (n<(now->val)){
            if(now->lptr==NULL){
                now->lptr=temp;
                temp->parent=now;
                x++;}
            else{
                now=now->lptr;}}
        else{
            if(now->rptr==NULL){
                now->rptr=temp;
                temp->parent=now;
                x++;}
            else{
                now=now->rptr;}
}}}

void delet(struct node *start,int n){
    struct node *temp,*mix,*loc;
    loc=search(start,n);
    if (loc->lptr==NULL && loc->rptr==NULL){
        if (loc->parent->val>n){
        loc->parent->lptr=NULL;
        free(loc);
        return;}
        else{
        loc->parent->rptr=NULL;
        free(loc);
        return;}}
    if (loc->lptr==NULL || loc->rptr==NULL){
        if (loc->lptr==NULL){
            if (loc->parent->lptr==NULL){
                loc->parent->rptr=loc->rptr;}
            else{
                loc->parent->lptr=loc->rptr;}}
        else{
            if (loc->parent->rptr==NULL){
                loc->parent->lptr=loc->lptr;}
            else{
                loc->parent->rptr=loc->lptr;
}}}
    if (loc->lptr!=NULL && loc->rptr!=NULL){
            mix=minsearch(loc);
            loc->val=mix->val;
            mix->parent->lptr=NULL;
            free(mix);}}

int search(struct node *start,int n){
    int x=1;
while(x==1){
    if (start->val==n){
        printf("%d exists in the binary search tree \n",n);
        return(start);
        x=2;}
    else{
        if (start->val<n){
            if(start->rptr==NULL){
                printf("The required element does not exist in the created binary search tree.");
                x=2;
                return;}
            else{start=start->rptr;}}
        else{
            if(start->lptr==NULL){
                printf("The required element does not exist in the created binary search tree.");
                x=2;
                return;}
            else{start=start->lptr;}}}}
}

int minsearch(struct node *start){
struct node *mi;
mi=start;
    while(start!=NULL){
    if (start->val<mi){
        mi=start;}
    start=start->lptr;}
    return(mi);
}
void inorder(struct node *start){
    if (start == NULL) return;
    inorder(start->lptr);
    printf("%d ",start->val);
    inorder(start->rptr);
    return;
}

void main(){
    int le;
    struct node *loc,*a;
    int c,y;
    create();
    inorder(start);
    y=0;
    while(1){
    printf("\n Choose the operation that you wish to perform- 1)Insertion 2)Deletion 3)Search 4)End Process- ");
    scanf("%d",&c);
    if(y==1){
        break;}
    switch(c){
        case 1:
            printf("Enter the element that is to be added- ");
            scanf("%d",&le);
            insert(le);
            printf("INORDER Traversal-");
            inorder(start);
            y=0;
            break;
        case 2:
            printf("Enter the element that is to be deleted- ");
            scanf("%d",&le);
            delet(start,le);
            printf("INORDER Traversal-");
            inorder(start);
            y=0;
            break;
        case 3:
            printf("Enter the element that is to be searched- ");
            scanf("%d",&le);
            loc=search(start,le);
            printf("INORDER Traversal-");
            inorder(start);
            y=0;
            break;
        case 4:
            y++;
            break;
       }}}//45, 15, 79, 90, 10, 55, 12, 20, 50
