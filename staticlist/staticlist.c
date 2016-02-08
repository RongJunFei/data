#include <stdio.h>
#include <malloc.h>
#include "staticlist.h"

#define AVAILABLE -1

typedef struct _tag_StaticListNode
{
	unsigned int data;
	int next;
}TStaticListNode;

typedef struct _tag_StaticList
{
	int capacity;
	TStaticListNode header;
	TStaticListNode node[];
}TStaticList;

StaticList *StaticList_Create(int capacity)
{
	TStaticList *ret = NULL;
	int i = 0;

	if(capacity >= 0)
	{
		ret = (TStaticList *)malloc(sizeof(TStaticList) + sizeof(TStaticListNode) * (capacity + 1));
	}

	if(ret != NULL)
	{
		ret->capacity = capacity;
		ret->header.data = 0;
		ret->header.next = 0;

		for(i = 0; i <= capacity; i++)
		{
			ret->node[i].next = AVAILABLE;
		}
	}

	return ret;
}

void StaticList_Destroy(StaticList *list)
{
	free(list);
}

void StaticList_Clear(StaticList *list)
{
	TStaticList *sList = (TStaticList *)list;
	int i = 0;

	if(sList != NULL)
	{
		sList->header.data = 0;
		sList->header.next = 0;

		for(i = 0; i <= sList->capacity; i++)
		{
			sList->node[i].next = AVAILABLE;
		}
	}
}

int StaticList_Length(StaticList *list)
{
	TStaticList *sList = (TStaticList *)list;
	int ret = -1;

	if(sList != NULL)
	{
		ret = sList->header.data;
	}

	return ret;
}

int StaticList_Capacity(StaticList *list)
{
	TStaticList *sList = (TStaticList *)list;
	int ret = -1;

	if(sList != NULL)
	{
		ret = sList->capacity;
	}

	return ret;
}

int StaticList_Insert(StaticList *list, StaticListNode *node, int pos)
{
}

StaticListNode *StaticList_Get(StaticList *list, int pos)
{
}

StaticListNode *StaticList_Delete(StaticList *list, int pos)
{
}

