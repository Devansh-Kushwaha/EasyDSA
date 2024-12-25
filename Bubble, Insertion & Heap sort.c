#include <stdio.h>
#include <conio.h>

// Function prototypes for sorting algorithms
void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void heapSort(int arr[], int size);

// Utility function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int choice, i, size, x = 1;

    // Input the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[100]; // Array to store elements (maximum size 100)

    // Input the elements of the array
    printf("Enter the elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Loop for menu-driven sorting options
    while (x == 1) {
        printf("\nSorting Options:\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Heap Sort\n");
        printf("4. End Program\n");
        printf("5. Insert an Element\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on the choice
        switch (choice) {
            case 1: // Bubble Sort
                bubbleSort(arr, size);
                printf("\nBubble Sort Result:\n");
                for (i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2: // Insertion Sort
                insertionSort(arr, size);
                printf("\nInsertion Sort Result:\n");
                for (i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3: // Heap Sort
                heapSort(arr, size);
                printf("\nHeap Sort Result:\n");
                for (i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4: // End program
                x = 2; // Exit the loop
                break;

            case 5: // Insert a new element and sort the array
                printf("Enter the new element: ");
                scanf("%d", &arr[size]); // Insert at the end of the array
                size++; // Increase the size of the array
                insertionSort(arr, size); // Sort the array after insertion
                printf("\nInsertion Sort Result:\n");
                for (i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            default: // Invalid choice
                printf("Invalid choice!\n");
                return 0;
        }
    }
}

// Bubble Sort: Repeatedly swaps adjacent elements if they are in the wrong order
void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) { // Outer loop for passes
        for (j = 0; j < size - i - 1; j++) { // Inner loop for comparisons
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]); // Swap if elements are out of order
            }
        }
    }
}

// Insertion Sort: Builds the sorted array one element at a time
void insertionSort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) { // Start from the second element
        key = arr[i]; // Key is the element to be inserted
        j = i - 1;
        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insert key into its correct position
    }
}

// Heapify: Maintains the heap property for the subtree rooted at index i
void heapify(int arr[], int size, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if left child is larger than root
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child is larger than the largest so far
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and recursively heapify the affected subtree
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

// Heap Sort: Sorts the array using the heap data structure
void heapSort(int arr[], int size) {
    int i;

    // Build the max heap
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    // Extract elements from the heap one by one
    for (i = size - 1; i >= 0; i--) {
        // Move current root to the end
        swap(&arr[0], &arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
