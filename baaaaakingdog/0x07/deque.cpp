#include "bits/stdc++.h"

using namespace std;

const int MAX = 1000005;
int data[2*MAX +1];
int head = MAX, tail = MAX;

void push_front(int x){
    data[--head] = x;
}

void push_back(int x){
    data[tail++] = x;
}

void pop_front() {
    head++;
}

void pop_back() {
    tail--;
}

int front() {
    return data[head];
}

int back() {
    return data[tail-1];
}

void test(){
    push_back(30); // 30
    cout << front() << '\n'; // 30
    cout << back() << '\n'; // 30
    push_front(25); // 25 30
    push_back(12); // 25 30 12
    cout << back() << '\n'; // 12
    push_back(62); // 25 30 12 62
    pop_front(); // 30 12 62
    cout << front() << '\n'; // 30
    pop_front(); // 12 62
    cout << back() << '\n'; // 62
}

int main(void){
    test();
}