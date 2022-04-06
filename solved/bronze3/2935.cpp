#include "bits/stdc++.h"

using namespace std;
int ans[10001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a,b;
    char c;
    cin >> a >> c >> b;
    int len_a = a.length();
    int len_b = b.length();
    if (c == '*'){
        ans[0] = 1;
        for (int i = 0; i < len_a+len_b-1; ++i) {
            cout << ans[i];
        }
    }else {
        if (len_a > len_b){
            int j = len_a-1;
            for (int i = len_b-1; i >=0; --i ,--j) {
                if (a[j] == '1' && b[i] == '1'){
                    a[j] ='2';
                }else if (a[j] =='0' && b[i] == '1'){
                    a[j] = '1';
                }
            }
            cout << a;
        }else {
            int j = len_b-1;
            for (int i = len_a-1; i >=0; --i , --j) {
                if (b[j] == '1' && a[i] == '1'){
                    b[j] ='2';
                }else if (b[j] =='0' && a[i] == '1'){
                    b[j] = '1';
                }
            }
            cout << b;
        }
    }
}