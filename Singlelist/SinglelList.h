#pragma once
#include<stdio.h>
#include<assert.h>
#include <stdlib.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

SLTNode* BuySLTNode(SLTDataType x);
void SListPrint(SLTNode* phead);
void SListDestory(SLTNode** pphead);
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);

SLTNode* SListFind(SLTNode* phead, SLTDataType x);

// ��pos֮ǰ����
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

// ��pos�������
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// ɾ��posλ��
void SListErase(SLTNode** pphead, SLTNode* pos);

// ɾ��pos����λ��
void SListEraseAfter(SLTNode* pos);
