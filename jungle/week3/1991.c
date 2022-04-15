#include "stdio.h"

int tree[25][2];

void print_order(int p, int num) {
    if (p == '.') return;
    if (num == 2) printf("%c", p);
    print_order(tree[p][0], num);
    if (num == 1) printf("%c", p);
    print_order(tree[p][1], num);
    if (num == 0) printf("%c", p);
}

int main(void) {
    int n;
    int p, l, r;
    scanf("%d", &n);
    while (n--) {
        scanf(" %c %c %c", &p, &l, &r);
        printf("%d %d %d \n", p, l, r);
//        tree[p - 65][0] = l - 65;
//        tree[p - 65][1] = r - 65;
    }
//    int t = 3;
//    while (t--) {
//        print_order(0, t);
//        printf("\n");
//    }
}