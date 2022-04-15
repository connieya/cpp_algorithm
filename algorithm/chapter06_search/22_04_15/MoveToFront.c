#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
    int Data;
    struct Node * next;
} Node;

Node * SLL_MoveToFront(Node ** Head , int target)
{
    Node * Current = (*Head);
    Node * Previous = NULL;
    Node * Match = NULL;

    while (Current != NULL)
    {
        if (Current->Data == target){
            Match = Current;
            if (Previous != NULL){
                Previous->next = Current->next;
                Current->next = (*Head);
                (*Head) = Current;
            }
            break;
        }else {
            Previous = Current;
            Current = Current->next;
        }
    }
    return Match;
}