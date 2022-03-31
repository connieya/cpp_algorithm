#include "bits/stdc++.h"

using namespace std;

int arr[10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c;
    cin >> a>> b >> c;
    int num = a*b*c;
    string str = to_string(num);
    for (int i = 0; str[i]; ++i) {
        arr[str[i]-'0']++;
    }
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << '\n';
    }

}