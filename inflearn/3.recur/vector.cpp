#include <iostream>
#include "vector"
using namespace::std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a;
    a.push_back(6);
    a.push_back(8);
    a.push_back(11);
    cout << a.size() << "\n"; // 3
    cout << a[1] << "\n"; // 8
    vector<int > b(5);
    b.push_back(2);
    b.push_back(4);
    b.push_back(6);
    b.push_back(8);
    b.push_back(10);
    b.push_back(12);
    for (int i = 0; i < b.size(); ++i) {
        cout << b[i] <<' '; // 0 0 0 0 0 2 4 6 8 10 12
    }
    cout << '\n';

    vector<int> c[3];
    c[0].push_back(1);
    c[0].push_back(3);
    c[0].push_back(5);
    c[1].push_back(2);
    c[1].push_back(4);
    c[1].push_back(6);
    c[2].push_back(7);
    cout << c[1][1] << '\n'; // 4
    cout << c[2][0] << '\n'; // 7
    cout << c[2][1] << '\n';  // 쓰레기 값

    vector<pair<int , int>> g[3]; // 빈 벡터 3개
   g[1].push_back({3,6});
   g[1].push_back({4,7});
   g[1].push_back({5,9});
   g[2].push_back(make_pair(7,7));
   cout << g[2][0].first << " " << g[2][0].second  << "\n";
}
