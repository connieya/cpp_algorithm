#include "stdio.h"

void recursive(int v) {
    if (v > 7)return;
//    printf("%d ",v); 전위 순회 출력
    recursive(v * 2);
    printf("%d ", v); //중위 순회 출력
    recursive(v * 2 + 1);
//    printf('%d ',v); 후위 순회 출력
}

int main() {
    int n;
    scanf("%d", &n);
    recursive(n);
    /*
    전위순회 출력 : 1 2 4 5 3 6 7
    중위순회 출력 : 4 2 5 1 6 3 7
    후위순회 출력 : 4 5 2 6 7 3 1
     */
}