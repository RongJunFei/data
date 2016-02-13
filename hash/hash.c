#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "bstree.h"

typedef struct _tag_HashNode HashNode;
struct _tag_HashNode
{
	BSTreeNode header;
	HashValue *value;
};

Hash *Hash_Create()
{
	return BSTree_Create();
}

void Hash_Destroy(Hash *hash)
{
}

void Hash_Clear(Hash *hash)
{
}

int Hash_Add(Hash *hash, HashKey *key, HashValue *value, Hash_Compare *compare)
{
	return 0;
}

HashValue *Hash_Remove(Hash *hash, HashKey *key, Hash_Compare *compare)
{
	return NULL;
}

HashValue *Hash_Get(Hash *hash, HashKey *key, Hash_Compare *compare)
{
	return NULL;
}

int Hash_Count(Hash *hash)
{
	return 0;
}

