#include<conio.h>
#include<stdio.h>
int ar[50];
void create(n){
    int i,a;
    for(i=0;i<n;i++){
        printf("Enter the number to be stored at %d= ",i);
        scanf("%d",&a);
        ar[i]=a;}
}
void display(n){
    int i,a;
    printf("Array- ");
    for(i=0;i<n;i++){
            printf("%d ",ar[i]);}
}
void delet(int n){ //deletion//
    int ch,i,v,j,ne;
    printf("Which node do you wish to delete \n 1)Beginning node \n 2)Ending node \n 3)A Particular node \n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            for(i=1;i<=n;i++){
                ar[i-1]=ar[i];}
        break;
        case 2:
            ar[n-1]=NULL;
            break;
        case 3:
            printf("Which value do you wish to delete: ");
            scanf("%d",&j);
            for (i=0;i<n;i++){
                if (ar[i]==j){
                   for(ne=i;ne<n;ne++){
                        ar[ne]=ar[ne+1];
}}}}}
void traverse(n){ //traversal//
    int x=0;
    printf("Now the linked list is: \n");
while (x<n){
    printf("Index number %d- %d \n ",x,ar[x]);
    x++;}}

void insert(int n){ //insertion//

    int ch,i,v,l,j;
    printf("Where do you want to insert a node \n 1)In the beginning 2)In the ending 3)After a node \n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("Enter the value: ");
            scanf("%d",&v);
           for (i=n;i>0;i--){
            ar[i+1]=ar[i];}
           ar[0]=v;
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d",&v);
            ar[n+1]=v;
            break;
        case 3:
            printf("After what value do you wish to add: ");
            scanf("%d",&j);
            printf("Enter the value: ");
            scanf("%d",&v);
            for (i=0;i<n;i++){
                    if (j==ar[i]){
                        for (l=n;l>i;l--){
                            ar[l+1]=ar[l];}
                        ar[i+1]=v;
                    }
}}}
void main(){
    int l,c;
    printf("Enter the number of elements to be added in the Array");
    scanf("%d",&l);
    create(l);
    display(l);
    printf("\n");
        int p=0;
         while(p==0){
    printf("What operation do you wish to perform: \n 1)Insertion \n 2)Deletion \n 3)Traversal \n 4)End program \n");
    scanf("%d",&c);
    switch(c){
        case 1:
            insert(l);
            l++;
            display(l);
            break;
        case 2:
            delet(l);
             l--;
            display(l);
            break;
        case 3:
            traverse(l);
            break;
        case 4:
            p=1;}}
   }

