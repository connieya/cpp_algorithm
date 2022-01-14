#include "bits/stdc++.h"

using namespace std;

int main()
{
    list<int> L = {1,2}; // 1 2
    list<int>::iterator t = L.begin(); // t는 1을 가리키는 중
    L.push_front(10); // 10 1 2
    cout << *t << '\n'; // t가 가리키는 값인 1을 출력
    L.push_back(5); // 10 1 2 5
    L.insert(t,6); // 10 6 1 2 5
    t++; // t를 1칸 앞으로 전진 이제 t가 가리키는 값은 2
    t = L.erase(t); // t가 가리키는 값 을 제거,  10 6 1 5
    // 그 다음 원소인 5의 위치를 반환 -> t가 가리키는 값은 5
    cout << *t << '\n'; // 5
    for(auto i : L) {
        cout << i << ' ';
    }
    cout << '\n';
    for (list<int>::iterator it = L.begin();  it != L.end(); it ++) {
            cout << *it << ' ';
    }
}