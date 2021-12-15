#include "bits/stdc++.h"

using namespace std;

const int MAX = 1000005;
int data[MAX];
int pos = 0;

void push(int x) {
    data[pos++] = x;
}

void pop() {
    pos--;
}

int top() {
    return data[pos - 1];
}

void test() {
    push(5);
    push(4);
    push(3);
    cout << top() << '\n'; // 3
    pop();
    pop();
    cout << top() << '\n'; // 5
    push(10);
    push(12);
    cout << top() << '\n'; // 12
    pop();
    cout << top() << '\n'; // 10
}

int main(void) {
    test();
}