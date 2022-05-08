#include "bits/stdc++.h"

using namespace std;

int main()
{
    list<int> mylist;
    list<int> ::iterator it;

    for (int i = 1; i <=5; ++i) {
        mylist.push_back(i); // {1 ,2 ,3, 4 , 5 }
    }

    it = mylist.begin(); //it 는 첫번째 인덱스의 값인 값 1을 가리킨다.
    it++; // it points now to number 2

    mylist.insert(it , 10); // { 1, 10 , 2, 3 ,4 ,5 }


    // 20을 2개 넣는다.
    mylist.insert(it,2,20); // { 1, 10 , 20 , 2 ,3, 4, 5 };
    for (int m : mylist) {
        cout << m << ' ';
    }
    cout << '\n';

    // it 는 인덱스를 가리키는 것이 아니라 값 2를 가리킨다. 2가 있는 위치
    mylist.insert(it ,5 ,-1);  // { 1 , 10 ,20 ,20 ,-1 ,-1 ,-1 ,-1 ,-1 ,2 ,3, 4, 5 }
    for(int m : mylist) {
        cout << m << ' ';
    }
    cout << '\n';


    mylist.insert(it,0); // { 1, 10 ,20 ,20 ,-1, -1 , -1,-1 ,-1, 0 ,2 ,3, 4 ,5 }
    for(int m : mylist) {
        cout << m << ' ';
    }
    cout << '\n';

    it--;
    mylist.insert(it,-10); // {1,10,20,20,-1,-1,-1,-1,-10 ,0,2,3,4,5}

    for(int m : mylist) {
        cout << m << ' ';
    }
    cout << '\n';
}