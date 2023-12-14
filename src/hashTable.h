#define PRIME_NUM1 151
#define PRIME_NUM2 163

typedef struct {
  char *key;
  char *value;
} htItem;

typedef struct {
  int size;
  int count;
  htItem **items;
} hashTable;

hashTable *htNew();
void delHashTable(hashTable *);
void htInsert(hashTable *ht, char *key, char *value);
char *htSearch(hashTable *ht, char *key);
void htDelete(hashTable *ht, char *key);
