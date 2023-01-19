#include <stdio.h>
void Shell(int * arr, int length, int gap) {
    int i = gap;
    for(; i < length; i++) {
        int j = 0;
        int tmp = arr[i];
        for(j = i - gap; j >= 0; j -= gap) {
            if(tmp < arr[j]) {
                arr[j+gap] = arr[j];
            }else {
                break;
            }
        }
        arr[j + gap] = tmp;
    }
}
void ShellSort(int * arr,int length) {
    int gap = length;
    while(gap>0) {
        Shell(arr,length,gap);
        gap /= 2;
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
    ShellSort(arr,size);
    print(arr,size);
    return 0;
}