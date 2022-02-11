#include "bits/stdc++.h"

typedef char * KeyType;
typedef char * ValueType;

typedef struct tagNode
{
    KeyType Key;
    ValueType Value;
    struct tagNode * Next;
} Node;

typedef Node * List;

typedef struct tagTable
{
    int tableSize;
    List * Table;
} HashTable;

Node * createNode(KeyType,ValueType);
void Set(HashTable*,KeyType,ValueType);
int Hash(KeyType,int,int);

HashTable * createHashTable(int tableSize)
{
    HashTable  * HT = (HashTable*) malloc(sizeof(HashTable));
    HT -> Table = (List *) malloc(sizeof(List) * tableSize);

    memset(HT->Table , 0 , sizeof(List) * tableSize);
    HT -> tableSize = tableSize;;
    return HT;
}

Node * createNode(KeyType key , ValueType value)
{
    Node * NewNode  = (Node *) malloc(sizeof(Node));

    NewNode -> Key = (char  *) malloc(sizeof(char) * (strlen(key) +1));
    strcpy(NewNode->Key , key);

    NewNode -> Value = (char  *) malloc(sizeof(char) * (strlen(value) +1));
    strcpy(NewNode->Value , value);

    NewNode->Next = NULL;
    return NewNode;
}

void destroyNode(Node * TheNode)
{
    free(TheNode -> Key);
    free(TheNode -> Value);
    free(TheNode);
}

void Set(HashTable * HT , KeyType key , ValueType value)
{
   int address = Hash(key, strlen(key), HT->tableSize);
   Node  * NewNode = createNode(key,value);

    if (HT->Table[address] == NULL) {
        HT -> Table[address] = NewNode;
    }else {
        List L = HT->Table[address];
        NewNode -> Next = L;
        HT -> Table[address] = NewNode;

        printf("Collision occured : Key(%s) , address(%d) \n",key,address);
    }
}

ValueType Get(HashTable * HT , KeyType key)
{
    int address = Hash(key, strlen(key), HT->tableSize);

    List TheList = HT -> Table[address];
    List target = NULL;
    if(TheList == NULL){
        return NULL;
    }

    /* 원하는 값을 찾을 때까지 순차 탐색*/
    while (1)
    {
        if (strcmp(TheList -> Key, key) == 0)
        {
            target = TheList;
            break;
        }

        if (TheList -> Next == NULL)
            return NULL;
        else
            TheList = TheList -> Next;
    }
    return target -> Value;
}

void destroyList(List L)
{
    if (L == NULL)
        return;

    if (L->Next != NULL)
        destroyList(L->Next);

    destroyNode(L);
}

void destroyHashTable(HashTable * HT)
{
    for (int i = 0; i < HT->tableSize; ++i) {
        List L = HT->Table[i];
        destroyList(L);
    }
    free(HT->Table);
    free(HT);
}

int Hash(KeyType key , int len , int tableSize)
{
    int hashValue = 0;
    for (int i = 0; i < len; ++i) {
        hashValue = (hashValue << 3) + key[i];
    }

    hashValue = hashValue % tableSize;

    return hashValue;
}

int main(void)
{
    HashTable * HT = createHashTable(12289);
    Set(HT, "MSFT","Microsoft Corporation");
    Set(HT, "JAVA","Sun Microsystems");
    Set(HT, "REDH","Red Hat Linux");
    Set(HT, "APAC","Apache Org");
    Set(HT, "ZYMZZ","Unisys Ops Check");
    Set(HT, "IBM","IBM Ltd.");
    Set(HT, "ORCL","Oracle Corporation");
    Set(HT, "CSCO","Cisco Systems, Inc.");
    Set(HT, "GOOG","Google Inc.");
    Set(HT, "YHOO","Yahoo! Inc.");
    Set(HT, "NOVL","Novell, Inc.");

    printf("\n");
    printf("Key : %s , Value : %s \n","MSFT", Get(HT,"MSFT"));
    printf("Key : %s , Value : %s \n","JAVA", Get(HT,"JAVA"));
    printf("Key : %s , Value : %s \n","REDH", Get(HT,"REDH"));
    printf("Key : %s , Value : %s \n","APAC", Get(HT,"APAC"));
    printf("Key : %s , Value : %s \n","ZYMZZ", Get(HT,"ZYMZZ"));
    printf("Key : %s , Value : %s \n","IBM", Get(HT,"IBM"));
    printf("Key : %s , Value : %s \n","ORCL", Get(HT,"ORCL"));
    printf("Key : %s , Value : %s \n","CSCO", Get(HT,"CSCO"));
    printf("Key : %s , Value : %s \n","GOOG", Get(HT,"GOOG"));
    printf("Key : %s , Value : %s \n","YHOO", Get(HT,"YHOO"));
    printf("Key : %s , Value : %s \n","NOVL", Get(HT,"NOVL"));

    destroyHashTable(HT);
    return 0;
}