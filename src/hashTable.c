#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

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

static void htDelItem(htItem* i)
{
    free(i->key);
    free(i->value);
    free(i);
}

void delHashTable(hashTable* ht)
{
    for (int i = 0; i < ht->size; i++) {
        htItem* item = ht->items[i];
        if (item != NULL) {
           htDelItem(item);
        }
    }
    free(ht->items);
    free(ht);
}

static int hashFunc(const char* s, const int primeNum, const int hashTableLen)
{
    long hash = 0;
    const int lenKey = strlen(s);
    for (int i=0; i < lenKey; i++) {
        hash += (long)pow(primeNum, lenKey- (i+1)) * (int)s[i];
        hash = hash % hashTableLen;
    }
    return (int)hash;
}
