#include "List.h"

void TestList1()
{
	

	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	ListPrint(plist);

	ListPushFront(plist, 10);
	ListPushFront(plist, 20);
	ListPushFront(plist, 30);
	ListPushFront(plist, 40);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPopBack(plist);
	ListDestory(plist);
	plist = NULL;
}

void TestList2()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	ListDestory(plist);
	plist = NULL;
}

void TestList3()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPrint(plist);
	printf("%u\n",ListSize(plist));
	LTNode* node = ListFind(plist, 1);
	if(node) {
		ListInsert(node,7);
	}
	ListPrint(plist);

	node = ListFind(plist, 5);
	if(node) {
		ListInsert(node,8);
	}
	ListPrint(plist);
	node = ListFind(plist, 8);
	if(node) {
		ListErase(node);
	}
	ListPrint(plist);
	
}

int main()
{
	TestList3();

	return 0;
}