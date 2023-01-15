#include "List.h"

LTNode* ListInit() {
    LTNode* guard = (LTNode*)malloc(sizeof(LTNode));
    assert(guard);
    guard->next = guard;
    guard->prev = guard;
    return guard;
}

void ListDestory(LTNode* phead) {
    LTNode * cur = phead;
    while(cur != phead) {
        LTNode *next = cur->next;
        free(cur);
        cur = next;
    }
    free(phead);
}

void ListPrint(LTNode* phead) {
    printf("phead<>");
    LTNode * cur = phead->next;
    while(cur != phead) {
        printf("%d<>",cur->data);
        cur = cur->next;
    }
    printf("\n");
}
LTNode * BuyNode(LTDataType x) {
    LTNode* newNode = (LTNode *)malloc(sizeof(LTNode));
    assert(newNode);
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = x;
    return newNode;
}
void ListPushBack(LTNode* phead, LTDataType x) {
    LTNode *newNode = BuyNode(x);
    
    newNode->prev = phead->prev;
    phead->prev->next = newNode;
    newNode->next = phead;
    phead->prev = newNode;
}

void ListPushFront(LTNode* phead, LTDataType x) {
    LTNode *newNode = BuyNode(x);
    LTNode * first = phead->next;
    newNode->next = first;
    first->prev = newNode;
    phead->next = newNode;
    newNode->prev = phead;
}
bool ListEmpty(LTNode* phead) {
    return phead->next == phead;
}
void ListPopBack(LTNode* phead) {
    assert(!ListEmpty(phead));
    LTNode * tail = phead->prev;
    tail->prev->next = phead;
    phead->prev = tail->prev;
    free(tail);
    tail = NULL;
}

void ListPopFront(LTNode* phead) {
    assert(!ListEmpty(phead));
    LTNode *first = phead->next;
    LTNode *second = first->next;
    phead->next = second;
    second->prev = phead;
    free(first);
    first = NULL;
}
size_t ListSize(LTNode* phead) {
    size_t count  = 0;
    LTNode *cur = phead->next;
    while(cur != phead){
        count++;
        cur = cur->next;
    }
    return count;
}

LTNode* ListFind(LTNode* phead, LTDataType x){
    LTNode *cur = phead->next;
    while(cur != phead) {
        if(cur->data == x) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
void ListInsert(LTNode* pos, LTDataType x) {
    assert(pos);
    LTNode * newNode = BuyNode(x);
    LTNode * prev = pos->prev;
    prev->next = newNode;
    newNode->prev = prev;
    newNode->next = pos;
    pos->prev = newNode;
}
void ListErase(LTNode* pos) {
    assert(pos);
    LTNode *prev = pos->prev;
    prev->next = pos->next;
    pos->next->prev = prev;
    free(pos);
    pos = NULL;
}