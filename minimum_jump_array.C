// Online C compiler to run C program online
#include <stdio.h>

int min_step(int arr[], int size) {
    
    int step = 0;
    int max_val = 0;
    
    if (arr[0] >= size) {
        return 1;
    }
    
    if (arr[0] == 0) {
        return -1;
    }
    int prev = 0, l = 0;
    for (int i = 0; i < size; (i += prev)) {
        prev = arr[i];
        if (prev == 0) {
            step = -1;
            break;
        }
        max_val = arr[i + l];
        l++;
        if(l > 0) {
            l = 1;
        }
        for (int j = 1; j <= arr[i]; j++) {
            if (arr[i + j] > max_val) {
                max_val = arr[i + j];
            }
        }
        step++;
        if ((i + max_val) > size) {
            //step++;
            break;
        }
    }
    return step;
}

int main() {
    int arr[] = {1, 1, 9, 1, 1, 1, 9, 1, 1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    // Write C code here
    printf("Hello world: %d\n", min_step(arr, size));

    return 0;
}
