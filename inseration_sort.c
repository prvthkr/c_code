// Online C compiler to run C program online
#include <stdio.h>

void swap(int *num1, int *num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void inseration_sort(int arr[], int size) {
    int i = 0, j = 0;
    
    for (i = 1; i < size - 1; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    // Write C code here
    inseration_sort(arr, size);
    printf("Sorted Arrary:");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;
}
