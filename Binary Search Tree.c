#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

// Define a structure for a node in the binary search tree
struct node {
    struct node *lchild; // Pointer to the left child
    int val;             // Value of the node
    struct node *rchild; // Pointer to the right child
} *root, *now;           // Global pointers to the root and current node

int ar[50]; // Array to hold the values to be inserted into the tree

// Function to create the binary search tree
void create(int l) {
    int i, q;

    // Input values to be inserted into the tree
    for (i = 0; i < l; i++) {
        printf("Enter %d number: ", i);
        scanf("%d", &q);
        ar[i] = q;
    }

    // Initialize the root node
    root = malloc(sizeof(struct node));
    root->val = ar[0];    // Assign the first value from the array to the root
    root->lchild = NULL;  // No left child initially
    root->rchild = NULL;  // No right child initially

    // Insert remaining elements into the tree
    for (i = 1; i < l; i++) {
        now = root;       // Start from the root for each new value
        child(i);         // Insert the value at the correct position
    }
}

// Function to recursively find the correct position for a node
void child(int i) {
    struct node *temp;

    // If the current value is less than the current node's value
    if (ar[i] < now->val) {
        // If the left child is NULL, create a new node
        if (now->lchild == NULL) {
            temp = malloc(sizeof(struct node));
            temp->lchild = NULL;  // Initialize left child
            temp->rchild = NULL;  // Initialize right child
            temp->val = ar[i];    // Assign value to the new node
            now->lchild = temp;   // Link the new node as the left child
        } else {
            now = now->lchild;    // Move to the left child
            child(i);             // Recursively find the position
        }
    } else { // If the current value is greater than or equal to the current node's value
        // If the right child is NULL, create a new node
        if (now->rchild == NULL) {
            temp = malloc(sizeof(struct node));
            temp->lchild = NULL;  // Initialize left child
            temp->rchild = NULL;  // Initialize right child
            temp->val = ar[i];    // Assign value to the new node
            now->rchild = temp;   // Link the new node as the right child
        } else {
            now = now->rchild;    // Move to the right child
            child(i);             // Recursively find the position
        }
    }
}

// Function to perform a preorder traversal of the tree
void preorder(struct node *root) {
    if (root == NULL) return;      // Base case: if the node is NULL, return
    printf("%d ", root->val);      // Visit the root node
    preorder(root->lchild);        // Recursively traverse the left subtree
    preorder(root->rchild);        // Recursively traverse the right subtree
}

void main() {
    int l;

    // Prompt the user to enter the number of nodes
    printf("BINARY SEARCH TREE CREATION\n");
    printf("Enter the number of nodes in Binary Search Tree: ");
    scanf("%d", &l);

    // Create the binary search tree
    create(l);

    // Perform a preorder traversal and display the result
    printf("Preorder Traversal: ");
    preorder(root);
}
