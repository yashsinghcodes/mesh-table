typedef struct {
    char* key;
    char* value;
}htItem;

typedef struct {
    int size;
    int count;
    htItem** items;  
}hashTable;

hashTable* htNew();
void delHashTable(hashTable*);
