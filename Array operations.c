#include<conio.h>
#include<stdio.h>

// Define an array to store elements
int ar[50];

// Function to create the array
void create(int n) {
    int i, a;
    for (i = 0; i < n; i++) {
        printf("Enter the number to be stored at index %d: ", i);
        scanf("%d", &a);
        ar[i] = a;  // Store the input number in the array
    }
}

// Function to display the elements of the array
void display(int n) {
    int i;
    printf("Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ar[i]);  // Print each element of the array
    }
}

// Function to delete an element from the array
void delet(int n) {
    int ch, i, j, ne;
    printf("Which node do you wish to delete? \n 1) Beginning node \n 2) Ending node \n 3) A Particular node \n");
    scanf("%d", &ch);
    switch (ch) {
        case 1:  // Deletion from the beginning
            for (i = 1; i < n; i++) {
                ar[i - 1] = ar[i];  // Shift elements to the left
            }
            break;
        case 2:  // Deletion from the end
            ar[n - 1] = 0;  // Remove the last element (set to 0)
            break;
        case 3:  // Deletion of a particular value
            printf("Which value do you wish to delete: ");
            scanf("%d", &j);
            for (i = 0; i < n; i++) {
                if (ar[i] == j) {
                    for (ne = i; ne < n - 1; ne++) {
                        ar[ne] = ar[ne + 1];  // Shift elements to the left
                    }
                    break;
                }
            }
    }
}

// Function to traverse the array and print its elements
void traverse(int n) {
    int x = 0;
    printf("Now the array is: \n");
    while (x < n) {
        printf("Index %d: %d\n", x, ar[x]);
        x++;
    }
}

// Function to insert an element into the array
void insert(int n) {
    int ch, i, v, l, j;
    printf("Where do you want to insert a node? \n 1) In the beginning \n 2) At the end \n 3) After a node \n");
    scanf("%d", &ch);
    switch (ch) {
        case 1:  // Insertion at the beginning
            printf("Enter the value: ");
            scanf("%d", &v);
            for (i = n; i > 0; i--) {
                ar[i] = ar[i - 1];  // Shift elements to the right
            }
            ar[0] = v;  // Insert the new value at index 0
            break;
        case 2:  // Insertion at the end
            printf("Enter the value: ");
            scanf("%d", &v);
            ar[n] = v;  // Add the value at the end of the array
            break;
        case 3:  // Insertion after a specific value
            printf("After what value do you wish to add: ");
            scanf("%d", &j);
            printf("Enter the value: ");
            scanf("%d", &v);
            for (i = 0; i < n; i++) {
                if (ar[i] == j) {
                    for (l = n; l > i; l--) {
                        ar[l] = ar[l - 1];  // Shift elements to the right
                    }
                    ar[i + 1] = v;  // Insert the new value after the specified value
                    break;
                }
            }
    }
}

// Main function to perform various operations on the array
void main() {
    int l, c;
    printf("Enter the number of elements to be added in the array: ");
    scanf("%d", &l);
    create(l);  // Initialize the array with elements
    display(l); // Display the array
    printf("\n");
    int p = 0;
    while (p == 0) {  // Menu-driven operations
        printf("What operation do you wish to perform? \n 1) Insertion \n 2) Deletion \n 3) Traversal \n 4) End program \n");
        scanf("%d", &c);
        switch (c) {
            case 1:
                insert(l);  // Insert an element
                l++;  // Increase the size of the array
                display(l); // Display the updated array
                break;
            case 2:
                delet(l);  // Delete an element
                l--;  // Decrease the size of the array
                display(l); // Display the updated array
                break;
            case 3:
                traverse(l);  // Traverse and print the array
                break;
            case 4:
                p = 1;  // Exit the loop and end the program
        }
    }
}
