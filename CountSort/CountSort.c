#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void CountSort(int * arr,int length) {
    int max = arr[0];
    int min = arr[0];
    int i = 0;
    for(; i < length; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    int * tmp = (int*)malloc(sizeof(int) * (max - min + 1));
    memset(tmp,0,sizeof(int) * (max - min + 1));
    i = 0;
    for(; i < length; i++) {
        tmp[arr[i] - min]++;
    }
    i = 0;
    int j = 0;
    for(; i < (max - min + 1); i++) {
        while(tmp[i] != 0) {
            arr[j++] = i + min;
            tmp[i]--;
        }
    }
    free(tmp);

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
    CountSort(arr,size);
    print(arr,size);
    return 0;
}