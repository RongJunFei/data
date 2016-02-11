#include <stdio.h>
#include <malloc.h>
#include "linklist.h"

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	int length;
}TDLinkList;

DLinkList *DLinkList_Create()   //O(1)
{
	TDLinkList * ret = (TDLinkList *)malloc(sizeof(TDLinkList));
	if(ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
	}

	return ret;
}

void DLinkList_Destroy(DLinkList *list)   //O(1)
{
	free(list);
}

void DLinkList_Clear(DLinkList *list)    //O(1)
{
	TDLinkList *slist = (TDLinkList *)list;
	
	if(slist != NULL)
	{
		slist->length = 0;
		slist->header.next = NULL;
	}
}

int DLinkList_Length(DLinkList *list)   //O(1)
{
	TDLinkList * slist = (TDLinkList *)list;
	int ret = -1;

	if(slist != NULL)
	{
		ret = slist->length;
	}

	return ret;
}

int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos)   //O(n)
{
	TDLinkList *slist = (TDLinkList *)list;
	int ret = (slist != NULL) && (pos >= 0) && (node != NULL);
	int i = 0;

	if(ret)
	{
		DLinkListNode *current = (DLinkListNode *)slist;

		for(i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;
		}

		node->next = current->next;
		current->next = node;

		slist->length++;
	}

	return ret;
}

DLinkListNode *DLinkList_Get(DLinkList *list, int pos)    //O(n)
{
	TDLinkList *slist = (TDLinkList *)list;
	DLinkListNode * ret = NULL;
	int i = 0;

	if((slist != NULL) && (0 <= pos) && (pos < slist->length))
	{
		DLinkListNode * current = (DLinkListNode *)slist;

		for(i = 0; i < pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
	}

	return ret;
}

DLinkListNode *DLinkList_Delete(DLinkList *list, int pos)   //O(n)
{
	TDLinkList *slist = (TDLinkList *)list;
	DLinkListNode * ret = NULL;
	int i = 0;

	if((slist != NULL) && (0 <= pos) && (pos < slist->length))
	{
		DLinkListNode * current = (DLinkListNode *)slist;

		for(i = 0; i < pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
		current->next = ret->next;

		slist->length--;
	}

	return ret;
}

