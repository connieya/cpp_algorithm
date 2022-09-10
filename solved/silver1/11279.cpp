#include "bits/stdc++.h"

using namespace std;

int max_heap[100001];
int sz;

void push(int x) {
    max_heap[++sz] = x;
    int child = sz;
    while (child > 1) {
        int parent = child / 2;
        if (max_heap[parent] >= max_heap[child]) break;
        swap(max_heap[parent], max_heap[child]);
        child = parent;
    }
}

int pop() {
    int root = 1;
    if(sz == 0) return 0;
    int answer = max_heap[root];
    swap(max_heap[1], max_heap[sz]);
    sz--;
    while (root*2 <= sz) {
        int lt = root * 2;
        int rt = root * 2 + 1;
        int mx = lt;
        if (rt <= sz && max_heap[rt] > max_heap[lt]) mx = rt;
        if (max_heap[root] >= max_heap[mx]) break;
        swap(max_heap[mx], max_heap[root]);
        root = mx;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x) {
            push(x);
        } else {
            cout << pop() << '\n';
        }
    }
}