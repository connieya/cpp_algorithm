#include "stdio.h"

int a[1000000];
int b[1000000];
int c[2000000];

int main(void) {
    int n, m, ai = 0, bi = 0, idx = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    while (ai < n && bi < m){
        if (a[ai] < b[bi]) {
            c[idx++] = a[ai];
            ai++;
        }else{
            c[idx++] = b[bi];
            bi++;
        }
    }
    while (ai < n){
        c[idx++] = a[ai++];
    }
    while (bi < m) {
        c[idx++] = b[bi++];
    }
    for (int i = 0; i < n+m; ++i) {
        printf("%d ",c[i]);
    }
}