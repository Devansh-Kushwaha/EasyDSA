#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct node {
    struct node *preptr; // Pointer to the previous node
    int val;             // Value stored in the node
    struct node *nxtptr; // Pointer to the next node
};

// Define the structure for a queue
struct queue {
    int rear;          // Rear index for the queue
    int capacity;      // Maximum capacity of the queue
    int front;         // Front index for the queue
    struct node *frontptr; // Pointer to the front node
    struct node *rearptr;  // Pointer to the rear node
} *q;

// Function to initialize and create the queue
void createq(struct queue *q) {
    int c;
    printf("Enter the capacity of the queue- ");
    scanf("%d", &c);
    q->capacity = c;      // Set the capacity
    q->rear = -1;         // Initialize rear index
    q->front = -1;        // Initialize front index
    q->frontptr = malloc(sizeof(struct node)); // Allocate memory for the front node
    q->rearptr = malloc(sizeof(struct node));  // Allocate memory for the rear node
}

// Function to check if the queue is full
int isfullq(struct queue *q) {
    if (q->rear - q->front + 1 == q->capacity) {
        return 1; // Queue is full
    } else {
        return 0; // Queue is not full
    }
}

// Function to check if the queue is empty
int isemptyq(struct queue *q) {
    if (q->front == q->rear && q->rear == -1) {
        return 1; // Queue is empty
    } else {
        return 0; // Queue is not empty
    }
}

// Function to add an element to the queue
void enqueue() {
    int e, w;
    w = isfullq(q); // Check if the queue is full
    struct node *temp;

    if (w == 0) { // If the queue is not full
        temp = malloc(sizeof(struct node)); // Allocate memory for the new node

        if (q->front == q->rear && q->rear == -1) { // If the queue is initially empty
            q->front = 0;
            q->frontptr = temp; // Set the front pointer to the new node
        }

        printf("Enter the element to be added into the queue- ");
        scanf("%d", &e);

        q->rear = (q->rear + 1) % q->capacity; // Update the rear index
        (q->rearptr)->nxtptr = temp;          // Link the current rear to the new node
        temp->preptr = q->rearptr;            // Set the previous pointer of the new node
        temp->val = e;                        // Store the value in the new node
        temp->nxtptr = NULL;                  // Set the next pointer to NULL
        q->rearptr = temp;                    // Update the rear pointer
    } else {
        printf("\n The queue is full \n"); // If the queue is full
    }
}

// Function to remove an element from the queue
int dequeue() {
    int w = isemptyq(q); // Check if the queue is empty
    if (w == 0) {        // If the queue is not empty
        int e;
        e = q->frontptr->val; // Get the value from the front of the queue
        printf("Dequeued value is %d", e);

        q->front = (q->front + 1) % q->capacity; // Update the front index
        q->frontptr = q->frontptr->nxtptr;      // Move the front pointer to the next node

        if (q->front > q->rear) { // If the queue becomes empty after the operation
            q->front = -1;
            q->rear = -1;
        }
        return e; // Return the dequeued value
    } else {
        printf("\n The queue is empty \n"); // If the queue is empty
    }
}

// Function to traverse and print the queue
void traverseq(struct queue *q) {
    struct node *show = q->frontptr; // Start from the front pointer
    if (!(q->rear == -1)) {          // If the queue is not empty
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", show->val); // Print each node's value
            show = show->nxtptr;     // Move to the next node
        }
    }
}

// Main function to execute the program
void main() {
    int c = 0, d = 0; // Variables for menu and loop control
    q = malloc(sizeof(struct queue)); // Allocate memory for the queue
    createq(q); // Create the queue

    // Menu-driven loop for queue operations
    while (d == 0) {
        printf("\n What operation do you wish to perform- \n 1)Enqueue \n 2)Dequeue \n 3)Traversal \n 4)End Program \n");
        scanf("%d", &c);

        switch (c) {
            case 1: // Enqueue operation
                enqueue();
                printf("Now, the queue is- ");
                traverseq(q);
                break;

            case 2: // Dequeue operation
                dequeue();
                printf("\n Now, the queue is- ");
                traverseq(q);
                break;

            case 3: // Traversal
                printf("The queue is- ");
                traverseq(q);
                break;

            case 4: // Exit program
                d = 1;
                break;

            default: // Invalid input
                printf("Invalid choice! Please try again.\n");
        }
    }
}
