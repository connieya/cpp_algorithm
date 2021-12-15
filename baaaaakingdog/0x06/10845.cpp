#include "stdio.h"

int head, tail;
int data[10000];

void push(int x) {
    data[tail++] = x;
}

void pop() {
    if (head == tail) {
        printf("-1\n");
        return;
    }
    printf("%d\n",data[head]);
    for (int i = head; i < tail; i++) {
        data[i] = data[i + 1];
    }
    tail--;
}

void front() {
    if (data[head]) {
        printf("%d\n", data[head]);
    } else {
        printf("%d\n", -1);
    }
}

void back() {
    if (!tail) {
        printf("-1\n");
    } else {
        printf("%d\n", data[tail - 1]);
    }
}

void size() {
    printf("%d\n", tail - head);
}

void empty() {
    if (!tail) {
        printf("1\n");
    } else {
        printf("0\n");
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        char str[6];
        scanf("%s", str);
        if (str[0] == 'p') {
            if (str[1] == 'u') {
                int t;
                scanf("%d", &t);
                push(t);
            }
            if (str[1] == 'o') {
                pop();
            }
        } else if (str[0] == 'f') {
            front();
        } else if (str[0] == 'b') {
            back();
        } else if (str[0] == 'e') {
            empty();
        } else {
            size();
        }
    }
}