#include "stdio.h"
#include "stdlib.h"
#include "string.h"

enum VisitMode {Visited, NotVisited};

typedef int ElementType;


typedef struct tagVertex
{
    ElementType Data;
    int Visited;
    int index;
    struct tagVertex * Next;
    struct tagEdge* AdjacencyList;
} Vertex;

typedef struct tagEdge
{
    int Weight;
    struct tagEdge*Next;
    Vertex * From;
    Vertex * Target;
} Edge;



typedef struct tagGraph
{
    Vertex * Vertices;
    int VertexCount;
} Graph;

typedef struct tagNode {
    char *Data;
    struct tagNode *NextNode;
} Node;

typedef struct tagLinkedQueue {
    Node *Front;
    Node *Rear;
    int Count;
} LinkedQueue;

Graph * CreateGraph()
{
    Graph * graph = (Graph *) malloc(sizeof(Graph));
    graph->Vertices = NULL;
    graph->VertexCount = 0;
    return graph;
}

void DestroyEdge(Edge * E){
    free(E);
}

void AddVertex(Graph * G , Vertex * V)
{
    Vertex * VertexList = G->Vertices;
    if (VertexList == NULL)
    {
        G->Vertices = V;
    }else {
        while (VertexList->Next != NULL){
            VertexList = VertexList->Next;
        }
        VertexList->Next = V;
    }
    V->index = G->VertexCount++;
}

void AddEdge(Vertex * V , Edge * E)
{
    if (V->AdjacencyList == NULL)
    {
        V->AdjacencyList = E;
    }else {
        Edge * AdjacencyList = V->AdjacencyList;
        while (AdjacencyList->Next != NULL) {
            AdjacencyList = AdjacencyList->Next;
        }
        AdjacencyList -> Next = E;
    }
}

void DestroyVertex(Vertex * v)
{
    while (v->AdjacencyList != NULL)
    {
        Edge *edge = v->AdjacencyList->Next;
        DestroyEdge(v->AdjacencyList);
        v->AdjacencyList = edge;
    }
    free(v);
}

Edge * CreateEdge(Vertex * From , Vertex * Target , int Weight)
{
    Edge * E = (Edge *) malloc(sizeof(Edge));
    E->From = From;
    E->Target = Target;
    E->Next = NULL;
    E->Weight = Weight;

    return E;
}

void DestroyGraph(Graph * G)
{
    while (G->Vertices != NULL)
    {
        Vertex  * Vertices = G->Vertices->Next;
        DestroyVertex(G->Vertices);
        G->Vertices = Vertices;

    }
    free(G);
}

Vertex * CreateVertex(ElementType Data)
{
    Vertex * V = (Vertex *) malloc(sizeof(Vertex));
    V->Data = Data;
    V->Next = NULL;
    V->AdjacencyList = NULL;
    V->Visited = NotVisited;
    V->index = -1;

    return V;

}

void PrintGraph(Graph * graph) {
    Vertex * V = NULL;
    Edge * E = NULL;
    if ( (V = graph->Vertices) == NULL) return;

    while (V != NULL){
        printf("%c : ", V->Data);
        if ( (E = V->AdjacencyList) == NULL ){
            V = V->Next;
            printf("\n");
            continue;
        }

        while (E != NULL)
        {
            printf("%c[%d] " , E->Target->Data , E->Weight);
            E = E->Next;
        }
        printf('\n');
        V = V->Next;
    }
    printf("\n");
}


int LQ_IsEmpty(LinkedQueue * Queue)
{
    return (Queue->Front == NULL);
}

Node * LQ_Dequeue(LinkedQueue * Queue)
{
    Node * Front = Queue->Front;
    if (Queue->Front->NextNode ==NULL)
    {
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else {
        Queue->Front = Queue->Front->NextNode;
    }
    Queue->Count--;
    return Front;
}

Node * LQ_CreateNode(char * NewData)
{
    Node * NewNode = (Node *) malloc(sizeof(Node));
    NewNode->Data = (Node *) malloc(sizeof(NewData)+1);
    strcpy(NewNode->Data, NewData);
    NewNode->NextNode = NULL;
    return NewNode;

}

void LQ_CreateQueue(LinkedQueue **Queue) {
    (*Queue) = (LinkedQueue *) malloc(sizeof(LinkedQueue));
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Count = 0;
}

void LQ_DestroyNode(Node * _Node)
{
    free(_Node->Data);
    free(_Node);
}

void LQ_DestroyQueue(LinkedQueue *Queue) {
    while (!LQ_IsEmpty(Queue)) {
        Node *Popped = LQ_Dequeue(&Queue);
        LQ_DestroyNode(Popped);
    }
    free(Queue);
}

void LQ_Enqueue(LinkedQueue *Queue, Node *NewNode) {
    if (Queue->Front == NULL) {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    } else {
        Queue->Rear->NextNode =NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
}


void DFS(Vertex* V)
{
    Edge * E = NULL;
    printf("%d ",V->Data);
    V->Visited = Visited;
    E = V->AdjacencyList;
    while (E != NULL)
    {
        if (E->Target != NULL && E->Target->Visited == NotVisited)
            DFS(E->Target);

        E = E->Next;
    }
}

void BFS(Vertex * V, LinkedQueue * Queue)
{
    Edge * E = NULL;
    printf("%d ",V->Data);
    V->Visited = Visited;

    LQ_Enqueue(&Queue, LQ_CreateNode(V));

    while (!LQ_IsEmpty(Queue)){
        Node * Popped = LQ_Dequeue(&Queue);
        V = Popped->Data;
        E = V->AdjacencyList;

        while (E!= NULL){
            if (V != NULL && V->Visited == NotVisited){
                printf("%d ", V->Data);
                V->Visited = Visited;
                LQ_Enqueue(&Queue, LQ_CreateNode(V));
            }
        }
        E = E->Next;
    }
}

int main(void)
{
    Graph * G = CreateGraph();
    Vertex * V1 = CreateVertex('1');
    Vertex * V2 = CreateVertex('2');
    Vertex * V3 = CreateVertex('3');
    Vertex * V4 = CreateVertex('4');
    Vertex * V5 = CreateVertex('5');

    AddVertex(G,V1);
    AddVertex(G,V2);
    AddVertex(G,V3);
    AddVertex(G,V4);
    AddVertex(G,V5);

    AddEdge(V1, CreateEdge(V1,V2,0));
    AddEdge(V1, CreateEdge(V1,V3,0));
    AddEdge(V1, CreateEdge(V1,V4,0));
    AddEdge(V1, CreateEdge(V1,V5,0));

    AddEdge(V2, CreateEdge(V2,V1,0));
    AddEdge(V2, CreateEdge(V2,V3,0));
    AddEdge(V2, CreateEdge(V2,V5,0));

    AddEdge(V3, CreateEdge(V3,V1,0));
    AddEdge(V3, CreateEdge(V3,V2,0));

    AddEdge(V4, CreateEdge(V4,V1,0));
    AddEdge(V4, CreateEdge(V4,V5,0));

    AddEdge(V5, CreateEdge(V5,V1,0));
    AddEdge(V5, CreateEdge(V5,V2,0));
    AddEdge(V5, CreateEdge(V5,V4,0));

    PrintGraph(G);
    DestroyGraph(G);
    return 0;
}