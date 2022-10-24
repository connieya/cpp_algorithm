#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int data;
    struct node * next; // 다음 노드의 주소를 저장할 필드
} Node;

Node * head = NULL; // 연결리스트의 첫 번째 노드의 주소를 저장할 포인터이다.

// 연결 리스트의 맨 앞에 새로운 노드 삽입하기
void add_first(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data =data;
    newNode->next = head;
    head = newNode;
}

void add_after(Node *node , int data){
    Node * newNode = (Node*) malloc(sizeof( Node));
    newNode->data =data;
    newNode->next = node->next;
    node->next = newNode;
}

void remove_node(Node *node){
    if(node == head){
        head = node->next;
        return;
    }
    Node * tmp = head;
    while (tmp->next != node && tmp->next){
        tmp =  tmp->next;
    }
    tmp->next = node->next;
    free(node);
}