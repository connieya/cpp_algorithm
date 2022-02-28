#include "bits/stdc++.h"

using namespace std;

int main()
{
   string a = "qwertysezq";
   cout << a.substr(0) << '\n'; // qwertysezq
   cout << a.substr(1) << '\n'; // wertysezq
   cout << a.substr(2) << '\n'; // ertysezq
   cout << a.substr(3) << '\n'; // rtysezq
   cout << a.substr(4) << '\n'; // tysezq
   cout << a.substr(2,5) << '\n'; // ertys  2번째 인덱스에서 5개
   cout << a.substr(2,3) << '\n'; // ert  2번째 인덱스에서 3개
   cout << a.substr(2,1) << '\n'; // e  2번째 인덱스에서 1개
   cout << a.substr(2,2) << '\n'; // e  2번째 인덱스에서 2개
   cout << a.substr(6,2) << '\n'; // se  6번째 인덱스에서 2개
   cout << a.substr(6,4) << '\n'; // sezq  6번째 인덱스에서 4개
   cout << a.substr(6,5) << '\n'; // sezq 6번째 인덱스에서 5개  <= 범위 초과해도 됨
   cout << a.substr(3,-1) << '\n'; // rtysezq  3번쩨 인덱스에서 마지막 인덱스 까지
   cout << a.substr(3,-2) << '\n'; // rtysezq  3번쩨 인덱스에서 마지막 인덱스 까지

}