#include <stdio.h>
#include <malloc.h>
#include "linklist.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList *LinkList_Create()   //O(1)
{
	TLinkList * ret = (TLinkList *)malloc(sizeof(TLinkList));
	if(ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
	}

	return ret;
}

void LinkList_Destroy(LinkList *list)   //O(1)
{
	free(list);
}

void LinkList_Clear(LinkList *list)    //O(1)
{
	TLinkList *slist = (TLinkList *)list;
	
	if(slist != NULL)
	{
		slist->length = 0;
		slist->header.next = NULL;
	}
}

int LinkList_Length(LinkList *list)   //O(1)
{
	TLinkList * slist = (TLinkList *)list;
	int ret = -1;

	if(slist != NULL)
	{
		ret = slist->length;
	}

	return ret;
}

int LinkList_Insert(LinkList *list, LinkListNode *node, int pos)   //O(n)
{
	TLinkList *slist = (TLinkList *)list;
	int ret = (slist != NULL) && (pos >= 0) && (node != NULL);
	int i = 0;

	if(ret)
	{
		LinkListNode *current = (LinkListNode *)slist;

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

LinkListNode *LinkList_Get(LinkList *list, int pos)    //O(n)
{
	TLinkList *slist = (TLinkList *)list;
	LinkListNode * ret = NULL;
	int i = 0;

	if((slist != NULL) && (0 <= pos) && (pos < slist->length))
	{
		LinkListNode * current = (LinkListNode *)slist;

		for(i = 0; i < pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
	}

	return ret;
}

LinkListNode *LinkList_Delete(LinkList *list, int pos)   //O(n)
{
	TLinkList *slist = (TLinkList *)list;
	LinkListNode * ret = NULL;
	int i = 0;

	if((slist != NULL) && (0 <= pos) && (pos < slist->length))
	{
		LinkListNode * current = (LinkListNode *)slist;

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

