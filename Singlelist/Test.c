#include "SinglelList.h"

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListDestory(&plist);
}

void TestSList2()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListDestory(&plist);

}


void TestSList3()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		pos->data *= 10;
	}
	SListPrint(plist);

	pos = SListFind(plist, 2);
	if (pos)
	{
		SListInsert(&plist, pos, 20);
	}
	SListPrint(plist);

	pos = SListFind(plist, 1);
	if (pos)
	{
		SListInsert(&plist, pos, 10);
	}
	SListPrint(plist);

	pos = SListFind(plist, 10);
	if (pos)
	{
		SListInsertAfter(pos, 11);
	}
	SListPrint(plist);

	pos = SListFind(plist, 4);
	if (pos)
	{
		SListInsertAfter(pos, 10);
	}
	SListPrint(plist);

	SListDestory(&plist);
}

void TestSList4()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 6);
	SListPushBack(&plist, 7);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SListErase(&plist,pos);
	}
	SListPrint(plist);
	pos = SListFind(plist, 7);
	if (pos)
	{
		SListErase(&plist,pos);
	}
	SListPrint(plist);
	pos = SListFind(plist, 1);
	if (pos)
	{
		SListErase(&plist,pos);
	}
	SListPrint(plist);
	SListDestory(&plist);

}

void TestSList5()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 6);
	SListPushBack(&plist, 7);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SListEraseAfter(pos);
	}
	SListPrint(plist);
	pos = SListFind(plist, 1);
	if (pos)
	{
		SListEraseAfter(pos);
	}
	SListPrint(plist);
	pos = SListFind(plist, 7);
	if (pos)
	{
		SListEraseAfter(pos);
	}
	SListPrint(plist);
	SListDestory(&plist);

}
int main()
{
	TestSList4();

	return 0;
}