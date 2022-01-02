#include "bits/stdc++.h"

using namespace std;

int heap[100005];
int size = 0;

void push(int x) {
    heap[++size] = x;
    int idx = size;
    while (idx != 1) {
        int parent = idx /2;
        if (heap[parent] <= heap[idx]) break;
        swap(heap[parent] , heap[idx]);
        idx = parent;
    }
}

int top() {
    return heap[1];
}

void pop() {
    heap[1] = heap[size--];
    int idx =1;
    while (2*idx <= size) {
        int lc =  2*idx , rc = 2*idx+1;
        int min_child = lc;
        if(rc <= size && heap[rc] < heap[lc]) {
            min_child = rc;
        }
        if (heap[idx] <= heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }

}

void test() {
    push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
    cout << top() << '\n'; // 2
    pop(); // {10, 5, 9}
    pop(); // {10, 9}
    cout << top() << '\n'; // 9
    push(5); push(15); // {10, 9, 5, 15}
    cout << top() << '\n'; // 5
    pop(); // {10, 9, 15}
    cout << top() << '\n'; // 9
}

int main(void)
{
    test();
}