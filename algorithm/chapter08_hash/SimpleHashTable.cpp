#include "stdio.h"
#include "stdlib.h"

typedef int KeyType;
typedef int ValueType;

typedef struct tagNode
{
    KeyType Key;
    ValueType Value;
} Node;

typedef struct tagHashTable
{
    int TableSize;
    Node * Table;
} HashTable;

void Set(HashTable * HT, KeyType,ValueType);
int Hash(KeyType , int);

HashTable * createHashTable(int tableSize)
{
    HashTable * HT = (HashTable *) malloc(sizeof(HashTable));
    HT ->TableSize = tableSize;
    HT -> Table = (Node *) malloc(sizeof(Node)*tableSize);

    return HT;
}

void Set(HashTable * HT , KeyType key , ValueType value)
{
    int address = Hash(key,HT->TableSize);
    HT -> Table[address].Key = value;
    HT -> Table[address].Value = value;
}

ValueType Get(HashTable * HT , KeyType Key)
{
    int address = Hash(Key, HT->TableSize);
    return HT->Table[address].Value;
}

void destroyHashTable(HashTable * HT)
{
    free(HT->Table);
    free(HT);
}

int Hash(KeyType key , int tableSize)
{
    return key % tableSize;
}

int main(void)
{
    HashTable  * HT = createHashTable(193);
    Set(HT , 418 ,32114);
    Set(HT,9,514);
    Set(HT,27,8917);
    Set(HT,1031,286);

    printf("Key : %d , Value : %d \n",418, Get(HT,418));
    printf("Key : %d , Value : %d \n",9, Get(HT,9));
    printf("Key : %d , Value : %d \n",27, Get(HT,27));
    printf("Key : %d , Value : %d \n",1031, Get(HT,1031));

    destroyHashTable(HT);
    return 0;
}