#include "SeqList.h"

void TestSeqList1()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);
}

void TestSeqList2()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);
}

void TestSeqList3()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void TestSeqList4()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	//SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void TestSeqList5()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);

	SeqListInsert(&sl, 3, 40);
	SeqListPrint(&sl);
	SeqListInsert(&sl, 0, 40);
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 1000);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void TestSeqList6()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);

	SeqListErase(&sl, 2);
	SeqListPrint(&sl);
	SeqListErase(&sl, 0);
	SeqListPrint(&sl);
	SeqListErase(&sl, 2);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
}


int main() {
    TestSeqList6();
}
