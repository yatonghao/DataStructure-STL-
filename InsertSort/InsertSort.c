#include <stdio.h>

void InsertSort(int * arr,int length) {
    int i = 1;
    for(; i < length; i++) {
        int j = 0;
        int tmp = arr[i];
        for(j = i - 1; j >= 0; j--) {
            if(tmp < arr[j]) {
                arr[j+1] = arr[j];
            }else {
                break;
            }
        }
        arr[j + 1] = tmp;
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
    InsertSort(arr,size);
    print(arr,size);
    return 0;
}