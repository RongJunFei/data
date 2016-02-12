#include <stdio.h>
#include <malloc.h>
#include "dlinklist.h"

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode *slider;
	int length;
}TDLinkList;

DLinkList *DLinkList_Create()   //O(1)
{
	TDLinkList * ret = (TDLinkList *)malloc(sizeof(TDLinkList));
	if(ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
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
		slist->header.pre = NULL;
		slist->slider = NULL;
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
		DLinkListNode *next = NULL;

		for(i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;
		}

		next = current->next;

		current->next = node;
		node->next = next;

		if(next != NULL)
		{
			next->pre = node;
		}

		node->pre = current;

		if(slist->length == 0)
		{
			slist->slider = node;
		}

		if(current == (DLinkListNode *)slist)
		{
			node->pre = NULL;
		}

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
		DLinkListNode * next = NULL;

		for(i = 0; i < pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
		next = ret->next;

		current->next = next;

		if(next != NULL)
		{
			next->pre = current;

			if(current == (DLinkListNode *)slist)
			{
				next->pre = NULL;
			}
		}

		if(slist->slider == ret)
		{
			slist->slider = next;
		}

		slist->length--;
	}

	return ret;
}

DLinkListNode *DLinkList_DeleteNode(DLinkList *list, DLinkListNode *node)
{
	TDLinkList *slist = (TDLinkList *)list;
	DLinkListNode *ret = NULL;
	int i = 0;

	if(slist != NULL)
	{
		DLinkListNode *current = (DLinkListNode *)slist;

		for (i = 0; i < slist->length; i++)
		{
			if(current->next == node)
			{
				ret = current->next;
				break;
			}

			current = current->next;
		}

		if(ret != NULL)
		{
			DLinkList_Delete(slist, i);
		}
	}

	return ret;
}

DLinkListNode *DLinkList_Reset(DLinkList *list)
{
	TDLinkList *slist = (TDLinkList *)list;
	DLinkListNode * ret = NULL;

	if(slist != NULL)
	{
		slist->slider = slist->header.next;
		ret = slist->slider;
	}

	return ret;
}

DLinkListNode *DLinkList_Current(DLinkList *list)
{
	TDLinkList *slist = (TDLinkList *)list;
	DLinkListNode * ret = NULL;

	if(slist != NULL)
	{
		ret = slist->slider;
	}

	return ret;
}

DLinkListNode *DLinkList_Next(DLinkList *list)
{
	TDLinkList *slist = (TDLinkList *)list;
	DLinkListNode * ret = NULL;

	if((slist != NULL) && (slist->slider != NULL))
	{
		ret = slist->slider;
		slist->slider = ret->next;
	}

	return ret;
}

DLinkListNode *DLinkList_Pre(DLinkList *list)
{
	TDLinkList *slist = (TDLinkList *)list;
	DLinkListNode * ret = NULL;

	if((slist != NULL) && (slist->slider != NULL))
	{
		ret = slist->slider;
		slist->slider = ret->pre;
	}

	return ret;

}

