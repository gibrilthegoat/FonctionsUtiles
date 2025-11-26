#include <stdio.h>

// Swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Increment each element of an array using pointer arithmetic
void increment_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) += 1;
    }
}

// Count how many values are greater than a threshold
int count_greater(int *arr, int size, int threshold) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) > threshold) {
            count++;
        }
    }
    return count;
}

// Return pointer to maximum element
int* find_max(int *arr, int size) {
    if (size <= 0) return NULL;

    int *max_ptr = arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *max_ptr) {
            max_ptr = arr + i;
        }
    }
    return max_ptr;
}

// Reverse an array in place using only pointers
void reverse(int *arr, int size) {
    int *left = arr;
    int *right = arr + size - 1;

    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

// Fill an array with values using a pointer
void fill_sequence(int *arr, int size, int start) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = start + i;
    }
}

// Demonstrate pointer-to-pointer (2D array simulation)
void fill_matrix(int **mat, int rows, int cols) {
    int value = 1;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            *(*(mat + r) + c) = value++;
        }
    }
}

int main() {
    int a = 10, b = 20;
    swap(&a, &b);
    printf("Swap: a=%d b=%d\n", a, b);

    int arr[5] = {1, 2, 3, 4, 5};
    increment_array(arr, 5);
    printf("Increment array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("Count > 3: %d\n", count_greater(arr, 5, 3));

    int *max_ptr = find_max(arr, 5);
    if (max_ptr) printf("Max value = %d\n", *max_ptr);

    reverse(arr, 5);
    printf("Reversed array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    fill_sequence(arr, 5, 100);
    printf("Sequence: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    // Matrix example using pointer-to-pointer
    int r1[3], r2[3], r3[3];
    int *matrix[3] = {r1, r2, r3};

    fill_matrix(matrix, 3, 3);
    printf("Matrix: \n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }

    return 0;
}
