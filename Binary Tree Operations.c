#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Structure for a node in the binary search tree
struct node {
    struct node *lptr;    // Pointer to the left child
    int val;              // Value stored in the node
    struct node *rptr;    // Pointer to the right child
    struct node *parent;  // Pointer to the parent node
} *start;

// Function to create the binary tree
void create() {
    int l, i, le, r;
    printf("Enter the number of elements in the binary tree- ");
    scanf("%d", &l);

    // Create the root node
    printf("Enter the value of the root of binary tree- ");
    scanf("%d", &r);
    start = malloc(sizeof(struct node));
    start->val = r;
    start->lptr = NULL;
    start->rptr = NULL;
    start->parent = NULL;

    // Insert remaining elements into the tree
    printf("Enter the numbers to be stored in the initial tree (Press enter after each number)- \n");
    for (i = 1; i < l; i++) {
        scanf("%d", &le);
        insert(le);
    }
}

// Function to insert a value into the binary search tree
void insert(int n) {
    struct node *temp, *now;
    int x = 1;

    now = start; // Start from the root
    temp = malloc(sizeof(struct node));
    temp->val = n;
    temp->lptr = NULL;
    temp->rptr = NULL;

    // Traverse the tree to find the correct position
    while (x != 2) {
        if (n < now->val) {  // Go to the left subtree
            if (now->lptr == NULL) {
                now->lptr = temp;  // Insert as the left child
                temp->parent = now;
                x++;
            } else {
                now = now->lptr;
            }
        } else {  // Go to the right subtree
            if (now->rptr == NULL) {
                now->rptr = temp;  // Insert as the right child
                temp->parent = now;
                x++;
            } else {
                now = now->rptr;
            }
        }
    }
}

// Function to delete a node from the binary search tree
void delet(struct node *start, int n) {
    struct node *temp, *mix, *loc;

    // Search for the node to be deleted
    loc = search(start, n);

    // If the node has no children
    if (loc->lptr == NULL && loc->rptr == NULL) {
        if (loc->parent->val > n) {
            loc->parent->lptr = NULL;
        } else {
            loc->parent->rptr = NULL;
        }
        free(loc);
        return;
    }

    // If the node has only one child
    if (loc->lptr == NULL || loc->rptr == NULL) {
        if (loc->lptr == NULL) {  // Only right child
            if (loc->parent->lptr == loc) {
                loc->parent->lptr = loc->rptr;
            } else {
                loc->parent->rptr = loc->rptr;
            }
        } else {  // Only left child
            if (loc->parent->rptr == loc) {
                loc->parent->rptr = loc->lptr;
            } else {
                loc->parent->lptr = loc->lptr;
            }
        }
        free(loc);
        return;
    }

    // If the node has two children
    if (loc->lptr != NULL && loc->rptr != NULL) {
        mix = minsearch(loc->rptr);  // Find the minimum value in the right subtree
        loc->val = mix->val;        // Replace the value
        delet(loc->rptr, mix->val); // Delete the node with the minimum value
    }
}

// Function to search for a node in the tree
struct node* search(struct node *start, int n) {
    while (start != NULL) {
        if (start->val == n) {
            printf("%d exists in the binary search tree \n", n);
            return start;
        }
        if (n < start->val) {
            start = start->lptr;  // Move to the left subtree
        } else {
            start = start->rptr;  // Move to the right subtree
        }
    }
    printf("The required element does not exist in the created binary search tree.\n");
    return NULL;
}

// Function to find the node with the minimum value in a subtree
struct node* minsearch(struct node *start) {
    struct node *mi = start;
    while (start != NULL) {
        if (start->val < mi->val) {
            mi = start;  // Update minimum node
        }
        start = start->lptr;  // Move to the left subtree
    }
    return mi;
}

// Function to perform inorder traversal
void inorder(struct node *start) {
    if (start == NULL) return;
    inorder(start->lptr);         // Traverse the left subtree
    printf("%d ", start->val);    // Print the current node
    inorder(start->rptr);         // Traverse the right subtree
}

// Main function
void main() {
    int le;
    struct node *loc;
    int c, y = 0;

    // Create the binary search tree
    create();
    printf("INORDER Traversal- ");
    inorder(start);

    // Menu-driven operations
    while (1) {
        printf("\nChoose the operation that you wish to perform: \n1)Insertion \n2)Deletion \n3)Search \n4)End Process\n");
        scanf("%d", &c);

        if (y == 1) {
            break;
        }

        switch (c) {
            case 1: // Insert a new element
                printf("Enter the element that is to be added- ");
                scanf("%d", &le);
                insert(le);
                printf("INORDER Traversal- ");
                inorder(start);
                y = 0;
                break;

            case 2: // Delete an element
                printf("Enter the element that is to be deleted- ");
                scanf("%d", &le);
                delet(start, le);
                printf("INORDER Traversal- ");
                inorder(start);
                y = 0;
                break;

            case 3: // Search for an element
                printf("Enter the element that is to be searched- ");
                scanf("%d", &le);
                loc = search(start, le);
                printf("INORDER Traversal- ");
                inorder(start);
                y = 0;
                break;

            case 4: // End process
                y++;
                break;
        }
    }
}
