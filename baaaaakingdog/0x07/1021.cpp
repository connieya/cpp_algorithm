#include "stdio.h"
#include "deque"
#include "bits/stdc++.h"
using namespace std;
int main(void) {
    int n, m , tmp ,idx , cnt = 0;
    scanf("%d %d", &n, &m);
    deque<int> deque;
    for (int i = 1; i <= n; ++i) {
        deque.push_back(i);
    }
    while (m--){
        scanf("%d",&tmp);
        for (int i = 0; i < deque.size(); ++i) {
            if(deque[i] == tmp){
                idx = i;
                break;
            }
        }
        if (idx <= deque.size()-idx-1){
            for (int i = 0; i < idx; ++i) {
                int v = deque.front();
                deque.push_back(v);
                deque.pop_front();
                cnt++;
            }
        }else{
            for (int i = 0; i < deque.size() - idx; ++i) {
                deque.push_front(deque.back());
                deque.pop_back();
                cnt++;
            }
        }
        deque.pop_front();
    }
    printf("%d",cnt);
}