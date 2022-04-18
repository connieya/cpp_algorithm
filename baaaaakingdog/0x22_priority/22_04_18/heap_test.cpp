#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void swap(int &a , int &b){
    int temp = a;
    a = b;
    b = temp;
}

void push(int x){
    heap[++sz] = x;
    int idx = sz;
    while (idx != 1) {
        int par = idx/2;
        if (heap[par] < heap[idx]) break;
        swap(heap[par] , heap[idx]);
        idx = par;
    }
}

int top(){
    return heap[1];
}

void pop(){
    heap[1] = heap[sz--];
    int root =1;
    while (2*root <= sz){
        int lc = 2*root , rc = 2*root+1;
        int min_child = lc;
        if (rc <= sz && heap[rc] < heap[lc]) {
            min_child = rc;
        }
        if (heap[root] <= heap[min_child]) break;
        swap(heap[root], heap[min_child]);
        root = min_child;
    }
}

void test(){
    int a = 10;
    int b = 20;
    swap(a,b);
    cout << a << ' ' << b << '\n';



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

int main(){
    test();
}