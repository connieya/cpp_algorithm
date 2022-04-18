#include "bits/stdc++.h"

using namespace std;

int heapq[100001];
int sz = 0;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void push(int x) {
    heapq[++sz] = x;
    int idx = sz;
    while (idx != 1) {
        int parent = idx / 2;
        if (heapq[idx] > heapq[parent]) break;
        swap(heapq[idx], heapq[parent]);
        idx = parent;
    }
}

void pop() {
    if (sz == 0) return;
    heapq[1] = heapq[sz--];
    int root = 1;
    while (root * 2 <= sz) {
        int lc = root * 2, rc = root * 2 + 1;
        int min_child = lc;
        if (rc <= sz && heapq[lc] > heapq[rc]) {
            min_child = rc;
        }
        if (heapq[root] <= heapq[min_child]) break;
        swap(heapq[root], heapq[min_child]);
        root = min_child;
    }

}

int top() {
    return heapq[1];
}

bool isEmpty() {
    return sz == 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        if (num) {
            push(num);
        } else {
            if (isEmpty()) {
                cout << 0 << '\n';
            } else {
                cout << top() << '\n';
                pop();
            }
        }
    }

}