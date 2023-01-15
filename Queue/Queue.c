#include "Queue.h"

void QueueInit(Queue* pq) {
    assert(pq);
    pq->head = pq->tail = NULL;
    pq->size = 0;
}
void QueueDestroy(Queue* pq) {
    assert(pq);
    QNode * cur = pq->head;
    while(cur) {
        QNode * next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
    pq->size = 0;
}
void QueuePush(Queue* pq, QDataType x) {
    assert(pq);
    QNode * newNode = (QNode*)malloc(sizeof(QNode));
    assert(newNode);
    newNode->data = x;
    newNode->next = NULL;
    if(pq->size == 0) {
        pq->head = pq->tail = newNode;
    }else {
        pq->tail->next = newNode;
        pq->tail = newNode;
    }
    pq->size++;
}
bool QueueEmpty(Queue* pq) {
    assert(pq);
    return pq->size == 0;
}
void QueuePop(Queue* pq) {
    assert(pq);
    assert(!QueueEmpty(pq));
    if(pq->head->next == NULL) {
        free(pq->head->next);
        pq->head = pq->tail = NULL;
    }else {
        QNode *del = pq->head;
        pq->head = pq->head->next;
        free(del);
        del = NULL;
    }
    pq->size--;
}
QDataType QueueFront(Queue* pq) {
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->head->data;
}
QDataType QueueBack(Queue* pq) {
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->tail->data;
}
int QueueSize(Queue* pq) {
    assert(pq);
    return pq->size;
}
