#include <stdio.h>
#include <malloc.h>
#include "circlelist.h"

typedef struct _tag_CircleList
{
	CircleListNode header;
	int length;
}TCircleList;

CircleList *CircleList_Create()   //O(1)
{
	TCircleList * ret = (TCircleList *)malloc(sizeof(TCircleList));
	if(ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
	}

	return ret;
}

void CircleList_Destroy(CircleList *list)   //O(1)
{
	free(list);
}

void CircleList_Clear(CircleList *list)    //O(1)
{
	TCircleList *slist = (TCircleList *)list;
	
	if(slist != NULL)
	{
		slist->length = 0;
		slist->header.next = NULL;
	}
}

int CircleList_Length(CircleList *list)   //O(1)
{
	TCircleList * slist = (TCircleList *)list;
	int ret = -1;

	if(slist != NULL)
	{
		ret = slist->length;
	}

	return ret;
}

int CircleList_Insert(CircleList *list, CircleListNode *node, int pos)   //O(n)
{
	TCircleList *slist = (TCircleList *)list;
	int ret = (slist != NULL) && (pos >= 0) && (node != NULL);
	int i = 0;

	if(ret)
	{
		CircleListNode *current = (CircleListNode *)slist;

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

CircleListNode *CircleList_Get(CircleList *list, int pos)    //O(n)
{
	TCircleList *slist = (TCircleList *)list;
	CircleListNode * ret = NULL;
	int i = 0;

	if((slist != NULL) && (0 <= pos) && (pos < slist->length))
	{
		CircleListNode * current = (CircleListNode *)slist;

		for(i = 0; i < pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
	}

	return ret;
}

CircleListNode *CircleList_Delete(CircleList *list, int pos)   //O(n)
{
	TCircleList *slist = (TCircleList *)list;
	CircleListNode * ret = NULL;
	int i = 0;

	if((slist != NULL) && (0 <= pos) && (pos < slist->length))
	{
		CircleListNode * current = (CircleListNode *)slist;

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

