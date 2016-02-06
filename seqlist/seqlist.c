#include <stdio.h>
#include <malloc.h>
#include "seqlist.h"

typedef unsigned int TSeqListNode;

typedef struct _tag_SeqList
{
	int capacity;
	int length;
	TSeqListNode *Node;
}TSeqList;

SeqList *SeqList_Create(int capacity)
{
	TSeqList *ret = NULL;

	if(capacity >= 0)
	{
		ret = (TSeqList *)malloc(sizeof(TSeqList) + sizeof(TSeqListNode) * capacity);
	}
	
	if(ret != NULL)
	{
		ret->capacity = capacity;
		ret->length = 0;
		ret->Node = (TSeqListNode *)(ret +1);
	}

	return ret;
}
