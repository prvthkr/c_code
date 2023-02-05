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

int dublicate_array(int arr[], int size) {
    int tmp = 0, res = 0;

    merge_sort(arr, 0, size - 1);
    for (int i = 0; i < size;) {
        tmp = arr[i];
        for (int j = i; j < size; j++) {
            if (tmp == arr[j]) {
                res += 1;
                continue;
            }
            i = j;
            break;
        }
        if (i == size - 1) {
            i++;
        }
        if (res > 1) {
            return res;
        } else {
            res = 0;
        }
    }
    
    return -1;
}

int main() {
    int arr[] = {1, 1, 13, 1, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("dublicate = %d \n", dublicate_array(arr, size));   
    return 0;
}
