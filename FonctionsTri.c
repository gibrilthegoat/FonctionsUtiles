#include <stdio.h>

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

// Insertion Sort
void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Binary Search (array must be sorted)
int binary_search(int *arr, int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Print array
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[6] = {5, 2, 9, 1, 5, 6};
    int arr2[6] = {5, 2, 9, 1, 5, 6};
    int arr3[6] = {5, 2, 9, 1, 5, 6};

    bubble_sort(arr1, 6);
    printf("Bubble Sort: ");
    print_array(arr1, 6);

    selection_sort(arr2, 6);
    printf("Selection Sort: ");
    print_array(arr2, 6);

    insertion_sort(arr3, 6);
    printf("Insertion Sort: ");
    print_array(arr3, 6);

    int target = 5;
    int idx = binary_search(arr1, 6, target);
    if (idx != -1) printf("Found %d at index %d\n", target, idx);
    else printf("%d not found\n", target);

    return 0;
}
