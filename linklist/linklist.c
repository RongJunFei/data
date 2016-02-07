#include <stdio.h>
#include <malloc.h>
#include "linklist.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList *LinkList_Create()
{
	TLinkList * ret = (TLinkList *)malloc(sizeof(TLinkList));
	if(ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
	}

	return ret;
}

void LinkList_Destroy(LinkList *list)
{
}

void LinkList_Clear(LinkList *list)
{
}

int LinkList_Length(LinkList *list)
{
}

int LinkList_Insert(LinkList *list, LinkListNode *node, int pos)
{
}

LinkListNode *LinkList_Get(LinkList *list, int pos)
{
}

LinkListNode *LinkList_Delete(LinkList *list, int pos)
{
}

