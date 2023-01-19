#include <stdio.h>

void swp(int * s1, int * s2) {
    int tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void BubbleSort(int * arr, int length) {
    int i = 0; 
    for(; i < length - 1; i++) {
        int j = 0;
        for(; j < length - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                swp(&arr[j],&arr[j+1]);
            }
        }
    }
}

void print(int * arr, int size) {
    int i = 0;
    for(; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {5,7,2,9,3,8,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(arr,size);
    BubbleSort(arr,size);
    print(arr,size);
    return 0;
}