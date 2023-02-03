/* Online C Compiler and Editor */
#include <stdio.h>

void alternate_print(int arr1[], int sz1, int arr2[], int sz2, int arr[]) {
    int i = 0, j = 0, k = 0;
    
    j = sz2;
    while(i < sz1 && j > 0) {
        arr[k++] = arr2[j - 1];
        --j;
        arr[k++] = arr1[i++];
    }
    
    while(i < sz1) {
        arr[k++] = arr1[i++];
    }
    
    while(j > 0) {
        arr[k++] = arr1[j - 1];
        --j;
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {1, 2, 3, 4};
    
    int sz1 = sizeof(arr1) / sizeof(arr1[0]);
    int sz2 = sizeof(arr2) / sizeof(arr2[0]); 
    
    int arr[sz1 + sz2];

    alternate_print(arr1, sz1, arr2, sz2, arr);
    for(int i = 0; i < (sz1 + sz2); i++) {
        printf("%d, ", arr[i]);
    }

    return 0;
}
