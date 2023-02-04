// Online C compiler to run C program online
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i = 0, j = 0, k = 0;
    
    int size1 = mid - left + 1;
    int size2 = right - mid;
    
    int left_arr[size1], right_arr[size2];
    
    for (i = 0; i < size1; i++) {
        left_arr[i] = arr[left + i];
    }
    
    for (j = 0; j < size2; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    while (i < size1 && j < size2) {
        if (left_arr[i] <= right_arr[j]) { // <= becuase of stability 
            arr[k++] = left_arr[i++];
        } else {
            arr[k++] = right_arr[j++];
        }
    }
    
    while (i < size1) {
        arr[k++] = left_arr[i++];
    }
    
    while (j < size2) {
        arr[k++] = right_arr[j++];
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    // Write C code here
    merge_sort(arr, 0, size - 1);
    printf("Sorted Arrary:");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;
}
