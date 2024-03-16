#include <stdio.h>
#include<conio.h>
void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void heapSort(int arr[], int size);

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;}

int main() {
    int choice, i, size,x=1;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int arr[100];
    printf("Enter the elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);}
    while(x==1){
    printf("\nSorting Options:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Heap Sort\n");
    printf("4. End Program\n");
    printf("5. Insert an Element\n");
    printf("Enter your choice: ");
        scanf("%d", &choice);
    switch (choice) {
        case 1:
            bubbleSort(arr, size);
            printf("\nBubble Sort Result:\n");
            for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);}
    printf("\n");
            break;
        case 2:
            insertionSort(arr, size);
            printf("\nInsertion Sort Result:\n");
            for (i = 0; i < size; i++) {
                printf("%d ", arr[i]);}
                    printf("\n");
            break;
        case 3:
            heapSort(arr, size);
            printf("\nHeap Sort Result:\n");
            for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);}
    printf("\n");
            break;
        case 4:
            x=2;
            break;
        case 5:
            printf("Enter the new element: ");
            scanf("%d",&arr[size]);
            size++;
            insertionSort(arr, size);
            printf("\nInsertion Sort Result:\n");
            for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);}
    printf("\n");
            break;
        default:
            printf("Invalid choice!\n");
            return 0;}}}

// Bubble Sort
void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);}}}}

// Insertion Sort
void insertionSort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;}
        arr[j + 1] = key;}}

// Heap Sort
void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] > arr[largest]) {
        largest = left;}
    if (right < size && arr[right] > arr[largest]) {
        largest = right;}
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);}
}

void heapSort(int arr[], int size) {
    int i;
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);}
    for (i = size - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);}
}
