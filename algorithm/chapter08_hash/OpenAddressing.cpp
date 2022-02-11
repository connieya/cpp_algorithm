#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef char * KeyType;
typedef char * ValueType;

enum ElementStatus
{
    EMPTY = 0,
    OCCUPIED = 1

};

typedef struct tagElementType
{
    KeyType key;
    ValueType value;
    ElementStatus status;
} ElementType;

typedef struct tagHashTable
{
    int occupiedCount;
    int tableSize;
    ElementType * table;
} HashTable;

void Set(HashTable**,KeyType,ValueType);
int Hash(KeyType,int,int);
int Hash2(KeyType,int,int);
void Rehash(HashTable**);

HashTable * createHashTable(int tableSize)
{
    HashTable * HT = (HashTable *) malloc(sizeof(HashTable));
    HT -> table = (ElementType *) malloc(sizeof(ElementType) * tableSize);

    memset(HT->table , 0 , sizeof(ElementType) * tableSize);

    HT -> tableSize = tableSize;
    HT -> occupiedCount = 0;
    return HT;
}

void Set(HashTable ** HT , KeyType key , ValueType value)
{
    int keyLen , address , stepSize;
    double usage;

    usage = (double ) (*HT)-> occupiedCount / (*HT) -> tableSize;
    if(usage > 0.5)
    {
        Rehash(HT);
    }
    keyLen = strlen(key);
    address = Hash(key,keyLen,(*HT)->tableSize);
    stepSize = Hash2(key,keyLen,(*HT)->tableSize);

    while ((*HT)-> table[address].status != EMPTY && strcmp((*HT)->table[address].key,key) != 0)
    {
        printf("collision occrued! : key(%s) , address(%d) stepSize(%d)",key,address,stepSize);

        address = (address+stepSize) % (*HT) -> tableSize;
    }
    (*HT) -> table[address].key = (char *) malloc(sizeof(char) * (keyLen+1));
    strcpy((*HT) -> table[address].key,key);

    (*HT) -> table[address].key = (char *) malloc(sizeof(char) * (keyLen+1));
    strcpy((*HT)-> table[address].key,key);

    (*HT)-> table[address].value = (char *) malloc(sizeof(char) * strlen(value) +1);
    strcpy((*HT)->table[address].value,value);
    (*HT)->table[address].status = OCCUPIED;
    (*HT)->occupiedCount++;

    printf("key(%s) entered at address(%d)\n",key,address);
}

