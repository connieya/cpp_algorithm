#include "stdio.h"
#include "algorithm"

using namespace std;

int size =0;
int heap[100001];

void push(int x) {
    heap[++size] = x;
    int child = size;
    while (child > 1) {
        int parent = child / 2;
        if (heap[parent] <= heap[child]) break;
        swap(heap[parent], heap[child]);
        child = parent;
    }
}

int top() {
    if (size == 0){
        return 0;
    }
    return heap[1];
}

void pop() {
    if (size ==0){
        return;
    }
    heap[1] = heap[size--];
    int parent = 1;
    while (parent * 2 <= size) {
        int left_child = 2 * parent;
        int right_child = 2 * parent + 1;
        int min_child = left_child;
        if (right_child <= size && heap[left_child] > heap[right_child]) {
            min_child = right_child;
        }
        if (heap[parent] <= heap[min_child]) break;
        swap(heap[min_child], heap[parent]);
        parent = min_child;
    }
}

int main(void) {
    int n, x;
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&x);
        if(!x){
            printf("%d\n",top());
            pop(); continue;
        }
        push(x);
    }
}