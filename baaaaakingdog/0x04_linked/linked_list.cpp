#include "bits/stdc++.h"
using namespace std;

const int MX = 1000005;
int data[MX] , pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) {
    data[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) {
        pre[nxt[addr]] = unused;
    }
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) {
        pre[nxt[addr]] = pre[addr];
    }
}

void traverse() {
    int cur = nxt[0];
    while (cur != -1){
        cout << data[cur] << ' ';
        cur = nxt[cur];
    }
    cout <<  "\n\n";
}

int main()
{
    fill(pre,pre+MX , -1);
    fill(nxt, nxt + MX , -1);
}