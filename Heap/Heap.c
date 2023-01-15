#include "Heap.h"

void HeapPrint(HP* php) {
    assert(php);
    int i = 0;
    for(; i < php->size; i++) {
        printf("%d ",php->a[i]);
    }
    printf("\n");
}
void HeapInit(HP* php) {
    assert(php);
    php->a = NULL;
    php->size = php->capacity = 0;
}
void HeapDestroy(HP* php) {
    assert(php);
    free(php->a);
    php->a = NULL;
    php->size = php->capacity = 0;
}
void swp(HPDataType * s1, HPDataType * s2) {
    
    HPDataType tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
    
}
void shiftUp(HP * php, int child) {
    int parent = (child - 1) / 2;
    while(child > 0) {
        if(php->a[child] < php->a[parent]) {
            swp(&php->a[child], &php->a[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }else {
            break;
        }
    }
}
void HeapPush(HP* php, HPDataType x) {
    assert(php);
    if(php->size == php->capacity) {
        int newCapacity = php->capacity == 0 ? 4 : 2* php->capacity;
        HPDataType* tmp = (HPDataType*)realloc(php->a,newCapacity * sizeof(HPDataType));
        assert(tmp);
        php->a = tmp;
        php->capacity = newCapacity;
    }
    php->a[php->size] = x;
    php->size++;
    shiftUp(php,php->size-1);
}
bool HeapEmpty(HP* php) {
    assert(php);
    return php->size == 0;
}
void shiftDown(HP* php, int size, int parent) {
    assert(php);
    int minchild = 2 * parent + 1;
    while(minchild < size) {
        if((minchild + 1) < size && php->a[minchild + 1] < php->a[minchild]) {
            minchild++;
        }
        if(php->a[parent] > php->a[minchild]) {
            swp(&php->a[parent],&php->a[minchild]);
            parent = minchild;
            minchild = 2*parent + 1;
        }else {
            break;
        }
    }
}
void HeapPop(HP* php) {
    assert(php);
    assert(!HeapEmpty(php));
    swp(&php->a[0],&php->a[php->size-1]);
    php->size--;
    shiftDown(php,php->size,0);
}
HPDataType HeapTop(HP* php) {
    assert(php);
    return php->a[0];
}
int HeapSize(HP* php) {
    assert(php);
    return php->size;
}