﻿#include "stdio.h"
#include "memory.h"
#include "stdlib.h"

typedef int ElementType;

typedef struct tagHeapNode {
    ElementType Data;
} HeapNode;

typedef struct tagHeap {
    HeapNode *Nodes;
    int Capacity;
    int UsedSize;
} Heap;

Heap *HEAP_Create(int IntitialSize) {
    Heap *NewHeap = (Heap *) malloc(sizeof(Heap));
    NewHeap->Capacity = IntitialSize;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = (HeapNode *) malloc(sizeof(HeapNode) * NewHeap->Capacity);

    printf("size : %d\n", sizeof(HeapNode));
    return NewHeap;
}

void HEAP_Destroy(Heap *H) {
    free(H->Nodes);
    free(H);
}

void HEAP_SwapNodes(Heap *H, int current, int parent) {
    int CopySize = sizeof(HeapNode);
    HeapNode *Temp = (HeapNode *) malloc(CopySize);
    memcpy(Temp, &H->Nodes[current], CopySize);
    memcpy(&H->Nodes[current], &H->Nodes[parent], CopySize);
    memcpy(&H->Nodes[current], Temp, CopySize);
    free(Temp);
}

int HEAP_GetParent(int Index) {
    return (int) ((Index - 1) / 2);
}

int HEAP_GetLeftChild(int Index) {
    return (2 * Index) + 1;
}

void HEAP_PrintNodes(Heap *H) {
    int i = 0;
    for (i = 0; i < H->UsedSize; i++) {
        printf("%d ", H->Nodes[i].Data);
    }
    printf("\n");
}

void HEAP_Insert(Heap *H, ElementType NewData) {
    int CurrentPosition = H->UsedSize;
    int ParentPosition = HEAP_GetParent(CurrentPosition);

    if (H->UsedSize == H->Capacity) {
        H->Capacity *= 2;
        H->Nodes = (HeapNode *) realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }
    H->Nodes[CurrentPosition].Data = NewData;

    while (CurrentPosition > 0 && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data) {
        HEAP_SwapNodes(H, CurrentPosition, ParentPosition);
        CurrentPosition = ParentPosition;
        ParentPosition = HEAP_GetParent(CurrentPosition);
    }
    H->UsedSize++;
}

void HEAP_DeleteMin(Heap *H, HeapNode *Root) {
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
    memset(&H->Nodes[0], 0, sizeof(HeapNode));
    H->UsedSize--;
    HEAP_SwapNodes(H, 0, H->UsedSize);
    LeftPosition = HEAP_GetLeftChild(0);
    RightPosition = LeftPosition + 1;

    while (1)
    {
        int SelectedChild = 0;
        if (LeftPosition >= H->UsedSize){
            break;
        }
        if (RightPosition >= H->UsedSize)
        {
            SelectedChild = LeftPosition;
        }else {
            if (H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data){
                SelectedChild = RightPosition;
            }else {
                SelectedChild = LeftPosition;
            }
        }

        if (H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data)
        {
            HEAP_SwapNodes(H,ParentPosition,SelectedChild);
            ParentPosition = SelectedChild;
        }else {
            break;
        }
        LeftPosition = HEAP_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition+1;
    }

    if (H->UsedSize < (H->Capacity /2)){
        H->Capacity /=2;
        H->Nodes =
                (HeapNode *) realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }

}


int main(void) {
    Heap *H = HEAP_Create(3);
    HeapNode MinNode;

    HEAP_Insert(H, 12);
    HEAP_Insert(H, 87);
    HEAP_Insert(H, 111);
    HEAP_Insert(H, 34);
    HEAP_Insert(H, 16);
    HEAP_Insert(H, 75);
    HEAP_PrintNodes(H);

    HEAP_DeleteMin(H,&MinNode);
    HEAP_PrintNodes(H);

    HEAP_DeleteMin(H,&MinNode);
    HEAP_PrintNodes(H);

    HEAP_DeleteMin(H,&MinNode);
    HEAP_PrintNodes(H);

    HEAP_DeleteMin(H,&MinNode);
    HEAP_PrintNodes(H);

    HEAP_DeleteMin(H,&MinNode);
    HEAP_PrintNodes(H);

}