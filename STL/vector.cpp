#include "bits/stdc++.h"

using namespace std;

int main()
{
    vector<int> v;
    for(int i=0; i<5; i++){
        v.push_back(i);
    }
    v.erase(v.begin());
    for(auto a : v){
        cout << a << ' ';
    }
}