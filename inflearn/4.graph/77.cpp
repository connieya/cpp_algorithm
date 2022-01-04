#include "stdio.h"

int arr[1001];

int Find(int );
void Union(int a, int b);

int main(void) {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        arr[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d",&a,&b);
        Union(a,b);
    }
    scanf("%d %d",&a,&b);
    if (Find(a) == Find(b)){
        printf("YES");
    } else{
        printf("NO");
    }
}
int Find(int v){
    if (v == arr[v]){
        return v;
    }
    return arr[v] = Find(arr[v]);
}

void Union(int a, int b){
    int fa = Find(a);
    int fb = Find(b);
    if (fa != fb){
        arr[fa] = fb;
    }
}