#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *lptr;
    int val;
    int bf;
    int lh;
    int rh;
    struct node *rptr;
    struct node *parent;
}*start,*gstart;

void create (){
    int r;
    printf("Enter the value of the root of binary tree- ");
    scanf("%d",&r);
    start=malloc(sizeof(struct node));
    gstart=malloc(sizeof(struct node));
    start->bf=0;
    start->lh=0;
    start->rh=0;
    start->val=r;
    start->lptr=NULL;
    start->rptr=NULL;
    start->parent=gstart;
    gstart->lptr=start;
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
            now->lh++;
            now->bf=now->lh-now->rh;
            if(now->lptr==NULL){
                now->lptr=temp;
                temp->parent=now;
                x++;
            }
            else{
                now=now->lptr;
                }
        }
        else{
            now->rh++;
            now->bf=now->lh-now->rh;
            if(now->rptr==NULL){
                now->rptr=temp;
                temp->parent=now;
                x++;
                  }
            else{
                now=now->rptr;}
            }}}


void inorder(struct node *start){
    printf("R");
    if (start == NULL) return;
    inorder(start->lptr);
    printf("%d ",start->val);

    inorder(start->rptr);
    return;
}

void balance (struct node *start){

    if (start == NULL) return;

    inorder(start->lptr);
    if (start->bf<-1 || start->bf>1){

        if (start->bf==-2 && start->rptr->bf==-1){
            start->rptr->rh++;
            start->rptr->lh++;
            start->bf=start->lh-start->rh;
            start->rptr->bf=start->rptr->lh-start->rptr->rh;
            start->rh=start->rh-2;
            start->bf=start->lh-start->rh;
            start->rptr->parent=start->parent;
            start->parent=start->rptr;
            start->rptr->lptr=start;
            start->rptr=NULL;
            if (start->parent->parent->lptr==start){
                start->parent->parent->lptr=start->parent;
            }
            else{
                start->parent->parent->rptr=start->parent;
            }
        }
        else if (start->bf=2 && start->lptr->bf==1)  {

            start->lptr->lh++;
            start->lptr->rh++;
            start->lptr->bf=start->lptr->lh-start->lptr->rh;
            start->lh=start->lh-2;
            start->bf=start->lh-start->rh;
            start->lptr->parent=start->parent;
            start->parent=start->lptr;
            start->lptr->rptr=start;
            start->lptr=NULL;
            if (start->parent->parent->lptr==start){
                start->parent->parent->lptr=start->parent;
            }
            else{
                start->parent->parent->rptr=start->parent;
            }
        }
        else if (start->bf=-2 && start->rptr->bf==1)  {
            start->rh=start->rh-2;
            start->bf=start->lh-start->rh;
            start->rptr->lh--;
            start->rptr->bf=start->rptr->lh-start->rptr->rh;
            start->rptr->lptr->lh++;
            start->rptr->lptr->rh++;
            start->rptr->lptr->bf=start->rptr->lptr->lh-start->rptr->lptr->rh;
            start->rptr->lptr->parent=start->parent;
            start->rptr->lptr->lptr=start;
            start->rptr->lptr->rptr=start->rptr;
            start->rptr->parent=start->rptr->lptr;
            start->parent=start->rptr->lptr;
            start->rptr->lptr=NULL;
            start->rptr=NULL;
            if (start->parent->parent->lptr==start){
                start->parent->parent->lptr=start->parent;
            }
            else{
                start->parent->parent->rptr=start->parent;
            }
    }
    else if (start->bf=2 && start->lptr->bf==-1)  {
                        start->lh=start->lh-2;
            start->bf=start->lh-start->rh;
            start->lptr->rh--;
            start->lptr->bf=start->lptr->lh-start->lptr->rh;
            start->lptr->rptr->lh++;
            start->lptr->rptr->rh++;
            start->lptr->rptr->bf=start->lptr->rptr->lh-start->lptr->rptr->rh;
            start->lptr->rptr->parent=start->parent;
            start->lptr->rptr->rptr=start;
            start->lptr->rptr->lptr=start->rptr;
            start->lptr->parent=start->lptr->rptr;
            start->parent=start->lptr->rptr;
            start->lptr->rptr=NULL;
            start->lptr=NULL;
            if (start->parent->parent->lptr==start){
                start->parent->parent->lptr=start->parent;
            }
            else{
                start->parent->parent->rptr=start->parent;
            }
    }
}
    inorder(start->rptr);
    }
int search(struct node *start,int n){
    int x=1;
while(x==1){
    if (start->val==n){
        printf("%d exists in the binary search tree \n",n);
        return(start);
        x=2;
    }

    else{
        if (start->val<n){
            if(start->rptr==NULL){
                printf("The required element does not exist in the created binary search tree.");
                x=2;
                return;
            }
            else{start=start->rptr;
            }
        }
        else{
            if(start->lptr==NULL){
                printf("The required element does not exist in the created binary search tree.");
                x=2;
                return;
            }
            else{start=start->lptr;
            }
        }}}


        }

int minsearch(struct node *start){

struct node *mi;
mi=start;
    while(start!=NULL){
    if (start->val<mi){
        mi=start;

    }
    start=start->lptr;}

    return(mi);
}
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
        return;}
    }
    if (loc->lptr==NULL || loc->rptr==NULL){

        if (loc->lptr==NULL){
            if (loc->parent->lptr==NULL){
                loc->parent->rptr=loc->rptr;

            }
            else{
                loc->parent->lptr=loc->rptr;

            }
        }
        else{
            if (loc->parent->rptr==NULL){
                loc->parent->lptr=loc->lptr;

            }
            else{
                loc->parent->rptr=loc->lptr;

            }}}
    if (loc->lptr!=NULL && loc->rptr!=NULL){

            mix=minsearch(loc);
            loc->val=mix->val;
            mix->parent->lptr=NULL;
            free(mix);}}


void main(){
    int le;
    struct node *loc,*a;
    int c,y;
    create();
    inorder(start);
    y=0;
    while(1){
    printf("\n Choose the operation that you wish to perform- 1)Insertion 2)Deletion 3)End Process- ");
    scanf("%d",&c);
    if(y==1){
        break;
    }

    switch(c){
        case 1:
            printf("Enter the element that is to be added- ");
            scanf("%d",&le);
            insert(le);
            balance(gstart->lptr);
            printf("INORDER Traversal-");
            inorder(gstart->lptr);

            break;
        case 2:
            printf("Enter the element that is to be deleted- ");
            scanf("%d",&le);
            delet(start,le);
            balance(gstart->lptr);
            printf("INORDER Traversal-");
            inorder(start);

            break;

        case 3:
            y++;
            break;
       }}}
