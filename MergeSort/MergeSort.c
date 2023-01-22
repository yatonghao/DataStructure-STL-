#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Merge(int * arr, int left, int right){
    int mid = (left + right) / 2;
    int * tmp = (int*)malloc(sizeof(int) * (right - left + 1));
    int s1 = left;
    int s2 = mid + 1;
    int i = 0;
    while(s1 <= mid && s2 <= right) {
        if(arr[s1] < arr[s2]) {
            tmp[i++] = arr[s1++];
        }else {
            tmp[i++] = arr[s2++];
        }
    }
    while(s1<=mid) {
        tmp[i++] = arr[s1++];
    }
    while(s2<=right) {
        tmp[i++] = arr[s2++];
    }
    memcpy(arr+left,tmp,sizeof(int) * (right - left + 1));
    free(tmp);
}
void MergeSort(int * arr,int left,int right) {
    if(left >= right) return;
    int mid = (left + right) / 2;
    MergeSort(arr,left,mid);
    MergeSort(arr,mid + 1,right);
    Merge(arr,left,right);
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
    MergeSort(arr,0,size-1);
    print(arr,size);
    return 0;
}