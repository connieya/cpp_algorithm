#include "bits/stdc++.h"

using namespace std;

const int M = 1000003;
const int a = 1000;
const int MX = 500005; // 최대 삽입 횟수

int head[M];
int pre[MX];
int nxt[MX];
string key[MX];
int val[MX];
int unused = 0;

int my_hash(string &s) {
    int h = 0;
    for (auto x: s) {
        h = (h * a + x) % M;
    }
    return h;
}

// key[idx] == k 인 idx를 반환, 만약 k가 존재하지 않을 경우 -1을 반환
// 키에 대응되는 값을 반환하는게 아니라 인덱스를 반환함에 주의
int find(string k) {
    int h = my_hash(k);
    int idx = head[h];
    while (idx != -1) {
        if (key[idx] == k) return idx;
        idx = nxt[idx];
    }
    return -1;
}

void insert(string k , int v) {
    int idx = find(k);
    if (idx != -1){
        val[idx] = v;
        return;
    }
    int h = my_hash(k);
    key[unused] = k;
    val[unused] = v;
    if (head[h] != -1) {
        nxt[unused] = head[h];
        pre[head[h]] = unused;
    }
    head[h] = unused;
    unused++;
}


int main()
{

}

