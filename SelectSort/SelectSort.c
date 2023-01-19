#include <stdio.h>

void SelectSort(int * arr,int length) {
    int i = 0;
    for(; i < length - 1; i++) {
        int j = i + 1;
        int min = i;
        for(; j < length; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
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
    int arr[] = {5,7,2,9,3,8,1,0};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(arr,size);
    SelectSort(arr,size);
    print(arr,size);
    return 0;
}