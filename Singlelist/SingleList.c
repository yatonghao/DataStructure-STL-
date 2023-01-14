#include "SinglelList.h"

SLTNode* BuySLTNode(SLTDataType x) {
    SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
    assert(node);
    node->data = x;
    node->next = NULL;
    return node;
}

void SListPrint(SLTNode* phead) {
    SLTNode* cur = phead;
    while(cur != NULL) {
        printf("%d->",cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void SListDestory(SLTNode** pphead) {
    assert(pphead);
    SLTNode * cur = *pphead;
    while(cur != NULL) {
        SLTNode * next = cur->next;
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}

void SListPushFront(SLTNode** pphead, SLTDataType x) {
    assert(pphead);
    SLTNode* newNode = BuySLTNode(x);
    newNode->next = *pphead;
    *pphead = newNode;
}

void SListPushBack(SLTNode** pphead, SLTDataType x) {
    assert(pphead);
    SLTNode * newNode = BuySLTNode(x);
    if(*pphead == NULL) {
        *pphead = newNode;
        return;
    }
    SLTNode * cur = *pphead;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
}

void SListPopBack(SLTNode** pphead) {
    assert(pphead);
    assert(*pphead);
    SLTNode* cur = *pphead;
    if(cur->next == NULL) {
        free(*pphead);
        *pphead = NULL;
        return;
    }
    while(cur->next->next != NULL) {
        cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL;
}

void SListPopFront(SLTNode** pphead) {
    assert(pphead);
    assert(*pphead);
    SLTNode * first = *pphead;
    *pphead = (*pphead)->next;
    free(first);
    first = NULL;
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x) {
    assert(phead);
    SLTNode * cur = phead;
    while(cur) {
        if(cur->data == x) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
    assert(pphead);
    assert(pos);
    
    if(*pphead == pos) {
        SListPushFront(pphead,x);
        return;
    }
    SLTNode * cur = *pphead;
    while(cur->next != pos) {
        cur = cur->next;
        assert(cur);
    }
    SLTNode * newNode = BuySLTNode(x);
    newNode->next = pos;
    cur->next = newNode;
}

void SListInsertAfter(SLTNode* pos, SLTDataType x) {
    assert(pos);
    SLTNode *  newNode = BuySLTNode(x);
    newNode->next = pos->next;
    pos->next = newNode;
}

void SListErase(SLTNode** pphead, SLTNode* pos) {
    assert(pphead);
    assert(*pphead);
    assert(pos);
    if(*pphead == pos) {
        *pphead = (*pphead)->next;
        free(pos);
        pos = NULL;
        return;
    }
    SLTNode * cur = *pphead;
    while(cur->next != pos) {
        cur = cur->next;
        assert(cur);
    }
    cur->next = pos->next;
    free(pos);
    pos = NULL;
}
void SListEraseAfter(SLTNode* pos) {
    assert(pos);
    if(pos->next == NULL) {
        assert(pos->next);
    }
    SLTNode * del = pos->next;
    pos->next = pos->next->next;
    free(del);
    del = NULL;
}