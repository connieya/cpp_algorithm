#include "bits/stdc++.h"

using namespace std;

const int MX = 1000005;
int data[MX] , nxt[MX] , pre[MX];
int unused = 1;

void erase(int addr) {
    int n = nxt[addr];
    int p = pre[addr];
    nxt[p] = n;
    if (n != -1){
        pre[n] = p;
    }
}

void insert(int addr, int num) {
    data[unused] = num;
    pre[unused]  = addr;
    nxt[unused] = nxt[addr];
    // 맨 마지막 원소의 뒤에 새 원소를 추가하는 상황이 아니라면
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void traverse() {
    int cur = nxt[0];
    while (nxt[cur] != -1){
        cout << data[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test(){
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test(){
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}


int main() {
    fill(pre, pre+MX ,-1);
    fill(nxt ,nxt+MX,-1);
    insert_test();
    erase_test();
}
