#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
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

// index = (hash_a(string) + i * (hash_b(string) + 1)) % num_buckets

static int getHash(const char* s, const int hashTableLen, const int attempt)
{
    const int hash_a = hashFunc(s, PRIME_NUM1, hashTableLen);
    const int hash_b = hashFunc(s, PRIME_NUM2, hashTableLen);

    return (hash_a + (attempt * (hash_b + 1))) % hashTableLen;
}


void htInsert(hashTable *ht, const char *key, const char *value)
{
    htItem* item = htNewItem(key, value);
    int index = getHash(item->key, ht->size, 0);
    htItem* curItem = ht->items[index];
    for (int i = 1; curItem != NULL; ++i)
    {
        index = getHash(item->key, ht->size, i);
        curItem = ht->items[index];
    }
    ht->items[index] = item;
    ht->count++;
}

char* htSearch(hashTable *ht, const char* key)
{
    int index = getHash(key, ht->size, 0);
    htItem* item = ht->items[index];
    for (int i=1; item != NULL; ++i) {
        if (strcmp(key, item->key) == 0 ) {
            return item->value;
        }
        index = getHash(key, ht->size, i);
        item = ht->items[index];
    }
    return NULL;
}


