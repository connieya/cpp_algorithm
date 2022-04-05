#include "bits/stdc++.h"

using namespace std;

string toBinary(int num){
    string str = "";
    while (num > 0){
        if (num%2) str = "1"+str;
        else str = "0"+str;
        num /=2;
    }
    return str;
}

void t1(int num , int index){
    // 해당 인덱스를 0으로 바꿈 (불끄기!!)
    cout << "func t1 call !!!! " << '\n';
    cout << num << ' ' << toBinary(num) << '\n';
    num  &= ~(1 << index);
    cout << num << ' ' << toBinary(num) << '\n';

    cout << "completed" << '\n';
}

void t3(int num) {
    cout << "func t3 call !!!! " << '\n';
    cout << num << ' ' << toBinary(num) << '\n';
    int index = (num & ~num);
    cout << "index = " << index << '\n';
}

void t4(int t , int n){
    cout << "func t4 call !!!! " << '\n';
    cout << t << ' ' << toBinary(t) << '\n';
    n = (1 << n)-1;
    cout << n << ' ' << toBinary(n) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num = 11 , index =3;
//    t1(num,index);
//    num = 124 , index = 4;
//    t1(num,index);
//    t3(18);
    t4(11,3);
}