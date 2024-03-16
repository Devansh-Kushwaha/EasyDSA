#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *lchild;
    int val;
    struct node *rchild;
}*root,*now;
int ar[50];
void create(int l){
    int i,q;
    for(i=0;i<l;i++){
        printf("Enter %d number: ",i);
        scanf("%d",&q);
        ar[i]=q;
    }

    root=malloc(sizeof(struct node));
    root->val=ar[0];
    root->lchild=NULL;
    root->rchild=NULL;

    for(i=1;i<l;i++){


        now=root;

        child(i);
        }
}
void child(int i){

    struct node *temp;
        if (ar[i]<now->val){
            if (now->lchild==NULL){
                temp=malloc(sizeof(struct node));
                root->lchild=NULL;
                root->rchild=NULL;
                temp->val=ar[i];}
            else {
                now=now->lchild;
                child(i);}}
       else {

            if (now->rchild==NULL){

                temp=malloc(sizeof(struct node));
                root->lchild=NULL;
                root->rchild=NULL;
                temp->val=ar[i];}
            else {

                now=now->rchild;
                child(i);

        }
        }}
void preorder(struct node *root){
    printf("%d",root->val);
    preorder(root->lchild);
    preorder(root->rchild);
}

void main(){
    int l;
    printf("BINARY SEARCH TREE CREATION");
    printf("Enter the number of nodes in BInary Search Tree: ");
    scanf("%d",&l);
    create(l);
    inorder(start)


}
