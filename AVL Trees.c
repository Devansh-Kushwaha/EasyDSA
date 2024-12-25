#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

// Definition of the node structure
struct node {
    struct node *lptr;  // Pointer to the left child
    int val;            // Value of the node
    int bf;             // Balance factor
    int lh;             // Height of the left subtree
    int rh;             // Height of the right subtree
    struct node *rptr;  // Pointer to the right child
    struct node *parent; // Pointer to the parent node
} *start, *gstart;       // Global pointers for tree root and parent placeholder

// Function to create the root of the binary tree
void create() {
    int r;
    printf("Enter the value of the root of binary tree- ");
    scanf("%d", &r);

    // Allocating memory for the root and its parent placeholder
    start = malloc(sizeof(struct node));
    gstart = malloc(sizeof(struct node));

    // Initializing the root node
    start->bf = 0;
    start->lh = 0;
    start->rh = 0;
    start->val = r;
    start->lptr = NULL;
    start->rptr = NULL;
    start->parent = gstart;

    // Connecting the root to the parent placeholder
    gstart->lptr = start;
}

// Function to insert a new value into the binary tree
void insert(int n) {
    struct node *temp, *now;
    int x = 1;
    now = start;

    // Allocating memory for the new node
    temp = malloc(sizeof(struct node));
    temp->val = n;
    temp->lptr = NULL;
    temp->rptr = NULL;

    // Traversing the tree to find the correct position for insertion
    while (x != 2) {
        if (n < (now->val)) {  // Navigate left if the value is smaller
            now->lh++;         // Update left height
            now->bf = now->lh - now->rh; // Update balance factor

            if (now->lptr == NULL) { // Insert at the left child position
                now->lptr = temp;
                temp->parent = now;
                x++;
            } else {
                now = now->lptr; // Continue traversing left
            }
        } else {                // Navigate right if the value is greater
            now->rh++;         // Update right height
            now->bf = now->lh - now->rh; // Update balance factor

            if (now->rptr == NULL) { // Insert at the right child position
                now->rptr = temp;
                temp->parent = now;
                x++;
            } else {
                now = now->rptr; // Continue traversing right
            }
        }
    }
}

// Function for inorder traversal (Left-Root-Right)
void inorder(struct node *start) {
    if (start == NULL) return; // Base case
    inorder(start->lptr);      // Recurse on the left child
    printf("%d ", start->val); // Print the current node's value
    inorder(start->rptr);      // Recurse on the right child
}

// Function to balance the binary tree
void balance(struct node *start) {
    if (start == NULL) return; // Base case

    inorder(start->lptr); // Recurse on the left child

    // Check if the tree is unbalanced
    if (start->bf < -1 || start->bf > 1) {
        // Perform the appropriate rotations
        if (start->bf == -2 && start->rptr->bf == -1) {
            // Right-Right Case: Single Left Rotation
            // (Insert logic for left rotation)
        } else if (start->bf == 2 && start->lptr->bf == 1) {
            // Left-Left Case: Single Right Rotation
            // (Insert logic for right rotation)
        } else if (start->bf == -2 && start->rptr->bf == 1) {
            // Right-Left Case: Double Rotation (Right-Left)
            // (Insert logic for right-left rotation)
        } else if (start->bf == 2 && start->lptr->bf == -1) {
            // Left-Right Case: Double Rotation (Left-Right)
            // (Insert logic for left-right rotation)
        }
    }

    inorder(start->rptr); // Recurse on the right child
}

// Function to search for a value in the binary tree
int search(struct node *start, int n) {
    while (1) {
        if (start->val == n) { // Value found
            printf("%d exists in the binary search tree \n", n);
            return (int)start; // Return the address of the node
        } else if (n < start->val) { // Navigate left
            if (start->lptr == NULL) {
                printf("The required element does not exist in the created binary search tree.");
                return NULL;
            }
            start = start->lptr;
        } else { // Navigate right
            if (start->rptr == NULL) {
                printf("The required element does not exist in the created binary search tree.");
                return NULL;
            }
            start = start->rptr;
        }
    }
}

// Function to find the node with the minimum value in a subtree
int minsearch(struct node *start) {
    struct node *mi = start;
    while (start != NULL) {
        if (start->val < mi->val) {
            mi = start;
        }
        start = start->lptr;
    }
    return (int)mi;
}

// Function to delete a node from the binary tree
void delet(struct node *start, int n) {
    struct node *loc = search(start, n); // Find the node to delete

    if (loc == NULL) return; // Node not found

    if (loc->lptr == NULL && loc->rptr == NULL) {
        // Case 1: Node is a leaf
        if (loc->parent->lptr == loc) {
            loc->parent->lptr = NULL;
        } else {
            loc->parent->rptr = NULL;
        }
        free(loc);
    } else if (loc->lptr == NULL || loc->rptr == NULL) {
        // Case 2: Node has one child
        struct node *child = (loc->lptr != NULL) ? loc->lptr : loc->rptr;
        if (loc->parent->lptr == loc) {
            loc->parent->lptr = child;
        } else {
            loc->parent->rptr = child;
        }
        child->parent = loc->parent;
        free(loc);
    } else {
        // Case 3: Node has two children
        struct node *successor = (struct node *)minsearch(loc->rptr);
        loc->val = successor->val;
        delet(successor, successor->val); // Recursively delete successor
    }
}

// Main function
void main() {
    int le, c, y = 0;
    create(); // Create the root node
    inorder(start);

    while (1) {
        printf("\nChoose the operation: 1) Insertion 2) Deletion 3) End Process- ");
        scanf("%d", &c);

        if (c == 3) break; // Exit loop

        switch (c) {
            case 1:
                printf("Enter the element to be added- ");
                scanf("%d", &le);
                insert(le);
                balance(gstart->lptr);
                printf("INORDER Traversal- ");
                inorder(gstart->lptr);
                break;

            case 2:
                printf("Enter the element to be deleted- ");
                scanf("%d", &le);
                delet(start, le);
                balance(gstart->lptr);
                printf("INORDER Traversal- ");
                inorder(start);
                break;
        }
    }
}
