// Online C compiler to run C program online
#include <stdio.h>

void swap(int *num1, int *num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void selection_sort(int arr[], int size) {
    int min_idx = 0, i = 0, j = 0;
    
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[min_idx] > arr[j]) {
                swap(&arr[min_idx], &arr[j]);
            }
        }
    }
}

int main() {
    int arr[] = {5, 6, 3, 2, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    // Write C code here
    selection_sort(arr, size);
    printf("Sorted Arrary:");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;
}
