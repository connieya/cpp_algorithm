#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int num = 666 , cnt = 1;
    while (1){
        if (cnt ==N){
            break;
        }
        num++;
        string str = to_string(num);
        int len = str.length();
        bool flag = false;
        for (int i = 0; i < len; ++i) {
            if (str[i] == '6' && i+1 <len && i+2 < len && str[i+1] == '6' && str[i+2] == '6'){
                flag = true;
                break;
            }
        }
        if (flag) {
            cnt++;
        }
    }
    cout << num;
}