#include <stdio.h>

void swp(int * s1, int * s2) {
    int tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}
void shiftDown(int * arr, int length, int parent) {
    int child = 2 * parent + 1;
    while(child < length) {
        if((child + 1) < length && arr[child + 1] > arr[child]) {
            child++;
        }
        if(arr[parent] < arr[child]) {
            swp(&arr[parent], &arr[child]);
            parent = child;
            child = 2 * parent + 1;
        }else {
            break;
        }
    }
}
void HeapSort(int * arr, int length) {
    int parent = 0;
    for(parent = (length - 1 -1) / 2; parent >= 0; parent--) {
        shiftDown(arr,length, parent);
    }
    int i = 1;
    while(i < length) {
        swp(&arr[0], &arr[length - i]);
        shiftDown(arr,length-i,0);
        i++;
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
    HeapSort(arr,size);
    print(arr,size);
    return 0;
}