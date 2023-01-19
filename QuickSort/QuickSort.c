#include <stdio.h>
#include "Stack.h"
int Quick(int* arr,int left, int right) {
    int base = arr[left];
    while(left < right) {
        while(left < right && arr[right] >= base) {
            right--;
        }
        arr[left] = arr[right];
        while(left < right && arr[left] <= base) {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = base;
    return left;
}
void QuickSort(int * arr,int left , int right) {
    if(left >= right) return;
    int base = Quick(arr,left,right);
    QuickSort(arr,left, base);
    QuickSort(arr,base + 1 ,right);
}
void QuickSortNonR(int* arr, int left, int right) {
    ST stack;
    StackInit(&stack);
    StackPush(&stack,left);
    StackPush(&stack,right);
    while(!StackEmpty(&stack)) {
        int end = StackTop(&stack);
        StackPop(&stack);
        int start = StackTop(&stack);
        StackPop(&stack);
        int key = Quick(arr,start,end);
        if(start < key - 1) {
            StackPush(&stack,start);
            StackPush(&stack,key - 1);
        }
        if(key + 1 < end) {
            StackPush(&stack,key + 1);
            StackPush(&stack,end);
        }
    }
    StackDestroy(&stack); 

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
    QuickSortNonR(arr, 0, size-1);
    print(arr,size);
    return 0;
}