#include "stdlib.h"

typedef struct Node {
    int Data;
    Node *NextNode;
} Node;

Node *SLL_Transpose(Node **Head, int Target) {
    Node *Current = (*Head);
    Node *PPrevious = NULL; // 이전 노드의 이전노드
    Node *Previous = NULL; // 이전 노드
    Node *Match = NULL;
    while (Current != NULL) {

        if (Current->Data == Target) {
            Match = Current;
            if (Previous != NULL) {
                if (PPrevious != NULL) {
                    PPrevious->NextNode = Current;
                } else {
                    (*Head) = Current;
                }
                Previous->NextNode = Current->NextNode;
                Current->NextNode = Previous;
            }
            break;
        } else {
            if (Previous != NULL) {
                PPrevious = Previous;
            }
            Previous = Current;
            Current = Current->NextNode;
        }
    }
    return Match;

}