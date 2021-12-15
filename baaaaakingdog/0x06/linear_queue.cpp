#include "bits/stdc++.h"

using namespace std;

const int MAX = 1000005;
int data[MAX];
int head, tail;

void push(int x) {
    data[tail++] = x;
}

void pop() {
    head++;
}

int front() {
    return data[head];
}

int back() {
    return data[tail - 1];
}

void test() {
    push(10);
    push(20);
    push(30);
    cout << front() << '\n'; // 10
    cout << back() << '\n'; // 30
    pop();
    pop();
    push(15);
    push(25);
    cout << front() << '\n'; // 30
    cout << back() << '\n'; // 25
}

int main() {
    test();
}