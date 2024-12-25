#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Define the structure for a node in the binary tree
struct node {
    struct node *preptr;  // Pointer to the left child
    int val;              // Value stored in the node
    struct node *nxtptr;  // Pointer to the right child
    struct node *parent;  // Pointer to the parent node
} *start;                 // Global pointer to the root node

int t = 0, h = 0;         // Variables to track depth (t) and height (h) of the tree
int arr[50];              // Array for potential use (currently unused in operations)
int *ar = arr;            // Pointer to the array

// Function to create the binary tree interactively
void create() {
    struct node *tmp, *now;
    int a, v, b;

    // Initialize the root node
    printf("Enter the Root Node Value: ");
    scanf("%d", &a);
    start = malloc(sizeof(struct node));
    start->val = a;
    start->preptr = NULL;
    start->nxtptr = NULL;
    now = start;

    int p = 0;
    while (p == 0) {
        // Menu-driven approach to construct the tree
        printf("\nChoose \n 1)Insert Left Child \n 2)Insert Right Child \n 3)Go to Left Child \n 4)Go to Right Child \n 5)Go to Parent \n 6)Go to Root \n 7)End process \n");
        scanf("%d", &b);
        switch (b) {
            case 1: // Insert left child
                t++;
                if (t > h) h++;
                tmp = malloc(sizeof(struct node));
                now->preptr = tmp;
                printf("Enter the value to be inserted here: ");
                scanf("%d", &v);
                tmp->val = v;
                tmp->nxtptr = NULL;
                tmp->preptr = NULL;
                tmp->parent = now;
                now = tmp;
                break;

            case 2: // Insert right child
                t++;
                if (t > h) h++;
                tmp = malloc(sizeof(struct node));
                now->nxtptr = tmp;
                printf("Enter the value to be inserted here: ");
                scanf("%d", &v);
                tmp->val = v;
                tmp->nxtptr = NULL;
                tmp->preptr = NULL;
                tmp->parent = now;
                now = tmp;
                break;

            case 3: // Move to left child
                t++;
                now = now->preptr;
                printf("You are now at %d", now->val);
                break;

            case 4: // Move to right child
                t++;
                now = now->nxtptr;
                printf("You are now at %d", now->val);
                break;

            case 5: // Move to parent
                t--;
                now = now->parent;
                printf("You are now at %d", now->val);
                break;

            case 6: // Move to root
                t = 0;
                now = start;
                printf("You are now at %d", now->val);
                break;

            case 7: // End process
                p = 1;
                break;
        }
    }
}

// Preorder traversal function
void preorder(struct node *start) {
    if (start == NULL) return;
    printf("%d ", start->val);        // Visit root
    preorder(start->preptr);          // Recursively traverse left subtree
    preorder(start->nxtptr);          // Recursively traverse right subtree
}

// Inorder traversal function
void inorder(struct node *start) {
    if (start == NULL) return;
    inorder(start->preptr);           // Recursively traverse left subtree
    printf("%d ", start->val);        // Visit root
    inorder(start->nxtptr);           // Recursively traverse right subtree
}

// Postorder traversal function
void postorder(struct node *start) {
    if (start == NULL) return;
    postorder(start->preptr);         // Recursively traverse left subtree
    postorder(start->nxtptr);         // Recursively traverse right subtree
    printf("%d ", start->val);        // Visit root
}

// Function to print leaf nodes
void leaf(struct node *start) {
    if (start == NULL) return;
    if (start->nxtptr == NULL && start->preptr == NULL) {
        printf("%d ", start->val);    // Print leaf node
    }
    leaf(start->preptr);              // Recursively check left subtree
    leaf(start->nxtptr);              // Recursively check right subtree
}

int tr = 0, tre = 0;                  // Track traversal depth
int he = 0, rhe = 0;                  // Track heights of paths

// Function to calculate the height of the tree using left-to-right traversal
void path(struct node *start) {
    if (start == NULL) {
        tr--;
        return;
    }
    tr++;
    if (tr > he) he = tr;             // Update maximum height
    path(start->preptr);              // Traverse left subtree
    path(start->nxtptr);              // Traverse right subtree
}

// Function to calculate height using right-to-left traversal
void rpath(struct node *start) {
    if (start == NULL) {
        tre--;
        return;
    }
    tre++;
    if (tre > rhe) rhe = tre;         // Update maximum height
    rpath(start->nxtptr);             // Traverse right subtree
    rpath(start->preptr);             // Traverse left subtree
}

// Main function
void main() {
    printf("BINARY TREE CREATION \n");
    create();                         // Create the binary tree

    // Perform and display different traversals
    printf("\nPRE-ORDER TRAVERSAL- ");
    preorder(start);

    printf("\nIN-ORDER TRAVERSAL- ");
    inorder(start);

    printf("\nPOST-ORDER TRAVERSAL- ");
    postorder(start);

    // Display the height of the tree
    printf("\nHeight of the tree is- %d \n", h + 1);

    // Display leaf nodes
    printf("Leaf nodes in the tree are- ");
    leaf(start);

    // Calculate and display the longest path in the tree
    path(start);
    rpath(start);
    printf("\nLongest Path of the tree is- %d", he + rhe);
}
