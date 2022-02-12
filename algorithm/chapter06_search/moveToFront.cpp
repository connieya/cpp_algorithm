#include "bits/stdc++.h"

typedef int ElementData;

typedef struct tagNode
{
    ElementData data;
    tagNode * nextNode;
}Node;


Node * SLL_MoveToFront(Node ** Head , int target)
{
    Node * current  = (*Head);
    Node * previous = NULL;
    Node * Match = NULL;

    while(current != NULL)
    {
        if (current->data == target)
        {
            Match = current;
            if (previous != NULL)
            {
                previous->nextNode = current->nextNode;
                current->nextNode = (*Head);
                (*Head) = current;

            }
            break;
        }else {
            previous = current;
            current = current->nextNode;
        }
    }
    return Match;

}

Node * SLL_Transpose(Node ** Head , int target)
{
    Node * current = (*Head);
    Node * PPrevious = NULL;
    Node * Previous = NULL;
    Node * Match = NULL;

    while (current != NULL){
        if (current->data = target){
            Match = current;
            if (Previous != NULL){
                if (PPrevious != NULL){
                    PPrevious -> nextNode = current;
                }else {
                    (*Head) = current;
                }
                Previous ->nextNode = current ->nextNode;
                current-> nextNode = Previous;
            }
            break;
        }else {

            if (Previous != NULL){
                PPrevious = Previous;
            }
            Previous = current;
            current = current->nextNode;
        }
    }
    return Match;
}