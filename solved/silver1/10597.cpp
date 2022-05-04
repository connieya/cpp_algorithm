#include "bits/stdc++.h"

using namespace std;

int max_num;
bool check[51];
vector<int> ans;
string numbers;
int len;

void dfs(int L){
    if (L == max_num){
        for (int a: ans) {
            cout << a << ' ';
        }
        exit(0);
    }
    for (int i = 0; i < len; ++i) {

    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> numbers;
    len = numbers.length();
    if(len <= 9){
        for (int i = 0; i < len; ++i) {
            cout << numbers[i] << ' ';
        }
        exit(0);
    }
    max_num = (len-9)/2 + 9;
}