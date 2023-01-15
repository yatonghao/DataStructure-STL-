#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

LTNode* ListInit();
void ListDestory(LTNode* phead);

void ListPrint(LTNode* phead);
void ListPushBack(LTNode* phead, LTDataType x);
void ListPushFront(LTNode* phead, LTDataType x);
void ListPopBack(LTNode* phead);
void ListPopFront(LTNode* phead);
bool ListEmpty(LTNode* phead);
size_t ListSize(LTNode* phead);
LTNode* ListFind(LTNode* phead, LTDataType x);


void ListInsert(LTNode* pos, LTDataType x);

void ListErase(LTNode* pos);