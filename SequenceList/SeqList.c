#include "SeqList.h"

void SeqListInit(SeqList* ps) {
    assert(ps);
    ps->a = NULL;
    ps->capacity = ps->size = 0;
}

void SeqListDestroy(SeqList* ps) {
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->size = 0;
}

void SeqListPrint(SeqList* ps) {
    assert(ps);
    for(int i = 0; i < ps->size; i++) {
        printf("%d ",ps->a[i]);
    }
    printf("\n");
}
void CheckCapacity(SeqList* ps) {
    assert(ps);
    if(ps->size == ps->capacity) {
        size_t newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        SLDateType* ptr = (SLDateType*)realloc(ps->a,sizeof(SLDateType) * newCapacity);
        if(ptr == NULL) {
            perror("CheckCapacity");
            return;
        }
        ps->a = ptr;
        ps->capacity = newCapacity;
    }
}
void SeqListPushBack(SeqList* ps, SLDateType x) {
    assert(ps);
    CheckCapacity(ps);
    ps->a[ps->size] = x;
    ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDateType x) {
    assert(ps);
    CheckCapacity(ps);
    int i = 0;
    size_t end = ps->size;
    while(end > 0) {
        ps->a[end] = ps->a[end - 1];
        end--;
    }
    ps->a[0] = x;
    ps->size++;
}

void SeqListPopFront(SeqList* ps) {
    assert(ps);
    assert(ps->size > 0);
    int i = 0;
    for(i = 0; i < ps->size - 1; i++) {
        ps->a[i] = ps->a[i + 1];
    }
    ps->size--;
}
void SeqListPopBack(SeqList* ps) {
    assert(ps);
    assert(ps->size > 0);
    ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x) {
    assert(ps);
    int i = 0;
    for(; i < ps->size; i++) {
        if(ps->a[i] == x) {
            return i;
        }
    }
    return -1;
}

void SeqListInsert(SeqList* ps, size_t pos, SLDateType x) {
    assert(ps);
    assert(pos >= 0 && pos <= ps->size );
    CheckCapacity(ps);
    size_t end = ps->size;
    while(end > pos) {
        ps->a[end] = ps->a[end - 1];
        end--;
    }
    ps->a[pos] = x;
    ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos) {
    assert(ps);
    assert(pos >= 0 && pos < ps->size);
    size_t start = pos;
    while(start < ps->size - 1) {
        ps->a[start] = ps->a[start + 1];
        start++;
    }
    ps->size--;
}