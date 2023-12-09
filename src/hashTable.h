#define PRIME_NUM1 151
#define PRIME_NUM2 163


typedef struct {
    const char* key;
    char* value;
}htItem;

typedef struct {
    int size;
    int count;
    htItem** items;  
}hashTable;

hashTable* htNew();
void delHashTable(hashTable*);
void htInsert(hashTable* ht, const char* key, char* value);
char* htSearch(hashTable* ht, const char* key);
void htDelete(hashTable* ht, const char* key);
