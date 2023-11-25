#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashTable.h"

static htItem* htNewItem(const char* k, const char* v)
{
    htItem* newItem = malloc(sizeof(htItem));
    newItem->key = k;
    newItem->value = v;
    return newItem;
}

hashTable* htNew()
{
    hashTable* newHashTable = malloc(sizeof(hashTable));

    newHashTable->size = 53;
    newHashTable->count = 0;
    newHashTable->items = calloc((size_t)newHashTable->size, sizeof(htItem*));
    return newHashTable;
}


